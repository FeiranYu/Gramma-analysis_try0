#include"main.h"

int iListIndex = -1;
string iList[iListSum];
int CListIndex = -1;
string CList[CListSum];	//Charset字符
int SListIndex = -1;
string SList[SListSum];
int cListIndex = -1;
double cList[cListSum];  //const 常数
int KListLike[kListSum] = { 0,0,0,0,0,0 };


token tokenList[100];
int tokenIndex = -1;

ifstream infile;

void LoadFile(const char* filename, ifstream& infile)
{
	infile.open(filename, ios::out | ios::in);
}

bool isAlphabet(const char& Char)
{
	if ((Char >= 'a' && Char <= 'z') || (Char >= 'A' && Char <= 'Z'))
	{
		return true;
	}
	return false;
}

bool isNum(const char& Char)
{
	if (Char >= '0' && Char <= '9')
	{
		return true;
	}
	return false;
}


void ShowToken(token* Token)
{
	cout << " Token type " << Token->Type << " index " << Token->Index;
	if (Token->Type == 'k')
	{
		cout << " value " << kList[Token->Index];
	}
	if (Token->Type == 'C')
	{
		cout << " value " << CList[Token->Index];
	}
	if (Token->Type == 'c')
	{
		cout << " value " << cList[Token->Index];
	}
	if (Token->Type == 'i')
	{
		cout << " value " << iList[Token->Index];
	}
	if (Token->Type == 'S')
	{
		cout << " value " << SList[Token->Index];
	}
	if (Token->Type == 'p')
	{
		cout << " value " << pList[Token->Index];
	}
	cout << endl;
}

void ShowAllToken()
{
	cout << endl;
	cout << "TokenList is follow" << endl;
	for (int i = 0; i <= tokenIndex; i++)
	{
		cout << i << " Token type " << tokenList[i].Type << " index " << tokenList[i].Index;
		if (tokenList[i].Type == 'k')
		{
			cout << " value " << kList[tokenList[i].Index];
		}
		if (tokenList[i].Type == 'C')
		{
			cout << " value " << CList[tokenList[i].Index];
		}
		if (tokenList[i].Type == 'c')
		{
			cout << " value " << cList[tokenList[i].Index];
		}
		if (tokenList[i].Type == 'i')
		{
			cout << " value " << iList[tokenList[i].Index];
		}
		if (tokenList[i].Type == 'S')
		{
			cout << " value " << SList[tokenList[i].Index];
		}
		if (tokenList[i].Type == 'p')
		{
			cout << " value " << pList[tokenList[i].Index];
		}
		cout << endl;
	}



}

bool isKeyWord(char charNow)
{
	for (int KlistIndex = 0; KlistIndex < kListSum; KlistIndex++)
	{
		char nowCompateChar = kList[KlistIndex].c_str()[KListLike[KlistIndex]];

		if (nowCompateChar == charNow)
		{
			KListLike[KlistIndex]++;

		}
		else
		{
			KListLike[KlistIndex] = 0;
			if (charNow == kList[KlistIndex].c_str()[KListLike[KlistIndex]])
			{
				KListLike[KlistIndex]++;
			}
		}
		if (KListLike[KlistIndex] == kList[KlistIndex].length())
		{
			token newToken;
			newToken.Type = 'k';
			newToken.Index = KlistIndex;
			tokenIndex++;
			tokenList[tokenIndex] = newToken;
			KListLike[KlistIndex] = 0;
			return true;
		}
	}

	return false;
}

int findRepeatStringInCList(const char* str)
{
	for (int i = 0; i <= CListIndex; i++)
	{
		if (strcmp(CList[i].c_str(), str) == 0)
		{
			return i;
		}
	}
	return -1;
}

void AddToken(char Type, int Index)
{
	token newToken;
	newToken.Type = Type;
	newToken.Index = Index;

	tokenIndex++;
	tokenList[tokenIndex] = newToken;
}

void judgeP(char* twoword)
{
	if (sizeof(twoword) == 8)
	{
		for (int i = 0; i < pListSum; i++)
		{
			if (twoword[0] == pList[i].c_str()[0] && twoword[1] == pList[i].c_str()[1])
			{
				AddToken('p', i);
				char tempchar;
				infile.get(tempchar);
				return;
			}
		}
		bool findOneFlag = false;
		for (int i = 0; i < pListSum; i++)
		{
			if (pList[i].length() == 1)
			{
				if (twoword[0] == pList[i].c_str()[0])
				{
					AddToken('p', i);
					findOneFlag = true;
				}
			}

		}
		if (findOneFlag == true)
		{
			for (int i = 0; i < pListSum; i++)
			{
				if (twoword[1] == pList[i].c_str()[0])
				{
					AddToken('p', i);
					char tempchar;
					infile.get(tempchar);


					return;
				}
			}
		}
		
	}

	else if (sizeof(twoword) == 4)
	{
		for (int i = 0; i < pListSum; i++)
		{
			if (pList[i].length() == 1)
			{
				if (twoword[0] == pList[i].c_str()[0])
				{
					AddToken('p', i);
				}
			}

		}
	}

}

