#include"header.h"
using namespace std;
int main(int argc, char **argv) 
{
	if(strcmp(argv[1],"create")==0)
	{
		createFile(argc,argv);
	}
	else if(strcmp(argv[1],"compare")==0)
	{
		isSameStructure(argv);
	}
	else if(strcmp(argv[1],"isduprow")==0)
	{
		isDuplicate(argv);
	}
	else if(strcmp(argv[1],"removedup")==0)
	{
		removeDuplicate(argv);
	}
	else if(strcmp(argv[1],"sort")==0)
	{
		sortFile(argv);
	}
	else if(strcmp(argv[1],"union")==0)
	{
		unionFile(argv,argc);
	}
	else if(strcmp(argv[1],"intersection")==0)
	{
		intersectFile(argv);
	}
	else
	{
		cout<<argv[1]<<"doesn't exist terminating";
	}
	return 0;
}
