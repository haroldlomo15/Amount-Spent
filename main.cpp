#include <iostream>	//library for input/output
#include <string>	//library for strings
#include <fstream>	//for the file opening
#include <iomanip>	//library for setw
using namespace std;

struct sports_data	//structure that contains two sports
{
	string sports_one;
	string sports_two;
};
struct data_student	//structure that contains all the data
{
	string fname;
	string lname;
	string dormitory;
	int num_of_sports;
	sports_data sports;
	float money;

};
//prototypes
void class_heading();
void get_student_data(ifstream&, data_student[]);
void amount_spent_on_sports(data_student[]);
void amount_spent_on_dormitory(data_student[]);
void amount_each_sports_each_dormitory(data_student[]);
void total_student_sports(data_student[]);
void total_student_dormitory(data_student[]);
void total_student_each_sports_each_dormitories(data_student[]);
int main()
{
	const int max_value = 30;
	ifstream myfile;
	data_student student_data[max_value];	//assigning max value to struct
	class_heading();	//calls the class heading
	get_student_data(myfile, student_data);	//get the infile data
	// called void functions that outputs the different questions
	amount_spent_on_sports(student_data);	
	amount_spent_on_dormitory(student_data);	
	amount_each_sports_each_dormitory(student_data);	
	total_student_sports(student_data);
	total_student_dormitory(student_data);
	total_student_each_sports_each_dormitories(student_data);
	cin.get();
}
void class_heading()	// declaring personal heading
{
	cout << "*********************************************\n";
	cout << "Harold Lomotey\n"
		"@02732375\n"
		"SYCS-135 Computer Science I \n"
		"December 10, 2015\n"
		"Extra Credit Assignment\n" 
		"**********************************************\n"<< endl;
}
void get_student_data(ifstream& myfile, data_student student_data[])	//void function that gets all the data from infile
{
	myfile.open("infile.txt");	//opens the file;
	for (int index = 1; index <= 25; index++)	// for loop assign data to struct in their respective index
	{
		myfile >> student_data[index].fname
			>> student_data[index].lname
			>> student_data[index].dormitory
			>> student_data[index].num_of_sports;
		if (student_data[index].num_of_sports == 2)
		{
			myfile >> student_data[index].sports.sports_one
				>> student_data[index].sports.sports_two;
		}
		else
		{
			myfile >> student_data[index].sports.sports_one;
		}
		myfile >> student_data[index].money;
	}
}

void amount_spent_on_sports(data_student student_data[])	//void function that calculates and outputs the amount spent on sports
{
	cout << "Question 1: What is the total amount of money spent on each sport?" << endl;
	string sports_array[4] = { "FOOTBALL","TENNIS","SOCCER","BASKETBALL" };	
	float amount_array[4] = {};
	for (int i = 0; i < 4; i++)
	{
		for (int index = 1; index <= 25; index++)
		{
			if (student_data[index].num_of_sports == 2 && (student_data[index].sports.sports_one == sports_array[i] || student_data[index].sports.sports_two == sports_array[i]))
				amount_array[i] += (student_data[index].money) / 2;
			else if (student_data[index].num_of_sports == 1 && student_data[index].sports.sports_one == sports_array[i])
				amount_array[i] += student_data[index].money;
		}
		cout << sports_array[i] << ": $" << amount_array[i] << endl;
	}
}

void amount_spent_on_dormitory(data_student student_data[])	//void function that calulates and outputs the amount sprnt on the dormitory
{
	cout << "\nQuestion 2: What is the total amount of money spent at each of the dormitories?" << endl;
	string dormitory_array[6] = { "BT", "DG", "FT", "TU", "OP", "LN" };
	float amount_array[6] = {};
	for (int i = 0; i < 6; i++)
	{
		for (int index = 1; index <= 25; index++)
		{
			if (student_data[index].dormitory == dormitory_array[i])
				amount_array[i] += student_data[index].money;
		}
		cout << dormitory_array[i] << ": $" << amount_array[i] << endl;
	}
	
}

void amount_each_sports_each_dormitory(data_student student_data[])	//void function that calculates and outputs the amount of each sports in each dormitory
{

	string sports_array[4] = { "FOOTBALL","TENNIS","SOCCER","BASKETBALL" };
	float amount_array[4][6] = { {}, {} };
	string dormitory_array[6] = { "BT", "DG", "FT", "TU", "OP", "LN" };
	cout << "\nQuestion 3: What is the total amount of money spent on each of the sports at each of the dormitories?" << endl;
	for (int y = 0; y < 6; y++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int index = 1; index <= 25; index++)
			{
				if (student_data[index].num_of_sports == 2)
				{
					if ((student_data[index].sports.sports_one == sports_array[i] || student_data[index].sports.sports_two == sports_array[i]) && student_data[index].dormitory == dormitory_array[y])
						amount_array[i][y] += (student_data[index].money) / 2;
				}
				else if (student_data[index].num_of_sports == 1)
				{
					if (student_data[index].sports.sports_one == sports_array[i] && student_data[index].dormitory == dormitory_array[y])
						amount_array[i][y] += student_data[index].money;
				}
			}
			cout << sports_array[i] << " in " << dormitory_array[y] << ": $" << amount_array[i][y] << endl;
		}

	}
}

