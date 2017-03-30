//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Environment.h"
#include "Gap.h"
#include "Cell.h"
#include "Cell_A.h"
#include "Cell_B.h"
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::endl;

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[]){
	freopen("output.txt","w",stdout);
	cout << "T - value" << "," << "A_init" << ","<< "ratiocellfinal" << endl;
	srand(time(NULL));
	for (int Tvalue = 1; Tvalue < 1500; Tvalue+= 500){
   		for (int Ainitvalue = 0; Ainitvalue < 50; Ainitvalue+=20){
			Environment* env1 = new Environment(Ainitvalue, Tvalue);
			env1->Run();
		}
	}	
	cout << "\n" << endl;
	fclose (stdout);
	return 0;
}
