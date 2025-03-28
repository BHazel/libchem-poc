// BWH Chemistry Library for ANSI C - LibChem
// Released under the GNU LGPL

// libCoordinates
// Functions related to Cartesian and Spherical Polar coordinates

#include <stdio.h>
#include <math.h>

#include "coord.h"

coord_cart res_coordCart;
coord_polar res_coordPolar;

coord_cart coordCartAlloc(double a, double b, double c)
{
	// Assign Cartesian coordinate struct
	res_coordCart.x = a;
	res_coordCart.y = b;
	res_coordCart.z = c;
	return res_coordCart;
}

coord_polar coordPolarAlloc(double a, double b, double c)
{
	// Assign polar coordinate struct
	res_coordPolar.r = a;
	res_coordPolar.theta = b;
	res_coordPolar.phi = c;
	return res_coordPolar;
}

void coordCartDealloc(coord_cart *a)
{
	// Set Cartesian coordinates to (0,0,0)
	(*a).x = 0;
	(*a).y = 0;
	(*a).z = 0;
}

void coordPolarDealloc(coord_polar *a)
{
	// Set Polar coordinates to (0,0,0)
	(*a).r = 0;
	(*a).theta = 0;
	(*a).phi = 0;
}

void coordCartDeallocToVar(coord_cart *a, double *b, double *c, double *d)
{
	// Set 3 double variables to Cartesian coordinates
	// and set struct coordinates (0,0,0)
	*b = (*a).x;
	*c = (*a).y;
	*d = (*a).z;
	(*a).x = 0;
	(*a).y = 0;
	(*a).z = 0;
}

void coordPolarDeallocToVar(coord_polar *a, double *b, double *c, double *d)
{
	// Set 3 double variables to Polar coordinates
	// and set struct coordinates to (0,0,0)
	*b = (*a).r;
	*c = (*a).theta;
	*d = (*a).phi;
	(*a).r = 0;
	(*a).theta = 0;
	(*a).phi = 0;
}

coord_cart convertPolarToCart(coord_polar a)
{
	res_coordCart.x = a.r * sin(a.theta) * cos(a.phi);
	res_coordCart.y = a.r * sin(a.theta) * sin(a.phi);
	res_coordCart.z = a.r * cos(a.theta);
	return res_coordCart;
}
