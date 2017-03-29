#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H 

//==============================
//    INCLUDES
//==============================
#include "Gap.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDRED "\033[1m\033[31m"
#define RESET   "\033[0m"

/**
 * @class Environment
 * @brief Creates a Environment
 */

class Environment{
	
public:
//==============================
//    CONSTRUCTORS
//==============================
Environment();
//==============================
//    DESTRUCTOR
//==============================
~Environment();

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
void Diffusion(int x, int y);
void Division();
void Mutation();
void Run();
void Display();
void clear_Env();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
unsigned int T_;
const unsigned int t_sim = 10000;
const unsigned int W_ = 32;
const unsigned int H_ = 32;
float D_;
Gap **themap ;
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


#endif // ENVIRONMENT_H
