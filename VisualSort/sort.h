#pragma once
#include "miles.cpp"
#include <chrono>
#include <windows.h>
#define showneworder()\
s0->Location = Point(Xes[order.find(0)],s0->Location.Y);\
s1->Location = Point(Xes[order.find(1)],s1->Location.Y);\
s2->Location = Point(Xes[order.find(2)],s2->Location.Y);\
s3->Location = Point(Xes[order.find(3)],s3->Location.Y);\
s4->Location = Point(Xes[order.find(4)],s4->Location.Y);\
s5->Location = Point(Xes[order.find(5)],s5->Location.Y);\
s6->Location = Point(Xes[order.find(6)],s6->Location.Y);\
s7->Location = Point(Xes[order.find(7)],s7->Location.Y);\
s8->Location = Point(Xes[order.find(8)],s8->Location.Y);\
s9->Location = Point(Xes[order.find(9)],s9->Location.Y);\

#define fixbug() sort::Refresh();

#define assignx(s,x)\
switch(s){\
	case 0: s0->Location = Point(x, s0->Location.Y); break;\
	case 1: s1->Location = Point(x, s1->Location.Y); break;\
	case 2: s2->Location = Point(x, s2->Location.Y); break;\
	case 3: s3->Location = Point(x, s3->Location.Y); break;\
	case 4: s4->Location = Point(x, s4->Location.Y); break;\
	case 5: s5->Location = Point(x, s5->Location.Y); break;\
	case 6: s6->Location = Point(x, s6->Location.Y); break;\
	case 7: s7->Location = Point(x, s7->Location.Y); break;\
	case 8: s8->Location = Point(x, s8->Location.Y); break;\
	case 9: s9->Location = Point(x, s9->Location.Y); break;\
}\
fixbug();

#define assigny(s,y)\
switch(s){\
	case 0: s0->Location = Point(s0->Location.X, y); break;\
	case 1: s1->Location = Point(s1->Location.X, y); break;\
	case 2: s2->Location = Point(s2->Location.X, y); break;\
	case 3: s3->Location = Point(s3->Location.X, y); break;\
	case 4: s4->Location = Point(s4->Location.X, y); break;\
	case 5: s5->Location = Point(s5->Location.X, y); break;\
	case 6: s6->Location = Point(s6->Location.X, y); break;\
	case 7: s7->Location = Point(s7->Location.X, y); break;\
	case 8: s8->Location = Point(s8->Location.X, y); break;\
	case 9: s9->Location = Point(s9->Location.X, y); break;\
}\
fixbug();

#define getx(var, s)\
switch(s){\
	case 0: var = s0->Location.X; break;\
	case 1: var = s1->Location.X; break;\
	case 2: var = s2->Location.X; break;\
	case 3: var = s3->Location.X; break;\
	case 4: var = s4->Location.X; break;\
	case 5: var = s5->Location.X; break;\
	case 6: var = s6->Location.X; break;\
	case 7: var = s7->Location.X; break;\
	case 8: var = s8->Location.X; break;\
	case 9: var = s9->Location.X; break;\
}

#define gety(var, s)\
switch(s){\
	case 0: var = s0->Location.Y; break;\
	case 1: var = s1->Location.Y; break;\
	case 2: var = s2->Location.Y; break;\
	case 3: var = s3->Location.Y; break;\
	case 4: var = s4->Location.Y; break;\
	case 5: var = s5->Location.Y; break;\
	case 6: var = s6->Location.Y; break;\
	case 7: var = s7->Location.Y; break;\
	case 8: var = s8->Location.Y; break;\
	case 9: var = s9->Location.Y; break;\
}

#define animateswap(ia,ib)\
int ax;\
int bx;\
getx(ax, order[ia]);\
getx(bx, order[ib]);\
for (int o = 0; o <= abs(ax-bx); o++){\
	auto laststamp = std::chrono::high_resolution_clock::now();\
	while ((std::chrono::high_resolution_clock::now() - laststamp)/std::chrono::milliseconds(1) < ANISPEED);\
	if (ax > bx) {\
		assignx(order[ia], ax - o);\
		assignx(order[ib], bx + o);\
	} else {\
		assignx(order[ia], ax + o);\
		assignx(order[ib], bx - o);\
	}\
}\
order.swap(ia,ib);

