#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

class market
{
	private:
		int Pcode;
		float Pprice;
		float Pdiscount;
		string Pname;
		
	public:
		void Administrator();
		void Buyer();
		void Menu();
		void add();
		void edit();
		void del();
		void list();
		void receipt();
		
};

void market :: Menu()   //CREATING main menu function
{
	m://for goto statement
	int choice;
	string mail,password;
	cout<<"\n\t\t                                 ";
	cout<<"\n\t\t\t WELCOME TO GHK SUPERMARKET";
	cout<<"\n\t\t                                 ";
	cout<<"\n 1) Administrator";
	cout<<"\n 2) Buyer";
	cout<<"\n 3) Exit";
	cout<<"\n\t\t Enter your choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\n\t\t\t_______________ please login___________";
			cout<<"\n Enter email";
			cin>>mail;
			cout<<"\n enter password";
			cin>>password;
			if(mail=="hemu@gmail.com" && password=="hemu@1")
			{
				 Administrator();
			}
			else
			{
				cout<<"\n invalid mail or password";
			}
			break;
		case 2:
			     Buyer();
			break;
		case 3:
			exit(0);
		default:
			cout<<"\n Enter correct choice";
	}
	goto m;
}

void market :: Administrator()  //creating administrator function
{
	
	m:
	int choice;
	cout<<"\n\t\t\t ________________Administrator  main MENU_________________";
	cout<<"\n 1) add new product";
	cout<<"\n 2) modify product";
	cout<<"\n 3) delete the product";
	cout<<"\n 4) go back to main menu";
	cout<<"\n enter your choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			del();
			break;
		case 4:
			Menu();
			break;
		default:
			cout<<"\n enter right choice";
	}
	goto m;
}

void market :: Buyer()   //creating buyer function
{
	m:
	int choice;
	cout<<"\n\t\t\t _______BUYER_______";
	cout<<"\n 1) Buy product";
	cout<<"\n 2) go back to main menu";
	cout<<"\n enter choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			Menu();
			break;
		default:
			cout<<"\n\t enter correct choice";
			
	}
	goto m;
}

void market :: add()   //creating add function
{
	m:
	int c; //product code
	string n; //name of product
	float p; //product price
	float d; //discount
	int token=0; //for checking purpose
	
	//we need to add product details for adding
	cout<<"\n _______Adding the data________";
	cout<<"\n enter product code";
	cin>>Pcode;
	cout<<"\n enter product name";
	cin>>Pname;
	cout<<"\n enter product price";
	cin>>Pprice;
	cout<<"\n enter product discount";
	cin>>Pdiscount;
	
	fstream data;  //data is the object of fstream
	
	data.open("supermarket.txt",ios::in); //open1     //ios::in open this file in reading mode
	if(!data)                //if this file doesn't exist
	{
		data.open("supermarket.txt",ios::app|ios::out);            //ios::out open this file in writing mode
		data<<" "<<Pcode<<" "<<Pname<<" "<<Pprice<<" "<<Pdiscount<<"\n";   //entering the data in file
		data.close();
	}
	else                    //if the file exists
	{
		data>>c>>n>>p>>d;// this is reading every element on the file like (c=1 n=apple p=50 d=2)      like i=0;
		while(!data.eof())        // it checks every content of the file by iterating
		{
			if(c==Pcode)   //it checks is there a duplicate product code or not
			{
				token++;
			}
			data>>c>>n>>p>>d;  //(c=2 n=banana p=20 d= 2) like this it checks all content in the file     like i++;
		}
		data.close(); //close1
		
		if(token==1)  //this means we entered Pcode is already existing on that file so we need to re enter the Pcode and all
		{
			goto m;   //so goto m
		}
		else
		{
			data.open("supermarket.txt",ios::app|ios::out);            //ios::out open this file in writing mode
		    data<<" "<<Pcode<<" "<<Pname<<" "<<Pprice<<" "<<Pdiscount<<"\n";  //printing the data in file
		    data.close();
		}
	}
	cout<<"\n Record(data) inserted";
	goto m;
	
}

void market :: edit()
{
	m:
	int pkey;
	int token=0;
	int c;
	float p,d;
	string n;
	fstream data,data1;                       //in this problem we need to transfer the data from one file(data) to other(data1)
	cout<<"\n ________modifying the product_________";
	cout<<"\n enter product code to change";
	cin>>pkey;
	
	data.open("supermarket.txt",ios::in);
	if(!data)
	{
		cout<<"\nfile is not existing\n";
		
	}
	else
	{
		data1.open("supermarket1.txt",ios::app|ios::out);
		
		data>>Pcode>>Pname>>Pprice>>Pdiscount;  //traversing
		while(!data.eof())
		{
			if(pkey==Pcode)
			{
				token++;
				cout<<"\n enter product code";
				data1>>c;
				cout<<"\n enter product name";
				data1>>n;
				cout<<"\n enter product price";
				data1>>p;
				cout<<"\n enter product discount";
				data1>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";                 //entering the data into new file            //editing the data
			}
			else
			{
			       data1<<" "<<Pcode<<" "<<Pname<<" "<<Pprice<<" "<<Pdiscount<<"\n"; 	//entering the data from supermarket file to supermarket1
			}
			   
			data>>Pcode>>Pname>>Pprice>>Pdiscount;  //traversing
		}
		data.close();
		data1.close();
		
		
		
		remove("supermarket.txt");                //removing the existing file 
		rename("supermarket1.txt","supermarket.txt");  //renaming this edited data to original file name (supermarket)
		
		if(token==0)
		{
			cout<<"\n there is no such product code";
		}
	}
	goto m;
}

