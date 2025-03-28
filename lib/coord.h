// BWH Chemistry Library for ANSI C - LibChem
// Released under the GNU LGPL

// libCoordinates Header
// Data types for libCoordinates

#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	double z;
} coord_cart;

typedef struct {
	double r;
	double theta;
	double phi;
} coord_polar;