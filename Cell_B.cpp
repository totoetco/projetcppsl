//==============================
//    INCLUDES
//==============================
#include "Cell_B.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Cell_B::Cell_B(){
	//Fitness=Phenotype[2];
	Fitness = Phenotype.at(1);
	RBB_=0.1;
	RBC_=0.1;
}

//==============================
//    DESTRUCTOR
//==============================
Cell_B::~Cell_B(){}

//==============================
//    PUBLIC METHODS
//==============================
float Cell_B::Metabolic_Network(float B_out){
	B_out=B_out*(1-RBB_);
	//Phenotype[1]=B_out*RBB_+Phenotype[1]*(1-RBC_);
	Phenotype.at(1)+=B_out*RBB_-Phenotype.at(1)*RBC_;
	Phenotype.at(2)+=Phenotype.at(1)*RBC_;
	
	//maj fitness + seuil minimal
	Fitness = Phenotype.at(2);
	if(Fitness < W_min) Fitness = 0;


	return B_out;
}
