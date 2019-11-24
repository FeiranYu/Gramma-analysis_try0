#include"main.h"

int main()
{

	MakeTokens("code.c");
	
	ShowAllToken();

	/*
	if (E())
	{
		token* TokenNow = GetToken();
		if (TokenNow->Type == 'p' && TokenNow->Index == 17)
		{
			cout << "Right" << endl;
			cout << "EOF" << endl;
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
	*/

	
	if (LL1())
	{
		token* TokenNow = GetToken();
		ShowToken(TokenNow);
		if (TokenNow->Type == 'p' && TokenNow->Index == 17)
		{
			cout << "Right" << endl;
			cout << "EOF" << endl;
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
	
	

	return 0;
}