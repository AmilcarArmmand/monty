#include "monty.h"

/**
 * free_stack - fucntion that frees a doubly linked list
 * @stack: pointer to head of double list
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		temp = stack->next;
		free(temp);
		stack = temp;
	}

}

/**
 * initialize_stack - function that adds node to empty list
 * @stack: pointer to the head of a doubly linked list in a stack/queue
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE in stack_malloc_error.
 */
int initialize_stack(stack_t **stack)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (EXIT_FAILURE);

	new->n = 0;
	new->prev = NULL;
	new->next = NULL;

	*stack = new;

	return (EXIT_SUCCESS);
}
