#include "lists.h"

/**
 * get_op_func - para obtener la funcion
 * @s: el parametro
 * Return: NULL si falla, sino puntero a la funcion
 */
void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t funciones[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{NULL, NULL}
	};

	while (i < 7)
	{
		if (strcmp(s, funciones[i].opcode) == 0)
			return (funciones[i].f);
		i++;
	}
	return (NULL);
}

/**
 * tokenizador - para tokenizar
 * @head: primer nodo del stak
 * @buffer: la linea
 * Return: -1 si falla, sino 0
 */

int tokenizador(stack_t **head, char *buffer, unsigned int line)
{
	char *cmd = NULL;
	char *integer = NULL, err[20];
	int status = 0;
	instruction_t function;

	cmd = strtok(buffer, " \n\f\v\t\r");
	integer = strtok(NULL, " \n\f\v\t\r");

	if (cmd == NULL)
		return (0);
	function.f = get_op_func(cmd);
	if (function.f == NULL)
	{
		sprintf(err, "%d", line);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": unknown instruction ", 22);
		write(2, cmd, strlen(cmd));
		write(2, "\n", 1);
		return (-1);
	}
	status = exec(function, integer, head, line);
	return (status);
}
