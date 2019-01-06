#include <stdio.h>
#include <stdlib.h>

# define	BUFF_SIZE	(1024)

void print_results (double res, int sel);

int main (int argc, char *argv[])
{
	double	a;
	double	b;
	double	res;
	char	str [BUFF_SIZE];
	int	sel;

	a = 0;
	b = 0;
	sel = 0;
	
	printf("introduce la operación a realizar y pulsa ENTER\n");
	printf("1	suma\n2	resta\n3	división\n4	multiplicación\n");

	fgets(str, BUFF_SIZE, stdin);
	sscanf(str, " %i ", &sel);

	if (sel < 1 || sel > 4) {
		printf("error\n");
		exit(EXIT_FAILURE);
	}

	printf("introduce los valores a y b, separados por espacios y pulsa ENTER\n");

	fgets(str, BUFF_SIZE, stdin);
	sscanf(str, " %lf %lf ", &a, &b);

	switch (sel) {
	case 1:
		res	= a + b;
		break;

	case 2:
		res	= a - b;
		break;

	case 3:
		res	= a / b;
		break;

	case 4:
		res	= a * b;
		break;
	}

	print_results(res, sel);

	return	0;
}

void print_results (double res, int sel)
{
	switch (sel) {
	case 1:
		printf("la suma es %08.2lf\n", res);
		break;

	case 2:
		printf("la resta es %08.2lf\n", res);
		break;

	case 3:
		printf("el cociente es %08.2lf\n", res);
		break;

	case 4:
		printf("el producto es %08.2lf\n", res);
		break;
	}

}
