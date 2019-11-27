#include"main.h"


//--------------------------生成四元式部分[开始]--------------------------

iStack OpStack;
quadStack QuadStack;

int tempIndexNow = 0;
token* AddNewTempToken()
{
	token* newToken = new token;
	iListIndex++;
	char newStr[100] = { 0 };
	sprintf_s(newStr, "t%d", tempIndexNow);
	tempIndexNow++;
	iList[iListIndex] = newStr;
	newToken->Index = iListIndex;
	newToken->Type = 'i';
	return newToken;
}

void MackQuad(token* op)
{
	quad* newQuad = new quad;
	newQuad->op = pList[op->Index];
	newQuad->in1 = OpStack.pop();
	newQuad->in2 = OpStack.pop();
	newQuad->out = AddNewTempToken();
	OpStack.push(newQuad->out);

	QuadStack.push(newQuad);
}

void ShowQuad(quad* Quad)
{

	cout << "( " << Quad->op << ",";
	if (Quad->in1->Type == 'i')
	{
		cout << iList[Quad->in1->Index] << ",";
	}
	else
	{
		cout << cList[Quad->in1->Index] << ",";
	}
	if (Quad->in2->Type == 'i')
	{
		cout << iList[Quad->in2->Index] << ",";
	}
	else
	{
		cout << cList[Quad->in2->Index] << ",";
	}
	cout << iList[Quad->out->Index] << ")" << endl;

}

void ShowAllQuad()
{
	for (int i = 0; i <= QuadStack.index; i++)
	{
		ShowQuad(QuadStack.pQuad[i]);
	}
}

//--------------------------生成四元式部分[结束]--------------------------

bool T();
bool E1();
bool F();
bool T1();

bool E()
{
	if (T() == true)
	{
		if (E1() == true)
		{
			return true;
		}
	}
	return false;
}

bool E1()
{
	token* TokenNow = GetToken();
	if (TokenNow->Type == 'p' && (TokenNow->Index == 5 || TokenNow->Index == 6))	//5 + 6-
	{
		if (T() == true)
		{
			
			if (E1() == true)
			{
				MackQuad(TokenNow);
				return true;
			}
		}
		
	}
	else
	{
		PushBackToken();
		return true;
	}

}

bool T()
{
	if (F() == true)
	{
		if (T1() == true)
		{
			return true;
		}
	}
	return false;
}

bool T1()
{
	token* TokenNow = GetToken();
	if (TokenNow->Type == 'p' && (TokenNow->Index == 7 || TokenNow->Index == 8))	// 7 * 8 /
	{
		if (F() == true)
		{
			
			if (T1() == true)
			{
				MackQuad(TokenNow);
				return true;
			}
		}
		
	}
	else
	{
		PushBackToken();
		return true;
	}
}

bool F()
{
	token* TokenNow = GetToken();
	if (TokenNow->Type == 'i' || TokenNow->Type == 'c')
	{
		OpStack.push(TokenNow);
		return true;
	}
	else if (TokenNow->Type == 'p' && TokenNow->Index == 13)	//左括号
	{
		if (E() == true)
		{
			token* TokenNow = GetToken();
			if (TokenNow->Type == 'p' && TokenNow->Index == 14) //右括号
			{
				return true;
			}
			else {
				PushBackToken();
			}
		}
	}
	else
	{
		PushBackToken();
		
	}
	return false;
	
}