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
