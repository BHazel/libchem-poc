#include <stdio.h>
#include <math.h>

#include "libchem.h"

int i;
double result;

double x, y, z;

coord_cart resCart;

int main()
{
	printf("QUANTUM ENERGY:\n");
	for (i = 1; i <= 10; i++)
	{
		result = energyQuantum('e',i,0);
		printf("E = h * %d /s = %.3e J\n", i, result);
	}
	printf("\nEINSTEIN ENERGY:\n");
	for (i = 1; i <= 10; i++)
	{
		result = energyEinstein('m',i,0);
		printf("m = %d J / C^2 = %.3e kg\n", i, result);
	}
	printf("\nLIGHT WAVELENGTH:\n");
	for (i = 1; i <= 10; i++)
	{
		result = lightWaveFreq('l',i,0);
		printf("[l] = C / %d /s = %.3e m\n", i, result);
	}
	printf("\nCARTESIAN COORDINATES:\n");
	resCart = coordCartAlloc(1.0, 2.0, 3.0);
	printf("x = %.2f\ny = %.2f\nz = %.2f", resCart.x, resCart.y, resCart.z);
	printf("\n- Deallocate to Variables:");
	coordCartDeallocToVar(&resCart, &x, &y, &z);
	printf("\nStruct:\nx = %.2f\ny = %.2f\nz = %.2f", resCart.x, resCart.y, resCart.z);
	printf("\nDouble Variables:\nx = %.2f\ny = %.2f\nz = %.2f", x, y, z);
	printf("\n\nERROR CHECK:\n");
	result = energyQuantum('a',10,0);
	return 0;
}
