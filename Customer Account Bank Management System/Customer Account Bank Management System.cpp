// Customer Account Bank Management System
//I will use Linkedlist Data structure to implement Accountslist
#include <iostream>
using namespace std;

struct CustomerAccountData{
    int customerID;
    string name;
    string dateOfBirth;
    string city;
    string PhoneNumber;
    double currentMoney;
    

};

struct CustomerAccount {
    //stored data
    CustomerAccountData customerData;
    //a referance that refer to next node 
    CustomerAccount* next;
};

class customerAccountsLinkedlist
{
private:
    CustomerAccount* head, * tail;
public:
    customerAccountsLinkedlist()
    {
        head = NULL;
        tail = NULL;
    }


    void addNewCustomerAccount(CustomerAccountData d)
    {
        CustomerAccount* temp = new CustomerAccount;
        //store data in temp
        temp->customerData.name = d.name;
        temp->customerData.dateOfBirth = d.dateOfBirth;
        temp->customerData.city = d.city;
        temp->customerData.currentMoney = d.currentMoney;
        temp->customerData.PhoneNumber = d.PhoneNumber;
        temp->customerData.customerID=d.customerID;
 
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }


    void updateCustomerAccount(CustomerAccountData d)
    {
        CustomerAccount* customerAccount = head;
        while (customerAccount != NULL) {
            if (customerAccount->customerData.customerID == d.customerID) {
                customerAccount->customerData.name = d.name;
                customerAccount->customerData.dateOfBirth = d.dateOfBirth;
                customerAccount->customerData.city = d.city;
                customerAccount->customerData.currentMoney = d.currentMoney;
                customerAccount->customerData.PhoneNumber = d.PhoneNumber;
                break;
            }
            customerAccount = customerAccount->next;
        }

        if (customerAccount == NULL && customerAccount->customerData.customerID != d.customerID) {
            cout << "The customer ID doesn't exist \n\n"; // customerAccount==null
        }

    }


    CustomerAccount* getHead() {
        return this->head;
    }


    void displayCustomersAccountsList(CustomerAccount* head)
    {
        CustomerAccount* customerAccount = head;
        while (customerAccount != NULL) {
            cout << "\n\n\n";
            cout << "Customer ID: " << customerAccount->customerData.customerID << endl;
            cout <<"Customer name: " <<customerAccount->customerData.name << endl;
            cout << "Customer date of birth: " << customerAccount->customerData.dateOfBirth << endl;
            cout << "Customer city: " << customerAccount->customerData.city << endl;
            cout<<"Customer phone: "<< customerAccount->customerData.PhoneNumber << endl;
            cout<<"Customer current money: "<< customerAccount->customerData.currentMoney << endl;
            cout<<"\n\n\n";
            customerAccount= customerAccount->next;
        }
    }

    void checkDetailsOfExistingAccount(CustomerAccount* head,int customerID)
    {
        CustomerAccount* customerAccount = head;
        while (customerAccount != NULL ) {
            if (customerAccount->customerData.customerID == customerID) {
                cout << "\n\n\n";
                cout << "Customer ID: " << customerAccount->customerData.customerID << endl;
                cout << "Customer name: " << customerAccount->customerData.name << endl;
                cout << "Customer date of birth: " << customerAccount->customerData.dateOfBirth << endl;
                cout << "Customer city: " << customerAccount->customerData.city << endl;
                cout << "Customer phone: " << customerAccount->customerData.PhoneNumber << endl;
                cout << "Customer current money: " << customerAccount->customerData.currentMoney << endl;
                cout << "\n\n\n";
                break;

            }
            
            customerAccount = customerAccount->next;
        }
        if (customerAccount == NULL && customerAccount->customerData.customerID != customerID) {
            cout << "The customer ID doesn't exist \n\n"; // customerAccount==null
        }
    }


    //5)delete a customer Account
    void deleteCustomerAccountNode(CustomerAccount* nodeBefore)
    {
        CustomerAccount* temp;
        temp = nodeBefore->next;
        nodeBefore->next = temp->next;
        delete temp;
    }

    void deleteHeadNode() {
        CustomerAccount* temp;
        temp = head;
        head = head->next;
        delete temp;
    }

