
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <windows.h> 
using namespace std;


void login();
void registration();
void forgot();

int main()
{
        int c;   // c for choice
        cout<<"\t\t\t__________________________________________________________________________\n\n\n";
        cout<<"\t\t\t                     Welcome to the Login page                               \n\n";
        cout<<"\t\t\t______________________        MENU        ________________________________\n\n";
        cout<<"                                                                                \n\n";
        cout<<"\t|  Press 1 to LOGIN                    |"<<endl;
        cout<<"\t|  Press 2 to REGISTER                 |"<<endl;
        cout<<"\t|  Press 3 to Exit                     |"<<endl;
        cout<<"\n\t\t\tPlease Enter your choice :";
        cin>>c;
        cout<<endl;
        switch(c)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registration();
                        break;
                case 3:
                	 system("cls");
                    cout<<"\t\t\Do you want to delete the exisiting record? (Y/N) :";
                    char inp;
                    cin>>inp;
                    if(inp=='Y')
                    {
                	const char* filename = "records.txt"; 
                	
				 if (remove(filename) != 0) {
                          perror("\nError deleting file"); // Print an error message if the file couldn't be deleted
                    }
				 else {
                          printf("\nFile deleted successfully\n\n");
                     }
                     
            }
                        cout<<"\t\t\tThankyou!\n\n";
                        
                        break;
                default:
                        system("cls");
                        cout<<"\t\t\tPlease select from the options given above , Try again..\n"<<endl;
                        main();
        }

}

void login()
{
        
        
        int count;
        string userId,password,id,pass;
        system("cls");
        cout<<"\t\t\tplease enter the username & password"<<endl;
        cout<<"\t\t\tUSERNAME :";
        cin>>userId;
        cout<<"\t\t\tPASSWORD :";
        cin>>password;

        ifstream input("records.txt");
        while(input>>id>>pass)                     //here reading is taking place
        {
                if(id==userId && pass==password)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();     //this is for closing the file
        if(count==1)
        {
                cout<<userId<<"\n Your Login is Successful\nThanks for logging in!\n";
                main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                Sleep(2000);
				forgot();
				//main();
        }
}

void registration()
{
//	 if (remove("records.txt") != 0)
//    {
//        perror("Error deleting file");
//    }
    string ruserId, rpassword, rid, rpass;
    bool usernameExists = false; // Flag to track username existence
    system("cls");
    cout << "\t\t\tEnter the username :";
    cin >> ruserId;

    ifstream checkExistingUsers("records.txt");
    string existingUser;
    while (checkExistingUsers >> existingUser >> rpass)
    {
        if (existingUser == ruserId)
        {
            usernameExists = true;
            break;
        }
    }
    checkExistingUsers.close();

    if (usernameExists)
    {
        cout << "\n\t\t\tUsername already exists. Please choose a different username.\n";
        registration(); // Prompt user to enter a new username
    }
    else
    {
        cout << "\n\t\t\tEnter the password :";
        cin >> rpassword;

        ofstream f1("records.txt", ios::app);
        f1 << ruserId << ' ' << rpassword << endl;
        system("cls");
        cout << "\n\t\t\tRegistration is Successful\n";
        main();
    }
}


void forgot()
{
	
        int option;
        system("cls");
        cout<<"\t\t\tYou forgot your password? No worries\n";
        cout<<"Press 1 to Search your id by username"<<endl;
        cout<<"Press 2 to go Back to the Main menu"<<endl;
        cout<<"\t\t\tEnter your choice :";
        cin>>option;
        switch(option)
        {
                case 1:
                {
                        int count=0;
                        string suserId,sId,spass;
                        cout<<"\n\t\t\tEnter the username which you remembered :";
                        cin>>suserId;

                        ifstream f2("records.txt");
                        while(f2>>sId>>spass)
                        {
                                if(sId==suserId)
                                {
                                        count=1;
                                }
                        }
                        f2.close();
                        if(count==1)
                        {
                                cout<<"\n\n\tYour account is found\n";
                                cout<<"\n\tYour password is "<<spass;
                                main();
                        }
                        else
                        {
                                cout<<"\n\tSorry, Account not found! \n";
                                main();
                        }
                        
                        break;
                }

                case 2:
                {
                        main();
                }
                default:
                        cout<<"\t\t\tWrong choice! Please try again"<<endl;
                        forgot();
        }
        
}

