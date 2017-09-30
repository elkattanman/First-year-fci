/*
*Developed By ::Mustafa Khaled
*This program about read and deal withs files;
*Date:: 2016/12/11
*/
//#include <sstream>
//#include <iostream>
//#include<fstream>
//#include<string>
#include<bits/stdc++.h>
using namespace std;

/*-----------DECLARATION GLOBAL variable--------------------------*/
char path[]="input.txt";
fstream myfile;
fstream myfile_temp;
string line;
char Search[25];
int p;

/*-----------DECLARATION variable--------------------------*/

/*-----------START METHODES--------------------------*/
void split(string splt){
string token;
stringstream ss(splt);
while(getline(ss,token,'*')){
cout<<setw(10)<<token;
}
cout<<endl;
}

void read(){
	cout<<"------------------------strat File------------------------------------\n\n";
	int counter=0;
	fstream myfile(path,ios::in|ios::out|ios::app);
	cout<<"\n"<<setiosflags(ios::left);
	cout<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Gendar"<<setw(10)<<"Address"<<setw(10)<<"Phone"<<setw(10)<<"E-mail"<<endl;
	if(myfile.is_open()){
		while(getline(myfile,line)){
		split(line);
		counter++;
		}
	myfile.close();
	cout<<"\n*---------------------------End of File------------------------------*\n";
	cout<<"*There is "<<counter<<"Recordes*\n";
}
else{
cout<<"unable to open the file";
}
	}

void insert(){
	cout<<"__________________________________________________________________________\n";
	fstream myfile(path,ios::out|ios::app);
	char data[25];
	cout<<"Enter Name >> ";
	cin.ignore();           //----insert Name---------
	cin.getline(data,25);
	myfile<<data;
	cin.ignore();
	cout<<"Enter Age >> ";            //----insert Age-----------
	cin.getline(data,25);
	myfile<<"*"<<data;
	cin.ignore();
	cout<<"Enter Gendar >> ";            //----insert sex-----------
	cin.getline(data,25);
	myfile<<"*"<<data;
	cin.ignore();
	cout<<"Enter Address >> ";       //----insert Address---------
	cin.getline(data,25);
	myfile<<"*"<<data;
	cin.ignore();
	cout<<"Enter Mobile Number >> ";//----insert Mobile Number----
	cin.getline(data,25);
	myfile<<"*"<<data;
	cin.ignore();
	cout<<"Enter E-MAIL >> ";//----insert Email ----
	cin.getline(data,25);
	myfile<<"*"<<data<<endl;
	cin.ignore();
	myfile.close();
	cout<<"__________________________________________________________________________\n";
}
void search(){
	fstream myfile(path,ios::in);
	int counter=0;
if(myfile.is_open()){
	cout<<"Enter The Name to Search >>";
	cin.getline(Search,25);
	cin.ignore();
	cout<<"__________________________________________________________________________\n";
	while(getline(myfile,line)){
		p=line.find(Search);
		if(p>=0){
			split(line);
			counter++;
		}
	}

	if(counter<=0){
	cout<<"Search NOT FOUND";
	}
	else{
	cout<<"-----------there is "<<counter<<" Search FOUND-----------------\n";
	}
	cout<<"__________________________________________________________________________\n";
	counter=0;
	myfile.close();
}
else
cout<<"unable to open the file";
}

void dlt(){
	fstream myfile(path,ios::in|ios::app);
	fstream myfile_temp("input_temp.txt",ios::in|ios::app);
	int counter=0;
if(myfile.is_open()){
	cout<<"Enter The Name to delete >> ";
	cin.getline(Search,25);
	cin.ignore();
	cout<<"-----------------------------------------------------------\n";
	while(getline(myfile,line)){
		p=line.find(Search);
		if(p<0)
			myfile_temp<<line<<endl;
		else{
			cout<<"";
			counter++;
		}
	}
	myfile.close();
	myfile_temp.close();
	remove(path);
	rename("input_temp.txt",path);
	cout<<"there is "<<counter<<" DELETED\n";
	cout<<"------------------------------------------------------------\n";
}
else
cout<<"unable to open the file";

}

void update(){
	fstream myfile(path,ios::in|ios::app);
	fstream myfile_temp("input_temp.txt",ios::in|ios::app);
	int counter=0;
if(myfile.is_open()){
	cout<<"Enter The Name to update >> ";
	cin.getline(Search,25);
	cin.ignore();
	cout<<"------------------------------------------------------------\n";
	while(getline(myfile,line)){
		p=line.find(Search);
		if(p<0)
			myfile_temp<<line<<endl;
		else{
            insert();
		}
	}
	myfile.close();
	myfile_temp.close();
	remove(path);
	rename("input_temp.txt",path);
	cout<<"there is "<<counter<<" updated\n";
	cout<<"------------------------------------------------------------\n";
}
else
cout<<"unable to open the file";

}

void update_1(){
    fstream myfile(path,ios::in|ios::app);
	fstream myfile_temp("input_temp.txt",ios::in|ios::app);
	int counter=0;
if(myfile.is_open()){
	cout<<"Enter The Name to update >> ";
	cin.getline(Search,25);
	cin.ignore();
	cout<<"------------------------------------------------------------\n";
	while(getline(myfile,line)){
		p=line.find(Search);
		if(p<0)
			myfile_temp<<line<<endl;
		else{
			string token;
            stringstream ss(line);
            cout<<"\nTo Update Name Enter 1\nTo Update Age Enter 2\nTo Update Gender Enter 3\nTo Update location Enter 4\nTo Update phone Number Enter 5\nTo Update E-Mail Enter 6\nYoyr Choiose:: ";
            int num;
            cin>>num;
            for(int i=1;getline(ss,token,'*');i++){
                if(num==i){
                    cout<<"Enter New data ::";
                    cin>>token;
                    myfile_temp<<token<<"*";
                }else
                    myfile_temp<<token<<"*";
            }
            myfile_temp<<endl;
            cout<<endl;
		}
	}
	myfile.close();
	myfile_temp.close();
	remove(path);
	rename("input_temp.txt",path);
	cout<<"there is "<<counter<<" updated\n";
	cout<<"------------------------------------------------------------\n";
	}
}
/*-----------END   METHODES--------------------------*/


int main(){
	cout<<"\aDeveloped by::Mustafa Khaled El-Kattan\n";
   	int c;
   	while(true){
	cout<<"1-insert\n2-update\n3-search4-delete\n5-display\nyour choise:: ";
   	cin>>c;
   	switch(c){
   		case 1:
   			insert();
			break;
		case 2:
			update_1();
			break;
		case 3:
			search();
			break;
		case 4:
			dlt();
			break;
		case 5:
			read();
			break;
		default:
			return 0;
			break;
	   }
	   	cin.ignore();
		cin.get();
	   system("cls");
	   }
return 0;
}
