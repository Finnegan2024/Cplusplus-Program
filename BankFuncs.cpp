#include <iostream> //include appropriate libraries
#include <iomanip>
using namespace std;

#include "BANK.H" //include header file

void Bank::setYears (int numYears) {
	m_years = numYears;
}

int Bank::getYears() const{
	return m_years;
}

void Bank::setOpeningAmount(double openingAmount) {
	m_openingAmount = openingAmount;
}

double Bank::getOpeningAmount() const{
	return m_openingAmount;
}

void Bank::setDepositedAmount(double depositAmount) {
	m_depositedAmount = depositAmount;
}

double Bank::getDepositAmount() const{
	return m_depositedAmount;
}

void Bank::setInterestRate(double interestRate) {
	m_interestRate = interestRate;
}

double Bank::getInterestRate() const{
	return m_interestRate;
}

void printDetails(int year, double yearEndBalance, double interestEarned) { //prints year number, year end balance, and interest earned in appropriate format
	cout << year << "		$" << fixed << setprecision(2) << yearEndBalance << "			$" << interestEarned << endl;
}

void printDetailsHeaderWithoutMonthlyDeposit() { //prints header for report containing no monthly deposits
	string dashes(65, '-');
	string spaces(5, ' ');

	cout << endl;
	cout << endl;
	cout << spaces << "Balance And Interest Without Additional Monthly Deposits" << spaces << endl;
	cout << dashes << endl;
	cout << dashes << endl;
	cout << "Year		" << "Year End Balance	" << "Year End Earned Interest" << endl;
	cout << dashes << endl;
}

void printDetailsHeaderWithMonthlyDeposit() { //prints header for report containing monthly contributions
	string dashes(65, '-');
	string spaces(6, ' ');

	cout << endl;
	cout << endl;
	cout << spaces << "Balance And Interest With Additional Monthly Deposits" << spaces << endl;
	cout << dashes << endl;
	cout << dashes << endl;
	cout << "Year		" << "Year End Balance	" << "Year End Earned Interest" << endl;
	cout << dashes << endl;
}

void printDetailsFooter() { //prints footer for reports
	string dashes(65, '-');

	cout << dashes << endl;
	cout << dashes << endl;
	cout << endl;
	cout << endl;
}


void Bank::displayData(double initialInvestmentAmount, double monthlyDeposit, double annualInterest, int numYears) { //displays data for variables used in generating reports
	string row1(44, '*');
	string row2(16, '*');

	cout << endl;
	cout << endl;
	cout << row1 << endl;
	cout << row2 << "Current Data" << row2 << endl;
	cout << "1. Initial Investment Amount:   $" << fixed << setprecision(2) << initialInvestmentAmount << endl;
	cout << "2. Monthly Deposit:     $" << monthlyDeposit << endl;
	cout << "3. Annual Interest:     %" << fixed << setprecision(0) << annualInterest << endl;
	cout << "4. Number of years:     " << numYears << endl;
	cout << "5. Print Reports" << endl;
	cout << "6. Exit" << endl;
	cout << endl;
	cout << endl;

}


void Bank::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) { //generates report with no monthly contributions
	double interestPerMonth = (interestRate / 100) / 12;
	int temp = 0;
	double thisYearInterest;
	double initialInvestmentCopy = initialInvestment;
	double priorYearBalance;

	printDetailsHeaderWithoutMonthlyDeposit();
	if (interestRate == 0 || numberOfYears == 0) {
		while (temp < numberOfYears) {
			printDetails(temp + 1, initialInvestment, 0);
			temp += 1;
		}
		printDetailsFooter();
		cout << endl;
		cout << endl;
	}
	else {
		while (temp < numberOfYears) {
			if (temp == 0) {
				priorYearBalance = initialInvestment;
			}
			else {
				priorYearBalance = initialInvestmentCopy;
			}
			for (int i = 0; i < 12; ++i) {
				initialInvestmentCopy = (initialInvestmentCopy * interestPerMonth) + initialInvestmentCopy;
			}
			thisYearInterest = initialInvestmentCopy - priorYearBalance;
			printDetails(temp + 1, initialInvestmentCopy, thisYearInterest);
			temp += 1;
		}
		printDetailsFooter();
	}
}

void Bank::calculateBalanceWithMonthlyDeposit(double initialInvestment,double monthlyDeposit, double interestRate, int numberOfYears) { //generates report with monthly contributions
	double interestPerMonth = (interestRate / 100) / 12;
	int temp = 0;
	double thisMonthInterest;
	double initialInvestmentCopy = initialInvestment;
	double priorYearBalance;
	double totalInterest = 0;

	printDetailsHeaderWithMonthlyDeposit();
	if (numberOfYears == 0) {
		//printDetails(temp + 1, initialInvestmentCopy, thisYearInterest);
		cout << "No data available for 0 years." << endl;
		cout << endl;
		cout << endl;
	}
	else if (interestRate == 0) {
		while (temp < numberOfYears) {
			initialInvestmentCopy = (monthlyDeposit * 12) + initialInvestmentCopy;
			printDetails(temp + 1, initialInvestmentCopy, 0);
			temp += 1;
		}
		printDetailsFooter();
		cout << endl;
		cout << endl;
	}
	else {
		while (temp < numberOfYears) {
			double thisYearInterest = 0;

			if (temp == 0) {
				priorYearBalance = initialInvestment;
			}
			else {
				priorYearBalance = initialInvestmentCopy;
			}
			for (int i = 0; i < 12; ++i) {
				thisMonthInterest = initialInvestmentCopy * interestPerMonth;
				thisYearInterest += thisMonthInterest;
				initialInvestmentCopy = (initialInvestmentCopy * interestPerMonth) + initialInvestmentCopy + monthlyDeposit;
			}
			printDetails(temp + 1, initialInvestmentCopy, thisYearInterest);
			temp += 1;
		}
		printDetailsFooter();
	}
}

