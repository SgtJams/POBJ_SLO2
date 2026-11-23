/*----------------------------------------------------------------------------------
// Projet Name 			: POBJ_DemoCPP_25_26
// File Name 			: demoSLO.cpp
// Creation Date 		: 19.09.2024
// Modification Date	: 18.11.2026
//
// Author 				: Philou (Ph. Bovey)
//
// Version				: 1.5
//
// Description          : demo for SLO2's team  
//						  -> type (primitive) 
//						  -> static or dynamic memories
//						  -> objects
// Remarks				: 
//----------------------------------------------------------------------------------*/

//-- standart libraries --// 
#include <iostream>		// equivalent at the <stdio.h> in C
#include <string>		// for the objects linked to the string 
#include <cstdint>		// to use a C library -> here the normalised type 
#include <cstdbool>		// not required to use the boolean type 


//-- personnal libraries -> class --//
#include "mesFcts.h"

//-- main programme -> entry point of the programm --//
int main()
{
	//--- variable's declaration ---//
	//--> static memory -> "ROM" 
	//--> primitive type  --// 
	//-- integer --//
	bool		valCheck;						//-> 1 byte			//-> true ou false 
	char		valInteration;					//-> 1 byte
	short		valDiviseur, valDividende;		//-> 2 bytes
	int			valRetour; 						//-> 4 bytes 
	long		valL; 							//-> 4 bytes 
	long long	valLong; 						//-> 8 bytes
	
	//-- example with normalized type --// 
	int8_t		val_8bits;		//-> 1 byte
	int16_t		val_16bits; 	//-> 2 byte
	int32_t		val_32bits; 	//-> 4 byte 
	int64_t		val_64bits; 	//-> 8 byte

	//-- real --//
	float valF;		//-> 4 octet 
	double valD;	//-> 8 octet 

	//-- declaration of table (static memory) --// 
	char chaineCararter[NB_MAX_ALPHABET]; 

	//-- Fill an alphabetical letter table --// 
	for (valInteration = 0; valInteration < NB_MAX_ALPHABET; valInteration++)
	{
		chaineCararter[valInteration] = 0x41 + valInteration; 
	}
 
	//-- pointer declaration --// 
	char* ptTb; 	//-> primitive type 

	//-- using the dynamique memories with a primitive variable --//
	ptTb = new char[40];
	
	//-- copy a static caracter table --// 
	ptTb = chaineCararter; 

	//-- check if the entire table has been copied --// 
	std::cout << "test -> dernière de lettre de l'alphabet ? :" << ptTb[25] << std::endl;

	//-- creating static object --// 
	//--> objet class/type string 
	//--> creating and instantating the object; 
	//--> static object memory
	// class abstraite -> std class enfant -> string objet -> msg datas -> "hello" 
	std::string msg = "hello"; 

	msg += " ";  // msg = msg + " "

	//-- creating the dynamic object
	std::string* msg2; 

	//-- instantiating the dynamic objetc
	msg2 = new std::string("SLO");

	//-- other methode to copy a string 
	msg2->insert(0, msg);

	//msg.clear();

	//-- check if 2 is present in string --//
	if (msg2->find("2") < 0)
	{
		valCheck = true; 
	}
	else
	{
		valCheck = false; 
		std::cout << *msg2 + "2";
	}

	//-- destruction of dynamic objetc --// 
	delete(msg2); 

	//-- end of first demo --// 
	std::cout << std::endl; 

	//-- new user request --// 
	std::cout << "Veuiller insérer une valeur pour le dividande  : "; 
	std::cin >> val_16bits; 
	std::cout << "Veuiller insérer une valeur pour le diviseur  : ";
	std::cin >> valDiviseur;
	
	//-- function calling for the division  --// 
	Divide(val_16bits, valDiviseur, valF);
	std::cout << val_16bits << " / " << valDiviseur << " = " << valF << std::endl;
	

	valRetour = Divide((int&)valF, (double)val_16bits);
	std::cout << val_16bits << " / " << valDiviseur << " = " << valF << std::endl;


	//-- example to take a keyboard value --//
	/*std::cin >> valI;		// integer value pour valeur entière 
	std::cin >> valF;		// real value   
	std::cin >> chaine;		// string with an object 
	std::cin >> valC; 		// character value
	*/

	



	/*

	//-- value assignment on a variable -> static memory --// 
	valI = 10;

	//-- object--// 
	//description : -> class -> objet -> () <- constructor calling 
	std::string chaine("hello"), chaine2;

	//-- déclaration d'objet type 
	Personnage slo2Student(50);		//object statique 
	Personnage *slo2Etudiant;		//object dynamique 

	couteau couteauSuisse("couteau suisse", 1);  

	slo2Student.taille = 160; 


	//-- démo statique --// 
	user demoStatique(0,0);
	user* demo2; 

	demo2 = new user(10, 100); 

	demo2->LIM_MAX = 10; 
	
	demoStatique.FctDemoStatique(0, 0); 

	user::FctDemoStatique(1, 10); 

	//user::AfficherMsgUser(demo2); 

	demoStatique.LIM_MAX = 0; 

	 

	//user::AfficherMsgUser(demoStatique);
	demoStatique.AfficherMsgUser(user::msg1); 
	
	




	//-- instancier un objet dynamique --// 
	slo2Etudiant = new Personnage(); 

	//-- afficher vie sur objet statique 
	slo2Student.AfficherVie(); 

	//-- affficher vie sur objet dynamique
	slo2Etudiant->AfficherVie(); 

	//-- tester une exception --// 
	try 
	{
		slo2Etudiant->Attaquer(); 
	}
	catch (std::exception &erreur)
	{
		//-- affichage exception --// 
		std::cerr << "cause de l'exception : " << erreur.what() << std::endl; 
		std::cerr << "type d'erreur : " << typeid(erreur).name() << std::endl; 
	}

	slo2Etudiant->ChoisirArme(); 
	slo2Etudiant->SupprimerArme(); 


	//-- destruction de l'objet dynamique
	delete slo2Etudiant; 

	slo2Etudiant->AfficherVie(); 

	//-- use of an object -> methode utilisation 
	//-> lenth of character string 
	valI = chaine.length(); 

	//-> search the occurence number, here in a string with find methode 
	valI = chaine.find("on");

	//-- msg user --// 
	std::cout << chaine << " " << chaine2 << std::endl;
	std::cout << "HELLO SLO !! \n" << std::endl;



	

		

	// REMARQUE : static en C : garder la valeur d'une variable dans une fct 
	//            static en C++ : pas besoin d'objet pour utiliser des méthodes ou attributs static 

	//-- dynamique
	*/

	system("pause"); 

	return 0; 
}




