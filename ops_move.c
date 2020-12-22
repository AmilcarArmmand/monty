#include "monty.h"

/**
 * op_swap - swaps last nodes of stack
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *third;

	if (stack_len(&stack) < 2)
		return (op_swap_error(line_number));
	
	first = *stack;
	second = first->next;
	third = second->next;

	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	first->next = third;
	third->prev = first;
}

/**
 * op_rotl - top to bottom
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom, *new_top;

	(void)line_number;

	if (stack_len(&stack) > 1)
	{
		top = *stack;
		new_top = top->next;
		bottom = *stack;
		while (bottom->next != NULL)
			bottom = bottom->next;

		new_top->prev = top->prev;
		top->prev = bottom;
		top->next = bottom->next;
		bottom->next = top;
	}
}

/**
 * op_rotr - bottom to top
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom, *new_bottom;

	(void)line_number;

	if (stack_len(&stack) > 1)
	{
		top = *stack;
		bottom = *stack;
		while (bottom->next != NULL)
			bottom = bottom->next;
		new_bottom = bottom->prev;
		new_bottom->next = bottom->next;
		bottom->next = top;
		bottom->prev = top->prev;
		top->prev = bottom;
	}
}

/**
 * op_stack -
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * op_queue -
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}