#define animatecheckswap(ia,ib)\
int ax;\
int bx;\
int ay;\
int by;\
getx(ax, order[ia]);\
getx(bx, order[ib]);\
gety(ay, order[ia]);\
gety(by, order[ib]);\
if (doupdown) for (int o = 1; o <= 10; o++){\
	auto laststamp = std::chrono::high_resolution_clock::now();\
	while ((std::chrono::high_resolution_clock::now() - laststamp)/std::chrono::milliseconds(1) < ANISPEED);\
	assigny(order[ia], ay - o);\
	assigny(order[ib], by - o);\
}\
for (int o = 0; o <= abs(ax-bx); o++){\
	auto laststamp = std::chrono::high_resolution_clock::now();\
	while ((std::chrono::high_resolution_clock::now() - laststamp)/std::chrono::milliseconds(1) < ANISPEED);\
	if (ax > bx) {\
		assignx(order[ia], ax - o);\
		assignx(order[ib], bx + o);\
	} else {\
		assignx(order[ia], ax + o);\
		assignx(order[ib], bx - o);\
	}\
}\
if (doupdown) for (int o = 9; o >= 0; o--){\
	auto laststamp = std::chrono::high_resolution_clock::now();\
	while ((std::chrono::high_resolution_clock::now() - laststamp)/std::chrono::milliseconds(1) < ANISPEED);\
	assigny(order[ia], ay - o);\
	assigny(order[ib], by - o);\
}\
order.swap(ia,ib);

#define animatecheck(ia,ib)\
int ax;\
int bx;\
int ay;\
int by;\
getx(ax, order[ia]);\
getx(bx, order[ib]);\
gety(ay, order[ia]);\
gety(by, order[ib]);\
if (doupdown) for (int o = 1; o <= 10; o++){\
	auto laststamp = std::chrono::high_resolution_clock::now();\
	while ((std::chrono::high_resolution_clock::now() - laststamp)/std::chrono::milliseconds(1) < ANISPEED);\
	assigny(order[ia], ay - o);\
	assigny(order[ib], by - o);\
}\
if (doupdown) for (int o = 9; o >= 0; o--){\
	auto laststamp = std::chrono::high_resolution_clock::now();\
	while ((std::chrono::high_resolution_clock::now() - laststamp)/std::chrono::milliseconds(1) < ANISPEED);\
	assigny(order[ia], ay - o);\
	assigny(order[ib], by - o);\
}

#define hidebuttons()\
insertion_button->Visible = false;\
selection_button->Visible = false;\
bubble_button->Visible = false;\
quick_button->Visible = false;\
merge_button->Visible = false;\
shuffle_button->Visible = false;\
load_button->Visible = false;\
settings_button->Visible = false;

#define showbuttons()\
insertion_button->Visible = true;\
selection_button->Visible = true;\
bubble_button->Visible = true;\
quick_button->Visible = true;\
merge_button->Visible = true;\
shuffle_button->Visible = true;\
load_button->Visible = true;\
settings_button->Visible = true;

milesArray order = { 0,1,2,3,4,5,6,7,8,9 };
const milesArray Xes = { 6,47,88,129,170,211,252,293,334,375 };
bool animatortick = false;
int ANISPEED = 1;
bool doupdown = true;
#include "load.h"
#include "settings.h"

