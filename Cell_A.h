#ifndef CELL_A_H
#define CELL_A_H 

//==============================
//    INCLUDES
//==============================
#include "Cell.h"

/**
 * @class Cell_A
 * @brief Creates a Cell_A
 */

class Cell_A : public Cell
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Cell_A();

//==============================
//    DESTRUCTOR
//==============================
virtual ~Cell_A();
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
virtual float Metabolic_Network(float A_out);

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
float RAA_;
float RAB_;

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


#endif // CELL_A_H
