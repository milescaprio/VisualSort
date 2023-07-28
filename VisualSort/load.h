#pragma once

namespace VisualSort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for load
	/// </summary>
	public ref class load : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		load(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		load(Form ^obj1)
		{
			obj = obj1;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~load()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ loadinput_text;
	private: System::Windows::Forms::Label^ load_label;
	protected:



	private: System::Windows::Forms::Button^ ok_button;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loadinput_text = (gcnew System::Windows::Forms::TextBox());
			this->load_label = (gcnew System::Windows::Forms::Label());
			this->ok_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// loadinput_text
			// 
			this->loadinput_text->Location = System::Drawing::Point(92, 120);
			this->loadinput_text->Name = L"loadinput_text";
			this->loadinput_text->Size = System::Drawing::Size(100, 20);
			this->loadinput_text->TabIndex = 0;
			// 
			// load_label
			// 
			this->load_label->AutoSize = true;
			this->load_label->Location = System::Drawing::Point(111, 104);
			this->load_label->Name = L"load_label";
			this->load_label->Size = System::Drawing::Size(63, 13);
			this->load_label->TabIndex = 1;
			this->load_label->Text = L"Load Order:";
			// 
			// ok_button
			// 
			this->ok_button->Location = System::Drawing::Point(105, 226);
			this->ok_button->Name = L"ok_button";
			this->ok_button->Size = System::Drawing::Size(75, 23);
			this->ok_button->TabIndex = 2;
			this->ok_button->Text = L"OK";
			this->ok_button->UseVisualStyleBackColor = true;
			this->ok_button->Click += gcnew System::EventHandler(this, &load::ok_button_Click);
			// 
			// load
			// 
			this->AcceptButton = this->ok_button;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->ok_button);
			this->Controls->Add(this->load_label);
			this->Controls->Add(this->loadinput_text);
			this->Name = L"load";
			this->Text = L"load";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void ok_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ input = loadinput_text->Text;
		milesArray temporder = 10;
		if (input->Length != 10) {
			MessageBox::Show("Incorrect Format: Please enter the numbers 0-9 in the order of your choice.", "Please Reformat", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		for (int i = 0; i < 10; i++) {
			temporder[i] = input[i] - '0';
		}
		if (!(temporder.ascending() == milesArray({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}))) {
			MessageBox::Show("Incorrect Format: Please enter the numbers 0-9 in the order of your choice.", "Please Reformat", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		order = temporder;
		this->Hide();
		obj->Show();
	}
	};
}
