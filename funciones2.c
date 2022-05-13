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

/**
 * push - ejeuta f_pall
 * @head: primer noo del stack
 * @function: puntero a funcion
 * @integer: stack neuvo
 * Return: -1 si falla, sino 0
 */

int push(instruction_t function, char *integer, stack_t **head, unsigned int l)
{
	int status = 0, num = 0;
	char err[20];

	status = isnum(integer);
	if (status == -1)
	{
		sprintf(err, "%d", 1);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": usage: poush integer\n", 22);
		return (-1);
	}
	num = atoi(integer);
	function.f(head, num);
	return (0);
}
