#include "monty.h"

/**
 * free_stack - fucntion that frees a doubly linked list
 *
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;
	while (stack)
	{
		temp = (*stack)->next;
		*stack = temp;
		free(temp);
	}

}

/**
 * initialize_stack - fucntion that frees a doubly linked list
 * @stack: pointer to the head of a doubly linked list in a stack/queue
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE in stack_malloc_error.
 */
int initialize_stack(stack_t **stack)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (stack_malloc_error());

	new->n = 0;
	new->prev = NULL;
	new->next = NULL;

	*stack = new;

	return (EXIT_SUCCESS);
}
