#include"header.h"
using namespace std;
void isDuplicate(char **argv)
{
	ifstream file1,file2;
	int line=0,flag=0;
	string temp1,temp2;
	FILE *f1;
	char c;
	f1=fopen(argv[2],"r");
	if(f1==NULL)
	{
		cout<<"File not found::";
		return ;
	}
	c=fgetc(f1);
	while(c!=EOF)
	{
			c=fgetc(f1);
			if(c=='\n')
			line++;
	}
	fclose(f1);
	file1.open(argv[2]);
	
	for(int i=0;i<line;i++)
	{
		getline(file1,temp1,'\n');
		file2.open(argv[2]);
		for(int j=0;j<line;j++)
		{
			if(j<=i)
			{
				getline(file2,temp2,'\n');
			}
			else
			{
				cout<<j<<"@";
			getline(file2,temp2,'\n');
			cout<<temp1<<temp2<<endl;
			if(temp1==temp2)
			{
				
				cout<<"Duplicate line exit that are line "<<i+1<<"and"<<j+1;
				flag=1;
				break;
				 	
			}	
			}
		}
		file2.close();
			if(flag==1)
			break;
	}
	if(flag==0)
	cout<<"No Duplicate line exist";
	
}
