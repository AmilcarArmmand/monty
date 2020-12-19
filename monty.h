#ifndef  MONTY_H
#define MONTY_H

/* Libraries used  */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DELIMS " \n\t\v\r"

/* extern char **op_tokens  /* idea for the global variable tokens */
/* ??? flags for exit_success, exit codes, stack, queue, */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* need function naming convention and rename below functions */
void op_push(*f)(stack_t **stack, unsigned int line_number);
void op_pall(*f)(stack_t **stack, unsigned int line_number);
void op_pint(*f)(stack_t **stack, unsigned int line_number);
void op_pop(*f)(stack_t **stack, unsigned int line_number);
void op_swap(*f)(stack_t **stack, unsigned int line_number);
void op_add(*f)(stack_t **stack, unsigned int line_number);
void op_nop(*f)(stack_t **stack, unsigned int line_number);
void op_sub(*f)(stack_t **stack, unsigned int line_number);
void op_div(*f)(stack_t **stack, unsigned int line_number);
void op_mul(*f)(stack_t **stack, unsigned int line_number);
void op_mod(*f)(stack_t **stack, unsigned int line_number);
void op_pchar(*f)(stack_t **stack, unsigned int line_number);
void op_pstr(*f)(stack_t **stack, unsigned int line_number);
void op_rotl(*f)(stack_t **stack, unsigned int line_number);
void op_rotr(*f)(stack_t **stack, unsigned int line_number);
void op_stack(*f)(stack_t **stack, unsigned int line_number);
void op_queue(*f)(stack_t **stack, unsigned int line_number);

#endif  /* MONTY_H  */
