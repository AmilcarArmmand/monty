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
	int n = 2020;

	(void)line_number;
	
	temp = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		stack_malloc_error();

	new->n = n;
	if (temp->next != NULL)
		temp->next->prev = new;
	new->next = temp->next;
	temp->next = new;
	new->prev = temp;
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

	temp = *stack;
	if (temp->next == NULL)
		op_pop_error(line_number);
	temp = temp->next;
	temp->prev->next = temp->next;
	if (temp->next != NULL)
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