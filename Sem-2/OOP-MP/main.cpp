/*********************************************************
 *
 * OOP MICRO PROJECT BY:
 *
 *  1. Vinit Akhar (5)
 *  1. Prathamesh Mutkure (23)
 *  1. Samyak Sukhdeve (26)
 *
 * PROGRAM: Banking Program
 *
 * TOPICS COVERED:
 *
 *  1. Basics of C++
 *  2. Classes and Object
 *  3. File Handling
 *
 *********************************************************/

#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <fstream>
#include <iomanip>

#define FILE_ERROR "\nCould not open the File, Error!!"

using namespace std;

void write_account();           // Creating new Account
void withdraw_deposit_money(int);           // Creating new Account
void edit_account();            // Modify existing Account
void delete_account();          // Delete existing Account
void display_account();     // Display info of all users
void display_options();         // Functions to display Choices
void display_all_accounts();

class Account
{
private:
    int acc_num;
    char name[50];
    double balance;
    char PAN_num[10];
    long long int aadhar_num;
public:
    void create_account();          // Function for creating new Account
    void deposit();     	        // Add money to account
    void withdraw();                // Withdraw money from account
    void display_acc();             // Function to display data of user
    void modify_acc();              // Function to Modify existing user
    void display_basic_info();

    int getAccNum() { return acc_num; }

};

void Account::create_account()
{
    cout << "*****CREATING NEW ACCOUNT*****" << endl;

    cout << "\nEnter Your Name: ";
    cin >> name;

    cout << "Enter Account Number: ";
    cin >> acc_num;

    cout << "Enter Initial Account Balance: ";
    cin >> balance;

    cout << "Enter Aadhar Number: ";
    cin >> aadhar_num;

    cout << "Enter your PAN Number: ";
    cin >> PAN_num;
}



void Account::deposit()
{
    double amount;

    cout << "Enter amount to Deposit: ";
    cin >> amount;

    balance += amount;
}

void Account::withdraw()
{
    double amount;

    cout << "Enter amount to Withdraw: ";
    cin >> amount;

    if (amount > balance)
        cout << "\nYou cannot withdraw more money than Balance!" << endl;
    else
        balance -= amount;
}

void Account::display_acc()
{
    cout << "\nHolder's Name : " << name << endl;
    cout << "Account Number : " << acc_num << endl;
    cout << "Account Balance : " << balance << endl;
    cout << "Aadhar Number : " << balance << endl;
    cout << "PAN Number : " << balance << endl;
}

void Account::modify_acc()
{
    int choice;

    cout << "\nEnter data to be edited: " << endl;
    cout << "\n\t1. Name" << endl;
    cout << "\n\t2. Balance" << endl;
    cout << "\n\t3. Aadhar Number" << endl;
    cout << "\n\t4. PAN Number" << endl;

    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "\nEnter new name: ";
            cin >> name;
            break;
        case 2:
            cout << "\nEnter Balance: ";
            cin >> balance;
        case 3:
            cout << "\nEnter new Aadhar Number: ";
            cin >> aadhar_num;
        case 4:
            cout << "\nEnter new PAN Number: ";
            cin >> PAN_num;
        default:
            cout << "Enter valid choice!" << endl;
            modify_acc();
    }
}

void Account::display_basic_info()
{
    cout << acc_num << setw(10) << name << setw(10) << balance << endl;
}

int main()
{

    cout << "\n\n\t\t\t  **ANJUMAN POLYTECHNIC**" << endl;
    cout << "\t\tMicro-Project for OOP - CO3I" << endl << endl;

    bool exit = false;
    int choice;

    do {

        display_options();
        cout << "\nEnter your Choice: ";
        cin >> choice;

        switch (choice)
        {

            case 1:
                write_account();
                break;
            case 2:
                withdraw_deposit_money(1);
                break;
            case 3:
                withdraw_deposit_money(2);
                break;
            case 4:
                edit_account();
                break;
            case 5:
                delete_account();
                break;
            case 6:
                display_account();
                break;
            case 7:
                display_all_accounts();
                break;
            case 8:
                exit = true;
                break;
            default:
                cout << "\n*****Enter a valid Choice!*****" << endl;
        }

    } while (!exit);

    return 0;
}

