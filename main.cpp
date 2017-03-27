//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>

#include "Environment.h"
#include "Gap.h"
#include "Cell.h"
#include "Cell_A.h"
#include "Cell_B.h"

#include <iostream>
using std::cout;
using std::endl;

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[]){
	Environment* env1 = new Environment();
	env1->Run();
	return 0;
}
