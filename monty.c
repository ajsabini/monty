#include "lists.h"

unsigned int line;

/**
 * get_op_func - selecionar la funcion
 * @s: el parametro
 * Return: NULL si falla, sino un puntero a la funcion
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
		{"sub", f_sub},
		{"div", f_div},
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
 * tokenizador - tokeniza
 * @head: primer nodo del stack
 * @buffer: la linea
 * @line: as
 * Return: -1 si falla, sino 0
 */

int tokenizador(stack_t **head, char *buffer)
{
	char *cmd = NULL;
	char *integer = NULL, err[20];
	int status = 0;
	instruction_t function;

	cmd = strtok(buffer, " \n\f\v\t\r");
	integer = strtok(NULL, " \n\f\v\t\r");

	if (cmd == NULL)
		return (0);
	if (cmd[0] == 35)
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

/**
 * main - el interprete
 * @argc: numero de arg recibidos
 * @argv: los argumentos
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *fo;
	char *buffer = NULL, *copia = NULL;
	int status = 0;
	size_t size = 0;
	stack_t *push = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fo = fopen(argv[1], "rw+");
	if (fo == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fo) != -1)
	{
		line++;
		suprtab(buffer);
		copia = strdup(buffer);
		copia[strlen(copia) - 1] = '\0';
		status = tokenizador(&push, copia);
		if (status == -1)
		{
			free(copia);
			break;
		}
		free(copia);
	}
	if (buffer)
		free(buffer);
	freelist(push);
	fclose(fo);
	if (status == -1)
		exit(EXIT_FAILURE);
	return (0);
}
