/******************************************************************************
 *	Copyright (C) 2018	Ganímedes Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <math.h>
	/* bool */
#include <stdbool.h>

#include "input.h"
#include "print.h"

#include "calc.h"


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
void calc_loop (void)
{
	double	a;
	double	b;
	double	ans;
	int	sel;
	bool	clr;

	clr	= true;

	do {
		if (clr) {
			a	= input_a();
			clr	= false;
		}

		sel	= input_operator();

		b	= input_b(sel);

		ans	= calc_results(a, b, sel, &clr);
		print_results(ans, sel);

		a	= ans;
	} while (sel != OPERATION_QUIT);
}

double calc_results (double a, double b, char sel, bool *clr)
{
	double	ans;

	switch (sel) {
	case OPERATION_SUM:
		ans	= a + b;
		break;

	case OPERATION_SUB:
		ans	= a - b;
		break;

	case OPERATION_DIV:
		ans	= a / b;
		break;

	case OPERATION_MULT:
		ans	= a * b;
		break;

	case OPERATION_SQRT:
		ans	= sqrt(a);
		break;

	case OPERATION_POW:
		ans	= pow(a, b);
		break;

	case OPERATION_EXP:
		ans	= exp(a);
		break;

	case OPERATION_POW10:
		ans	= a * pow(10, b);
		break;

	case OPERATION_SIN:
		ans	= sin(a);
		break;

	case OPERATION_COS:
		ans	= cos(a);
		break;

	case OPERATION_TAN:
		ans	= tan(a);
		break;

	case OPERATION_ASIN:
		ans	= asin(a);
		break;

	case OPERATION_ACOS:
		ans	= acos(a);
		break;

	case OPERATION_ATAN:
		ans	= atan(a);
		break;

	case OPERATION_CLEAR:
		*clr	= true;
		ans	= 0;
		break;
	}

	return	ans;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
