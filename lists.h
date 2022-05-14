#ifndef monty
#define monty
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*funciones1.c*/
void f_pint(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_push(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);

/*funciones2.c*/
void f_add(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);
void f_sub(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);

/*funciones3.c*/
void f_mul(stack_t **stack, unsigned int line_number);

/*otras.c*/
int isnum(char *integer);
void suprtab(char *buffer);
int lenstack(stack_t **head);
void freelist(stack_t *head);
int push(instruction_t function, char *intege, stack_t **head, unsigned int l);

/*execs.c*/
int exec(instruction_t function, char *intege, stack_t **head, unsigned int l);
int exe_pall(stack_t **head);
int exe_pint(stack_t **head, unsigned int lin);
int exe_pop(stack_t **head, unsigned int lin);
int exe_swap(stack_t **head, unsigned int lin);

/*exes.c*/
int exe_add(stack_t **head, unsigned int lin);
int exe_nop(stack_t **head, unsigned int lin);
int exe_sub(stack_t **head, unsigned int lin);
int exe_div(stack_t **head, unsigned int lin);
int exe_mul(stack_t **head, unsigned int lin);

#endif
