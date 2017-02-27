#ifndef CELL_H
#define CELL_H 

//==============================
//    INCLUDES
//==============================


/**
 * @class Cell
 * @brief Creates a Cell
 */

class Cell{
	
public:
//==============================
//    CONSTRUCTORS
//==============================
Cell();
//==============================
//    DESTRUCTOR
//==============================
virtual ~Cell();
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

protected:
//==============================
//    PROTECTED METHODS
//==============================
virtual float Metabolic_Network(float i) = 0;
//==============================
//    ATTRIBUTES
//==============================
float* Phenotype;
float Fitness;
static float W_min;
static float death_Probability;
static float mutation_Probability;
};

//==============================
//    GETTER DEFINITION
//==============================
inline float Cell::get_death_P() const{
  return death_Probability;
}

inline float Cell::get_mutation_P() const{
  return mutation_Probability;
}

inline float* Cell::get_Phenotype() const{
  return Phenotype;
}

//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // CELL_H
