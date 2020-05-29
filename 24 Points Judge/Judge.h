#pragma once
#include "../24 Points/compute.h"

namespace My24PointsJudge {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Judge 摘要
	/// </summary>
	public ref class Judge : public System::Windows::Forms::Form
	{
	public:
		Judge(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Judge()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  number_box1;
	protected:
	private: System::Windows::Forms::TextBox^  number_box2;
	private: System::Windows::Forms::TextBox^  number_box3;
	private: System::Windows::Forms::TextBox^  number_box4;
	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::TextBox^  solution_box;
	private: System::Windows::Forms::Button^  btn_find_solution;

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
			this->number_box1 = (gcnew System::Windows::Forms::TextBox());
			this->number_box2 = (gcnew System::Windows::Forms::TextBox());
			this->number_box3 = (gcnew System::Windows::Forms::TextBox());
			this->number_box4 = (gcnew System::Windows::Forms::TextBox());
			this->title = (gcnew System::Windows::Forms::Label());
			this->solution_box = (gcnew System::Windows::Forms::TextBox());
			this->btn_find_solution = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// number_box1
			// 
			this->number_box1->Font = (gcnew System::Drawing::Font(L"宋体", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->number_box1->Location = System::Drawing::Point(12, 45);
			this->number_box1->Name = L"number_box1";
			this->number_box1->Size = System::Drawing::Size(144, 144);
			this->number_box1->TabIndex = 0;
			// 
			// number_box2
			// 
			this->number_box2->Font = (gcnew System::Drawing::Font(L"宋体", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->number_box2->Location = System::Drawing::Point(162, 45);
			this->number_box2->Name = L"number_box2";
			this->number_box2->Size = System::Drawing::Size(144, 144);
			this->number_box2->TabIndex = 1;
			// 
			// number_box3
			// 
			this->number_box3->Font = (gcnew System::Drawing::Font(L"宋体", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->number_box3->Location = System::Drawing::Point(312, 45);
			this->number_box3->Name = L"number_box3";
			this->number_box3->Size = System::Drawing::Size(144, 144);
			this->number_box3->TabIndex = 2;
			// 
			// number_box4
			// 
			this->number_box4->Font = (gcnew System::Drawing::Font(L"宋体", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->number_box4->Location = System::Drawing::Point(462, 45);
			this->number_box4->Name = L"number_box4";
			this->number_box4->Size = System::Drawing::Size(144, 144);
			this->number_box4->TabIndex = 3;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"宋体", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->title->Location = System::Drawing::Point(12, 9);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(488, 28);
			this->title->TabIndex = 4;
			this->title->Text = L"Input four numbers between 1 to 13";
			// 
			// solution_box
			// 
			this->solution_box->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->solution_box->Location = System::Drawing::Point(12, 209);
			this->solution_box->Name = L"solution_box";
			this->solution_box->ReadOnly = true;
			this->solution_box->Size = System::Drawing::Size(444, 30);
			this->solution_box->TabIndex = 5;
			// 
			// btn_find_solution
			// 
			this->btn_find_solution->Location = System::Drawing::Point(462, 195);
			this->btn_find_solution->Name = L"btn_find_solution";
			this->btn_find_solution->Size = System::Drawing::Size(139, 56);
			this->btn_find_solution->TabIndex = 6;
			this->btn_find_solution->Text = L"find a solution";
			this->btn_find_solution->UseVisualStyleBackColor = true;
			this->btn_find_solution->Click += gcnew System::EventHandler(this, &Judge::btn_find_solution_Click);
			// 
			// Judge
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 264);
			this->Controls->Add(this->btn_find_solution);
			this->Controls->Add(this->solution_box);
			this->Controls->Add(this->title);
			this->Controls->Add(this->number_box4);
			this->Controls->Add(this->number_box3);
			this->Controls->Add(this->number_box2);
			this->Controls->Add(this->number_box1);
			this->Name = L"Judge";
			this->Text = L"Judge";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_find_solution_Click(System::Object^  sender, System::EventArgs^  e) {
		if (number_box1->Text != "" && number_box2->Text != "" && number_box3->Text != "" && number_box4->Text != "" ) {
			int num[4];
			num[0] = Convert::ToInt32(this->number_box1->Text);
			num[1] = Convert::ToInt32(this->number_box2->Text);
			num[2] = Convert::ToInt32(this->number_box3->Text);
			num[3] = Convert::ToInt32(this->number_box4->Text);
			for (int i = 0; i < 4; i++) {
				if (num[i] > 13 || num[i] < 1) {
					MessageBox::Show(this, "the number input is not in the range");
					return;
				}
			}

			String ^str(gcnew System::String(get_answer(num).c_str()));

			this->solution_box->ReadOnly = false;
			this->solution_box->Text = str;
			this->solution_box->ReadOnly = true;
		}
		else
			MessageBox::Show(this, "Please enter numbers");
	}
};
}
