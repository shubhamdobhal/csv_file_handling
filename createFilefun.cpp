#include"header.h
#include<iostream>
using namespace std;
void createFile(int argc,char  **argv)
{
	string check,take;
	int num;
	ofstream file;
	file.open (argv[2]);
	for(int i=3;i<argc-1;i++)
	{
		file<<argv[i]<<",";
	}
	file<<argv[argc-1]<<"\n";
	cout<<"Do you want to input data in file from console Yes/No::";
	cin>>check;
	if(check=="Yes"||check=="yes")
	{
		cout<<"Enter number of lines you want to add ::";
		cin>>num;
		for(int i=0;i<num;i++)
		{
			fflush(stdin);
			getline(cin,take);
			file<<take;
			file<<endl;
		}
	}
	file.close();
}
