#include "monty.h"

/**
 * stack_rotl - top to bottom
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
int stack_rotl(stack_t **stack)
{
	stack_t *top, *bottom, *new_top;

	top = *stack;
	while (top->next != NULL)
		top = top->next;
	new_top = top->prev;
	bottom = *stack;

	new_top->next = top->next;
	top->prev = bottom->prev;
	top->next = bottom;
	bottom->prev = top;
	return (EXIT_SUCCESS);
}

/**
 * stack_rotr - bottom to top
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
int stack_rotr(stack_t **stack)
{
	stack_t *top, *bottom, *new_bottom;

	bottom = *stack;
	new_bottom = bottom->next;
	top = *stack;
	while (top->next != NULL)
		top = top->next;
	new_bottom->prev = bottom->prev;
	bottom->prev = top;
	bottom->next = top->next;
	top->next = bottom;
	return (EXIT_SUCCESS);
}

/**
 * stack_pop - removes top element of stack
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
int stack_pop(stack_t **stack)
{
	stack_t *temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = temp->next;
	free(temp);
	return (EXIT_SUCCESS);
}