void market :: del()
{
	m:
	int pkey;
	int token=0;
	cout<<"\n __________deleting product___________";
	cout<<"\n enter deleted product code";
	cin>>pkey;
	fstream data,data1;
	
	data.open("supermarket.txt",ios::in);
	
	if(!data)
	{
		cout<<"\n data does't exist";
	}
	else
	{
		
		
		data>>Pcode>>Pname>>Pprice>>Pdiscount;
		while(!data.eof())
		{
			if(pkey==Pcode)
			{
				token++; 
				cout<<"\n deleted successfully";      //here deleting the product which have pkey
			}
			else
			{
				data1.open("supermarket1.txt",ios::app|ios::out);
				data1<<" "<<Pcode<<" "<<Pname<<" "<<Pprice<<" "<<Pdiscount<<"\n";  //entering data from supermarket to supermarket1
			}
			data>>Pcode>>Pname>>Pprice>>Pdiscount;
		}
		data.close();
		data1.close();
		
		if(token==0)
		{
			cout<<"\n product key not found";
		}
		else
		{
			remove("supermarket.txt");                //removing the existing file 
			rename("supermarket1.txt","supermarket.txt");
		}
	}
	goto m;
}

void market :: list()      //showing receipt(all products)
{
	fstream data;
	data.open("supermarket.txt",ios::in);
	cout<<"\n__________________RECEIPT_______________";
	cout<<"\n product.NO \t\t NAME \t\t  PRICE \n";
	
	data>>Pcode>>Pname>>Pprice>>Pdiscount;
	while(!data.eof());
	{
		cout<<Pcode<<"\t\t"<<Pname<<"\t\t"<<Pprice<<"\n";
		data>>Pcode>>Pname>>Pprice>>Pdiscount;
	}
	data.close();
}

void market :: receipt()
{
	
	fstream data;
	int arrc[100];   //for array of product codes
	int arrq[100];   //for product quantities
	int c=0;         // counter
	char choice;     //for selecting yes or no
	float amount=0;    //item amounts
	float total=0;     //total after  discount
	float aft_discount_amt=0;  //amt after discount
	
	data.open("supermarket.txt",ios::in);
	if(!data)   //checking data existing or not
	{
		cout<<"\n data not existing store is empty";
	}
	else
	{
		data.close();
		
		list();   //showing all products to users
		cout<<"\n|_______________________________________\n";
		cout<<"                                           \n";
		cout<<"                                           \n";
		cout<<"          Please place the order            \n";
		cout<<"|___________________________________________\n";
		
		do
		{
			m:
			cout<<"\n product code";
			cin>>arrc[c];   //storing all selecting product codes in arrc from 0th index;
			cout<<"\n product quantity";
			cin>>arrq[c];   // storing all quantities in arrq from 0th index
			
			for(int i=0;i<c;i++)    //checking entered product code is already entered or not
			{
				if(arrc[i]==arrc[c])
				{
					cout<<"\n its a duplicate product code re enter";
					goto m;
				}
			}
			c++;
			cout<<"\n do you want to buy again then press y else n ?";
			cin>>choice;
		}
		while(choice=='y');
		cout<<"\n___________________RECEIPT___________________\n";
		cout<<"P.NO \t\t P.NAME \t\t quantity \t\t price \t\t amt \t\t amt_aft_disc\n";
		cout<<"________________________________________________________________________\n";
		for(int i=0;i<c;i++)
		{
			data.open("supermarket.txt",ios::in);
			
			data>>Pcode>>Pname>>Pprice>>Pdiscount;
			while(!data.eof())
			{
				if(Pcode==arrc[i])
				{
					amount=Pprice*arrq[i];
					aft_discount_amt=amount-(amount*(Pdiscount/100));
					total=total+aft_discount_amt;
					cout<<Pcode<<"\t\t"<<Pname<<"\t\t"<<arrq[i]<<"\t\t"<<Pprice<<"\t\t"<<aft_discount_amt<<"\n";
				}
				data>>Pcode>>Pname>>Pprice>>Pdiscount;
			}
			data.close();
		}
		cout<<"\n_______________________________________________";
		cout<<"\n total :"<<total;
		
	}
	
	
	
}

int main()
{
	market m1;
	m1.Menu();
}
