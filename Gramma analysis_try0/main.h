#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
using namespace std;


const int iListSum = 100;
extern int iListIndex;
extern string iList[iListSum];
const int CListSum = 100;
extern int CListIndex;
extern string CList[CListSum];	//Charset×Ö·û
const int SListSum = 100;
extern int SListIndex;
extern string SList[SListSum];
const int cListSum = 100;
extern int cListIndex;
extern double cList[cListSum];  //const ³£Êý
const int kListSum = 6;
const string kList[kListSum] = { "int","main","void","if","else","char" };
extern int KListLike[kListSum];

const int pListSum = 18;
const string pList[pListSum] = { "<=","==","=",">","<","+","-","*","/","{","}",",",";","(",")" ,"[","]" ,"#" };



struct token
{
	char Type;
	int Index;
};

extern token tokenList[100];
extern int tokenIndex;

void MakeTokens(const char* dest);
void ShowAllToken();
void ShowToken(token* Token);
token* GetToken();
void PushBackToken();
bool E();
bool LL1();