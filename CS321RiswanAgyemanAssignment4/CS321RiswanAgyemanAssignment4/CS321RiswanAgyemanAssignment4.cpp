// CS321RiswanAgyemanAssignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

long long int factorial(long long int num);
double sumover(unsigned int n);
void tower(const int& disk, const int& fromPole, const int& toPole);

int main() {
	int menu = 0;

	while (menu != 4) {
		cout << "*******************************************************" << endl;
		cout << "** Assignment 4: Select one menu **" << endl;
		cout << "*******************************************************" << endl;

		cout << "*******************************************************" << endl;
		cout << "** 1. Sum                                            **" << endl;
		cout << "** 2. Factorial                                      **" << endl;
		cout << "** 3. Tower                                          **" << endl;
		cout << "** 4. Exit                                           **" << endl;
		cout << "*******************************************************" << endl;

		cin >> menu;

		//ASK FOR ANOTHER INPUT IF THE USER INPUTS VALUE LESS THAN 1 or GREATER THAN 4 OPTION
		while (menu > 4 || menu < 1) {
			cout << "Error: Please select 1, 2, 3, or 4" << endl;
			cin >> menu;
		}

		//USER INPUTS 1 FROM THE MENU
		if (menu == 1) {
			int n;
			cout << "This is the Sumover Function" << endl;
			cout << "Input the integer you want to sumover: " << endl;
			cin >> n;
			cout << "The sumover of " << n << " is " << sumover(n) << endl;
		}
		//USER INPUTS 2 FROM THE MENU
		else if (menu== 2) {
			int num;
			cout << "Menu 2 is the Factorial Function" << endl;
			cout << "Enter the integer you want to find the factorial of: " << endl;
			cin >> num;
			cout << "The factorial of " << num << " is " << factorial(num) << endl;
		}
		//USER INPUTS 3 FROM THE MENU
		else if (menu == 3) {
			int total,startPole, endPole;
			cout << "Function 3-toTower Function" << endl;
			cout << "total number of disks: ";
			cin >> total;
			cout << "Move disk(s) from which pole to which pole?\n";
			cout << "From: ";
			cin >> startPole;
			cout << "To: ";
			cin >> endPole;
			tower(total, startPole, endPole);
		}
	}

	//USER INPUTS 4
	cout << "User has exited the Program" << endl;

	return 0;
}

//FACTORIAL FUNCTION
long long int factorial(long long int num) {
	if (num == 1) return 1;

	return num * factorial(num - 1);
}

//SUMOVER FUNCTION
double sumover(unsigned int x) {
	if (x == 0)
		return 0.0;
	if (x == 1)
		return 1.0;

	return ((double)1 / x + sumover(x - 1));
}

//TOWER OF HANOI FUNCTION
void tower(const int& disk, const int& fromPole, const int& toPole) {
	if (disk == 1)
		cout << "Move from " << fromPole << " to " << toPole << endl;
	else {
		int unusedPole = 6 - fromPole - toPole;
		tower(disk - 1, fromPole, unusedPole);
		cout << "Move from " << fromPole << " to " << toPole << endl;
		tower(disk - 1, unusedPole, toPole);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
