#include"main.h"
/*
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
			if (TokenNow->Type == 'p' && (TokenNow->Index == 5 || TokenNow->Index == 6))	//5 + 6-
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

bool E1()
{

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
			if (TokenNow->Type == 'p' && (TokenNow->Index == 7|| TokenNow->Index == 8))	// 7 * 8 /
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
	else if(TokenNow->Type=='p'&&TokenNow->Index==13)	//◊Û¿®∫≈
	{
		if (E() == true)
		{
			token* TokenNow = GetToken();
			if (TokenNow->Type == 'p' && TokenNow->Index == 14) //”“¿®∫≈
			{
				return true;
			}
		}
	}
	return false;
}

*/

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
		return true;
	}
	else if (TokenNow->Type == 'p' && TokenNow->Index == 13)	//◊Û¿®∫≈
	{
		if (E() == true)
		{
			token* TokenNow = GetToken();
			if (TokenNow->Type == 'p' && TokenNow->Index == 14) //”“¿®∫≈
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