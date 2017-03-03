//==============================
//    INCLUDES
//==============================
#include "Environment.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Environment::Environment(){
	T_ = 1000;
   Gap **themap = new Gap*[H_];
   for (int i = 0; i < H_; i++){
      themap[i] = new Gap[W_];
   }

   // utiliser tableau2D...
	cout << "I have created an Environment" << endl;
}
//==============================
//    DESTRUCTOR
//==============================

//==============================
//    PUBLIC METHODS
//==============================
