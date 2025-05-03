// BWH Chemistry Library for ANSI C - LibChem
// Released under the GNU LGPL

// libFoundation
// Basic physical functions

#include <stdio.h>
#include <math.h>

#include "chmconst.h"

void libError(char libraryName[], char functionName[], char errorText[]);

// Output value
double res;

double forceMassAccel(char out, double a, double b)
{
	// F = ma

	if (out == 'f')
	{
		// a = m; b = a
		res = a * b;
	}
	else if (out == 'm' || out == 'a')
	{
		// FOR m: a = F; b = a
		// FOR a: a = F; b = m
		res = a / b;
	}
	else
	{
		libError("libFoundation", "forceMassAccel", "Unidentified output request character");
	}
	return res;
}

double workForceDist(char out, double a, double b)
{
	// w = Fd
	// TO DO: Check signs

	if (out == 'w')
	{
		// a = F; b = d
		res = a * b;
	}
	else if (out == 'f' || out == 'd')
	{
		// FOR f: a = w; b = d
		// FOR d: a = w; b = F
		res = a / b;
	}
	else
	{
		libError("libFoundation", "workForceDist", "Unidentified output request character");
	}
	return res;
}

double energyKinetic(char out, double a, double b)
{
	// E = 0.5 * mv^2

	if (out == 'e')
	{
		// a = m; b = v
		res = 0.5 * a * (b * b);
	}
	else if (out == 'm')
	{
		// a = E; b = v
		res = (2 * a) / (b * b);
	}
	else if (out == 'v')
	{
		// a = E; b = m
		res = sqrt((2 * a) / b);
	}
	else
	{
		libError("libFoundation", "energyKinetic", "Unidentified output request character");
	}
	return res;
}

double energyPotentialGrav(char out, double a, double b, double c)
{
	// E = mgh

	if (out == 'e')
	{
		// a = m; b = h
		res = a * FREE_FALL * b;
	}
	else if (out == 'm' || out == 'h')
	{
		// FOR m: a = E; b = h
		// FOR h: a = E; b = m
		res = a / (FREE_FALL * b);
	}
	else if (out == 'g')
	{
		// a = E; b = m; c = h
		res = a / (b * c);
	}
	else
	{
		libError("libFoundation", "energyPotentialGrav", "Unidentified output request character");
	}
	return res;
}

double energyTotal(char out, double a, double b)
{
	// E = E(k) + E(p)

	if (out == 't')
	{
		// a = E(k); b = E(p)
		res = a + b;
	}
	else if (out == 'k' || out == 'p')
	{
		// FOR k: a = E; b = E(p)
		// FOR p: a = E; b = E(k)
		res = a - b;
	}
	else
	{
		libError("libFoundation", "energyTotal", "Unidentified output request character");
	}
	return res;
}

double presForceArea(char out, double a, double b)
{
	// p = F / a

	if (out == 'p' || out == 'a')
	{
		// FOR p: a = F; b = a
		// FOR a: a = F; b = p
		res = a / b;
	}
	else if (out == 'f')
	{
		// a = p; b = a
		res = a * b;
	}
	else
	{
		libError("libFoundation", "presForceArea", "Unidentified output request character");
	}
	return res;
}

double presDensityHeight(char out, double a, double b, double c)
{
	// p = [rho] * g * h

	if (out == 'p')
	{
		// a = [rho]; b = h
		res = a * FREE_FALL * b;
	}
	else if (out == 'r' || out == 'h')
	{
		// FOR r: a = p; b = h
		// FOR h: a = p; b = [rho]
		res = a / (FREE_FALL * b);
	}
	else if (out == 'g')
	{
		// a = p; b = [rho]; c = h
		res = a / (b * c);
	}
	else
	{
		libError("libFoundation", "presDensityHeight", "Unidentified output request character");
	}
	return res;
}

double densityMassVolume(char out, double a, double b)
{
	// [rho] = m / V

	if (out == 'r'|| out == 'v')
	{
		// FOR r: a = m; b = V
		// FOR v: a = m; b = [rho]
		res = a / b;
	}
	else if (out == 'm')
	{
		// a = [rho]; b = V
		res = a * b;
	}
	else
	{
		libError("libFoundation", "densityMassVolume", "Unidentified output request character");
	}
	return res;
}
