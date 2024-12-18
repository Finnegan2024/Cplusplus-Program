#pragma once //add header guard
#ifndef PROJECT2_PROJECT2_BANK_H
#define PROJECT2_PROJECT2_BANK_H

class Bank { //define bank class
	public: //add public functions to manipulate bank object
		void setYears(int t_numYears);
		int getYears() const;
		void setOpeningAmount(double t_openingAmount);
		double getOpeningAmount() const;
		void setDepositedAmount(double t_depositAmount);
		double getDepositAmount() const;
		void setInterestRate(double t_interestRate);
		double getInterestRate() const; //compute interest rate
		void displayData(double t_initialInvestmentAmount = 0.0, double t_monthlyDeposit = 0.0, double t_annualInterest = 0.0, int t_numYears = 0);
		void calculateBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears);
		void calculateBalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);
	private: //initialize and declare private variables
		int m_month = 0;
		int m_years = 0;
		double m_openingAmount = 0;
		double m_depositedAmount = 0;
		double m_total = 0;
		double m_interestRate = 0;
		double m_closingBalance = 0;
};

#endif