#ifndef GAP_H
#define GAP_H 

//==============================
//    INCLUDES
//==============================
#include "Cell.h"
#include "Cell_A.h"
#include "Cell_B.h"
#include <vector>
using namespace std;

/**
 * @class Gap
 * @brief Creates a Gap
 */

class Gap{
	
public:
//==============================
//    CONSTRUCTORS
//==============================
Gap();

//==============================
//    DESTRUCTOR
//==============================
~Gap();
//==============================
//    GETTERS
//==============================

//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
bool Death_test();
bool Mutation_test();
void Set_Gap(int x,int y, bool is_A);
friend class Environment;

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
float A_init;
static float D_;
vector<float> P_;
int x_coord;
int y_coord;
Cell* C_;

};

//==============================
//    GETTER DEFINITION
//==============================


//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // GAP_H
