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
using namespace std;

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[]){

	Gap* gap1 = new Gap(1,2,true);
	cout << "I have created a Gap" << endl;


	return 0;
}