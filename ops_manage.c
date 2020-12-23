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
	int n, i;

	for (i = 0; op_tokens[1][i]; i++)
		if (!isdigit(op_tokens[1][i]))
		{
			op_tokens[0] = "FAIL";
			op_push_error(line_number);
			return;
		}
	n = atoi(op_tokens[1]);

	(void)line_number;

	temp = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		stack_malloc_error();
	new->n = n;
	if (temp->n == 0)
	{
		if (temp->next != NULL)
			temp->next->prev = new;
		new->next = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		new->next = temp->next;
		new->prev = temp;
		temp->next = new;
	}
}

/**
 * op_pop - removes top element of stack
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	temp = *stack;
	if (temp->next == NULL)
	{
		op_tokens[0] = "FAIL";
		op_pop_error(line_number);
		return;
	}
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

/**
 * op_stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	temp->n = 0;
}

/**
 * op_queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	temp->n = 1;
}