void write_account()
{
    Account ac;
    ac.create_account();

    ofstream writeFile;
    writeFile.open("account.dat", ios::binary|ios::app);

    writeFile.write((char*) &ac, sizeof(Account));
    writeFile.close();
}

void withdraw_deposit_money(int choice)
{
    Account ac;
    bool found = false;

    int accNo;
    cout << "\nEnter Account Number: ";
    cin >> accNo;

    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if (!File)
    {
        cout << FILE_ERROR << endl;
        return;
    }

    while (File.read((char*) &ac, sizeof(Account)) && !found)
    {
        if (ac.getAccNum() == accNo)
        {
            if (choice == 1)
                ac.withdraw();
            if (choice == 2)
                ac.deposit();

            found = true;
            cout << "\nRecord Updates!!" << endl;

            int pos = (-1) * (int)sizeof(Account);
            File.seekp(pos, ios::cur);
            File.write((char*) &ac, sizeof(Account));
        }
    }

    File.close();

    if(!found)
        cout << "\nRecord not Found!" << endl;
}

void edit_account()
{
    Account ac;
    bool found = false;

    int accNo;
    cout << "\nEnter Account Number to be modified: ";
    cin >> accNo;

    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if (!File)
    {
        cout << FILE_ERROR << endl;
        return;
    }

    while (File.read((char*) &ac, sizeof(Account)) && !found)
    {
        if (accNo == ac.getAccNum())
        {
            ac.display_acc();
            ac.modify_acc();

            int pos = (-1)* (int) sizeof(Account);
            File.seekp(pos, ios::cur);
            File.write((char*) &ac, sizeof(Account));

            cout << "\nRecord Updated!!" << endl;
            found = true;
        }
    }

    File.close();

    if (!found)
        cout << "\nRecord not found!!" << endl;
}

void delete_account()
{
    Account ac;
    ifstream accFile;
    ofstream tempFile;

    int accNo;
    cout << "\nEnter Account Number to be modified: ";
    cin >> accNo;

    accFile.open((char*) "account.dat", ios::binary);

    if (!accFile)
    {
        cout << "\nFile could not be found!!" << endl;
        return;
    }

    tempFile.open("temp.dat", ios::binary);

    accFile.seekg(0, ios::beg);
    while (accFile.read((char*) &ac, sizeof(Account)))
        if (ac.getAccNum() != accNo)
            tempFile.write((char*) &ac, sizeof(Account));


    accFile.close();
    tempFile.close();

    remove("account.dat");
    rename("temp.dat", "account.dat");

    cout << "\nAccount Deleted!!" << endl;
}

void display_account()
{
    Account ac;
    bool acc_found = false;

    int accNo;
    cout << "\nEnter Account Number: ";
    cin >> accNo;

    ifstream File;
    File.open("account.dat", ios::binary);

    if (!File)
    {
        cout << "Failed to Open File, Data could not be read!!" << endl;
        return;
    }

    while (File.read((char*) &ac, sizeof(Account)))
        if (ac.getAccNum() == accNo)
        {
            ac.display_acc();
            acc_found = true;
        }

    File.close();

    if (!acc_found)
        cout << "\nAccount number " << accNo << " doesn't exist!" << endl;

}

void display_all_accounts()
{

    Account ac;
    ifstream File;

    File.open("account.dat", ios::binary);
    if (!File)
    {
        cout << "\nFile not found!!" << endl;
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n";
    cout << "====================================================\n";
    cout << "A/C No          NAME          BALANCE\n";
    cout << "====================================================\n\n";

    while (File.read((char*) &ac, sizeof(Account)))
    {
        ac.display_basic_info();
    }

    File.close();
}

void display_options()
{
    cout << "\n\t\t**MAIN MENU**\t\t\n" << endl;
    cout << "1. CREATE NEW ACCOUNT" <<endl;
    cout << "2. WITHDRAW MONEY FROM ACCOUNT" <<endl;
    cout << "3. DEPOSIT MONEY TO ACCOUNT" <<endl;
    cout << "4. MODIFY EXISTING ACCOUNT" <<endl;
    cout << "5. DELETE EXISTING ACCOUNT" <<endl;
    cout << "6. DISPLAY ACCOUNT INFO" <<endl;
    cout << "7. DISPLAY ACCOUNT LIST" <<endl;
    cout << "8. EXIT THE PROGRAM" <<endl;
}