#include"main.h"
bool T();
bool F();

bool E()
{
	if (T() == true)
	{
		return true;
	}
	else
	{
		if (E() == true)
		{
			token* TokenNow = GetToken();
			if (TokenNow->Type == 'p' && (TokenNow->Index == 5 || TokenNow->Index == 6))
			{
				if (T() == true)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool T()
{
	if (F() == true)
	{
		return true;
	}
	else
	{
		if (T() == true)
		{
			token* TokenNow = GetToken();
			if (TokenNow->Type == 'p' && (TokenNow->Index == 7|| TokenNow->Index == 8))
			{
				if (F() == true)
				{
					return true;
				}
			}

		}
	}
	return false;
}

bool F()
{
	token* TokenNow = GetToken();
	if (TokenNow->Type == 'i' || TokenNow->Type == 'c')
	{
		return true;
	}
	else if(TokenNow->Type=='p'&&TokenNow->Index==13)	//×óÀ¨ºÅ
	{
		if (E() == true)
		{
			token* TokenNow = GetToken();
			if (TokenNow->Type == 'p' && TokenNow->Index == 14) //ÓÒÀ¨ºÅ
			{
				return true;
			}
		}
	}
	return false;
}