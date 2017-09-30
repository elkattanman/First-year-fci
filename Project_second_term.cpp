#include<bits/stdc++.h>
using namespace std;

class ATM_USER{
	private:
		int id;
		int pass;
		char name[15];
		double balance;
	public:
		ATM_USER(){}
    	int get_id(){return id;}
    	string get_name(){return name;}
		double get_balance(){return balance;}
    	int get_pass(){return pass;}
    	void dept(double v){
        	if(v<=balance)
            	balance-=v;
        	else{
            	cout<<"can't Dept more than your balance \n";
            	balance-=5;}
		}
	    void credit(double v){
			balance+=v;
			cout<<"Current Balance ::"<<balance<<endl;
		}
		bool find_id(int n){
			ATM_USER ac;
			bool flag = false;
			ifstream inFile;
			inFile.open("Mydata.dat",ios::binary);
			if (!inFile){
				cout << "File could not be open !! Press any Key...";
				exit(0);
			}
			while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(ATM_USER))){
				if (ac.get_id() == n){
					flag = true;
				}
			}
				inFile.close();
				if (flag == true){
					cout << "\n\nAccount ID  exist\n";
				}
			return flag;
		}
		void Update(){
			cout<<"Update User id --> "<<id<<endl;
			cout<<"Enter New Name :: ";
			cin>>name;
			cout<<"Enter New pass :: ";
			cin>>pass;
			cout<<"Enter Balance :: ";
			cin>>balance;
		}

	friend istream &operator>>(istream& ,ATM_USER&);
    friend ostream &operator<<(ostream&,ATM_USER&);
};



