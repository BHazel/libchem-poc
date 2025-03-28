// BWH Chemistry Library for ANSI C - LibChem
// Released under the GNU LGPL

// libGases
// Functions related to gases, both perfect and real

#include <stdio.h>
#include <math.h>

#include "chmconst.h"

// Output value
double res;

double gasPerfect(char out, double a, double b, double c, double d)
{
	// pV = nRT

	if (out == 'p' || out == 'v')
	{
		// FOR p: a = n; b = T; c = V
		// FOR v: a = n; b = T; c = p
		res = (a * MOLAR_GAS * b) / c;
	}
	else if (out == 'n' || out == 't')
	{
		// FOR n: a = p; b = V; c = T
		// FOR t: a = p; b = V; c = n
		res = (a * b) / (c * MOLAR_GAS);
	}
	else if (out == 'r')
	{
		// a = p; b = V; c = n; d = T
		res = (a * b) / (c * d);
	}
	else
	{
		libError("libGases", "gasPerfect", "Unidentified output request character");
	}
	return res;
}

	