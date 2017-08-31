#include"header.h"
using namespace std;
void intersectFile(char **argv)
{
	int index1,index2,flag=0;
	string str;
	ifstream file1,file2;
	ofstream file3;
	int line1=0,h1=0,line2=0,h2=0,i,j;
	vector <string> row;
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
			line1++;
	}
	fclose(f1);
	f1=fopen(argv[3],"r");
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
			line2++;
	}
	fclose(f1);
	f1=fopen(argv[2],"r");
	c=fgetc(f1);
	while(c!='\n')
	{
			c=fgetc(f1);
			if(c==',')
			h1++;
	}
	h1=h1+1;
	fclose(f1);
	f1=fopen(argv[3],"r");
	c=fgetc(f1);
	while(c!='\n')
	{
			c=fgetc(f1);
			if(c==',')
			h2++;
	}
	h2=h2+1;
	fclose(f1);
	file1.open(argv[2]);
	for(i=0;i<h1-1;i++)
	{
		getline(file1,str,',');
		row.push_back(str);
	}
	getline(file1,str,'\n');
	row.push_back(str);
	flag=0;
	for(j=0;j<h1;j++)
	{
		if(argv[4]==row[j])
		{
			flag=1;
			index1=j;
		}
	}
	if(flag==0)
	{
		printf("Coloum not found::");
		return ;
	}
	row.erase(row.begin(),row.end());
	file2.open(argv[3]);
	for(i=0;i<h2-1;i++)
	{
		getline(file2,str,',');
		row.push_back(str);
	}
	getline(file2,str,'\n');
	row.push_back(str);
	flag=0;
	for(j=0;j<h2;j++)
	{
		if(argv[4]==row[j])
		{
			flag=1;
			index2=j;
		}
	}
	if(flag==0)
	{
		cout<<"Coloum not found::";
		return ;
	}
	file3.open("file3.csv");
	file3<<argv[4]<<"\n";
	for(i=0;i<line1-1;i++)
	{
		row.erase(row.begin(),row.end());
		for(j=0;j<h1-1;j++)
		{
			getline(file1,str,',');
			row.push_back(str);
		}
			getline(file1,str,'\n');
			row.push_back(str);
			file3<<row[index1]<<"\n";	 
	}
	file3.close();
	file1.close();
	file3.open("file4.csv");
	file3<<argv[4]<<"\n";
	for(i=0;i<line2-1;i++)
	{
		row.erase(row.begin(),row.end());
		for(j=0;j<h2-1;j++)
		{
			getline(file2,str,',');
			row.push_back(str);
		}
			getline(file2,str,'\n');
			row.push_back(str);
			file1.open("file3.csv");
			getline(file1,str);
			for(j=0;j<line1-1;j++)
			{
					getline(file1,str);
					if(str==row[index2])
					{
						file3<<str<<endl;
						break;
					}
			}	
			file1.close();
	}
	file2.close();
	file3.close();
}
