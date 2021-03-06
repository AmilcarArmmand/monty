#ifndef MONTY_H
#define MONTY_H

/* Libraries used  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DELIMS " \n\t\v\r\a"

#define EXIT_SUCCESS 0
extern char **op_tokens; /* here instead of in files, defined in main_monty */

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
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);

int file_open_error(char *filename);
int stack_malloc_error(void);
int op_push_error(unsigned int line_number);
int op_pop_error(unsigned int line_number);
int op_add_error(unsigned int line_number);
int op_swap_error(unsigned int line_number);
int op_sub_error(unsigned int line_number);
int op_mul_error(unsigned int line_number);
int op_div_error(unsigned int line_number);
int op_mod_error(unsigned int line_number);
int op_div_zero_error(unsigned int line_number);
int op_pint_error(unsigned int line_number);
int op_pchar_error(unsigned int line_number);
int op_pchar_value_error(unsigned int line_number);
int usage_error(void);
int unknown_instruct(unsigned int line_number, char *token);


int parse_monty(FILE *fp);
char **evaluate_monty(char *str);
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number);
char **op_seperater(char *str);
void free_stack(stack_t **stack);
int initialize_stack(stack_t **stack);

unsigned int stack_len(stack_t **stack);
void free_tokens(void);
int line_is_space(char *line, char *delims);

#endif  /* MONTY_H  */
