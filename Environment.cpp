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
	D_ = 0.1;
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
void Environment::Diffusion(int x, int y){
	float A=themap[x][y].P_[0];
	float B=themap[x][y].P_[1];
	float C=themap[x][y].P_[2];
	for(int i=(x-1);i<=(x+1);i++){
		for(int j=(y-1);j<=(y+1);j++){
			A+=themap[i][j].P_[0];
			B+=themap[i][j].P_[1];
			C+=themap[i][j].P_[2];
		}
	}
	themap[x][y].P_[0]=A-9*D_*themap[x][y].P_[0];
	themap[x][y].P_[1]=B-9*D_*themap[x][y].P_[1];
	themap[x][y].P_[2]=C-9*D_*themap[x][y].P_[2];
}
