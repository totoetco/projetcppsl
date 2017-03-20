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
	int Max_ = (W_ * H_)/2.0;
	int comptA_ = 0;
	int comptB_ = 0;
   themap = new Gap*[H_];
   for (int i = 0; i < H_; i++){
      this->themap[i] = new Gap[W_];
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
void Environment::Diffusion(int x, int y){
	float A=themap[x][y].P_.at(0);
	float B=themap[x][y].P_.at(1);
	float C=themap[x][y].P_.at(2);
	for(int i=(x-1);i<=(x+1);i++){
		for(int j=(y-1);j<=(y+1);j++){
			if((i<0)||(i>(W_-1))||(j<0)||(j>(H_-1))){
				if(i<0){ 
					i+=W_;
					A+=themap[i][j].P_.at(0);
					B+=themap[i][j].P_.at(1);
					C+=themap[i][j].P_.at(2);
					i-=W_;
				}
				if(i>(W_-1)){ 
					i-=W_;
					A+=themap[i][j].P_.at(0);
					B+=themap[i][j].P_.at(1);
					C+=themap[i][j].P_.at(2);
					i+=W_;
				}
				if(j<0){ 
					j+=H_;
					A+=themap[i][j].P_.at(0);
					B+=themap[i][j].P_.at(1);
					C+=themap[i][j].P_.at(2);
					j-=H_;
				}
				if(j>(H_-1)){ 
					j-=H_;
					A+=themap[i][j].P_.at(0);
					B+=themap[i][j].P_.at(1);
					C+=themap[i][j].P_.at(2);
					j+=H_;
				}
			} else {
				A+=themap[i][j].P_.at(0);
				B+=themap[i][j].P_.at(1);
				C+=themap[i][j].P_.at(2);
			}
			cout << i << j << endl;
		}
	}
	themap[x][y].P_.at(0)=A-9*D_*themap[x][y].P_.at(0);
	themap[x][y].P_.at(1)=B-9*D_*themap[x][y].P_.at(1);
	themap[x][y].P_.at(2)=C-9*D_*themap[x][y].P_.at(2);
}

void Environment::Run(){
	for(int i=0;i<W_;i++){
		for(int j=0;i<H_;j++){
			Diffusion(i,j);
			themap[i][j].Death_test();
		}
	}
} 
void Environment::Division(){
	vector<int> x_empty,y_empty;
	for(int i = 0; i <= (W_-1); i++){
		for(int j = 0; j <= (H_-1); j++){
			if(themap[i][j].C_->Phenotype.at(0) == 0 && themap[i][j].C_->Phenotype.at(1) == 0 && themap[i][j].C_->Phenotype.at(2) == 0){

			}
		}
	}
}
