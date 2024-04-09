#include<iostream>
#include<conio.h>
using namespace std;
class login{
	private:
		string username,password;
	public:
		void setname(string n){
			username=n;
		}
		string getname(){
			return username;
		}
		void setpw(string p){
			password=p;
		}
		string getpw(){
			return password;
		}
		bool check(){
			int found=0;
			string n,p;
			fstream file;
			file.open("account.txt",ios::in);//(file name ,mode)	
			file>>n>>p;
	
			   while (1){
                	if (username==n && password==p ){
			   		found++;
			   		break; 
				   }
			   else {
			   	break;
			   	 } 
	} 
	file.close();
	if(found==1){
		cout<<"******** Congratulations!! You have Logged in. ********";
		return true;
	} else {
		cout<<"opss!!\nInvalid Username & Password ";
		return false;
			  }
		}
		void change(){
			cout<<"Enter the New User Name: ";
			cin>>username;
			cout<<"Enter the New  Password: ";
			cin>>password;
			fstream file;
			file.open("account.txt",ios::out);
			file<<username<<" "<<password;
			file.close();
			
		}
}a;
