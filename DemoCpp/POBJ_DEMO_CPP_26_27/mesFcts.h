/*----------------------------------------------------------------------------------
// Projet Name 			: POBJ_DemoCPP_25_26
// File Name 			: mesFcts.h
// Creation Date 		: 18.11.2025
// Modification Date	: 18.11.2026
//
// Author 				: Philou (Ph. Bovey)
//
// Version				: 0.1
//
// Description          : demo for SLO2's team
//						-> function protoytpes without link with a class 
//
// Remarks				:
//----------------------------------------------------------------------------------*/
#ifndef MES_FCTS_H
#define MES_FCTS_H 

#define NB_MAX_ALPHABET 26
#define BASE_10			10


//-- prototype with "surcharge" concept --//
//-- WARNING : if the oupput is only modified, this is not equivalent to on "surcharge"
void Divide(float dividing, int divider, float& realQuotient);		// prototype 1
int Divide(float dividing, float divider, float& realQuotient);		// prototype 2 -> Surcharge 
int Divide(int& realQuotient, double dividing, double divider = BASE_10);		// prototype 3 -> surcharge and default value
//void Diviser(void* pt, int var2, float& result); 

#endif // !MES_FCTS_H

