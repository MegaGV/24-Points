#pragma once
#include <msclr\marshal_cppstd.h>
#include "compute.h"

namespace My24Points {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// twentyFour_Points 摘要
	/// </summary>
	public ref class twentyFour_Points : public System::Windows::Forms::Form
	{
	public:
		ArrayList^ numbers = gcnew ArrayList();
	public:
		twentyFour_Points(void)
		{
			InitializeComponent();
			this->pictureBox1->ImageLocation = "card\\b2fv.png";
			this->pictureBox2->ImageLocation = "card\\b2fv.png";
			this->pictureBox3->ImageLocation = "card\\b2fv.png";
			this->pictureBox4->ImageLocation = "card\\b2fv.png";
			//
			//TODO:  在此处添加构造函数代码
			//
		}
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~twentyFour_Points()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_refresh;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  expression_box;
	private: System::Windows::Forms::Button^  btn_verify;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Button^  btn_find_solution;
	private: System::Windows::Forms::TextBox^  solution_box;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(twentyFour_Points::typeid));
			this->btn_refresh = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->expression_box = (gcnew System::Windows::Forms::TextBox());
			this->btn_verify = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_find_solution = (gcnew System::Windows::Forms::Button());
			this->solution_box = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_refresh
			// 
			this->btn_refresh->Location = System::Drawing::Point(487, 12);
			this->btn_refresh->Name = L"btn_refresh";
			this->btn_refresh->Size = System::Drawing::Size(111, 46);
			this->btn_refresh->TabIndex = 0;
			this->btn_refresh->Text = L"Refresh";
			this->btn_refresh->UseVisualStyleBackColor = true;
			this->btn_refresh->Click += gcnew System::EventHandler(this, &twentyFour_Points::btn_refresh_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 64);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(142, 192);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 11));
			this->label1->Location = System::Drawing::Point(8, 307);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 19);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Enter an expression:";
			// 
			// expression_box
			// 
			this->expression_box->Font = (gcnew System::Drawing::Font(L"宋体", 15));
			this->expression_box->Location = System::Drawing::Point(223, 298);
			this->expression_box->Name = L"expression_box";
			this->expression_box->Size = System::Drawing::Size(244, 36);
			this->expression_box->TabIndex = 6;
			// 
			// btn_verify
			// 
			this->btn_verify->Location = System::Drawing::Point(487, 293);
			this->btn_verify->Name = L"btn_verify";
			this->btn_verify->Size = System::Drawing::Size(111, 46);
			this->btn_verify->TabIndex = 7;
			this->btn_verify->Text = L"Verify";
			this->btn_verify->UseVisualStyleBackColor = true;
			this->btn_verify->Click += gcnew System::EventHandler(this, &twentyFour_Points::btn_verify_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(160, 64);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(142, 192);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(308, 64);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(142, 192);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 9;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(456, 64);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(142, 192);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 10;
			this->pictureBox4->TabStop = false;
			// 
			// btn_find_solution
			// 
			this->btn_find_solution->Location = System::Drawing::Point(12, 12);
			this->btn_find_solution->Name = L"btn_find_solution";
			this->btn_find_solution->Size = System::Drawing::Size(142, 46);
			this->btn_find_solution->TabIndex = 11;
			this->btn_find_solution->Text = L"Find a Solution";
			this->btn_find_solution->UseVisualStyleBackColor = true;
			this->btn_find_solution->Click += gcnew System::EventHandler(this, &twentyFour_Points::btn_find_solution_Click);
			// 
			// solution_box
			// 
			this->solution_box->Font = (gcnew System::Drawing::Font(L"宋体", 15));
			this->solution_box->Location = System::Drawing::Point(175, 17);
			this->solution_box->Name = L"solution_box";
			this->solution_box->ReadOnly = true;
			this->solution_box->Size = System::Drawing::Size(292, 36);
			this->solution_box->TabIndex = 12;
			// 
			// twentyFour_Points
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(612, 365);
			this->Controls->Add(this->solution_box);
			this->Controls->Add(this->btn_find_solution);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btn_verify);
			this->Controls->Add(this->expression_box);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btn_refresh);
			this->Name = L"twentyFour_Points";
			this->Text = L"twentyFour_Points";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_refresh_Click(System::Object^  sender, System::EventArgs^  e) {//random get four different cards
		Random^ rd = gcnew Random();
		numbers->Clear();

		int num[4];
		int i = 0;
		while (i < 4) {
			int r = rd->Next(1, 53);
			for (int j = i - 1; j >= -1; j--) {
				if (r == num[j])
					break;
				if (j == -1)
					num[i++] = r;
			}
		}
		for (int i = 0; i < 4; i++)
			numbers->Add(num[i]);

		this->pictureBox1->ImageLocation = "card\\" + numbers[0]->ToString() + ".png";
		this->pictureBox2->ImageLocation = "card\\" + numbers[1]->ToString() + ".png";
		this->pictureBox3->ImageLocation = "card\\" + numbers[2]->ToString() + ".png";
		this->pictureBox4->ImageLocation = "card\\" + numbers[3]->ToString() + ".png";
	}
private: System::Void btn_verify_Click(System::Object^  sender, System::EventArgs^  e) {//check the input expression whether can get 24
	if (numbers->Count) {// if cards are exist
		std::string expression = msclr::interop::marshal_as<std::string>(expression_box->Text->ToString());
		if (expression == "") {//confirm the input is not empty
			MessageBox::Show(this, "please enter the expression");
			return;
		}
		int num[4];//save the numbers input have
		int card_num[4];//save the cards' numbers
		for (int i = 0; i < 4; i++) {
			card_num[i] = Convert::ToInt32(numbers[i]) % 13;
			if (card_num[i] == 0)
				card_num[i] = 13;
		}
		
		String ^str(gcnew System::String(convert_post(expression, num).c_str()));//transform the String^ to std::string

		//check the numbers input
		if (str->Equals("too many args") || str->Equals("too few args")) {
			MessageBox::Show(this, str);
			return;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 4; j++) {
				if (j == 4) {
					MessageBox::Show(this, "The numbers in the expression don't match the numbers in the set");
					return;
				}
				if (card_num[i] == num[j])
					break;
			}
		}
		//transform the expression to post_order_expression
		expression = msclr::interop::marshal_as<std::string>(str);
		
		if (compute(expression) == 24)
			MessageBox::Show(this, "Correct");
		else
			MessageBox::Show(this, "incorrect result");
	}
}
private: System::Void btn_find_solution_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numbers->Count) {
		int card_num[4];
		for (int i = 0; i < 4; i++) {
			card_num[i] = Convert::ToInt32(numbers[i]) % 13;
			if (card_num[i] == 0)
				card_num[i] = 13;
		}
		String ^str(gcnew System::String(get_answer(card_num).c_str()));

		this->solution_box->ReadOnly = false;
		this->solution_box->Text = str;
		this->solution_box->ReadOnly = true;
	}
}
};
}
