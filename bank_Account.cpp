//Name :Syed Ali Ahmed                          department: FBAS/BSSE/F-21
//Roll No :4308                                 university:International Islamic University Islamabad
                
//                                  Question #14
// a. Define the class bankAccount to store a bank customer’s account
// number and balance.Suppose that account number is of type int, and
// balance is of type double.Your class should, at least, provide the
// following operations : set the account number, retrieve the account
// number, retrieve the balance, depositand withdraw money, and print
// account information.Add appropriate constructors.

// b. Every bank offers a checking account.Derive the class
//  checkingAccount from the class bankAccount(designed in
//	part(a)).This class inherits members to store the account number
//	and the balance from the base class.A customer with a checking
//	account typically receives interest, maintains a minimum balance,
//	and pays service charges if the balance falls below the minimum
//	balance.Add member variables to store this additional information.
//	In addition to the operations inherited from the base class, this class
//	should provide the following operations : set interest rate, retrieve
//	interest rate, set minimum balance, retrieve minimum balance, set
//	service charges, retrieve service charges, post interest, verify if the
//	balance is less than the minimum balance, write a check, withdraw
//	(override the method of the base class), and print account information.Add appropriate constructors.
// 
// c. Every bank offers a savings account.Derive the class
//	savingsAccount from the class bankAccount(designed in part
//	(a)).This class inherits members to store the account numberand
//	the balance from the base class.A customer with a savings account
//	typically receives interest, makes deposits, and withdraws money.In
//	addition to the operations inherited from the base class, this class
//	should provide the following operations : set interest rate, retrieve
//	interest rate, post interest, withdraw(override the method of the
//		base class), and print account information.Add appropriate constructors.
//	d.Write a program to test your classes designed in parts(b) and (c).


#include <iostream>
using namespace std;
class bankAccount {
	int accNo;
	double balance;
public:
	bankAccount(int no=0,double money=0.0):accNo(no),balance(money){}    //default argument constructor
	void setAccNo();
	int getAccNo();
	double getAccBal();
	void deposit();
	void withDraw();
	void dipslAccInfo();
};
void bankAccount::setAccNo() {
	cout << "enter the account Number" << endl;
	cin >> accNo;
}
int bankAccount::getAccNo() {
	return accNo;
}
double bankAccount::getAccBal() {
	return balance;
}
void bankAccount::deposit() {
	cout << "enter the money you want to deposite in your account" << endl;
	int money;
	cin >> money;
	balance += money;
}

void bankAccount::withDraw() {
	cout << "enter the money you want to deposite in your account" << endl;
	int money;
	cin >> money;
	balance -= money;
}

void bankAccount::dipslAccInfo() {
	cout << "Account Number : " << accNo << endl;
	cout << "Balance :  " << balance << endl;
}

class checkingAccount :public bankAccount {
	float interest;
	double minimumBalance;
	double serviceCharges;
public:
	checkingAccount(float Interest=0.0,double miniBalance=0.0,double servCharges=0.0):
		bankAccount(), interest(Interest),minimumBalance(miniBalance),serviceCharges(servCharges){}
	
	void setAcc();
	void setAccountInfo();
	float getInterest();
	double getMinBalance();
	double getServiceCharges();
	bool verify();
	void withDraw();
	void AccountInfo();
};
void checkingAccount::setAcc() {
	setAccNo(); 
	deposit();
}
void checkingAccount::setAccountInfo() {
	cout << "set the Interst of a customer in percentage" << endl;
	cin >> interest;
	cout << "set the minimum balance for customer's checking Account " << endl;
	cin >> minimumBalance;
	cout << "set the services charges if the balance is less than minimum amount in percentage" << endl;
	cin >> serviceCharges;
}
float checkingAccount::getInterest() {
	int bal = getAccBal();
	float inter = (interest / 100) * bal;
	return inter;
}
double checkingAccount::getMinBalance() {
	return minimumBalance;
}
double checkingAccount::getServiceCharges() {
	int bal = getAccBal();
	double servChar = (serviceCharges / 100) * minimumBalance;
	return servChar;
}
bool checkingAccount::verify() {
	int min = getAccBal();
	if ((min < minimumBalance) && (minimumBalance > 0.0))
		return true;
	
	else 
		return false;
	
}
void checkingAccount::withDraw() {
	bankAccount::withDraw();
}

void checkingAccount::AccountInfo() {
	bankAccount::dipslAccInfo();
	cout << "interst that customer receives :- " << getInterest() << endl;
	if (verify()) {
		cout << "service charges that dues on customer are : " << getServiceCharges() << endl;
		cout << "Warning ! your minimum Balance Should be greater than: " << getMinBalance() << endl;
	}
	else {
		cout << "No Service Charges dues on Customer" << endl;
		cout << "your balance is greater than: " << getMinBalance();
		cout << endl;
	}
}

