//==============================
//    INCLUDES
//==============================
#include "Environment.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Environment::Environment(){
	srand(time(NULL));
	T_ = 1000;
	int Max_ = (W_ * H_)/2;
	int comptA_ = 0;
	int comptB_ = 0;
   Gap **themap = new Gap*[H_];
   for (int i = 0; i < H_; i++){
      themap[i] = new Gap[W_];
      for (int j = 0; j < W_; j++){
      	bool randbool = rand() & 1;
      	if (comptA_ <= Max_ && comptB_ <= Max_){
      		themap[i][j].Set_Gap(i,j,randbool);
      	} else if (comptA_ == Max_){
      		themap[i][j].Set_Gap(i,j,false);
      	} else {
      		themap[i][j].Set_Gap(i,j,true);
      	}
      }	
   }


	cout << "I have created an Environment" << endl;
}
//==============================
//    DESTRUCTOR
//==============================
Environment::~Environment(){
for (int i = 0; i < H_; i++){
	delete[] themap[i];
}
delete[] themap;
}
//==============================
//    PUBLIC METHODS
//==============================
