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

/*funciones1*/
void f_pint(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_push(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);

/*funciones2*/
void f_add(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);

/*otras*/
int isnum(char *integer);
void suprtab(char *buffer);
int lenstack(stack_t **head);
void freelist(stak_t *head);
int push(instruction_t function, char *integer, stack_t **head, unsigned int lin);

/*execs*/
int exec(instruction_t function, char *integer, stack_t **head, unsigned int lin);
int exe_pall(stack_t **head);
int exe_pint(stack_t **head, unsigned int lin);
int exe_pop(stack_t **head, unsigned int lin);
int exe_swap(stack_t **head, unsigned int lin);

/*exes*/
int exe_add(stack_t **head, unsigned int lin); 
int exe_nop(stack_t **head, unsigned int lin);

#endif
