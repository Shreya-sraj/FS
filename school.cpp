#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char data[15];
	int n = 0, option = 0, count_n = 0;
	string empty = "00";
	string proctor = "";
	ifstream f("Example.txt");
	string line;

	for (int i = 0; std::getline(f, line); ++i) {
		count_n++;
	}

	while (option != 5) {
		cout << "\nAvailable operations: \n1.Add New Students\n2."
			<< "Student Login\n3. Faculty Login\n4. Admin View\n"
			<< "5. Exit\nEnter option: ";
		cin >> option;

		if (option == 1) {
			cout << "Enter the number of students: ";
			cin >> n;

			count_n = count_n + n;

			for (int i = 0; i < n; i++) {
				ofstream outfile;
				outfile.open("Example.txt", ios::app);
				cout << "Enter your registration number: ";
				cin >> data;
				outfile << data << "\t";

				cout << "Enter your name: ";
				cin >> data;
				int len = strlen(data);

				while (len < 15) {
					data[len] = ' ';
					len = len + 1;
				}
				outfile << data << "\t";
				outfile << empty << "\t";
				outfile << empty << "\t";
			}
		}
		

		else if (option == 2) {
			char regno[9];
			cout << "Enter your registration number: ";
			cin >> regno;
			ifstream infile;
			int check = 0;
			infile.open("Example.txt", ios::in);

			while (infile >> data) {
				if (strcmp(data, regno) == 0) {
					cout
						<< "\nRegistration Number: " << data
						<< endl;
					infile >> data;
					cout << "Name: " << data << endl;

					infile >> data;
					cout << "CSE1001 mark: " << data
						<< endl;

					infile >> data;
					cout << "CSE1002 mark: " << data
						<< endl;

					infile >> data;

					infile.close();
					check = 1;
				}
			}

			if (check == 0) {
				cout << "No such registration number found!"
					<< endl;
			}
		}

		else if (option == 3) {
			char subcode[7];
			cout << "Enter your subject code: ";
			cin >> subcode;
			string code1 = "CSE1001", code2 = "CSE1002",
				mark = "";
			ifstream infile;
			int check = 0;

			cout << "\nAvailable operations: \n1. Add data "
					"about marks\n"
				<< "2. View data\nEnter option: ";
			cin >> option;

			if (option == 1) {
				cout
					<< "Warning! You would need to add mark"
					<< "details for all the students!"
					<< endl;
				for (int i = 0; i < count_n; i++) {
					fstream file("Example.txt");
					if (strcmp(subcode, code1.c_str())
						== 0) {
						file.seekp(26 + 37 * i,
								std::ios_base::beg);
						cout << "Enter the mark of student#"
							<< (i + 1) << " : ";
						cin >> mark;
						file.write(mark.c_str(), 2);
					}

					if (strcmp(subcode, code2.c_str())
						== 0) {
						file.seekp(29 + 37 * i,
								std::ios_base::beg);
						cout << "Enter the mark of student#"
							<< (i + 1) << " : ";
						cin >> mark;
						file.write(mark.c_str(), 2);
					}
				}
			}
			else if (option == 2) {
				infile.open("Example.txt", ios::in);
				if (strcmp(subcode, code1.c_str()) == 0) {
					cout << "Registration number - Marks\n"
						<< endl;
					while (infile >> data) {
						cout << data;
						infile >> data;
						infile >> data;
						cout << " - " << data << endl;
						infile >> data;
						infile >> data;
						check = 1;
					}
				}

				infile.close();
				infile.open("Example.txt", ios::in);

				if (strcmp(subcode, code2.c_str()) == 0) {
					cout << "Registration number - Marks\n"
						<< endl;
					while (infile >> data) {
						cout << data;
						infile >> data;
						infile >> data;
						infile >> data;
						cout << " - " << data << endl;
						infile >> data;
						check = 1;
					}
				}
			}

			infile.close();

			if (check == 0) {
				cout << "No such subject code found!"
					<< endl;
			}
		}
		else if (option == 4) {
			char password[25];
			cout << "Enter the admin password: ";
			cin >> password;
			string admin_pass = "admin";

			if (strcmp(password, admin_pass.c_str()) == 0) {
				cout << "Reg No. \t\tName\t\tCSE1001\t\t\tCSE1002\t"<< endl;
				ifstream infile;
				infile.open("Example.txt", ios::in);
				char data[20];

				while (infile >> data) {
					cout << data << "\t\t";
					infile >> data;
					cout << data << "\t\t";
					infile >> data;
					cout << data << "\t\t";
					infile >> data;
					cout << data << "\t\t";
					infile >> data;
					cout << data << endl;
				}
			}
		}
	}
}

