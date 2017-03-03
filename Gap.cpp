//==============================
//    INCLUDES
//==============================
#include "Gap.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
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
	float P_[3] = {A_init,0.0,0.0};
	if(is_A){
		Cell_A* cell = new Cell_A();
		C_ = cell;
	}else{
		Cell_B* cell = new Cell_B();
		C_ = cell;
	}
}

void Gap::Death_test(){
	float n = 0;
	srand(time(NULL));
	n = (float)rand() / 1.0;
	if(n<C_->get_death_P()) {
		P_[0]+=C_->get_Phenotype()[0];
		P_[1]+=C_->get_Phenotype()[1];
		P_[2]+=C_->get_Phenotype()[2];
	}
	
}
