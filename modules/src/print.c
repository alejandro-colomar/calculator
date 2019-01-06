/******************************************************************************
 *	Copyright (C) 2018	Ganímedes Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	/* printf() & fgets() & sscanf()*/
#include <stdio.h>

#include "calc.h"

#include "print.h"


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
void print_results (double ans, char sel)
{
	switch (sel) {
	case OPERATION_SUM:
	case OPERATION_SUB:
	case OPERATION_DIV:
	case OPERATION_MULT:
	case OPERATION_SQRT:
	case OPERATION_POW:
	case OPERATION_EXP:
	case OPERATION_POW10:
	case OPERATION_SIN:
	case OPERATION_COS:
	case OPERATION_TAN:
	case OPERATION_ASIN:
	case OPERATION_ACOS:
	case OPERATION_ATAN:
		printf("= %.2lf\n", ans);
		break;
	case OPERATION_CLEAR:
		printf("CLEAR\n");
		break;
	case OPERATION_QUIT:
		printf("QUIT\n");
		break;
	}
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
