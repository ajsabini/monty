#include "lists.h"

/**
 * exe_add - ejecuta f_add
 * @head: primer nodo del stack
 * @lin: numero de lineas
 * Return: -1 si falla, sino 0
 */

int exe_add(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lin);
		return (-1);
	}
	f_add(head, lin);
	return (0);
}

/**
 * exe_nop - ejecuta f__nop
 * @head: primer nodo del stack
 * @lin: numero de lineas
 * Return: -1 si falla, sino 0
 */

int exe_nop(stack_t **head, unsigned int lin)
{
	f_nop(head, lin);
	return (0);
}

/**
 * exe_sub - ejeuta la fun f_sub
 * @head: primer nodo del stack
 * @lin: numero de lineas
 * Return: -1 si falla, sino 0
 */

int exe_sub(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lin);
		return (-1);
	}
	f_sub(head, lin);
	return (0);
}

/**
 * exe_div - ejecutamos f_div
 * @head: primer nodo del stack
 * @lin: numero de lineas
 * Return: -1 si falla, 0 sino
 */

int exe_div(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lin);
		return (-1);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lin);
		return (-1);
	}
	f_div(head, lin);
	return (0);
}

/**
 * exe_mul - ejecuta f_mul
 * @head: primer nodo del stack
 * @lin: numero de lineas
 * Return: -1 si falla, sino 0
 */

int exe_mul(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lin);
		return (-1);
	}
	f_mul(head, lin);
	return (0);
}