    void deleteCustomerAccountWithID(int customerID)
    {
        CustomerAccount* nodeBefore = head;

        if (nodeBefore->customerData.customerID == customerID)
        {
            deleteHeadNode();
        }
        else
        {
            while (nodeBefore->next->customerData.customerID != customerID)
            {
                nodeBefore = nodeBefore->next;
                if (nodeBefore->next == NULL)
                {
                    break;
                }
            }

            if (nodeBefore->next == NULL)
            {
                cout << "Node not found" << endl;
            }
            else
            {
                deleteCustomerAccountNode(nodeBefore);
            }
        }
    }
    //3)transactions
    void deposit(CustomerAccount* customerAccount) {
        double depositMoney;
        cout << "Please Enter the anount of money you want deposit at your account: \n";
        cin >> depositMoney;
        customerAccount->customerData.currentMoney += depositMoney;
        


    }
    void withdraw(CustomerAccount* customerAccount) {
        double withdrawMoney;
        cout << "Please Enter the anount of money you want withdraw from your account: \n";
        cin >> withdrawMoney;
        if (customerAccount->customerData.currentMoney>= withdrawMoney) {
            customerAccount->customerData.currentMoney -= withdrawMoney;
        }
        else {
            cout << "Sorry, you don't have enough money. \n";
        }

    }
    void transact(int customerID , int transactionType) {
        CustomerAccount* customerAccount = head;
        while (customerAccount != NULL) {
            if (customerAccount->customerData.customerID == customerID) {
                if (transactionType == 1) {
                    deposit(customerAccount);
                }
                else if (transactionType == 2) {
                    withdraw(customerAccount);
                }
                break;
            }
            customerAccount = customerAccount->next;
        }
  
      if (customerAccount == NULL && customerAccount->customerData.customerID != customerID) {
            cout << "The customer ID doesn't exist \n\n"; // customerAccount==null
       }
    }


};

int main()
{
    customerAccountsLinkedlist  customersList;
    int choice;
    CustomerAccountData customerData;
    while (true) {
        cout << "*********************************** Welcome in Customer Account Bank Management System. ********************************\n\n\n\n\n";
        cout << "1) Create new account. \n2) Update information of existing account. \n3) for transactions. \n4) check the details of existing account.\n5) Remove existing account. \n6) View customer's list. \n7)Exit \n\n\n\n\n";
        cout << "Enter your choice: \n";
        cin >> choice;

        if (choice == 1) {
            system("Cls");
            cout << "Enter customer ID: ";
            cin >> customerData.customerID;
            cout << "Enter customer name: ";
            cin >> customerData.name;
            cout << "Enter customer date of birth: ";
            cin >> customerData.dateOfBirth;
            cout << "Enter customer city: ";
            cin >> customerData.city;
            cout << "Enter customer phone number: ";
            cin >> customerData.PhoneNumber;
            cout << "Enter customer current money: ";
            cin >> customerData.currentMoney;
            customersList.addNewCustomerAccount(customerData);
            system("Cls");

        }else if (choice == 2) {
            system("Cls");
            cout << "Please Enter the ID of the customer account you want to modify: \n";
            cin >> customerData.customerID;
            cout << "Enter new customer name: ";
            cin >> customerData.name;
            cout << "Enter new customer date of birth: ";
            cin >> customerData.dateOfBirth;
            cout << "Enter new customer city: ";
            cin >> customerData.city;
            cout << "Enter new customer phone number: ";
            cin >> customerData.PhoneNumber;
            cout << "Enter new customer current money: ";
            cin >> customerData.currentMoney;
            customersList.updateCustomerAccount(customerData);

        }else if (choice == 3) {
            system("Cls");
            int customerID,transactionType;
            cout << "Please Enter Your Customer ID: \n";
            cin >> customerID;
            cout << "Please Choose Your Transaction type:\n1)deposit.\n2)withdraw\n\n";
            cin >> transactionType;
            customersList.transact(customerID, transactionType);

        }else if (choice == 4) {
            system("Cls");
            int customerID;
            cout << "Please Enter the ID of the customer account you want to check: \n";
            cin >> customerID;
            CustomerAccount* head = customersList.getHead();
            customersList.checkDetailsOfExistingAccount(head, customerID);

        }else if (choice == 5) {
            system("Cls");
            int customerID;
            cout << "Please Enter the ID of the customer account you want to delete: \n";
            cin >> customerID;
            customersList.deleteCustomerAccountWithID( customerID);
            

        }
        else if (choice == 6) {
            system("Cls");
            CustomerAccount* head = customersList.getHead();
            customersList.displayCustomersAccountsList(head);

        }else if (choice == 7) {
            system("CLS");
            cout << "EXIT \n";
            break;

        }else  {
            cout << "Your choice is invalid, please enter a valid choice \n\n\n\n";

        }


    }
  
   
    system("pause>0");
}

