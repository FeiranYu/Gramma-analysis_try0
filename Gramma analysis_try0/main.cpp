#include"main.h"

int main()
{

	MakeTokens("code.c");
	
	ShowAllToken();

	
	if (E())
	{
		token* TokenNow = GetToken();
		if (TokenNow->Type == 'p' && TokenNow->Index == 17)
		{
			cout << "Right" << endl;
			cout << "EOF";
		}
		else
		{
			cout << "Wrong" << endl;
			cout << "Not EOF";
		}
	}
	else
	{
		cout << "Wrong" << endl;
	}
	
	
	

	return 0;
}