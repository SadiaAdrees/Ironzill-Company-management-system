#include<iostream>
#include<fstream>
#include<conio.h>//output screen output
#include<stdio.h>//for renaming the text file 
#include<iomanip>//designing
using namespace std;
fstream file,file1;
class Order{
	private:
		int pno;
		string name ;
		float price,qty,dis;
	public:
		void create();
		void show();
		void write();
		void display();
		void search(int n);
		void modify (int n);
		void del(int n);
		void order();
		void menu();
		void admin();
};
       
		void Order::create(){
			cout<<endl<<endl<<"Please Enter the Product no: ";
			cin>>pno;
			cout<<endl<<endl<<"Please Enter the Product name: ";
			cin>>name;
			cout<<endl<<endl<<"Please Enter the Product price: ";
			cin>>price;
			cout<<endl<<endl<<"Please Enter the Product Discount(%) ";
			cin>>dis;
		} 
		void Order::show(){
			cout<<endl<<"The product no. of the Product : "<<pno;
			cout<<endl<<"The name of the product : "<<name;
			cout<<endl<<"The price of the product : "<<price;
		    cout<<endl<<"Discount of the product : "<<dis<<"%";
		}
		void Order::write(){
		file.open("order.txt",ios::out | ios::app );
		create();
		file<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
		file.close();
		cout<<endl<<endl<<"The Product Has Been Created. ";
		getch();//conio.h//pause the screen until user press any key of the keyboard
			
			
		}
		void Order::display(){
			system("cls");
			cout<<"\n\n\n\t\t***** All Record *****"<<endl<<endl;
			file.open("order.txt",ios::in);
			if (!file){
				admin();
				}
			file>>pno>>name>>price>>dis;
			while(!file.eof())
			{
				show();
				cout<<endl<<endl<<"============================================================";
				file>>pno>>name>>price>>dis;
				}
				file.close();
				getch();		
		}
		void Order::search(int n){
			int found=0;
			file.open("order.txt",ios::in);
			if(!file){
				admin();
			}
			file>>pno>>name>>price>>dis;
			while(!file.eof()){
				if(pno==n){
					system("cls");
					show();
					found=1;
				}
			file>>pno>>name>>price>>dis;
			}
			file.close();
			if(found==0){
				cout<<endl<<endl<<"Record not Exist";
				getch();
			}
			getch();
		}
		void Order::modify (int n){
			int found=0;
			system("cls");
			cout<<endl<<endl<<"\t**** Modify ****\t";
			file.open("order.txt",ios::in);
			if(!file)
			admin();
			file1.open("order1.txt",ios::out| ios::app);
			file>>pno>>name>>price>>dis;
			while(!file.eof()){
			if(pno==n){
			
				show();
				cout<<endl<<endl<<"Please Enter the new Detail of the Product ";
				create();
				file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
				cout<<endl<<endl<<"\t Record Updated";
				found=1;
			}else 
			file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
			file>>pno>>name>>price>>dis;	
			}
			file.close();
			file1.close();
			remove("order.txt");
			rename("order1.txt","order.txt");
			
			if(found==0)
			cout<<endl<<endl<<"Record not Exist";
			getch();
			
		}
		void Order::del(int n){
			int found =0;
			file.open("order.txt",ios::in);
			if(!file)
			admin();
			file1.open("order1.txt",ios::out);
			file>>pno>>name>>price>>dis;
			while (!file.eof()){
				if(pno==n)
				{
				  cout<<endl<<endl<<"\tRecord Deleted";
				  found=1;	
				}else 
			file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
			file>>pno>>name>>price>>dis;
			}
			file.close();
			file1.close();
			remove("order.txt");
			rename("order1.txt","order.txt");
			
			if(found==0)
			cout<<endl<<endl<<"Record not Exist";
			getch();
			
		}
		void Order::order(){
			int order_arr[25], quan[25],c=0;
			float amt=0,damt=0,total=0;
			char ch;
			file.open("order.txt",ios::in);
			if (file){//exist hoti hai tw 
				file.close();
				
				menu();
				cout<<endl<<"========================================================"<<endl<<"\t\tPLACE YOUR ORDER"<<endl<<"========================================================"<<endl;
				do{
					cout<<endl<<"Enter the Product no. of the product: ";
					cin>>order_arr[c];
					cout<<endl<<"Quantity in number: ";
					cin>>quan[c];
					c++;
					cout<<"\nDo You Want To Order Another Product?Y/n: ";
					cin>>ch;	
				}while(ch=='Y'||ch=='y');
				cout<<endl<<"Thank You For Your Order"<<endl<<"Press Enter For The Bill.";
				getch();
				system("cls");
				cout<<"\n\n***********************The Invoice*************************"<<endl;
				cout<<"\nPr no.\tPr Name\tQuantity  Price  Amount  Amount after Discount\n";
				for(int x=0;x<=c;x++){
					file.open("order.txt",ios::in);
					file>>pno>>name>>price>>dis;
					while(!file.eof()){  //jab tk file end nhi hoti loop ko chalao.....
						if(pno==order_arr[x]){
							amt=price*quan[x];
							damt=amt-(amt/100*dis);
							cout<<endl<<order_arr[x]<<"\t"<<name<<"\t"<<quan[x]<<"\t"<<price<<"\t"<<amt<<"\t"<<damt;
							total+=damt;//total=total+damt
						}
						file>>pno>>name>>price>>dis;
					
					}
					file.close();
				}
				cout<<endl<<endl<<"\t\t\t\t\tTotal Bill = "<<total;
				getch();
			}
			
		}
		void Order::menu(){
		 system ("cls");
		 file.open("order.txt",ios::in);
		 cout<<endl<<endl<<"\t\tProduct Menu"<<endl<<endl;
		 cout<<"========================================================"<<endl;
		 cout<<"P.no\t\tName\t\tPrice\n";
		 cout<<"========================================================"<<endl;
		 file>>pno>>name>>price>>dis;
		 while(!file.eof())
		{
			cout<<pno<<"\t\t"<<name<<"\t\t"<<price<<"\n";
			file>>pno>>name>>price>>dis;	
		 }
		 file.close();
		}
		void Order::admin(){
			order:
       	system("cls");
       	int choice;
       	cout<<endl<<endl<<endl<<"\t\t*** Product Menu ***";
       	cout<<endl<<endl<<"\t1.Create Product";
       	cout<<endl<<"\t2.Display All Products";
       	cout<<endl<<"\t3.Search Product";
       	cout<<endl<<"\t4.Modify Product";
       	cout<<endl<<"\t5.Delete Product";
       	cout<<endl<<"\t6.View Product Menu";
       	cout<<endl<<"\t7.Back to Menu";
       	cout<<endl<<endl<<"Enter the choice (1-7) ";
       	cin>>choice;
       	switch(choice){
       		case 1:{
       			system("cls");
       			write();
				   goto order;	
			   }break;
			case 2:{
       			system("cls");
       			display();
				 goto order;	
			   }break;
			case 3:{
				int num;
				system("cls");
       			cout<<endl<<endl<<"\tPlease Enter The Product Number :  ";
       			cin>>num;
       			search(num);
       			 goto order;
                }break;
			case 4:{
				int num;
       			system("cls");
       			cout<<endl<<endl<<"\tPlease Enter The Product Code : ";
				cin>>num;
				modify(num);
				 goto order;
			   }break;
			case 5:{
				int num;
				system("cls");
				cout<<endl<<endl<<"\t\t\tDelete Record";
				cout<<endl<<endl<<"Please Enter The Product no : ";
				cin>>num;
				del(num);
				 goto order;
			   }break;
			case 6:{
				menu();
				getch();
				goto order;
			   }break;
			case 7:{
       			
				
			   }break;
			   default: {
			   	cout<<"\a";admin();
			   }
		   }
	   }
