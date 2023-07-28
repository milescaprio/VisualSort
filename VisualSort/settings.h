#pragma once

namespace VisualSort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for settings
	/// </summary>
	public ref class settings : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		settings(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		settings(Form^ obj1)
		{
			obj = obj1;
			InitializeComponent();
			speed_bar->Value = speed_bar->Maximum + 1 - ANISPEED;
			show_comparison_check->Checked = doupdown;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^ speed_bar;
	private: System::Windows::Forms::Label^ sort_speed_label;
	private: System::Windows::Forms::CheckBox^ show_comparison_check;
	private: System::Windows::Forms::Button^ save_button;
	protected:

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
			this->speed_bar = (gcnew System::Windows::Forms::TrackBar());
			this->sort_speed_label = (gcnew System::Windows::Forms::Label());
			this->show_comparison_check = (gcnew System::Windows::Forms::CheckBox());
			this->save_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speed_bar))->BeginInit();
			this->SuspendLayout();
			// 
			// speed_bar
			// 
			this->speed_bar->Location = System::Drawing::Point(12, 25);
			this->speed_bar->Maximum = 19;
			this->speed_bar->Name = L"speed_bar";
			this->speed_bar->Size = System::Drawing::Size(260, 45);
			this->speed_bar->TabIndex = 0;
			this->speed_bar->Value = 19;
			// 
			// sort_speed_label
			// 
			this->sort_speed_label->AutoSize = true;
			this->sort_speed_label->Location = System::Drawing::Point(112, 9);
			this->sort_speed_label->Name = L"sort_speed_label";
			this->sort_speed_label->Size = System::Drawing::Size(60, 13);
			this->sort_speed_label->TabIndex = 1;
			this->sort_speed_label->Text = L"Sort Speed";
			// 
			// show_comparison_check
			// 
			this->show_comparison_check->AutoSize = true;
			this->show_comparison_check->Checked = true;
			this->show_comparison_check->CheckState = System::Windows::Forms::CheckState::Checked;
			this->show_comparison_check->Location = System::Drawing::Point(12, 76);
			this->show_comparison_check->Name = L"show_comparison_check";
			this->show_comparison_check->Size = System::Drawing::Size(116, 17);
			this->show_comparison_check->TabIndex = 2;
			this->show_comparison_check->Text = L"Show Comparisons";
			this->show_comparison_check->UseVisualStyleBackColor = true;
			// 
			// save_button
			// 
			this->save_button->Location = System::Drawing::Point(105, 226);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(75, 23);
			this->save_button->TabIndex = 4;
			this->save_button->Text = L"Save";
			this->save_button->UseVisualStyleBackColor = true;
			this->save_button->Click += gcnew System::EventHandler(this, &settings::save_button_Click);
			// 
			// settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->save_button);
			this->Controls->Add(this->show_comparison_check);
			this->Controls->Add(this->sort_speed_label);
			this->Controls->Add(this->speed_bar);
			this->Name = L"settings";
			this->Text = L"settings";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speed_bar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		ANISPEED = speed_bar->Maximum - speed_bar->Value + 1;
		doupdown = show_comparison_check->Checked;
		this->Hide();
		obj->Show();
	}
};
}
