#include "monty.h"

/**
 * op_swap - swaps last nodes of stack
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp; /* *first, *second, *third; */

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tokens[0] = "FAIL";
		op_swap_error(line_number);
		return;
	}
	temp = (*stack)->next->next;
	(*stack)->next->prev = temp;
	(*stack)->next->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}

/**
 * op_rotl - top to bottom
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
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
