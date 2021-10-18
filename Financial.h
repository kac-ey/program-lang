#pragma once
#ifndef PROJECTTWO_FINANCIAL_H
#define PROJECTTWO_FINANCIAL_H
#include <string>
using namespace std;

class Financial
{
public:
	void displayLayout();
	void checkInput(string t_initial, string t_monthly, string t_interest, string t_years);
	void withMonthlyDeposits(double t_initial, double t_monthly, double t_interest, int t_years);
	void withoutMonthlyDeposits(double t_initial, double t_interest, int t_years);

private:
	double m_initialAmount = -1.0, m_monthlyDeposit = -1.0, m_earnedInterest = -1.0;
	double m_endBalance = -1.0, m_annualInterest = -1.0, m_monthlyInterest = -1.0;
	int m_years = -1, m_decimalCount = 0;
	string m_inputAmount, m_inputMonthly, m_inputInterest, m_inputYears;
};
#endif PROJECTTWO_FINANCIAL_H