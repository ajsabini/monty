#include "lists.h"

/**
 * exec - chequqea que funion se ingreso
 * @head: primer nodo del stack
 * @l: numero de lineas
 * @function: puntero a una funion
 * @integer: enteroi
 * Return: -1 si falla, sino 0
 */
int exec(instruction_t function, char *integer, stack_t **head, unsigned int l)
{
	int status = 0;

	if (function.f == f_push)
		status = push(function, integer, head, l);
	if (function.f == f_pall)
		status = exe_pall(head);
	if (function.f == f_pint)
		status = exe_pint(head, l);
	if (function.f == f_pop)
		status = exe_pop(head, l);
	if (function.f == f_swap)
		status = exe_swap(head, l);
	if (function.f == f_add)
		status = exe_add(head, l);
	if (function.f == f_nop)
		status = exe_nop(head, l);
	if (function.f == f_sub)
		status = exe_sub(head, l);
	if (function.f == f_div)
		status = exe_div(head, l);
	if (function.f == f_mul)
		status = exe_mul(head, l);
	return (status);

}

/**
 * exe_pall - ejecuta f_pall
 * @head: primer nodo del stak
 * Return: 0
 */

int exe_pall(stack_t **head)
{
	f_pall(head, 2);
	return (0);
}

/**
 * exe_pint - ejeuta f_pall
 * @head: primer nodo del stack
 * @lin: numero e lineas
 * Return: -1 si falla, sino 0
 */

int exe_pint(stack_t **head, unsigned int lin)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: ant pint, stack empty\n", lin);
		return (-1);
	}
	f_pint(head, lin);
	return (0);
}

/**
 * exe_pop - funcion para ejecutar f_pop
 * @head: primer nodo del stack
 * @lin: numero e lineas
 * Return: -1 si falla, sino 0
 */

int exe_pop(stack_t **head, unsigned int lin)
{
	char err[20];

	if (*head == NULL)
	{
		sprintf(err, "%d", lin);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": cant pop en empty stack\n", 27);
	}
	f_pop(head, lin);
	return (0);
}

/**
 * exe_swap - ejecuta f_swap
 * @head: primer nodo del stack
 * @lin: numero de lineas
 * Return: -1 si falla, sino 0
 */

int exe_swap(stack_t **head, unsigned int lin)
{
	char err[20];
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		sprintf(err, "%d", lin);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": cant swap, stack too short\n", 30);
		return (-1);
	}
	f_swap(head, lin);
	return (0);
}
