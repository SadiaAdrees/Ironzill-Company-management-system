#include<iostream>
#include<fstream>
#include<stdlib.h>//memory control (exist program etc)
#include<unistd.h>//for the sleep function 
#include<string.h>
#include "login.h"
#include"card.h"
#include"Order.h"
#include"employee.h"
using namespace std;
void welcome_screen(void);
void animation(void);
void menu();


int main() {
	animation();
    welcome_screen();
    menu();
	return 0;
}

void welcome_screen(void){
    system("cls");
    FILE *welcome;
    welcome = fopen("welcome.txt", "r");
    while(!feof(welcome))
        printf("%c", fgetc(welcome));
}
void animation(void)
{
    int j = 60000;
    welcome_screen();
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t";
    cout<<"Loading...";
    cout<<"\n\n\n\n";
    for(int k=0; k<59; k++)
    {
        usleep(j);
       cout<<"||";
    }
}

void menu(){
	again:
	int choose;
	cout<<"\n\t\t\t1:Login\n\t\t\t2:Company Card\n\t\t\t3:Exit";
	cout<<"\n\t\t\tEnter Your Choice: ";
	cin>>choose;
	if (choose==1){
		string un,pw;
		cout<<"Enter the Username: ";
		cin>>un;
		cout<<"Enter the password: ";
		cin>>pw;
		//login a;
		a.setname(un);
		a.setpw(pw);
		if (a.check()== true){
			int i;
			subagain:
			system("cls");
			cout<<endl<<"***Welcome Owner***"<<endl<<"1:Enter Order"<<endl<<"2:Product"<<endl<<"3.Employee"<<endl<<"4:Change company Card"<<endl<<"5:Change password"<<endl<<"6:Main menu"<<endl<<"7:Exit"<<endl<<"Enter your Choice:";
		    cin>>i;
		    Order o;
		    
		switch(i){
		case 1:{

		//	cout<<"Enter Order: ";
			o.order();	
		}	break;
		case 2:{
			o.admin();
		  }
		   break;
		case 3:{
			employee e;
			e.admin();
		  }
		   break;
		      
		case 4:{
			string p,l;
				cout<<"You can Only Change The Location & The Phone Number of the Company."<<endl;
				cout<<"Enter The New Phone Number: ";
				cin>>p;
				cout<<"Enter the New Location: ";
				//cin>>l;
				cin.ignore();
				getline (cin,l);
				//company_card c;
				c.setpn(p);
				c.setlo(l);
				c.change();
				 }break;
		case 5:{
		 cout<<"***Password change*** "<<endl;	
		 a.change();
			
		}break;
		case 6:{
			cout<<"You are in main menu";
			system("cls");
			welcome_screen();
			goto again;	
			}break;
		case 7:{
		cout<<"You have Exit the Program";
		   exit(0);	}	
			break;
		}
		 getch();
		 goto subagain;
		
		
		}else  {
			int c;
		 cout<<"\n1: Go To the main Menu\n2:Exit\nEnter Choice: ";
		 cin>>c;
		  switch(c){
		  	case 1:{
		  		system("cls");
		  		welcome_screen();
		  		goto again;
			  }break;
			case 2:{
		cout<<"You have Exit the Program";	
			  exit(0);		
			}break;
		  }
		}
		
		
	}else if (choose == 2){
		system("cls");
		cout<<"\n\n\t\t\t******Company Card******\n";
		cout<<"Company Name: 'IronZill LTD' "<<endl;	
        FILE *card;
      // card = fopen("companycard.txt", "r");
       // while(!feof(card))
          //  printf("%c", fgetc(card));
          fstream file;
          string p,a;
          file.open("companycard.txt",ios::in);
          file>>p;
          getline(file,a);
          cout<<"Phone no: "<<p<<endl<<"Address : "<<a<<endl;
          file.close();
        card = fopen("companycard2.txt", "r");
        while(!feof(card))
            printf("%c", fgetc(card));
        
        			int c;
		 cout<<"\n1: Go To the main Menu\n2:Exit\nEnter Choice: ";
		 cin>>c;
		  switch(c){
		  	case 1:{
		  		system("cls");
		  		welcome_screen();
		  		goto again;
			  }break;
			case 2:{
		cout<<"You have Exit the Program";	
			  exit(0);		
			}break;
		  }
        
		
	}else if(choose == 3){
		cout<<"You have Exit the Program";
		exit(0);
	}
	else {
		cout<<"\n\t\t\tNot valid";
		system("cls");
		welcome_screen();
		goto again;
	}
}
