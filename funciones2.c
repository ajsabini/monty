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

/**
 * push - ejeuta f_pall
 * @function: puntero a funcion
 * @integer: stack neuvo
 * @head: primer noo del stack
 * @l: numero de lineas
 * Return: -1 si falla, sino 0
 */

int push(instruction_t function, char *integer, stack_t **head, unsigned int l)
{
	int status = 0, num = 0;
	char err[20];

	status = isnum(integer);
	if (status == -1)
	{
		sprintf(err, "%d", l);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": usage: push integer\n", 22);
		return (-1);
	}
	num = atoi(integer);
	function.f(head, num);
	return (0);
}

/**
 *  f_sub - subs a los 2 elem mas arriba del stack
 *  @stack: primer nodo del stak
 *  @line_number: numero de lineas
 *  Return: void
 */

void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int sub = 0;

	(void)line_number;
	sub = aux->n;
	aux = aux->next;
	sub = aux->n - sub;
	f_pop(stack, sub);
	f_pop(stack, sub);
	f_push(stack, sub);
}

/**
 * f_div - div los dos elementos de mas arriba del stack
 * @stack: primer nodo del stack
 * @line_number: numero de lineas
 * Return: void
 */

void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int div = 0;

	(void)line_number;
	div = aux->n;
	aux = aux->next;
	div = aux->n / div;
	f_pop(stack, div);
	f_pop(stack, div);
	f_push(stack, div);
}
