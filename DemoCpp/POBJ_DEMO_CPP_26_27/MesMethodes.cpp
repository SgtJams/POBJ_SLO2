//-----------------------------------------------------------------------------------//
// Project Name			: POBJ DEMO C++
// File Name	 		: demoSLO.cpp
// creation date 		: 21.11.2023
// modification date	: 23.11.2026
//
// Auteur 				: Philou (Ph. Bovey)
// 
// Version				: 1.1
//
// Description          : functions no linked at a class 
//
// Remarques :          : 
//----------------------------------------------------------------------------------//
//-- standard libraries --// 
#include <iostream>				// for mananing the input - output stream
#include <string>				// using the string type object 

//-- personnal libraries --// 
#include "ClassDemo.h"
#include "mesFcts.h"


/* ----------------------------------------------------------------------------------
// Function Name		: Convertir
// input parameters		: valAConv (integer 4o - signed) 
// output parameters	: 
// reference parameters : binaire (table of 100 case - integer 8o - signed) 
// descrription			: 
---------------------------------------------------------------------------------- */
void Convertir(int valAConv, char (&binaire)[100]) 
{
	int reste = 1; 
	int index = 0; 


	while (valAConv != 0)
	{
		reste = valAConv % 2;
		valAConv = valAConv >> 1; 

		if (reste == 1)
			binaire[index] = 0; 
		else 
			binaire[index] = 1;

		index++; 
	}
}


/* ----------------------------------------------------------------------------------
// Function Name		: Divide 
// input parameters		: v1 => dividing (real 4o), divider (integer 4o signed) 
//						  v2 => dividing (real 4o), divider (real 4o) 
//						  v3 => dividing (real 8o), divider (real 8o) 
// output parameters	: v1 => -
//						  v2 => integer 4o signed
//						  v3 => same think that the v1 
// reference parameters : v1 => realQuotient (real 4o) 
//					      v2 => same think that the v1 
//						  v3 => result (integer 4o signed) 
// descrription			: performs a simple division 
// 
// remark				: the various functions below are overloaded 
---------------------------------------------------------------------------------- */
//-- primary function (v1)
void Divide(float dividing, int divider, float &realQuotient)
{
	realQuotient = dividing / divider;
}

//-> overloaded function (v2)
int Divide(float dividing, float divider, float &realQuotient)
{
	return realQuotient = dividing / divider;
}

//-> overloaded function (v3)
int Divide(int &realQuotient, double dividing, double divider)
{
	return realQuotient = dividing / divider;
}

//-- A TESTER avec pointeur null --// 
/*void Diviser(void* pt, int var2, float& result)
{
	result = (int*) *pt / var2;
}*/