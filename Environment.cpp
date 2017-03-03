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
      	if (comptA_ < Max_ && comptB_ < Max_){
      		themap[i][j].Set_Gap(i,j,randbool);
      		if (randbool == true){
      			comptA_++;
      			cout << "CellA " << comptA_ << endl;
      		} else {
      			comptB_++;
      			cout << "CellB " << comptB_ << endl;
      		}
      	} else if (comptA_ >= Max_){
      		themap[i][j].Set_Gap(i,j,false);
      		comptB_++;
      		cout << "CellB " << comptB_ << endl;
      	} else {
      		themap[i][j].Set_Gap(i,j,true);
      		comptA_++;
      		cout << "CellA " << comptA_ << endl;
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
