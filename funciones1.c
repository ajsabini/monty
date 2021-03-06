#include "lists.h"

/**
 * f_push - hacemos un push de un elemento al stack
 * @stack: primer nodo del stack
 * @line_number: numero de lineas
 * Return: void
 */

void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error malloc failed\n", 22);
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}

/**
 * f_pint - impriome el valor que esta mas arriba en el stak
 * @stack: primer nodo del stak
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
 *  @line_number: numero de lineas
 *  Return: void
 */

void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * f_pop - eliminar el elemento de mas arriba de la pila
 * @stack: primer nodo del stack
 * @line_number: numero de lineas
 * Return: void
 */

void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;

	*stack = (*stack)->next;
	free(aux);
}

/**
 * f_swap - swaps
 * @stack: primer nodo del stack
 * @line_number: numero de lineas
 * Return: void
 */

void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int temp = 0;

	(void)line_number;
	aux = aux->next;
	temp = (*stack)->n;
	(*stack)->n = aux->n;
	aux->n = temp;
}
