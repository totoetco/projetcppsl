//==============================
//    INCLUDES
//==============================
#include "Cell.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
float Cell::death_Probability = 0.02;
float Cell::mutation_Probability = 0.001;
float Cell::W_min = 0.001;
//==============================
//    CONSTRUCTORS
//==============================
Cell::Cell(){
	float Phenotype[3] = {0.0,0.0,0.0};
	Fitness = 0.0;
}
//==============================
//    DESTRUCTOR
//==============================
Cell::~Cell(){};
//==============================
//    PUBLIC METHODS
//==============================
