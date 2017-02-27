#ifndef GAP_H
#define GAP_H 

//==============================
//    INCLUDES
//==============================
#include "Cell.h"
#include "Cell_A.h"
#include "Cell_B.h"

/**
 * @class Gap
 * @brief Creates a Gap
 */

class Gap{
	
public:
//==============================
//    CONSTRUCTORS
//==============================
Gap(int x,int y, bool is_A);

//==============================
//    DESTRUCTOR
//==============================

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
//void Cell_update();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
float A_init;
static float D_;
float* P_;
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
