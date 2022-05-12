#include "lists.h"

/**
 * f_add - agrega los dos elementos de arriba a la pila
 * @stack: primer nodo del stacl
 * @line_number: numero de lineas
 * Return: void
 */

void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int add = 0;

	(void)line_number;
	add = aux->n;
	aux = aux->next;
	add = add + aux->n;
	f_pop(stack, add);
	f_push(stack, add);
}

/**
 * f_nop - no hace nada
 * @stack: primer nodo del stack
 * @line_number: numero de lineas
 * Return: void
 */

void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
