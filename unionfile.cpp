#include"header.h"
using namespace std;
void unionFile(char **argv,int argc)
{
	int *index1,*index2,flag;
	string str;
	index1=new int[argc-4];
	index2=new int[argc-4];
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
	for(i=0;i<argc-4;i++)
	{
		flag=0;
		for(j=0;j<h1;j++)
		{
			if(argv[i+4]==row[j])
			{
				flag=1;
				index1[i]=j;
			}
		}
		if(flag==0)
		{
			cout<<"column not found::";
			return ;
		}
		
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
	for(i=0;i<argc-4;i++)
	{
		flag=0;
		for(j=0;j<h2;j++)
		{
			if(argv[i+4]==row[j])
			{
				flag=1;
				index2[i]=j;
			}
		}
		if(flag==0)
		{
			cout<<"Coloum not found::";
			return ;
		}
	}
	file3.open("file3.csv");
	for(i=4;i<argc-1;i++)
	{
		file3<<argv[i]<<",";
	}
	file3<<argv[argc-1]<<endl;
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
		for(j=0;j<argc-5;j++)
		{
			file3<<row[index1[j]]<<",";	 
		}
			file3<<row[index1[j]]<<"\n";
	}
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
		for(j=0;j<argc-5;j++)
		{
			file3<<row[index2[j]]<<",";	
		}
			file3<<row[index2[j]]<<"\n";
	}
	file1.close();
	file2.close();
	file3.close();
	return ;
}
