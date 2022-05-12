#include "monty.h"

unsigned int line = 0;

/**
 * main - el interprete
 * @argc: numero de arg recibidos
 * @argv: los argumentos
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *fo; char *buffer = NULL, *copia = NULL;
	int status = 0; size_t size = 0;
	stack_t *push = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fo = fopen(arg[1], "rw+");
	if (fo == NULL)
	{
		fprintf(stderr, "ERROR: ant open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fp) != -1)
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
	freelist(oush);
	flose(fp);
	if (status == -1)
		exit(EXIT_FAILURE);
	return (0);
}