namespace VisualSort {
#pragma region more windows code
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for sort
	/// </summary>
	public ref class sort : public System::Windows::Forms::Form
	{
	public:
		sort(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void quickSort(int low, int high, int& checks, int& swaps)
		{
			if (low < high)
			{
				/* pi is partitioning index, arr[p] is now
				   at right place */
				int pi = partition(low, high, checks, swaps);

				// Separately sort elements before
				// partition and after partition
				quickSort(low, pi - 1,checks, swaps);
				quickSort(pi + 1, high, checks, swaps);
			}
		}
		int partition(int low, int high, int& checks, int& swaps)
		{
			int pivot = order[high];    // pivot
			int i = (low - 1);  // Index of smaller element

			for (int j = low; j <= high - 1; j++)
			{
				// If current element is smaller than or
				// equal to pivot
				if (order[j] <= pivot)
				{
					i++;    // increment index of smaller element
					animatecheckswap(i, j);
					swaps++;
					checks++;
				}
				else {
					animatecheck(i + 1, j);
					checks++;
				}
			}
			animateswap(i + 1, high);
			return (i + 1);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~sort()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ insertion_button;
	private: System::Windows::Forms::Button^ selection_button;
	private: System::Windows::Forms::Button^ bubble_button;
	private: System::Windows::Forms::Button^ quick_button;
	private: System::Windows::Forms::Button^ merge_button;
	protected:

	protected:




	private: System::Windows::Forms::Button^ shuffle_button;
	private: System::Windows::Forms::Button^ load_button;


	private: System::Windows::Forms::PictureBox^ s0;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ s9;

	private: System::Windows::Forms::PictureBox^ s8;


	private: System::Windows::Forms::PictureBox^ s7;

	private: System::Windows::Forms::PictureBox^ s6;

	private: System::Windows::Forms::PictureBox^ s5;


	private: System::Windows::Forms::PictureBox^ s4;

	private: System::Windows::Forms::PictureBox^ s3;

	private: System::Windows::Forms::PictureBox^ s2;

	private: System::Windows::Forms::PictureBox^ s1;
	private: System::Windows::Forms::Button^ settings_button;



	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma endregion
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sort::typeid));
			this->insertion_button = (gcnew System::Windows::Forms::Button());
			this->selection_button = (gcnew System::Windows::Forms::Button());
			this->bubble_button = (gcnew System::Windows::Forms::Button());
			this->quick_button = (gcnew System::Windows::Forms::Button());
			this->merge_button = (gcnew System::Windows::Forms::Button());
			this->shuffle_button = (gcnew System::Windows::Forms::Button());
			this->load_button = (gcnew System::Windows::Forms::Button());
			this->s0 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->s9 = (gcnew System::Windows::Forms::PictureBox());
			this->s8 = (gcnew System::Windows::Forms::PictureBox());
			this->s7 = (gcnew System::Windows::Forms::PictureBox());
			this->s6 = (gcnew System::Windows::Forms::PictureBox());
			this->s5 = (gcnew System::Windows::Forms::PictureBox());
			this->s4 = (gcnew System::Windows::Forms::PictureBox());
			this->s3 = (gcnew System::Windows::Forms::PictureBox());
			this->s2 = (gcnew System::Windows::Forms::PictureBox());
			this->s1 = (gcnew System::Windows::Forms::PictureBox());
			this->settings_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s0))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s1))->BeginInit();
			this->SuspendLayout();
			// 
			// insertion_button
			// 
			this->insertion_button->Location = System::Drawing::Point(12, 276);
			this->insertion_button->Name = L"insertion_button";
			this->insertion_button->Size = System::Drawing::Size(75, 23);
			this->insertion_button->TabIndex = 1;
			this->insertion_button->Text = L"Insertion";
			this->insertion_button->UseVisualStyleBackColor = true;
			this->insertion_button->Click += gcnew System::EventHandler(this, &sort::insertion_button_Click);
			// 
			// selection_button
			// 
			this->selection_button->Location = System::Drawing::Point(95, 276);
			this->selection_button->Name = L"selection_button";
			this->selection_button->Size = System::Drawing::Size(75, 23);
			this->selection_button->TabIndex = 1;
			this->selection_button->Text = L"Selection";
			this->selection_button->UseVisualStyleBackColor = true;
			this->selection_button->Click += gcnew System::EventHandler(this, &sort::selection_button_Click);
			// 
			// bubble_button
			// 
			this->bubble_button->Location = System::Drawing::Point(178, 276);
			this->bubble_button->Name = L"bubble_button";
			this->bubble_button->Size = System::Drawing::Size(75, 23);
			this->bubble_button->TabIndex = 1;
			this->bubble_button->Text = L"Bubble";
			this->bubble_button->UseVisualStyleBackColor = true;
			this->bubble_button->Click += gcnew System::EventHandler(this, &sort::bubble_button_Click);
			// 
			// quick_button
			// 
			this->quick_button->Location = System::Drawing::Point(261, 276);
			this->quick_button->Name = L"quick_button";
			this->quick_button->Size = System::Drawing::Size(75, 23);
			this->quick_button->TabIndex = 1;
			this->quick_button->Text = L"Quick";
			this->quick_button->UseVisualStyleBackColor = true;
			this->quick_button->Click += gcnew System::EventHandler(this, &sort::quick_button_Click);
			// 
			// merge_button
			// 
			this->merge_button->Location = System::Drawing::Point(344, 276);
			this->merge_button->Name = L"merge_button";
			this->merge_button->Size = System::Drawing::Size(75, 23);
			this->merge_button->TabIndex = 1;
			this->merge_button->Text = L"Extra";
			this->merge_button->UseVisualStyleBackColor = true;
			// 
			// shuffle_button
			// 
			this->shuffle_button->Location = System::Drawing::Point(12, 247);
			this->shuffle_button->Name = L"shuffle_button";
			this->shuffle_button->Size = System::Drawing::Size(158, 23);
			this->shuffle_button->TabIndex = 2;
			this->shuffle_button->Text = L"Shuffle";
			this->shuffle_button->UseVisualStyleBackColor = true;
			this->shuffle_button->Click += gcnew System::EventHandler(this, &sort::shuffle_button_Click);
			// 
			// load_button
			// 
			this->load_button->Location = System::Drawing::Point(261, 247);
			this->load_button->Name = L"load_button";
			this->load_button->Size = System::Drawing::Size(158, 23);
			this->load_button->TabIndex = 3;
			this->load_button->Text = L"Load";
			this->load_button->UseVisualStyleBackColor = true;
			this->load_button->Click += gcnew System::EventHandler(this, &sort::load_button_Click);
			// 
			// s0
			// 
			this->s0->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s0.Image")));
			this->s0->Location = System::Drawing::Point(6, 203);
			this->s0->Name = L"s0";
			this->s0->Size = System::Drawing::Size(20, 20);
			this->s0->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s0->TabIndex = 4;
			this->s0->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->s9);
			this->groupBox1->Controls->Add(this->s8);
			this->groupBox1->Controls->Add(this->s7);
			this->groupBox1->Controls->Add(this->s6);
			this->groupBox1->Controls->Add(this->s5);
			this->groupBox1->Controls->Add(this->s4);
			this->groupBox1->Controls->Add(this->s3);
			this->groupBox1->Controls->Add(this->s2);
			this->groupBox1->Controls->Add(this->s1);
			this->groupBox1->Controls->Add(this->s0);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(410, 229);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sort";
			// 
			// s9
			// 
			this->s9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s9.Image")));
			this->s9->Location = System::Drawing::Point(375, 23);
			this->s9->Name = L"s9";
			this->s9->Size = System::Drawing::Size(20, 200);
			this->s9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s9->TabIndex = 4;
			this->s9->TabStop = false;
			// 
			// s8
			// 
			this->s8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s8.Image")));
			this->s8->Location = System::Drawing::Point(334, 43);
			this->s8->Name = L"s8";
			this->s8->Size = System::Drawing::Size(20, 180);
			this->s8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s8->TabIndex = 4;
			this->s8->TabStop = false;
			// 
			// s7
			// 
			this->s7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s7.Image")));
			this->s7->Location = System::Drawing::Point(293, 63);
			this->s7->Name = L"s7";
			this->s7->Size = System::Drawing::Size(20, 160);
			this->s7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s7->TabIndex = 4;
			this->s7->TabStop = false;
			// 
			// s6
			// 
			this->s6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s6.Image")));
			this->s6->Location = System::Drawing::Point(252, 83);
			this->s6->Name = L"s6";
			this->s6->Size = System::Drawing::Size(20, 140);
			this->s6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s6->TabIndex = 4;
			this->s6->TabStop = false;
			// 
			// s5
			// 
			this->s5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s5.Image")));
			this->s5->Location = System::Drawing::Point(211, 103);
			this->s5->Name = L"s5";
			this->s5->Size = System::Drawing::Size(20, 120);
			this->s5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s5->TabIndex = 4;
			this->s5->TabStop = false;
			// 
			// s4
			// 
			this->s4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s4.Image")));
			this->s4->Location = System::Drawing::Point(170, 123);
			this->s4->Name = L"s4";
			this->s4->Size = System::Drawing::Size(20, 100);
			this->s4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s4->TabIndex = 4;
			this->s4->TabStop = false;
			// 
			// s3
			// 
			this->s3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s3.Image")));
			this->s3->Location = System::Drawing::Point(129, 143);
			this->s3->Name = L"s3";
			this->s3->Size = System::Drawing::Size(20, 80);
			this->s3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s3->TabIndex = 4;
			this->s3->TabStop = false;
			// 
			// s2
			// 
			this->s2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s2.Image")));
			this->s2->Location = System::Drawing::Point(88, 163);
			this->s2->Name = L"s2";
			this->s2->Size = System::Drawing::Size(20, 60);
			this->s2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s2->TabIndex = 4;
			this->s2->TabStop = false;
			// 
			// s1
			// 
			this->s1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s1.Image")));
			this->s1->Location = System::Drawing::Point(47, 183);
			this->s1->Name = L"s1";
			this->s1->Size = System::Drawing::Size(20, 40);
			this->s1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->s1->TabIndex = 4;
			this->s1->TabStop = false;
			// 
			// settings_button
			// 
			this->settings_button->Location = System::Drawing::Point(178, 247);
			this->settings_button->Name = L"settings_button";
			this->settings_button->Size = System::Drawing::Size(75, 23);
			this->settings_button->TabIndex = 6;
			this->settings_button->Text = L"Settings";
			this->settings_button->UseVisualStyleBackColor = true;
			this->settings_button->Click += gcnew System::EventHandler(this, &sort::settings_button_Click);
			// 
			// sort
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 311);
			this->Controls->Add(this->settings_button);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->load_button);
			this->Controls->Add(this->shuffle_button);
			this->Controls->Add(this->merge_button);
			this->Controls->Add(this->quick_button);
			this->Controls->Add(this->bubble_button);
			this->Controls->Add(this->selection_button);
			this->Controls->Add(this->insertion_button);
			this->Name = L"sort";
			this->Text = L"Sort";
			this->VisibleChanged += gcnew System::EventHandler(this, &sort::sort_VisibleChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s0))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->s1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void shuffle_button_Click(System::Object^ sender, System::EventArgs^ e) {
		order = order.shuffled();
		showneworder();
	}
	private: System::Void animator_Tick(System::Object^ sender, System::EventArgs^ e) {
		animatortick = true;
	}
	private: System::Void insertion_button_Click(System::Object^ sender, System::EventArgs^ e) {
		hidebuttons();
		int checks = 0;
		int swaps = 0;
		for (int i = 1; i < 10; i++) {
			int j = i;
			while (j > 0 && order[j - 1] > order[j]) {
				animatecheckswap(j, j - 1);
				j--;
				swaps++; checks++;
			}
			if (j) {
				animatecheck(j, j - 1);
				checks++;
			}
		}
		MessageBox::Show("Insertion Sort done with " + System::Convert::ToString(swaps) + " item swaps and " + System::Convert::ToString(checks) + " size comparisons.");
		showbuttons();
	}
	private: System::Void load_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		load^ obj1 = gcnew load(this);
		obj1->ShowDialog();
	}
	private: System::Void settings_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		settings^ obj1 = gcnew settings(this);
		obj1->ShowDialog();
	}
	private: System::Void sort_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		showneworder();
	}
	private: System::Void selection_button_Click(System::Object^ sender, System::EventArgs^ e) {
		hidebuttons();
		int checks = 0;
		int swaps = 0;
		for (int i = 0; i < 9; i++) {
			int currentmin = 10;
			int currentminindex = i;
			for (int j = i; j < 10; j++) {
				animatecheck(j, currentminindex);
				if (order[j] < currentmin) {
					currentmin = order[j];
					currentminindex = j;
				}
				checks++;
			}
			animateswap(i, currentminindex);
			swaps++;
		}
		MessageBox::Show("Selection Sort done with " + System::Convert::ToString(swaps) + " item swaps and " + System::Convert::ToString(checks) + " size comparisons.");
		showbuttons();
	}
	private: System::Void bubble_button_Click(System::Object^ sender, System::EventArgs^ e) {
		hidebuttons();
		int checks = 0;
		int swaps = 0;
		int changes = 0;
		int hardened = 9;
		do {
			changes = 0;
			int newhardened = 0;
			for (int i = 0; i < hardened; i++) {
				if (order[i] > order[i + 1]) {
					animatecheckswap(i, i + 1);
					newhardened = i + 1;
					swaps++;
					changes++;
				}
				else {
					animatecheck(i, i + 1);
				}
				checks++;
			}
			hardened = newhardened;
		} while (changes > 0);
		MessageBox::Show("Bubble Sort done with " + System::Convert::ToString(swaps) + " item swaps and " + System::Convert::ToString(checks) + " size comparisons.");
		showbuttons();
	}
	private: System::Void quick_button_Click(System::Object^ sender, System::EventArgs^ e) {
		hidebuttons();
		int checks = 0;
		int swaps = 0;
		quickSort(0, 9, checks, swaps);
		MessageBox::Show("Quick Sort done with " + System::Convert::ToString(swaps) + " item swaps and " + System::Convert::ToString(checks) + " size comparisons.");
		showbuttons();
	}
};
}


