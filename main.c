/******************************************************************************
 *	Copyright (C) 2018	Ganímedes Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	/* isalpha() */
#include <ctype.h>
#include <math.h>
	/* bool */
#include <stdbool.h>
	/* printf() & fgets() & sscanf()*/
#include <stdio.h>
	/* exit() */
#include <stdlib.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
# define	BUFF_SIZE	(1024)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
enum	Operation {
	OPERATION_FOO,
	OPERATION_SUM,
	OPERATION_SUB,
	OPERATION_DIV,
	OPERATION_MULT,
	OPERATION_SQRT,
	OPERATION_POW,
	OPERATION_POW10,
	OPERATION_EXP,
	OPERATION_SIN,
	OPERATION_COS,
	OPERATION_TAN,
	OPERATION_ASIN,
	OPERATION_ACOS,
	OPERATION_ATAN,
	OPERATION_CLEAR,
	OPERATION_QUIT
};


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
void	calc_loop (void);
double	input_a (void);
int	input_operator (void);
double	input_b (int sel);
double	calc_results (double a, double b, char sel, bool *clr);
void	print_results (double ans, char sel);


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
int main (int argc, char *argv[])
{
	
	puts("BIENVENIDO A LA PUTA MEJOR CALCULADORA DEL MUNDO");

	calc_loop();

	return	0;
}


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
void calc_loop (void)
{
	double	a;
	double	b;
	double	ans;
	char	str [BUFF_SIZE];
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

double input_a (void)
{
	char	str [BUFF_SIZE];
	char	num [10];
	double	a;

	a	= 0;

	fgets(str, BUFF_SIZE, stdin);
	sscanf(str, " %c", &num[0]);
	sscanf(str, " %*c%c", &num[1]);
	sscanf(str, " %*2c%c", &num[2]);

	if (isalpha(num[0])) {
		switch (num[0]) {
		case 'e':
			if (isalpha(num[1])) {
				a	= 0;
				printf("error\n");
			} else {
				a	= M_E;
			}
		case 'p':
			switch (num[1]) {
			case 'i':
				if (isalpha(num[2])) {
					a	= 0;
					printf("error\n");
				} else {
					a	= M_PI;
				}
				break;
			default:
				a	= 0;
				printf("error\n");
				break;
			}
		}
	} else if (isdigit(num[0])) {
		sscanf(str, " %lf ", &a);
	} else {
		printf("error\n");
	}

	return	a;
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
