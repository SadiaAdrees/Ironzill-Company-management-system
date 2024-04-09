#include<iostream>
#include<string.h>
using namespace std;
class company_card_var
{
	protected:
	string  phone_no, location;	
};

class company_card:public company_card_var
{

	public:
		company_card(){
		phone_no ="Null";
		location ="Null";	
		}
	 void setpn(string n){
	 	phone_no=n;
	 }
	 string getpn(){
	 	return phone_no;
	 }
	 void setlo(string l){
	 	location=l;
	 }
	 string getlo(){
	 	return location;
	 }
	 void change(){
	 	remove("companycard.txt");
	 	fstream f;
	 	f.open("companycard.txt",ios::out);//out>>write::in>>read
	 	f<<phone_no<<" "<<location;
	 	f.close();
	 	
	 }
		
}c; 
