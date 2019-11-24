#include"main.h"


int T_LIST[5][6] =
{
	//           i      w0    w1      (        )       #
	/*  E  */    1 ,    0,    0,       0,      0,       0,
	/*  E1 */    0,     2,    0,       0,      3,       3,
	/*  T  */    4,     0,    0,       4,      0,       0,
	/*  T1 */	 0,     6,    5,       0,      6,       6,
	/*  F  */    7,     0,    0,       8,      0,       0
};

const string ListName[12] = { "i","w0","w1","(",")","#","E","E1","T","T1","F","e" };

const int ListSum[8] = { 2,2,1,2,2,1,1,3 };
const string List[8][5] = {
	{"T","E1"},
	{"T","E1"},
	{"e"},
	{"F","T1"},
	{"F","T1"},
	{"e"},
	{"i"},
	{"(","E",")"}
};
const bool ReduceList[8]
{
	0,1,0,0,1,0,1,1
};


class stack
{
public:
	string Str[100];
	int StrNow = -1;
	void push(string Str);
	string pop();
};

void stack::push(string str)
{
	StrNow++;
	Str[StrNow] = str;
}

string stack::pop()
{
	
	StrNow--;
	string outStr = Str[StrNow + 1];
	Str[StrNow + 1] = "";
	return outStr;
}

int getIndex(token nowToken)
{
	if (nowToken.Type == 'i' || nowToken.Type == 'c')
	{
		return 0;
	}
	else if (nowToken.Type == 'p' && (nowToken.Index == 5 || nowToken.Index == 6))
	{
		return 1;
	}
	else if (nowToken.Type == 'p' && (nowToken.Index == 7 || nowToken.Index == 8))
	{
		return 2;
	}
	else if (nowToken.Type == 'p' && nowToken.Index == 13)
	{
		return 3;
	}
	else if (nowToken.Type == 'p' && nowToken.Index == 14)
	{
		return 4;
	}
	else if (nowToken.Type == 'p' && nowToken.Index == 17)
	{
		return 5;
	}

}

int getIndex(string nowState)
{
	if (strcmp(nowState.c_str(), "E") == 0)
	{
		return 0;
	}
	else if (strcmp(nowState.c_str(), "E1") == 0)
	{
		return 1;
	}
	else if (strcmp(nowState.c_str(), "T") == 0)
	{
		return 2;
	}
	else if (strcmp(nowState.c_str(), "T1") == 0)
	{
		return 3;
	}
	else if (strcmp(nowState.c_str(), "F") == 0)
	{
		return 4;
	}
}

int Find(string nowState, token nowToken)
{
	int indexNowState = getIndex(nowState);
	int indexNowToken = getIndex(nowToken);
	
	return T_LIST[indexNowState][indexNowToken];
}


stack Stack;
bool LL1()
{
	Stack.push("#");
	Stack.push("E");
	do
	{
		token* tokenNow = GetToken();
		string nowState = Stack.pop();
		if (strcmp(nowState.c_str(), "#")==0)
		{
			PushBackToken();
			return true;
		}

		int indexNextState = Find(nowState, *tokenNow) - 1;
		if (indexNextState != -1)
		{
			if (ReduceList[indexNextState] == 0)
			{
				PushBackToken();
			}
			int ListSumNow = ListSum[indexNextState];
			for (int i = ListSumNow - 1; i >= 0; i--)
			{
				string nowPushStr = List[indexNextState][i];
				if (strcmp(nowPushStr.c_str(), "e") != 0&& strcmp(nowPushStr.c_str(), "i") != 0)
				{
					Stack.push(nowPushStr);
				}
			}

		}
		else
		{
			return false;
		}

	} while (1);
	

	return false;
}