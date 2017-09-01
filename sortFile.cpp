#include"header.h"
using namespace std;
int numeric;
int isnumeric(string st)
{
	numeric=0;
	for(int i=0;i<st.size();i++)
	{
		if(!isdigit(st[i]))
		return 0;
	}
	for(int i=0;i<st.size();i++)
	{
		numeric=numeric*10+(st[i]-'0');
	}
	return 1;
}
typedef struct Node
{
	vector <string > row;
	struct Node *left;
	struct Node *right;
	string ifstr;
	int ifnum;
}Node;
Node  *addTreeNode(Node *root,int num,vector <string> str)
{
	if(root==NULL)
	{
		root=new Node;
		root->row=str;
		root->left=NULL;
		root->right=NULL;
		root->ifnum=num;
		return root;
	}
	else if(root->ifnum>num)
	{
		root->left=addTreeNode(root->left,num,str);
	}
	else
	{
		root->right=addTreeNode(root->right,num,str);
	}
	return root;
}
Node  *addTreeNode(Node *root,string strt,vector <string> str)
{
	if(root==NULL)
	{
		root=new Node;
		root->row=str;
		root->left=NULL;
		root->right=NULL;
		root->ifstr=strt;
		return root;
	}
	else if(root->ifstr>strt)
	{
		root->left=addTreeNode(root->left,strt,str);
	}
	else
	{
		root->right=addTreeNode(root->right,strt,str);
	}
	return root;
}

void writeTree(Node *root,int h)
{
	ofstream file;
	file.open("temp.csv",ios_base::app);
	if(root==NULL)
	{
		return;
	}
	else
	{
	
		writeTree(root->left,h);
		for(int i=0;i<h-1;i++)
		{
			file<<root->row[i]<<",";
		}
		file<<root->row[h-1]<<endl;
		writeTree(root->right,h);
		file.close();
	}
}
void sortFile(char **argv)
{
	Node *root=NULL;
	ifstream file;
	ofstream file2;
	string str;
	int line=0,h=0,indexSort,i,j;
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
	f1=fopen(argv[2],"r");
	c=fgetc(f1);
	while(c!='\n')
	{
			c=fgetc(f1);
			if(c==',')
			h++;
	}
	h=h+1;
	fclose(f1);
	file.open(argv[2]);
	file2.open("temp.csv");
	int flag=0;
	for(i=0;i<h-1;i++)
	{
		getline(file,str,',');
		if(str==argv[3])
		{
			flag=1;
			indexSort=i;
		}
		file2<<str<<",";
	}
	getline(file,str,'\n');
	if(str==argv[3])
	{
		flag=1;
		indexSort=i;
	}
	if(flag==0)
	{
		cout<<"column not found::";
		return ;
	}

	file2<<str<<"\n";
	for(j=1;j<line;j++)
	{
		vector <string> row;
		for(i=0;i<h-1;i++)
		{
			getline(file,str,',');
			row.push_back(str);	
	    }
	    getline(file,str);
		row.push_back(str);	
		if(isnumeric(row[indexSort])==1)
		root=addTreeNode(root,numeric,row);
		else
		root=addTreeNode(root,row[indexSort],row);
		row.erase(row.begin(),row.end());
	}
	
	file2.close();
	writeTree(root,h);
	file.close();
	remove(argv[2]);
	rename("temp.csv",argv[2]);
}
