// BWH Chemistry Library for ANSIC - LibChem
// Released under the GNU LGPL

// libQMFoundation
// Functions related to basic quantum mechanics

#include <stdio.h>
#include <math.h>

// LibChem Constants
#include "chmconst.h"

// Output value
double res;

double energyEinstein(char out, double a, double b)
{
	// E = m * C^2

	if (out == 'e')
	{
		// a = m
		res = a * (LIGHT_SPEED * LIGHT_SPEED);
	}
	else if (out == 'm')
	{
		// a = E
		res = a / (LIGHT_SPEED * LIGHT_SPEED);
	}
	else if (out == 'c')
	{
		// a = E; b = m
		res = sqrt(a / b);
	}
	else
	{
		libError("libQMFoundation", "energyEinstein", "Unidentified output request character");
	}
	return res;
}

double lightWaveFreq(char out, double a, double b)
{
	// c = [lambda] * [nu]

	if (out == 'l' || out == 'n')
	{
		// FOR l: a = [nu]
		// FOR n: a = [lambda]
		res = LIGHT_SPEED / a;
	}
	else if (out == 'c')
	{
		// a = [lambda]; b = [nu]
		res = a * b;
	}
	else
	{
		libError("libQMFoundation", "lightWaveFreq", "Unidentified output request character");
	}
	return res;
}

double energyQuantum(char out, double a, double b)
{
	// E = h * [nu]
	if (out == 'e')
	{
		// a = [nu]
		res = PLANCK * a;
	}
	else if (out == 'n')
	{
		// a = E
		res = a / PLANCK;
	}
	else if (out == 'h')
	{
		// a = E; b = [nu]
		// TO DO: NULL CHECK
		res = a / b;
	}
	else
	{
		libError("libQMFoundation", "energyQuantum", "Unidentified output request character");
	}
	return res;
}
