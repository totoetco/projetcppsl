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
#include <time.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[]){
	srand(time(NULL));
	Environment* env1 = new Environment(35.5, 1000.0);
	env1->Run();
	return 0;
}
