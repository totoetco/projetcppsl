//==============================
//    INCLUDES
//==============================
#include "Gap.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using std::cout;
using std::endl;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
float Gap::D_ = 0.1;
//==============================
//    CONSTRUCTORS
//==============================
Gap::Gap(){
	A_init=49.0;                                // Valeur comprise entre 0 et 50, à modifier	
}
//==============================
//    DESTRUCTOR
//==============================
Gap::~Gap(){}
//==============================
//    PUBLIC METHODS
//==============================

void Gap::Set_Gap(int x,int y, bool is_A){
	x_coord=x;
	y_coord=y;                             // Valeur comprise entre 0 et 50, à modifier
	P_.push_back(0.0);
	P_.push_back(0.0);
	if(is_A){
		Cell_A* cell = new Cell_A();
		C_ = cell;
	}else{
		Cell_B* cell = new Cell_B();
		C_ = cell;
	}
}

bool Gap::Death_test(){
	double n = 0;
	bool alive = true;
	n = (double)rand() / (double)RAND_MAX;
	if(n<C_->get_death_P()) {
		P_.at(0)+=C_->get_Phenotype().at(0);
		P_.at(1)+=C_->get_Phenotype().at(1);
		P_.at(2)+=C_->get_Phenotype().at(2);
		C_->Phenotype.at(0) = 0;
		C_->Phenotype.at(1) = 0;
		C_->Phenotype.at(2) = 0;
		alive = false;
	}
	return alive;
}

bool Gap::Mutation_test(){
	double n = 0;
	bool mutation = false;
	n = (double)rand() / (double)RAND_MAX;
	if(n < C_->get_mutation_P()) {
		
		mutation = true;
	}
	return mutation;
}