#include "lists.h"

/**
 * f_pint - impriome el valor que esta mas arriba en el stak
 * @stak: primer nodo del stak
 * @line_number: numero de lineas
 * Return: void
 */

void f_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	printf("%d\n", aux->n);
}

/**
 *  f_pall - imprime los valores que hay en el stack
 *  @stack: primer nodo del stack
 *  @line_numbernumero de lineas
 *  Return: void
 */

void f_pall(stack_t ** stack, unsigned int line number)
{
	stack_t *aux = *stack;

	(void)line_number;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
