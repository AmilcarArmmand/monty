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
 * op_rotl - rotates the stack to the top
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 *
 * Description: The top element of the stack becomes the last one, and
 *              the second top element of the stack becomes the first one.
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
 * op_rotr - rotates the stack to the bottom
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 *
 * Description: The last element of the stack becomes
 *              the top element of the stack
 * Return: address of new nodes or NULL on failure
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;

	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

}
