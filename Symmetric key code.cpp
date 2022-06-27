#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
int main() {
	string s;
	int size=0, key=0, op;
	char y;
	int *array;
	main:
	cout<<" 1: "Encryption\t 2: Decryption\n";
	cout<<"Select Operation=>";
	cin>>op;
	switch(op);
	case 1:
	cout<<"Enter Message to Encrypt =>";
	cin>>s;
	cout<<"\nEnter Key =>";
	cin>>key;
	size=s.length();
	array = new int[s.length()];
	cout<<"Data Encrypted Succesfully:\n";
	for(int i=0; i<size; i++)
		*(array = i)=s[i]+key;
	for(int i=0; i<size; i++)
	{
		y=*(array+i);
		cout<<array[i]<<"\t"<<y<<endl;
	}
	delete []array;
	
	break;
	
	case 2:
	cout<<"Enter Encrypted Message =>";
	cin>>s;
	cout<<"\nEnter Key =>";
	cin>>key;
	size=s.length();
	array=new int[s.length()];
	cout<<"Data Decrypted Succesfully:\n";
	for(int i=0; i<size;i++)
		*(array = i)=s[i]-key;
	for(int i=0;i<size; i++)
	{
		y=*(array=i);
		cout<<array[i]<<"\t"<<y<<endl;
	}
	delete [array];
	break;
	default:
	cout<<"Invalid Input Try again\n\n";
	system("cls");
	goto main;
}
cout<<"\n\n\n\n\n\n\n\n\n";
system("pause");
}

	
	
	