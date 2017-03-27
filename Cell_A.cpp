//==============================
//    INCLUDES
//==============================
#include "Cell_A.h"

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
Cell_A::Cell_A(){
	//Fitness = Phenotype[1];
	Fitness = Phenotype.at(1);
	RAA_ = 0.1 ;
	RAB_ = 0.1 ;
	isA=true;
}

//==============================
//    DESTRUCTOR
//==============================
Cell_A::~Cell_A(){}
//==============================
//    PUBLIC METHODS
//==============================

float Cell_A::Metabolic_Network(float A_out){
	A_out = A_out*(1-RAA_);
	Phenotype.at(0)+=A_out*RAA_-Phenotype.at(0) * RAB_;
	Phenotype.at(1)+=Phenotype.at(0)*RAB_;

	//màj fitness
	Fitness = Phenotype.at(1);
	if(Fitness < W_min) Fitness = 0;
	return A_out;
}