class savingAccount:public bankAccount {
	int interest;
public:
	savingAccount(int inter=0):bankAccount(),interest(inter){}
	void setInterest();
	float getInterest();
	void withDraw();
	void SavAccountInfo();
};
void savingAccount::SavAccountInfo() {
	bankAccount::dipslAccInfo();
	cout << "interst that customer receives :- " << getInterest() << endl;
}
void savingAccount::setInterest() {
	cout << "set the Interst of a customer in percentage" << endl;
	cin >> interest;
}
float savingAccount::getInterest() {
	int bal = getAccBal();
	float inter = (interest / 100) * bal;
	return inter;
}
void savingAccount::withDraw() {
	withDraw();
}

void menu1() {
	cout << "                            1.Enter the new Account" << endl;
	cout << "                            2.display the Account Info" << endl;
	cout << "                            3.Edit the checking Account" << endl;
	cout << "                            4.Edit the saving Account" << endl;
	cout << "                                     5.Exit" << endl;
}

void menu2() {
	cout << "                            1. checking Account" << endl;
	cout << "                             2. saving Account" << endl;
	cout << "                          3.go back to main menu" << endl;
}
void menu2Process(char option,checkingAccount *C, savingAccount *S, int &i,int &j) {
	switch (option) {
	case '1':
		C[i].setAcc();
		cout << endl;
		C[i].setAccountInfo();
		i++;
		break;
	case '2':
		S[j].setAccNo();
		S[j].deposit();
		j++;
		break;
	case '3':
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}


void menu2Process2(char option,checkingAccount* C, savingAccount* S, int i,int j) {
	int accountNo;
	switch (option) {
	case '1':
		cout << "enter the account No you want to find the information of" << endl;
		cin >> accountNo;
		for (int k = 0; k < i; k++) {
			if (accountNo == C[k].getAccNo()) {
				C[k].AccountInfo();
				break;
			}
		}
		break;
	case '2':
		cout << "enter the account No you want to find the information of" << endl;
		cin >> accountNo;
		for (int k = 0; k < j; k++) {
			if (accountNo == S[k].getAccNo()) {
				S[k].dipslAccInfo();
				break;
			}
		}
		break;
	case '3':
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}

void menu3() {
	cout << "                           1.withdraw cash" << endl;
	cout << "                           2.deposite cash" << endl;
	cout << "                         3.set Account Detail" << endl;
	cout << "                        4.go back to main menu" << endl;
}
void menu3process3(char option, int accountNo, checkingAccount* C, int i, int k) {
	switch (option) {
	case '1':
		C[k].withDraw();
		break;
	case '2':
		C[k].deposit();
		break;
	case '3':
		C[k].setAccountInfo();
		break;
	case '4':
		break;
	default:
		cout << "chose the correct option" << endl;
	}
	cout << endl;
}
void menu3process4(char option, int accountNo, savingAccount* S, int j, int k) {
	switch (option) {
	case '1':
		S[k].withDraw();
		break;
	case '2':
		S[k].deposit();
		break;
	case '3':
		S[k].setInterest();
		break;
	case '4':
		break;
	default:
		cout << "chose the correct option" << endl;
	}
	cout << endl;
}
int main()
{
	checkingAccount C[10];
	savingAccount S[10];
	int accountNo;
	int i=0;
	int j = 0;
	char option;
	char option2;
	char option3;
	bool found = false;
	do {
		menu1();
		cout << "chose your option" << endl;
		cin >> option;
		switch (option) {
		case '1':
			menu2();
			cout << "chose your option" << endl;
			cin >> option2;
			menu2Process(option2, C, S, i,j);
			cout << endl;
			break;
		case '2':
					menu2();
					cout << "chose your option" << endl;
					cin >> option3;
					menu2Process2(option3,C, S, i, j);
					cout << endl;
			break;
		case '3':
			cout << "enter the account No you want to edit" << endl;
			cin >> accountNo;
			for (int k = 0; k < i; k++) {
				if (accountNo == C[k].getAccNo()) {
					found = true;
					menu3();
					cout << "chose your option" << endl;
					cin >> option3;
					menu3process3(option3, accountNo, C, i, k);
					cout << endl;
					break;
				}
			}
			if (found == false) {
				cout << "Account Not present" << endl;
			}
			found = false;
			break;
		case '4':
			cout << "enter the account No you want to edit" << endl;
			cin >> accountNo;
			for (int k = 0; k < j; k++) {
				if (accountNo == S[k].getAccNo()) {
					found = true;
					menu3();
					cout << "chose your option" << endl;
					cin >> option3;
					menu3process4(option3, accountNo, S, j, k);
					cout << endl;
					break;
				}
			}
			if (found == false) {
				cout << "Account Not present" << endl;
			}
			found = false;
			break;
		case '5':
			exit(0);
		default:
			cout << "chose the correct option" << endl;
		}

	} while (true);

}

