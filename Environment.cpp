//==============================
//    INCLUDES
//==============================
#include "Environment.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <cassert>
#include <vector>
using std::cout;
using std::endl;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Environment::Environment(float Ainit, float T){
   srand(time(NULL));
   T_ = T;
   A_init = Ainit;
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
            themap[i][j].P_.push_back(A_init);
            themap[i][j].Set_Gap(i,j,randbool);
            if (randbool == true){
               comptA_++;
            } else {
               comptB_++;
            }
         } else if (comptA_ >= Max_){
            themap[i][j].P_.push_back(A_init);
            themap[i][j].Set_Gap(i,j,false);
            comptB_++;
         } else {
            themap[i][j].P_.push_back(A_init);
            themap[i][j].Set_Gap(i,j,true);
            comptA_++;
         }
      }  
   }
}

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
      		} else {
      			comptB_++;
      		}
      	} else if (comptA_ >= Max_){
      		themap[i][j].Set_Gap(i,j,false);
      		comptB_++;
      	} else {
      		themap[i][j].Set_Gap(i,j,true);
      		comptA_++;
      	}
      }	
   }
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
		}
	}
	themap[x][y].P_.at(0)=A-9*D_*themap[x][y].P_.at(0);
	themap[x][y].P_.at(1)=B-9*D_*themap[x][y].P_.at(1);
	themap[x][y].P_.at(2)=C-9*D_*themap[x][y].P_.at(2);
}

void Environment::Run(){
    freopen("output.txt","w",stdout);
	int T = 0;
	float ratiocell = 0;
	for(int t=0;t<t_sim;t++){
		if(T<T_){
			for(int i=0;i<W_-1;i++){
				for(int j=0;j<H_-1;j++){
					Diffusion(i,j);
				}
			}
			Division();
         Mutation();
			for(int i=0;i<W_-1;i++){
				for(int j=0;j<H_-1;j++){
					if(themap[i][j].C_->isA){
						themap[i][j].C_->Metabolic_Network(themap[i][j].P_.at(0));
					}
					else{
						themap[i][j].C_->Metabolic_Network(themap[i][j].P_.at(1));
					}
				}
			}
			//if(t%20==0) Display();
			T+=1;
		} else {
			clear_Env();
			T=0;
		}
	}

	for(int i=0;i<W_-1;i++){
				for(int j=0;j<H_-1;j++){
					if(themap[i][j].C_->isA){
						ratiocell = ratiocell + 1;
					}
				}
	}

	ratiocell = ratiocell/1024; //percentage of A cell at the end of simulation.
	cout << "T - value" << "," << "A_init" << ","<< "ratiocellfinal" << endl;
    cout << T_ << "," << A_init << ","<< ratiocell << endl;
    fclose (stdout);
} 

void Environment::Division(){
   int x_ref=0;
   int y_ref=0;
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

   for(int i = 0; i < x_empty.size(); i++){
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
                if(themap[k][l].C_->Fitness>=fit_ref){
                  fit_ref = themap[k][l].C_->Fitness;
                  x_ref = k;
                  y_ref = l;
               }
            }
            assert(themap[x_empty.at(i)][y_empty.at(i)].C_ != NULL);
            delete themap[x_empty.at(i)][y_empty.at(i)].C_;
            assert(themap[x_ref][y_ref].C_ != NULL);
            if(themap[x_ref][y_ref].C_->isA){
				  Cell_A* cell = new Cell_A();
				  themap[x_empty.at(i)][y_empty.at(i)].C_ = cell;
			   }else{
				  Cell_B* cell = new Cell_B();
				  themap[x_empty.at(i)][y_empty.at(i)].C_ = cell;
			   }

            themap[x_empty.at(i)][y_empty.at(i)].C_->Phenotype.at(0) = themap[x_ref][y_ref].C_->Phenotype.at(0)/2;
            themap[x_empty.at(i)][y_empty.at(i)].C_->Phenotype.at(1) = themap[x_ref][y_ref].C_->Phenotype.at(1)/2;
            themap[x_empty.at(i)][y_empty.at(i)].C_->Phenotype.at(2) = themap[x_ref][y_ref].C_->Phenotype.at(2)/2;

            themap[x_ref][y_ref].C_->Phenotype.at(0) = themap[x_ref][y_ref].C_->Phenotype.at(0)/2;
            themap[x_ref][y_ref].C_->Phenotype.at(1) = themap[x_ref][y_ref].C_->Phenotype.at(1)/2;
            themap[x_ref][y_ref].C_->Phenotype.at(2) = themap[x_ref][y_ref].C_->Phenotype.at(2)/2;          
            
         }
      }
   }
   x_empty.clear();
   y_empty.clear();
}

void Environment::Mutation(){
   for(int i = 0; i <= H_-1; i++){
      for(int j = 0; j<= W_-1; j++){
         if(themap[i][j].Mutation_test() == true){
            vector<float> meta = themap[i][j].C_-> Phenotype;
            if(themap[i][j].C_->isA){
              delete themap[i][j].C_;
              Cell_B* cell = new Cell_B();
              themap[i][j].C_ = cell;
              themap[i][j].C_->Phenotype = meta;
            }else{
              delete themap[i][j].C_;
              Cell_A* cell = new Cell_A();
              themap[i][j].C_ = cell;
              themap[i][j].C_->Phenotype = meta;
            }
         }
      }
   }
}

void Environment::clear_Env(){
	for(int i = 0; i <= (W_-1); i++){
      for(int j = 0; j <= (H_-1); j++){	
			themap[i][j].P_.at(0)= A_init;
			themap[i][j].P_.at(1)=0;
			themap[i][j].P_.at(2)=0;
			themap[i][j].C_->Phenotype.at(0)=0;
			themap[i][j].C_->Phenotype.at(1)=0;
			themap[i][j].C_->Phenotype.at(2)=0;
		}
	}
}


void Environment::Display(){
	std::system("clear");
	for(int i = 0; i <= (W_-1); i++){
      for(int j = 0; j <= (H_-1); j++){
      	if(themap[i][j].C_->isA == true){
      		cout << BOLDRED << "A " << RESET;
      	} else {
      		cout << BOLDBLUE << "B " << RESET;
      	}
      }
      cout << "" << endl;
    }
}
