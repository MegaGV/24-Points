#pragma once
#include <stack>
#include <math.h>
#include <queue>

using namespace std;

bool isoperator(const char& c) {
	return (c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-');
}

bool isnumber(const char& c) {
	return (c >= '0' && c <= '9');
}

int priority(const char& c) {
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}

string convert_post(const string& expression, int num[4]) {
	stack<char> operator_stack;
	string post_expression;
	int n = 0;

	for (int i = 0; expression != "" && i < expression.size(); i++) {
		if (expression[i] != ' ') {
			if (expression[i] == '(')
				operator_stack.push(expression[i]);
			else if (expression[i] == ')') {
				char ac = operator_stack.top();
				operator_stack.pop();

				while (ac != '(') {
					post_expression += ac;
					post_expression += ' ';

					ac = operator_stack.top();
					operator_stack.pop();
				}
			}
			else if (isoperator(expression[i])) {
				if (!operator_stack.empty()) {
					char ac = operator_stack.top();
					operator_stack.pop();

					while (priority(ac) > priority(expression[i])) {
						post_expression += ac;
						post_expression += ' ';

						if (operator_stack.empty())
							break;
						ac = operator_stack.top();
						operator_stack.pop();
					}
					if (priority(ac) <= priority(expression[i]))
						operator_stack.push(ac);
				}
				operator_stack.push(expression[i]);
			}
			else if (isnumber(expression[i])) {
				string snumber;
				int number = 0;
				while (i < expression.size() && expression[i] >= '0' && expression[i] <= '9') {
					snumber += expression[i];
					number = number * 10 + (expression[i++] - '0');
				}
				if (i != expression.size()) i--;
				
				if (n >= 4)
					return "too many args";
				num[n++] = number;
				post_expression += snumber;
				post_expression += ' ';
			}
		}
	}

	if (n < 4)
		return "too few args";

	while (!operator_stack.empty()) {
		char ac = operator_stack.top();
		operator_stack.pop();

		post_expression += ac;
		post_expression += ' ';
	}

	return post_expression;
}

int calculate(const int& num, const int& b, const char& op) {
	switch (op) {
	case '+':
		return num + b;
	case '-':
		return num - b;
	case '*':
		return num * b;
	case '/':
		return num / b;
	default:
		return 0;
	}
}

int compute(const std::string& expression) {
	stack<int> s;
	if (expression != "") {
		for (int i = 0; i < expression.size(); i++) {
			if (isoperator(expression[i])) {
				int d2 = s.top();
				s.pop();
				int d1 = s.top();
				s.pop();
				int d3 = calculate(d1, d2, expression[i]);
				s.push(d3);
			}
			else if (isnumber(expression[i])) {
				int number = 0;
				for (; i < expression.size() && isnumber(expression[i]); i++) {
					number = number * 10 + (expression[i] - '0');
				}
				if (i != expression.size()) i--;
				s.push(number);
			}
		}
	}
	return s.top();
}

string can_get_24(int num[4]) {
	char t[4] = { '+', '-', '*', '/' };
	for (int op1 = 0; op1 < 4; op1++) {
		if (num[0] != 0 && num[1] != 0 && (op1 == 3 && (num[0] % num[1] != 0 || num[1] % num[0] != 0))) {
			break;
		}
		int result1 = calculate(num[0], num[1], t[op1]);
		for (int op2 = 0; op2 < 4; op2++) {
			if (result1 != 0 && num[2] != 0 && (op2 == 3 && (result1 % num[2] != 0 || num[2] % result1 != 0))) {
				break;
			}

			int result2 = calculate(result1, num[2], t[op2]);

			for (int op3 = 0; op3 < 4; op3++) {
				if (result2 != 0 && num[3] != 0 && (op3 == 3 && (result2 % num[3] != 0 || result2 % num[3] != 0)))
					break;

				int result3 = calculate(result2, num[3], t[op3]);
				if (result3 == 24) {
					string answer = "(((";
					string snumber = "";

					while (num[0]) { snumber.insert(snumber.cbegin(), (num[0] % 10) + '0'); num[0] /= 10; }
					answer += snumber;
					snumber = "";
					answer += t[op1];

					while (num[1]) { snumber.insert(snumber.cbegin(), (num[1] % 10) + '0'); num[1] /= 10; }
					answer += snumber;
					snumber = "";
					answer += ')';
					answer += t[op2];

					while (num[2]) { snumber.insert(snumber.cbegin(), (num[2] % 10) + '0'); num[2] /= 10; }
					answer += snumber;
					snumber = "";
					answer += ')';
					answer += t[op3];

					while (num[3]) { snumber.insert(snumber.cbegin(), (num[3] % 10) + '0'); num[3] /= 10; }
					answer += snumber;
					answer += ')';

					return answer;
				}
			}
		}
	}
	return "";
}

string get_answer(int num[4]) {
	string result;
	for (int num1 = 0; num1 < 4; num1++) {
		for (int num2 = 0; num2 < 4; num2++) {
			if (num1 == num2)
				continue;
			for (int num3 = 0; num3 < 4; num3++) {
				if (num2 == num3 || num3 == num1)
					continue;
				for (int num4 = 0; num4 < 4; num4++) {
					if (num4 == num3 || num4 == num2 || num4 == num1)
						continue;
					int test[4] = { num[num1], num[num2], num[num3], num[num4] };
					
					string answer = can_get_24(test);
					if (answer != "") {
						if (result != "")
							result += ", ";
						result += answer;
					}
				}
			}
		}
	}
	if (result == "")
		return "No Solution";
	else
		return result;
}

