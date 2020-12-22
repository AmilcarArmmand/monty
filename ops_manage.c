#include "monty.h"

/**
 * op_push - adds node to list
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	(void)line_number;

	if (*stack == NULL)
		return (initialize_stack(&stack));
	
	temp = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (stack_malloc_error());

	/*new->n = n;*/
	new->next = temp;
	new->prev = temp->prev;
	temp->prev = new;
}

/**
 * op_pop - removes top element of stack
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;
	temp->next->prev = temp->prev;
	free(temp);
}

/**
 * op_nop - does nothing
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}