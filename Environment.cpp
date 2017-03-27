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
			if((i<0)||(i>W_-1)||(j<0)||(j>H_-1)){
				if((i<0)&&(j<0)){
					A+=themap[i+W_][j+H_].P_.at(0);
					B+=themap[i+W_][j+H_].P_.at(1);
					C+=themap[i+W_][j+H_].P_.at(2);
				} else if((i<0)&&(j>(H_-1))){
					A+=themap[i+W_][j-H_].P_.at(0);
					B+=themap[i+W_][j-H_].P_.at(1);
					C+=themap[i+W_][j-H_].P_.at(2);
				} else if((i>(W_-1))&&(j<0)){
					A+=themap[i-W_][j+H_].P_.at(0);
					B+=themap[i-W_][j+H_].P_.at(1);
					C+=themap[i-W_][j+H_].P_.at(2);
				} else if((i>(W_-1))&&(j>(H_-1))){
					A+=themap[i-W_][j-H_].P_.at(0);
					B+=themap[i-W_][j-H_].P_.at(1);
					C+=themap[i-W_][j-H_].P_.at(2);
				} else if(i<0){
					A+=themap[i+W_][j].P_.at(0);
					B+=themap[i+W_][j].P_.at(1);
					C+=themap[i+W_][j].P_.at(2);
				} else if(i>(W_-1)){
					A+=themap[i-W_][j].P_.at(0);
					B+=themap[i-W_][j].P_.at(1);
					C+=themap[i-W_][j].P_.at(2);
				} else if(j<0){
					A+=themap[i][j+H_].P_.at(0);
					B+=themap[i][j+H_].P_.at(1);
					C+=themap[i][j+H_].P_.at(2);
				} else if(j>(H_-1)){
					A+=themap[i][j-H_].P_.at(0);
					B+=themap[i][j-H_].P_.at(1);
					C+=themap[i][j-H_].P_.at(2);
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
	for(int i=0;i<W_-1;i++){
		for(int j=0;j<H_-1;j++){
			Diffusion(i,j);
			themap[i][j].Death_test();
		}
	}
} 
void Environment::Division(){
   int x_ref,y_ref;
   int fit_ref=0;
   vector<int> x_empty,y_empty;
   for(int i = 0; i <= (W_-1); i++){
      for(int j = 0; j <= (H_-1); j++){
         if(themap[i][j].Death_test() == false){
            x_empty.push_back(i);
            y_empty.push_back(j);
         }
      }
   }

   for(int i = 0; i <= x_empty.size(); i++){
      for(int k=x_empty.at(i)-1;k<=x_empty.at(i)+1;k++){ // To be replaced by a random selection
         for(int l=y_empty.at(i)-1;l<=y_empty.at(i)+1;l++){
            if(k<0 && l<0){
               if(themap[k+W_][l+H_].C_->Fitness>fit_ref){
                  fit_ref = themap[k+W_][l+H_].C_->Fitness;
                  x_ref = k+W_;
                  y_ref = l+H_;
               }
            } else if((k<0)&&(l>(H_-1))){
               if(themap[k+W_][l-H_].C_->Fitness>fit_ref){
                  fit_ref = themap[k+W_][l-H_].C_->Fitness;
                  x_ref = k+W_;
                  y_ref = l-H_;
               }
            } else if((k>(W_-1))&&(l<0)){
               if(themap[k-W_][l+H_].C_->Fitness>fit_ref){
                  fit_ref = themap[k-W_][l+H_].C_->Fitness;
                  x_ref = k-W_;
                  y_ref = l+H_;
               }
            } else if((k>(W_-1))&&(l>(H_-1))){
               if(themap[k-W_][l-H_].C_->Fitness>fit_ref){
                  fit_ref = themap[k-W_][l-H_].C_->Fitness;
                  x_ref = k-W_;
                  y_ref = l-H_;
               }
            } else if(k<0){
               if(themap[k+W_][l].C_->Fitness>fit_ref){
                  fit_ref = themap[k+W_][l].C_->Fitness;
                  x_ref = k+W_;
                  y_ref = l;
               }
            } else if(k>(W_-1)){
               if(themap[k-W_][l].C_->Fitness>fit_ref){
                  fit_ref = themap[k-W_][l].C_->Fitness;
                  x_ref = k-W_;
                  y_ref = l;
               }
            } else if(l<0){
               if(themap[k][l+H_].C_->Fitness>fit_ref){
                  fit_ref = themap[k][l+H_].C_->Fitness;
                  x_ref = k;
                  y_ref = l+H_;
               }
            } else if(l>(H_-1)){
               if(themap[k][l-H_].C_->Fitness>fit_ref){
                  fit_ref = themap[k][l-H_].C_->Fitness;
                  x_ref = k;
                  y_ref = l-H_;
               }
            } else {
                if(themap[k][l].C_->Fitness>fit_ref){
                  fit_ref = themap[k][l].C_->Fitness;
                  x_ref = k;
                  y_ref = l;
               }
            }

            themap[x_empty.at(i)][y_empty.at(i)].C_->Phenotype.at(0) = themap[x_ref][y_ref].C_->Phenotype.at(0)/2;
            themap[x_empty.at(i)][y_empty.at(i)].C_->Phenotype.at(0) = themap[x_ref][y_ref].C_->Phenotype.at(1)/2;
            themap[x_empty.at(i)][y_empty.at(i)].C_->Phenotype.at(0) = themap[x_ref][y_ref].C_->Phenotype.at(2)/2;

            themap[x_ref][y_ref].C_->Phenotype.at(0) = themap[x_ref][y_ref].C_->Phenotype.at(0)/2;
            themap[x_ref][y_ref].C_->Phenotype.at(1) = themap[x_ref][y_ref].C_->Phenotype.at(1)/2;
            themap[x_ref][y_ref].C_->Phenotype.at(2) = themap[x_ref][y_ref].C_->Phenotype.at(2)/2;
         }
      }
   }
}

void Environment::Display(Gap **plotmap_){
	for(int i = 0; i <= (W_-1); i++){
      for(int j = 0; j <= (H_-1); j++){
      	if(plotmap_[i][j].C_->isA == true){
      		cout << BOLDRED << A << RESET;
      	} else {
      		cout << BOLDBLUE << B << RESET;
      	}
      }
      cout << " " << endl;
    }
}