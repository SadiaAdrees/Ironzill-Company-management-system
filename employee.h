#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class employee 
{
 	private:
 	string name, designation,phone_no,address,city,joining_date;
 	int employee_no, salary;
 	public:
		void add();
		void show();
		void data();
		void display();
		void search(int n);
		void modify (int n);
		void del(int n);
		void admin();
};
       
		void employee::add(){
			cout<<endl<<endl<<"Employee No: ";
			cin>>employee_no;
			cout<<endl<<endl<<"Employee Name: ";
			cin>>name;
			cout<<endl<<endl<<"Employee Designation: ";
			cin>>designation;
			cout<<endl<<endl<<"Employee Phone no: ";
			cin>>phone_no;
			cout<<endl<<endl<<"Employee Joining date: ";
			cin>>joining_date;
			cout<<endl<<endl<<"Employee Salary: ";
			cin>>salary;
			cout<<endl<<endl<<"Employee City: ";
			cin>>city;
			cout<<endl<<endl<<"Employee Address: ";
			cin.ignore();
			getline(cin,address);
		} 
		void employee::show(){
		
	        cout<<endl<<"Employee No: "<<employee_no;
			cout<<endl<<"Employee Name: "<<name;
			cout<<endl<<"Employee Designation: "<<designation;
			cout<<endl<<"Employee Phone no: "<<phone_no;
			cout<<endl<<"Employee Joining date: "<<joining_date;
			cout<<endl<<"Employee Salary: "<<salary;
			cout<<endl<<"Employee City: "<<city;
			cout<<endl<<"Employee Address: "<<address;
		}
		void employee::data(){
		file.open("employee.txt",ios::out | ios ::app );
		add();
		file<<" "<<employee_no<<" "<<name<<" "<<designation<<" "<<phone_no<<" "<<joining_date<<" "<<salary<<" "<<city<<" "<<address<<"\n";
		file.close();
		cout<<endl<<endl<<"Data Added!!";
		getch();
			
			
		}
		void employee::display(){
			system("cls");
			cout<<"\n\n\n\t\t***** All Employee *****"<<endl<<endl;
			file.open("employee.txt",ios::in);
			if (!file){
				admin();
				}
				
		 	file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
		 	getline(file,address);
			while(!file.eof())
			{
				show();
			cout<<endl<<endl<<"============================================================";
			file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
		
			getline(file,address);
				}
				file.close();
				getch();		
		}
		void employee::search(int n){
			int found=0;
			file.open("employee.txt",ios::in);
			if(!file){
				admin();
			}
			file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
			getline(file,address);
			
			while(!file.eof()){
				if(employee_no==n){
					system("cls");
					show();
					found=1;
				}
			file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
			getline(file,address);
			}
			getch();
			file.close();
			if(found==0){
				cout<<endl<<endl<<"Record not Exist";
				getch();
			}
		}
		void employee::modify (int n){
			int found=0;
			system("cls");
			cout<<endl<<endl<<"\t**** Modify ****\t";
			file.open("employee.txt",ios::in);
			if(!file)
			admin();
			file1.open("employee1.txt",ios::out| ios::app);
			
			file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
			getline(file,address);
			
			while(!file.eof()){
			if(employee_no==n){
			
				show();
				cout<<endl<<endl<<"Please Enter the new Detail: ";
				add();
				file1<<" "<<employee_no<<" "<<name<<" "<<designation<<" "<<phone_no<<" "<<joining_date<<" "<<salary<<" "<<city<<" "<<address<<"\n";
				cout<<endl<<endl<<"\t Record Updated";
				found=1;
			}else 
		file1<<" "<<employee_no<<" "<<name<<" "<<designation<<" "<<phone_no<<" "<<joining_date<<" "<<salary<<" "<<city<<" "<<address<<"\n";
		file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
		getline(file,address);	
			}
			file.close();
			file1.close();
			remove("employee.txt");
			rename("employee1.txt","employee.txt");
			
			if(found==0)
			cout<<endl<<endl<<"Record not Exist";
			getch();
			
		}
		void employee::del(int n){
			int found =0;
			file.open("employee.txt",ios::in);
			if(!file)
			admin();
			file1.open("employee1.txt",ios::out);
			file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
			getline(file,address);
			while (!file.eof()){
				if(employee_no==n)
				{
				  cout<<endl<<endl<<"\tRecord Deleted";
				  found=1;	
				}else 
		file1<<" "<<employee_no<<" "<<name<<" "<<designation<<" "<<phone_no<<" "<<joining_date<<" "<<salary<<" "<<city<<" "<<address<<"\n";
			file>>employee_no>>name>>designation>>phone_no>>joining_date>>salary>>city;
			getline(file,address);
			}
			file.close();
			file1.close();
			remove("employee.txt");
			rename("employee1.txt","employee.txt");
			
			if(found==0)
			cout<<endl<<endl<<"Record not Exist";
			getch();
			
		}

		void employee::admin(){
			employee:
       	system("cls");
       	int choice;
       	cout<<endl<<endl<<endl<<"\t\t*** Menu ***";
       	cout<<endl<<endl<<"\t1.Add Employee";
       	cout<<endl<<"\t2.Display All Employee";
       	cout<<endl<<"\t3.Search Employee";
       	cout<<endl<<"\t4.Modify Employee";
       	cout<<endl<<"\t5.Delete Employee";
       	cout<<endl<<"\t6.Back to Menu";
       	cout<<endl<<endl<<"Enter the choice (1-6) ";
       	cin>>choice;
       	switch(choice){
       		case 1:{
       			system("cls");
       			data();	
       			goto employee;
			   }break;
			case 2:{
       			system("cls");
       			display();	
       			goto employee;
			   }break;
			case 3:{
				int num;
				system("cls");
       			cout<<endl<<endl<<"\tPlease Enter The Employee no :  ";
       			cin>>num;
       			search(num);
       			goto employee;
                }break;
			case 4:{
				int num;
       			system("cls");
       			cout<<endl<<endl<<"\tPlease Enter The Employee no : ";
				cin>>num;
				modify(num);
				goto employee;
			   }break;
			case 5:{
				int num;
				system("cls");
				cout<<endl<<endl<<"\t\t\tDelete Record";
				cout<<endl<<endl<<"Please Enter The Employee no : ";
				cin>>num;
				del(num);
				goto employee;
			   }break;
			case 6:{
       			
				
			   }break;
			   default: {
			   	cout<<"\a";admin();
			   }
		   }
	   }

