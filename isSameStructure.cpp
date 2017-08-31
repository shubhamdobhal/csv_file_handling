#include"header.h"
using namespace std;
void isSameStructure(char **argv)
{
	vector <string > header1;
	vector <string > header2;
	string temp,str;
	int flag=1,h1=0,h2=0;
	FILE *f1;
	char c;
	f1=fopen(argv[2],"r");
	if(f1==NULL)
	{
		cout<<"file not found::";
		return ;
	}
	c=fgetc(f1);
	while(c!='\n')
	{
			c=fgetc(f1);
			if(c==',')
			h1++;
	}
	h1++;
	fclose(f1);
	f1=fopen(argv[3],"r");
	if(f1==NULL)
	{
		cout<<"FILE not found::";
		return ;
	}
	c=fgetc(f1);
	while(c!='\n')
	{
			c=fgetc(f1);
			if(c==',')
			h2++;
	}
	h2++;
	fclose(f1);
	ifstream file1,file2;
	file1.open(argv[2]);
	for(int i=0;i<h1-1;i++)
	{
		getline(file1,str,',');
		header1.push_back(str);
	}
	getline(file1,str,'\n');
	header1.push_back(str);
	file1.close();
	file2.open(argv[3]);
	for(int i=0;i<h2-1;i++)
	{
		getline(file2,temp,',');
		header2.push_back(temp);
	}
	getline(file2,temp,'\n');
	header2.push_back(temp);
	file2.close();
	if(header1.size()!=header2.size())
	{
		flag=0;
		cout<<"Number of coloumn are not equals.  File not having  same structure\n";
	}
	else
	{
		sort(header1.begin(),header1.end());
		sort(header2.begin(),header2.end());
		
		for(int i=0;i<header1.size();i++)
		{
			//cout<<header1[i]<<" "<<header2[i];
			if(header1[i]!=header2[i])
			{
				flag=0;
				cout<<"File having different coloums not same structure";
				break;
			}
		}
	}
	if(flag==1)
	cout<<"File having same structure ";
}
