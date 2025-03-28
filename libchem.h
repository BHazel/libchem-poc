// BWH Chemistry Library for ANSI C = LibChem
// Released under the GNU LGPL

// libChem Header
// Declares all libChem functions

// Additional libChem Header Files
#include "src/coord.h"		// libCoordinates Data Types

// libChem Workflow Functions
void libError(char libraryName[], char functionName[], char errorText[]);

// libCoordinates Functions
coord_cart coordCartAlloc(double a, double b, double c);
coord_polar coordPolarAlloc(double a, double b, double c);
void coordCartDealloc(coord_cart *a);
void coordPolarDealloc(coord_polar *a);
void coordCartDeallocToVar(coord_cart *a, double *b, double *c, double *d);
void coordPolarDellocToVar(coord_polar *a, double *b, double *c, double *d);
coord_cart convertPolarToCart(coord_polar a);

// libFoundation Functions
double forceMassAccel(char out, double a, double b);
double workForceDist(char out, double a, double b);
double energyKinetic(char out, double a, double b);
double energyPotentialGrav(char out, double a, double b, double c);
double energyTotal(char out, double a, double b);
double presForceArea(char out, double a, double b);
double presDensityHeight(char out, double a, double b, double c);
double densityMassVolume(char out, double a, double b);

// libQMFoundation Functions
double energyEinstein(char out, double a, double b);
double lightWaveFreq(char out, double a, double b);
double energyQuantum(char out, double a, double b);

// libGas Functions
double gasPerfect(char out, double a, double b, double c, double d);