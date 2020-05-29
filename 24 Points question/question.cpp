#include <iostream>

using namespace std;

double sum = 0;
double success = 0;

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
		return -1;
	}
}

bool can_get_24(int num[4]) {
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
				if (result3 == 24)
					return true;
			}
		}
	}
	return false;
}

bool get_answer(int num[4]) {
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
					if(can_get_24(test))
						return true;
				}
			}
		}
	}
	return false;
}

void comb_all_card(int index, int begin, int len, int n, int all[4], int num[4]) {
	if (index == n) {
		int card_num[4];
		for (int i = 0; i < 4; i++) {
			card_num[i] = num[i] % 13;
			if (card_num[i] == 0)
				card_num[i] = 13;
		}
		if (get_answer(card_num))
			success++;
		sum++;

		return;
	}
	for (int j = begin; j <= len - n + index; j++) {
		num[index] = all[j];
		comb_all_card(index + 1, j + 1, len, n, all, num);
	}
}


int main() 
{
	int a = 1;

	int all[52];
	for (int i = 0; i < 52; i++)
		all[i] = i + 1;
	int num[4];

	comb_all_card(0, 0, 52, 4, all, num);
	
	cout << "Total number of combinations is " << sum << endl;
	cout << "Total number of combinations with solution is " << success << endl;
	cout << "The solution ratio is " << (success / sum) << endl;
	return 0;
}