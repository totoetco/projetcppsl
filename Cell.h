#ifndef CELL_H
#define CELL_H 

//==============================
//    INCLUDES
//==============================
#include <vector>
using namespace std;

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
inline float get_death_P() const;
inline float get_mutation_P() const;
inline vector<float> get_Phenotype() const;
friend class Gap;
protected:
//==============================
//    PROTECTED METHODS
//==============================
virtual float Metabolic_Network(float i) = 0;
//==============================
//    ATTRIBUTES
//==============================
vector<float> Phenotype;
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

inline vector<float> Cell::get_Phenotype() const{
  return Phenotype;
}

//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================


#endif // CELL_H
