#include"header.h"
using namespace std;
void removeDuplicate(char **argv)
{
	ifstream file1,file2;
	ofstream file3;
	int line=0,flag=0,line1=0;
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
		getline(file1,temp1);
		flag=0;
		file2.open("temp.csv");
		for(int j=0;j<line1;j++)
		{
			getline(file2,temp2);
			if(temp1==temp2)
			{
				flag=1;
				break;
			}
		}
		file2.close();
		if(flag==0)
		{
			file3.open("temp.csv",ios_base::app);
			file3<<temp1;
			file3<<"\n";
			file3.close();
		}
		f1=fopen("temp.csv","r");
		c=fgetc(f1);
		line1=0;
		while(c!=EOF)
		{
			c=fgetc(f1);
			if(c=='\n')
			line1++;
		}
		fclose(f1);
	
	}
	file1.close();
	remove(argv[2]);
	rename("temp.csv",argv[2]);
}