void MakeTokens(const char* dest)
{

	LoadFile(dest, infile);
	bool lastIsAlphabet = true;

	char identifiStr[100] = { 0 };
	int identifiStrIndex = -1;
	bool identifiStrState = false;
	int num = 0;
	int numexp = 0;
	int numState = 0;
	int Cstate = 0;
	char CChar = 0;
	int Sstate = 0;
	char SStr[100] = { 0 };
	int SStrIndex = -1;
	int pstate = 0;
	char pTempChar = 0;
	bool endFlag = false;

	while (1)
	{
		char charNow;
		infile.get(charNow);

		//ShowAllToken();
		if (infile.eof())
		{
			if (!endFlag)
			{
				charNow = ' ';
				endFlag = true;
			}
			else
			{
				break;
			}

		}


		if (isAlphabet(charNow))
		{
			//判断是否属于C字符
			if (Cstate == 1)
			{
				CChar = charNow;
				Cstate = 2;
			}
			else if (Sstate == 1)
			{
				SStrIndex++;
				SStr[SStrIndex] = charNow;

			}
			else
			{
				identifiStrState = true;
				identifiStrIndex++;
				identifiStr[identifiStrIndex] = charNow;
				bool isKeyWordFlag = false;
				isKeyWordFlag = isKeyWord(charNow);
				if (isKeyWordFlag)
				{
					identifiStrState = false;
					memset(identifiStr, 0, 100);
					identifiStrIndex = -1;
				}

			}

		}
		else
		{
			//num state  1 <- 整数 2 <-小数点 3 <-小数
			if (isNum(charNow))
			{
				if (identifiStrState == true)
				{
					identifiStrIndex++;
					identifiStr[identifiStrIndex] = charNow;
				}
				else
				{
					if (numState == 0)
					{
						numState = 1;
					}
					if (numState == 1)
					{
						num *= 10;
						num += charNow - '0';
						char tempChar;
						infile.get(tempChar);

						infile.putback(tempChar);
						if (!isNum(tempChar) && tempChar != '.')
						{
							numState = 0;
							cListIndex++;
							cList[cListIndex] = num;
							AddToken('c', cListIndex);
							num = 0;
							numexp = 0;
						}
					}
					if (numState == 3)
					{
						num *= 10;
						num += charNow - '0';
						numexp--;
						char tempChar;
						infile.get(tempChar);
						if (infile.eof() == false)
						{
							infile.putback(tempChar);
							if (!isNum(tempChar))
							{
								numState = 0;
								cListIndex++;
								cList[cListIndex] = num * pow(10, numexp);
								AddToken('c', cListIndex);
								num = 0;
								numexp = 0;
							}
						}
						else
						{
							numState = 0;
							cListIndex++;
							cList[cListIndex] = num * pow(10, numexp);
							AddToken('c', cListIndex);
							num = 0;
							numexp = 0;
						}


					}
				}


			}
			else
			{

				if (Sstate == 0)
				{
					if (charNow == '\"')
					{
						Sstate = 1;
					}
				}
				else if (Sstate == 1)
				{
					if (charNow == '\"')
					{
						char tempStr[100] = { 0 };
						sprintf_s(tempStr, "\"%s\"", SStr);
						SListIndex++;
						SList[SListIndex] = tempStr;

						AddToken('S', SListIndex);


						memset(SStr, 0, 100);
						SStrIndex = -1;
					}
					Sstate = 0;
				}

				if (Cstate == 0)
				{
					if (charNow == '\'')
					{
						Cstate = 1;
					}

				}
				else if (Cstate == 2)
				{
					if (charNow == '\'')
					{
						CListIndex++;
						char tempStr[100] = { 0 };
						sprintf_s(tempStr, "'%c'", CChar);
						CList[CListIndex] = tempStr;
						AddToken('C', CListIndex);
						CChar = 0;


					}
					Cstate = 0;
				}

				//-------------处理参数的部分[开始]-----------
				if (charNow == '.' && numState == 1)
				{

					numState = 3;
				}
				else if (numState != 0)
				{
					numState = 0;
					cListIndex++;
					cList[cListIndex] = num * pow(10, numexp);
					AddToken('c', cListIndex);
					num = 0;
					numexp = 0;
				}

				//------------处理常数的部分[结束]-----------


				if (identifiStrState)
				{
					int indexInCList = findRepeatStringInCList(identifiStr);
					if (indexInCList == -1)
					{
						iListIndex++;
						iList[iListIndex] = identifiStr;
						AddToken('i', iListIndex);
					}
					else
					{
						AddToken('i', indexInCList);
					}

					memset(identifiStr, 0, 100);
					identifiStrIndex = -1;

				}
				if (pstate == 0)
				{
					char twochar[2];
					twochar[0] = charNow;
					infile.get(twochar[1]);
					if (infile.eof() == false)
					{
						infile.putback(twochar[1]);
					}

					judgeP(twochar);
				}
				if (charNow == ' ')
				{

				}

				identifiStrState = false;

			}

		}
	}

}


int tokenNow = -1;

token* GetToken()
{
	tokenNow++;
	return &tokenList[tokenNow];

}

void PushBackToken()
{
	tokenNow--;
}
