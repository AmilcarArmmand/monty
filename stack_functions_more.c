#include "monty.h"

/**
 * stack_rotl - top to bottom
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
void stack_rotl(stack_t **stack)
{
	stack_t *top, *bottom, *new_top;

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

/**
 * stack_rotr - bottom to top
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
void stack_rotr(stack_t **stack)
{
	stack_t *top, *bottom, *new_bottom;

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

/**
 * stack_pop - removes top element of stack
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
void stack_pop(stack_t **stack)
{
	stack_t *temp;

	temp = *stack;
	temp->next->prev = temp->prev;
	free(temp);
}