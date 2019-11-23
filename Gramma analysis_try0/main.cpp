#include"main.h"

int main()
{
	MakeTokens("code.c");
	ShowAllToken();

	
	ShowToken(GetToken());
	if (E())
	{
		cout << "Right";
	}
	else
	{
		cout << "Wrong";
	}


	return 0;
}