#include "Financial.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayMenu() { // Formats main menu
	cout << endl;
	cout << setfill('~') << setw(14) << left << "";
	cout << " Data Input ";
	cout << setw(14) << right << "" << endl;
	cout << setfill('=') << setw(40) << "" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
}

int main() {
	Financial bankInfo;
	string investAmount, monthlyDeposit, annualInterest, numYears;
	string userChar = " ";

	while (userChar != "q") { // Allows user to run program over again until entering 'q'
		try {
			displayMenu(); // Calls function that displays main menu
			cin >> investAmount >> monthlyDeposit >> annualInterest >> numYears; // Inputs user info to string variables
			system("CLS"); // Clears screen to enhance readability

			// Verifies input validity and calls functions to calculate and display user request
			bankInfo.checkInput(investAmount, monthlyDeposit, annualInterest, numYears);

			cout << "Press 'q' then 'enter' to quit." << endl;
			cout << "Press any other key then 'enter' to try again with different numbers." << endl;
			cin >> userChar; // Allows user to restart or quit
			system("CLS"); // Clears screen to enhance readability
		}
		catch (runtime_error& excpt) { // Displays if runtime_error exception thrown
			cout << endl;
			cout << setfill(':') << setw(14) << right << "";
			cout << setw(52) << left << excpt.what() << endl;
			cout << "Each entry can only consist of numbers and a single decimal point." << endl;
			cout << setw(14) << right << "";
			cout << setw(52) << left << " *Years does not accept a decimal point.* " << endl;
			cout << endl;
		}
		catch (length_error& excpt) { // Displays if length_error exception thrown
			cout << endl;
			cout << setfill(':') << setw(9) << right << "";
			cout << setw(47) << left << excpt.what() << endl;
			cout << "Please enter a valid dollar amount with only two numbers" << endl;
			cout << setw(15) << right << "";
			cout << setw(41) << left << " after the decimal point. " << endl;
			cout << endl;
		}
		catch (invalid_argument& excpt) { // Displays if invalid_argument exception thrown
			cout << endl;
			cout << setfill(':') << setw(8) << right << "";
			cout << setw(49) << left << excpt.what() << endl;
			cout << setw(6) << right << "";
			cout << setw(51) << left << " Only whole numbers are accepted for years. " << endl;
			cout << endl;
		}
	}

	return 0;
}