/******************************************************************************
 *	Copyright (C) 2018	Ganímedes Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	/* isalpha() */
#include <ctype.h>
	/* M_PI & M_E */
#include <math.h>
	/* printf() & fgets() & sscanf()*/
#include <stdio.h>
	/* exit() */
#include <stdlib.h>

#include "calc.h"

#include "input.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
# define	BUFF_SIZE	(1024)


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
void	input	(double *a, int *sel, double *b)
{
	*a	= input_num();
	*sel	= input_operator();
	*b	= input_num();
	next_op	= INPUT_A;
}


double input_num (void)
{
	char	str [BUFF_SIZE];
	char	num [10];
	double	x;

	x	= 0;

	fgets(str, BUFF_SIZE, stdin);
	sscanf(str, " %c", &num[0]);

	if (isalpha(num[0])) {
		sscanf(str, " %*c%c", &num[1]);
		sscanf(str, " %*2c%c", &num[2]);
		sscanf(str, " %*3c%c", &num[3]);
		sscanf(str, " %*4c%c", &num[4]);
		sscanf(str, " %*5c%c", &num[5]);
		sscanf(str, " %*6c%c", &num[6]);

		switch (num[0]) {
		case 'e':
			if (isalpha(num[1]) || isdigit(num[1])) {
				x	= 0;
				printf("error\n");
			} else {
				x	= M_E;
			}
			break;
		case 'p':
			switch (num[1]) {
			case 'i':
				if (isalpha(num[2]) || isdigit(num[2])) {
					x	= 0;
					printf("error\n");
				} else {
					x	= M_PI;
				}
				break;
			default:
				x	= 0;
				printf("error\n");
				break;
			}
		}
	} else if (isdigit(num[0])) {
		sscanf(str, " %lf ", &x);
	} else {
		printf("error\n");
	}

	return	x;
}

int input_operator (void)
{
	char	str [BUFF_SIZE];
	char	sel_ch [9];
	int	sel;

	fgets(str, BUFF_SIZE, stdin);
	sel_ch[0]	= '\0';
	sel_ch[1]	= '\0';
	sscanf(str, " %c", &sel_ch[0]);
	sscanf(str, " %*c%c", &sel_ch[1]);

	sel	= 0;
	switch (sel_ch[0]) {
	case '+':
		sel	= OPERATION_SUM;
		break;
	case '-':
		sel	= OPERATION_SUB;
		break;
	case '/':
		sel	= OPERATION_DIV;
		break;
	case '*':
		sel	= OPERATION_MULT;
		break;
	case 's':
		switch (sel_ch[1]) {
		case 'q':
			sel	= OPERATION_SQRT;
			break;
		case 'i':
			sel	= OPERATION_SIN;
			break;
		default:
			sel	= OPERATION_FOO;
			printf("error\n");
			exit(EXIT_FAILURE);
			break;
		}
		break;
	case '^':
		sel	= OPERATION_POW;
		break;
	case 'e':
		sel	= OPERATION_EXP;
		break;
	case 'E':
		sel	= OPERATION_POW10;
		break;
	case 'c':
		sel	= OPERATION_COS;
		break;
	case 't':
		sel	= OPERATION_TAN;
		break;
	case 'a':
		switch (sel_ch[1]) {
		case 's':
			sel	= OPERATION_ASIN;
			break;
		case 'c':
			sel	= OPERATION_ACOS;
			break;
		case 't':
			sel	= OPERATION_ATAN;
			break;
		default:
			sel	= OPERATION_FOO;
			printf("error\n");
			exit(EXIT_FAILURE);
			break;
		}
		break;
	case 'C':
		sel	= OPERATION_CLEAR;
		break;
	case 'x':
		sel	= OPERATION_QUIT;
		break;
	default:
		sel	= OPERATION_FOO;
		printf("error\n");
		exit(EXIT_FAILURE);
		break;
	}

	return	sel;
}

double input_b (int sel)
{
	char	str [BUFF_SIZE];
	double	b;

	b	= 0;

	switch (sel) {
	case OPERATION_SUM:
	case OPERATION_SUB:
	case OPERATION_DIV:
	case OPERATION_MULT:
	case OPERATION_POW:
	case OPERATION_POW10:
		fgets(str, BUFF_SIZE, stdin);
		sscanf(str, " %lf ", &b);
		break;

	case OPERATION_SQRT:
	case OPERATION_EXP:
	case OPERATION_SIN:
	case OPERATION_COS:
	case OPERATION_TAN:
	case OPERATION_ASIN:
	case OPERATION_ACOS:
	case OPERATION_ATAN:

	case OPERATION_CLEAR:
	case OPERATION_QUIT:
		b	= 0;
		break;
	}

	return	b;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
