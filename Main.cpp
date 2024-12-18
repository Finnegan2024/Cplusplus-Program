#include <iostream> //include appropriate libraries
using namespace std;

#include "BANK.H" //include header file

int main() { //main function to control functionality
	Bank myBank; //declare appropriate variables with bank object created
	int choice;
	double initialAmount;
	double depositAmount;
	double interest;
	int years;


	myBank.displayData(); //display initial variable values for generating reports
	while (true) {
		cout << "Please click the number of the field you would like to change" << endl;
		cin >> choice;
		if (cin.fail() == true) { //ensures correct input for choice which will determine next clock function
			cout << "Invalid option" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		switch (choice) {
			case 1:
				//add initial amount
				cout << "Enter initial amount." << endl;
				cin >> initialAmount;
				if (cin.fail() || initialAmount < 0) {
					cout << "Invalid option, try again." << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				myBank.setOpeningAmount(initialAmount);
				myBank.displayData(myBank.getOpeningAmount(), myBank.getDepositAmount(), myBank.getInterestRate(), myBank.getYears());
				continue;
			case 2:
				//add monthly deposit
				cout << "Enter amount of monthly deposit." << endl;
				cin >> depositAmount;
				if (cin.fail() || depositAmount < 0) {
					cout << "Invalid option, try again." << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				myBank.setDepositedAmount(depositAmount);
				myBank.displayData(myBank.getOpeningAmount(), myBank.getDepositAmount(), myBank.getInterestRate(), myBank.getYears());
				continue;
			case 3:
				//add annual interest
				cout << "Enter interest amount." << endl;
				cin >> interest;
				if (cin.fail() || interest < 0) {
					cout << "Invalid option, try again." << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				myBank.setInterestRate(interest);
				myBank.displayData(myBank.getOpeningAmount(), myBank.getDepositAmount(), myBank.getInterestRate(), myBank.getYears());
				continue;
			case 4:
				//add number of years
				cout << "Enter number of years." << endl;
				cin >> years;
				if (cin.fail() || years < 0) {
					cout << "Invalid option, try again." << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				myBank.setYears(years);
				myBank.displayData(myBank.getOpeningAmount(), myBank.getDepositAmount(), myBank.getInterestRate(), myBank.getYears());
				continue;
			default:
				//catch any unwanted inputs
				cout << "Invalid option. Try again." << endl;
				continue;
			case 5:
				//print reports
				myBank.calculateBalanceWithoutMonthlyDeposit(myBank.getOpeningAmount(), myBank.getInterestRate(), myBank.getYears());
				myBank.calculateBalanceWithMonthlyDeposit(myBank.getOpeningAmount(), myBank.getDepositAmount(), myBank.getInterestRate(), myBank.getYears());
				continue;
			case 6:
				//end program
				break;
		}
		break;
	}
	return 0;
}