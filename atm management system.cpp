/*ATM MANAGEMENT SYSTEM PROJECTS*/

#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
int atm_pin_validation()
{
	char password[4]={'2','0','5','2'};
	char atm_pin[4],a;
	int i,result[4]={0,0,0,0},flag=1;
	cout<<"Please Enter Your ATM Pin:";
	for(i=0;i<4;i++)
	{
		a=getch();
		if(a>='0'&&a<='9')
		{
			atm_pin[i]=a;
			cout<<"*";
		}
	}
	cout<<endl;
	for(i=0;i<4;i++)
	{
		if(atm_pin[i]==password[i])
		{
			result[i]=1;
		}
	}
	for(i=0;i<4;i++)
	{
		if(result[i]!=1)
		{
			flag=0;
			break;
		}
	}
	return(flag);
}
void Cheack_Balance(double current_balance)
{
	cout<<"Your Current Balance Is:"<<current_balance;
}
double Cash_Depoist(double current_balance)
{
	double ammount_deposit;
	cout<<"Enter Ammount That You Want to Deposit"<<endl; 
	cin>>ammount_deposit;
	current_balance=current_balance+ammount_deposit;
	return(current_balance);
}
double Cash_widthdraw(double current_balance)
{
	double  ammount_widthdraw;
	cout<<"How Much Money You Want To Widtheaw"<<endl;
	cin>>ammount_widthdraw;
	if(ammount_widthdraw>current_balance)
	{
		cout<<"You Don't Have a Enough Money"<<endl;
	}
	else
	{
	   current_balance=current_balance-ammount_widthdraw;
    }
	return(current_balance);
}
int main()
{
	int option,pin;
	double current_balance=150000.0,ammount_deposit;
	system("COLOR 3B");
	pin=atm_pin_validation();
	if(pin==1)
	{
	   cout<<"Your ATM Pin Is Correct!"<<endl;
	   do
	   {
	        cout<<"\n\t\t<--------------MENU----------------->";
	        cout<<"\n\t\t!       1.Cheack Balance            !";        
	        cout<<"\n\t\t!       2.Cash Deposit              !"; 
	        cout<<"\n\t\t!       3.Cash Widthdraw            !";
	        cout<<"\n\t\t!       4.Exit                      !";
	        cout<<"\n\t\t<----------------------------------->";
	        cout<<"\n\nChoose Your Option"<<endl;
	        cin>>option;
	        switch(option)
	        {
	     	   case 1: Cheack_Balance(current_balance);
	     	           break;
	     	   case 2: current_balance=Cash_Depoist(current_balance);
			           cout<<"Your Current Balance Is:"<<current_balance;
	     	           break;
	     	   case 3: current_balance=Cash_widthdraw(current_balance);
	     	           cout<<"Your Current Balance Is:"<<current_balance;
	     	           break;
	     	   default:
	     		       if(option!=4)
	     		       {
	     		           cout<<"Your Option is Invalid! Please Enter a Valid Option"<<endl;
	     		       }
			           break; 
		    }
	    }while(option!=4);
	}
	else
	{
		cout<<"Your ATM Pin Is Incorrect! Please Enter Your Correct Pin"<<endl;
	}
	return 0;
}
