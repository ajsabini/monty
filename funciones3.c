#include "lists.h"

/**
 * f_mul - multiplica los dos elementos de arriba del stack
 * @stack: primer nodo del stack
 * @line_number: numero de lineas
 * Return: void
 */

void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int mul = 0;

	(void)line_number;
	mul = aux->n;
	aux = aux->next;
	mul = aux->n * mul;
	f_pop(stack, mul);
	f_pop(stack, mul);
	f_push(stack, mul);
}
