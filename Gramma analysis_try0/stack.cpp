#include"main.h"



void iStack::push(token* Token)
{
	index++;
	pToken[index] = Token;
}

token* iStack::pop()
{
	index--;
	return pToken[index + 1];
}

void quadStack::push(quad* Quad)
{
	index++;
	pQuad[index] = Quad;
}

quad* quadStack::pop()
{
	index--;
	return pQuad[index + 1];
}