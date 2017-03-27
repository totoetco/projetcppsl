//==============================
//    INCLUDES
//==============================
#include "Gap.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
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
	A_init=25.0;                                // Valeur comprise entre 0 et 50, à modifier
	//cout << "I have created a Gap" << endl;
	
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
	P_.push_back(A_init);
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
	float n = 0;
	bool alive = true;
	srand(time(NULL));
	n = (float)rand() / 1.0;
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