void total_student_sports(data_student student_data[])	//void function to calulate number of students in each sports
{
	cout << "\nQuestion 4: What is the total number students participating in each of the sports?" << endl;
	string sports_array[4] = { "FOOTBALL", "TENNIS", "SOCCER", "BASKETBALL" };
	int count_array[4] = {};
	for (int i = 0; i < 4; i++)
	{
		for (int index = 1; index <= 25; index++)
		{
			if (student_data[index].sports.sports_one == sports_array[i] || student_data[index].sports.sports_two == sports_array[i])
				count_array[i] += 1;
		}

		cout << sports_array[i] << ": " << count_array[i] << " students" << endl;
	}
}
void total_student_dormitory(data_student student_data[])	//void function that gets the total number of students in each dormitory
{
	cout << "\nQuestion 5: What is the total number students participating at each of the dormitories?" << endl;
	string dormitory_array[6] = { "BT", "DG", "FT", "TU", "OP", "LN" };
	int count_array[6] = {};
	for (int i = 0; i < 6; i++)
	{
		for (int index = 1; index <= 25; index++)
		{
			if (student_data[index].dormitory == dormitory_array[i])
				count_array[i] += 1;
		}
		cout << dormitory_array[i] << ": " << count_array[i] << " students" << endl;
	}
}
void total_student_each_sports_each_dormitories(data_student student_data[])	//void function that gets the total students in each sports and in each dormitory
{
	cout << "\nQuestion 6: What is the total number students participating in each of the sports at each of the dormitories?" << endl;
	string dormitory_array[6] = { "BT", "DG", "FT", "TU", "OP", "LN" };
	string sports_array[4] = { "FOOTBALL", "TENNIS", "SOCCER", "BASKETBALL" };
	int count_array[6][4] = { {},{} };
	for (int i = 0; i < 6; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int index = 1; index <= 25; index++)
			{
				if ((student_data[index].sports.sports_one == sports_array[y] || student_data[index].sports.sports_two == sports_array[y]) && student_data[index].dormitory == dormitory_array[i])
					count_array[i][y] += 1;
			}
			cout << sports_array[y] << " in " << dormitory_array[i] << ": " << count_array[i][y] << " students" << endl;
		}
		cout << endl;
	}
}

//*********************************************
//Harold Lomotey
//@02732375
//SYCS - 135 Computer Science I
//December 10, 2015
//Extra Credit Assignment
//**********************************************
//
//Question 1: What is the total amount of money spent on each sport ?
//FOOTBALL : $650
//	TENNIS : $400
//	SOCCER : $425
//	BASKETBALL : $275
//
//	Question 2 : What is the total amount of money spent at each of the dormitories ?
//	BT : $300
//	DG : $250
//	FT : $250
//	TU : $400
//	OP : $400
//	LN : $150
//
//	Question 3 : What is the total amount of money spent on each of the sports at each of the dormitories ?
//	FOOTBALL in BT : $100
//	TENNIS in BT : $100
//	SOCCER in BT : $50
//	BASKETBALL in BT : $50
//	FOOTBALL in DG : $100
//	TENNIS in DG : $50
//	SOCCER in DG : $100
//	BASKETBALL in DG : $0
//	FOOTBALL in FT : $100
//	TENNIS in FT : $100
//	SOCCER in FT : $50
//	BASKETBALL in FT : $0
//	FOOTBALL in TU : $200
//	TENNIS in TU : $50
//	SOCCER in TU : $0
//	BASKETBALL in TU : $150
//	FOOTBALL in OP : $100
//	TENNIS in OP : $100
//	SOCCER in OP : $125
//	BASKETBALL in OP : $75
//	FOOTBALL in LN : $50
//	TENNIS in LN : $0
//	SOCCER in LN : $100
//	BASKETBALL in LN : $0
//
//	Question 4 : What is the total number students participating in each of the sports ?
//	FOOTBALL : 13 students
//	TENNIS : 8 students
//	SOCCER : 9 students
//	BASKETBALL : 6 students
//
//	Question 5 : What is the total number students participating at each of the dormitories ?
//	BT : 5 students
//	DG : 3 students
//	FT : 3 students
//	TU : 5 students
//	OP : 6 students
//	LN : 3 students
//
//	Question 6 : What is the total number students participating in each of the sports at each of the dormitories ?
//	FOOTBALL in BT : 2 students
//	TENNIS in BT : 2 students
//	SOCCER in BT : 1 students
//	BASKETBALL in BT : 1 students
//
//	FOOTBALL in DG : 2 students
//	TENNIS in DG : 1 students
//	SOCCER in DG : 2 students
//	BASKETBALL in DG : 0 students
//
//	FOOTBALL in FT : 2 students
//	TENNIS in FT : 2 students
//	SOCCER in FT : 1 students
//	BASKETBALL in FT : 0 students
//
//	FOOTBALL in TU : 4 students
//	TENNIS in TU : 1 students
//	SOCCER in TU : 0 students
//	BASKETBALL in TU : 3 students
//
//	FOOTBALL in OP : 2 students
//	TENNIS in OP : 2 students
//	SOCCER in OP : 3 students
//	BASKETBALL in OP : 2 students
//
//	FOOTBALL in LN : 1 students
//	TENNIS in LN : 0 students
//	SOCCER in LN : 2 students
//	BASKETBALL in LN : 0 students

