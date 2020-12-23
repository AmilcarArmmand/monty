#include "monty.h"

/**
 * op_swap - swaps last nodes of stack
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *first, *second, *third;

	temp = *stack;
	if (temp->next == NULL || temp->next->next == NULL)
		op_swap_error(line_number);

	first = temp->next;
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
	stack_t *top, *bottom, *new_top, *temp;

	(void)line_number;

	temp = *stack;
	if (temp->next->next != NULL && temp->next != NULL)
	{
		temp = temp->next;
		top = temp;
		new_top = top->next;
		bottom = temp;
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
	stack_t *top, *bottom, *new_bottom, *temp;

	(void)line_number;

	temp = *stack;
	if (temp->next->next != NULL && temp->next != NULL)
	{
		temp = temp->next;
		top = temp;
		bottom = temp;
		while (bottom->next != NULL)
			bottom = bottom->next;
		new_bottom = bottom->prev;
		new_bottom->next = bottom->next;
		bottom->next = top;
		bottom->prev = top->prev;
		top->prev = bottom;
	}
}
