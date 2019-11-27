#include"main.h"

int main()
{

	MakeTokens("code.c");
	
	ShowAllToken();

	cout << "=====================================LL(1)分析===============================" << endl;

	if (LL1())
	{
		token* TokenNow = GetToken();
		if (TokenNow->Type == 'p' && TokenNow->Index == 17)
		{
			cout << "Right" << endl;
		}
		else
		{
			cout << "Wrong" << endl;
			cout << "Not EOF" << endl;
		}
	}
	else
	{
		cout << "Wrong" << endl;
	}

	
	cout << "==============================递归下降&&四元式生成===========================" << endl;
	GetTokenInit();
	if (E())
	{
		token* TokenNow = GetToken();
		if (TokenNow->Type == 'p' && TokenNow->Index == 17)
		{
			cout << "Right" << endl;
		}
		else
		{
			cout << "Wrong" << endl;
			cout << "Not EOF" << endl;
		}
	}
	else
	{
		cout << "Wrong" << endl;
	}

	ShowAllQuad();
	

	return 0;
}