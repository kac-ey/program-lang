#include "Financial.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void Financial::checkInput(string t_initial, string t_monthly, string t_interest, string t_years) {
	unsigned int i;
	int j = 0;
	int m_decimalCount = 0;
	Financial bankInfo;
	this->m_inputAmount = t_initial;
	this->m_inputMonthly = t_monthly;
	this->m_inputInterest = t_interest;
	this->m_inputYears = t_years;

	for (i = 0; i < m_inputAmount.size(); ++i) {
		if (!(isdigit(m_inputAmount.at(i)))) { // Checks if there is non-number input
			if (m_inputAmount.at(i) != '.') { // Checks non-number to allow for decimal point
				throw runtime_error(" You have entered an invalid character. "); // Throws if non-number, non-decimal entered
			}
			else if (m_inputAmount.at(i) == '.') { // Checks number of decimal points
				m_decimalCount += 1;
				if (m_decimalCount == 1) { // Stores location of first decimal
					j = i;
				}
				if (m_decimalCount > 1) { // Checks for more than one decimal
					throw runtime_error(" You have entered an invalid character. "); // Throws if more than one decimal entered
				}
			}
		}
		if (m_inputAmount.size() > (j + 4)) { // Checks number of integers after decimal
			throw length_error(" You have entered an invalid deposit. "); // Throws if more than 2 numbers after decimal
		}
	}
    double m_initialAmount = stod(m_inputAmount); // Transforms string to double for calculations
	j, m_decimalCount = 0; // Resets variables for next check
	
	for (i = 0; i < m_inputAmount.size(); ++i) {
		if (!(isdigit(m_inputAmount.at(i)))) { // Checks if there is non-number input
			if (m_inputAmount.at(i) != '.') { // Checks non-number to allow for decimal point
				throw runtime_error(" You have entered an invalid character. "); // Throws if non-number, non-decimal entered
			}
			else if (m_inputAmount.at(i) == '.') { // Checks number of decimal points
				m_decimalCount += 1;
				if (m_decimalCount == 1) { // Stores location of first decimal
					j = i;
				}
				if (m_decimalCount > 1) { // Checks for more than one decimal
					throw runtime_error(" You have entered an invalid character. "); // Throws if more than one decimal entered
				}
			}
		}
		if (m_inputAmount.size() > (j + 4)) { // Checks number of integers after decimal
			throw length_error(" You have entered an invalid deposit. "); // Throws if more than 2 numbers after decimal
		}
	}
	double m_monthlyDeposit = stod(m_inputMonthly); // Transforms string to double for calculations
	j, m_decimalCount = 0; // Resets variables for next check

	for (i = 0; i < m_inputAmount.size(); ++i) {
		if (!(isdigit(m_inputAmount.at(i)))) { // Checks if there is non-number input
			if (m_inputAmount.at(i) != '.') { // Checks non-number to allow for decimal point
				throw runtime_error(" You have entered an invalid character. "); // Throws if non-number, non-decimal entered
			}
			else if (m_inputAmount.at(i) == '.') { // Checks number of decimal points
				m_decimalCount += 1;
				if (m_decimalCount == 1) { // Stores location of first decimal
					j = i;
				}
				if (m_decimalCount > 1) { // Checks for more than one decimal
					throw runtime_error(" You have entered an invalid character. "); // Throws if more than one decimal entered
				}
			}
		}
		if (m_inputAmount.size() > (j + 4)) { // Checks number of integers after decimal
			throw length_error(" You have entered an invalid deposit. "); // Throws if more than 2 numbers after decimal
		}
	}
	double m_annualInterest = stod(m_inputInterest); // Transforms string to double for calculations

	for (i = 0; i < m_inputYears.size(); ++i) {
		if (!(isdigit(m_inputYears.at(i)))) { // Checks if there is a non-number input
			throw invalid_argument(" You have entered an invalid character. "); // Throws exceptions if non-number entered
		}
	}
	int m_years = std::stoi(m_inputYears); // Transforms string to integer for calculation

	bankInfo.withoutMonthlyDeposits(m_initialAmount, m_annualInterest, m_years); // Passes arguments for calculations
	bankInfo.withMonthlyDeposits(m_initialAmount, m_monthlyDeposit, m_annualInterest, m_years); // Passes arguments for calculations
}

void Financial:: displayLayout() { // Formats basic layout for displaying results
	cout << setfill('=') << setw(60) << "" << endl;
	cout << setfill(' ');
	cout << setw(6) << right << "Year";
	cout << setw(24) << right << "Year End Balance";
	cout << setw(30) << right << "Year End Earned Interest" << endl;
	cout << setfill('~') << setw(60) << "" << endl;
	cout << setfill(' ');
}

void Financial::withMonthlyDeposits(double t_initial, double t_monthly, double t_interest, int t_years) {
	int i;
	unsigned int j;
	this->m_initialAmount = t_initial;
	this->m_monthlyDeposit = t_monthly;
	this->m_annualInterest = t_interest;
	this->m_years = t_years;
	
	cout << "   Balance and Interest With Additional Monthly Deposits" << endl;
	Financial::displayLayout(); // Calls function to print header for results

	for (i = 1; i < m_years + 1; ++i) { // Calculates for each year
		m_earnedInterest = 0; // Resets to 0 for start of each year

		for (j = 1; j < 13; ++j) { // Calculates for each month in year
			m_monthlyInterest = ((m_annualInterest / 100) / 12) * (m_initialAmount + m_monthlyDeposit); // Finds monthly interest
			m_initialAmount += (m_monthlyInterest + m_monthlyDeposit); // Balance at start of each month including interest and deposit
			m_earnedInterest += m_monthlyInterest; // Tracks interest earned each month to get yearly interest earned
		}

		// Outputs values in table format
		cout << fixed << setprecision(2);
		cout << setw(5) << left << " ";
		cout << setw(12) << left << i;
		cout << setw(1) << left << "$";
		cout << setw(15) << left << m_initialAmount;
		cout << setw(12) << right << "$" << m_earnedInterest << endl;
	}
	cout << endl;
}

void Financial::withoutMonthlyDeposits(double t_initial, double t_interest, int t_years) {
	int i;
	this->m_initialAmount = t_initial;
	this->m_annualInterest = t_interest;
	this->m_years = t_years;
	
	cout << endl;
	cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
	Financial::displayLayout(); // Calls function to print header for results

	for (i = 1; i < m_years + 1; ++i) { // Calculates for each year
		m_earnedInterest = ((m_annualInterest / 100) * m_initialAmount); // Finds yearly interest
		m_endBalance = m_earnedInterest + m_initialAmount; // Finds year end account total

		// Outputs values in table format
		cout << fixed << setprecision(2);
		cout << setw(5) << left << " ";
		cout << setw(12) << left << i;
		cout << setw(1) << left << "$";
		cout << setw(15) << left << m_endBalance;
		cout << setw(12) << right << "$" << m_earnedInterest << endl;
		
		m_initialAmount = m_endBalance; // Balance at start of next year is end balance
	}

	cout << endl;
	cout << endl;
}