#include "lists.h"

/**
 * isnum - chequear si el segundo token es integer
 * @integer: el seguno token
 * Return: -1 si falla, sino 0
 */

int isnum(char *integer)
{
	int i = 0;

	if (integer == NULL)
		return (-1);
	if (integer[i] == '-' && strlen(integer) == 1)
		return (-1);

	for (i = 1; integer[i]; i++)
	{
		if (integer[i] < 48 || integer[i] > 57)
			return (-1);
	}

	for (i = 0; integer[i]; i++)
	{
		if ((integer[i] < 48 || integer[i] > 57) && integer[i] != '-')
			return (-1);
	}
	return (0);
}

/**
 * suprtab - elimina tab
 * @buffer: el buffer
 * Return: void
 */

void suprtab(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '	')
			buffer[i] = ' ';
	}
}

/**
 *  lenstack - calular la cantidad de elementos en lista
 *  @head: primer nodo de la lista
 *  Return: el largo de la lista
 */

int lenstack(stack_t **head)
{
	int i = 0;
	stack_t *aux = *head;

	for (i = 0; aux; i++)
		aux = aux->next;
	return (i);
}

/**
 * freelist - limpia la lista
 * @head: primer nodo del stak
 * Return: void
 */

void freelist(stack_t *head)
{
	stack_t *aux;

	if (head == NULL)
		return;
	while (head)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
