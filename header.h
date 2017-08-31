#include<string>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
void createFile(int ,char **);//for creating a csv file
void isSameStructure(char **);//if two seprate file have same structure
void isDuplicate(char **);//if a file contain duplicate row
void removeDuplicate(char **);//to remove duplicate rows from a file
void sortFile(char **);//To sort a file on column base
void unionFile(char **,int argc);//to union file on cloumn base
void intersectFile(char **argv);//intersection of rows on column base