istream &operator>>(istream & in,ATM_USER &u){
        cout<<"\t\tInserting User ::\n";
        cout<<"Enter ID:: ";
        in>>u.id;
        while(u.find_id(u.id)){
        	cout<<"Enter ID Again :(\n";
        	in>>u.id;
		}
        cout<<"Enter NAME :: ";
        in>>u.name;
        cout<<"Enter PASSWORD ::";
        in>>u.pass;
        cout<<"Enter USER balance :: ";
        in>>u.balance;
        	if(u.balance<0){
        		cout<<"Balance can't be negative ::";
				u.balance=0;
			}

        return in;
}

    ostream &operator<<(ostream &out,ATM_USER &u){
    	cout<<setiosflags(ios::left);
        out<<"|"<<setw(10)<<u.id<<"|"<<setw(10)<<u.pass<<"|"<<setw(10)<<u.name<<"|"<<setw(10)<<u.balance<<"|"<<endl;
        return out;
}
class ATM:public ATM_USER{
	private:
		ifstream inFile;
		ofstream outFile;
		fstream File;
		ATM_USER ac;
	public:
		void print_head(){
			cout<<"\n"<<setiosflags(ios::left);
	    	cout<<"+----------+----------+----------+----------+\n";
	        cout<<"|"<<setw(10)<<"Id"<<"|"<<setw(10)<<"Pass"<<"|"<<setw(10)<<"Name"<<"|"<<setw(10)<<"Balance"<<"|"<<endl;
	        cout<<"+----------+----------+----------+----------+\n";
		}
		void insert(){
			outFile.open("Mydata.dat", ios::binary | ios::app);
			cin>>ac;
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(ATM_USER));
			outFile.close();
		}
		void display(){
			inFile.open("Mydata.dat",ios::binary);
			if (!inFile){
					cout << "File could not be open !! Press any Key...";
					return;
			}
			print_head();
			while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(ATM_USER))){
				cout<<ac;
			}
			inFile.close();
			cout<<"+----------+----------+----------+----------+\n";
		}

		void display_sp(int n){
			bool flag = false;
			inFile.open("Mydata.dat",ios::binary);
			if (!inFile){
				cerr << "File could not be open !! Press any Key...";
				return;
			}

			cout << "\nBALANCE DETAILS\n";

			while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(ATM_USER))){
				if (ac.get_id() == n){
					print_head();
					cout<<ac;
					flag = true;
					cout<<"+----------+----------+----------+----------+\n";
				}
				inFile.close();
				if (flag == false)
					cout << "\n\nAccount number does not exist";

			}
		}

		void update(int n){
			bool found = false;
			File.open("Mydata.dat",ios::in|ios::out|ios::binary);
			if (!File){
				cout << "File could not be open !! Press any Key...";
				return;
			}
			while (!File.eof() && found == false){
				File.read(reinterpret_cast<char *> (&ac), sizeof(ATM_USER));
				if (ac.get_id() == n){
					cout<<"Data --->\n";
					print_head();
					cout<<ac;
					cout<<"+----------+----------+----------+----------+\n";
					cout << "\n\nEnter The New Details of account" << endl;
					ac.Update();
					int pos = (-1)*static_cast<int>(sizeof(ATM_USER));
					File.seekp(pos, ios::cur);
					File.write(reinterpret_cast<char *> (&ac), sizeof(ATM_USER));
					cout << "\n\n\t Record Updated";
					found = true;
				}
			}
			File.close();
			if (found == false)
			cout << "\n\n Record Not Found ";
		}
		void Delete(int n){
			inFile.open("Mydata.dat", ios::binary);
			if (!inFile){
				cout << "File could not be open !! Press any Key...";
				return;
			}
			outFile.open("Temp.dat", ios::binary);
			inFile.seekg(0, ios::beg);
			while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(ATM_USER))){
				if (ac.get_id() != n){
					outFile.write(reinterpret_cast<char *> (&ac), sizeof(ATM_USER));
				}
			}
			inFile.close();
			outFile.close();
			remove("Mydata.dat");
			rename("Temp.dat", "Mydata.dat");
			cout << "\n\n\tRecord Deleted ..\n";
		}
		void Credit_dept(int n, int option){
			int amt;
			bool found = false;
			File.open("Mydata.dat", ios::binary | ios::in | ios::out);
			if (!File){
				cout << "File could not be open !! Press any Key...";
				return;
			}
			while (!File.eof() && found == false){
				File.read(reinterpret_cast<char *> (&ac), sizeof(ATM_USER));
				if (ac.get_id() == n){
					print_head();
					cout<<ac;
					cout<<"+----------+----------+----------+----------+\n";
					if (option == 1){
						cout << "\n\n\tTO DEPOSITE AMOUNT ";
						cout << "\n\nEnter The amount to be deposited ::";
						cin >> amt;
						ac.credit(amt);
					}
					if (option == 2){
						cout << "\n\n\tTO WITHDRAW AMOUNT ";
						cout << "\n\nEnter The amount to be withdraw  ::";
						cin >> amt;
						ac.dept(amt);
					}
					int pos = (-1)*static_cast<int>(sizeof(ac));
					File.seekp(pos, ios::cur);
					File.write(reinterpret_cast<char *> (&ac), sizeof(ATM_USER));
					cout << "\n\n\t Record Updated";
					found = true;
				}
			}
			File.close();
			if (found == false)
				cout << "\n\n Record Not Found ";
		}

		bool check_pass(int n,int p){
			ATM_USER ac;
			bool flag = false;
			ifstream inFile;
			inFile.open("Mydata.dat",ios::binary);
			if (!inFile){
				cerr << "File could not be open !! Press any Key...";
				exit(0);
			}
			while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(ATM_USER))){
				if (ac.get_id() == n){
					if(ac.get_pass()==p){
						flag = true;
						break;
					}
				}
			}
				inFile.close();
				if (flag == true){
					cout << "\n\nWelcome "<<ac.get_name()<<"\n";
				}
			return flag;
		}
};
void Admin(){
	ATM o;
	int _id;
	int choise;
	string n,name="ADMIN";
	int p,pass=8426;
	cout<<"Enter Admin name ::";
			cin>>n;
			cout<<"Enter Password";
			cin>>p;
			if(name==n&&pass==p){
				while(true){
					system("cls");
					cout<<"\t\t\tWelcome ADMIN\n";
					cout<<"No.\t Choise\n";
					cout<<"1 -\t Display Accounts\n2 -\t Search For Account\n3 -\t update Account\n4 -\t Close Account\n5 -\t to Insert new account\n5 -\t To Quite\n\t\tYour Choise :: ";
					cin>>choise;
					if(choise==1)
						o.display();
					else if(choise==2){
						cout<<"Enter Account id to Search ::";
						cin>>_id;
						o.display_sp(_id);		
					}
					else if(choise==3){
						cout<<"Enter Account id to update ::";
						cin>>_id;
						o.update(_id);
					}
					else if(choise==4){
						cout<<"Enter Account id to close ::";
						cin>>_id;
						o.Delete(_id);
					}else if(choise==5)
						o.insert();
					else
						return;
					system("pause");
				}
			}else
				cout<<"Password incorrect\n";
}

void user(){
	ATM o;
	int _id,_pass,choise;
	cout<<"Enter Your ID:: ";
			cin>>_id;
			cout<<"Enter Your Password :: ";
			cin>>_pass;
			if(o.check_pass(_id,_pass)){
				while(true){
				cout<<"NO.\t Choise \n";
				cout<<"0 -\t to Show Your data\n1 -\t to credit \n2 -\t to debit\n\t\t your chois:: ";
				cin>>choise;
				if(choise==0)
					o.display_sp(_id);
				else if(choise==1)
					o.Credit_dept(_id,1);
				else if(choise==2)
					o.Credit_dept(_id,2);
				else
					break;
				system("pause");
				system("cls");
				}
			}else
				cout<<"Password Invalid "<<endl;

}
int main(){
	ATM o;
	int _id,_pass; 
	int c1,c2;
	cout<<"\t\t\tIf you admin press -1-\n\t\t\tIf you user press  -2-\nYour choise:: ";
	cin>>c1;
	switch(c1){
		case 1:
			Admin();
			break;
		case 2:
			user();
			break;
			
		
		
		
		
	}
	
}