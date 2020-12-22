#include "monty.h"

/**
 * free_stack - fucntion that frees a doubly linked list
 * @stack: pointer to head of double list
 * 
 * Return: nothing
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
		return (stack_malloc_error());

	new->n = 0;
	new->prev = NULL;
	new->next = NULL;

	*stack = new;

	return (EXIT_SUCCESS);
}

/**
 * stack_push_node - adds node to end of list
 * @stack: pointer to head of doubly linked list
 * @n: number
 * Return: address of new nodes or NULL on failure
 */
int stack_push_node(stack_t **stack, int n)
{
	stack_t *new, *temp;

	if (*stack == NULL)
		return (initialize_stack(&stack));
	
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (stack_malloc_error());

	new->n = n;
	new->next = NULL;
	new->prev = temp;
	temp->next = new;
	return (EXIT_SUCCESS);
}

/**
 * stack_print_node - prints nodes of stack
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
int stack_print_node(stack_t **stack)
{
	stack_t *temp;

	for (temp = *stack; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}

/**
 * stack_swap_node - swaps last nodes of stack
 * @stack: pointer to head of doubly linked list
 *
 * Return: address of new nodes or NULL on failure
 */
int stack_swap_node(stack_t **stack)
{
	stack_t *first, *second, *third;

	first = *stack;
	second = *stack;
	third = *stack;
	while (first->next != NULL)
		first = first->next;
	while (second->next != first)
		second = second->next;
	while (third->next != second)
		third = third->next;
	
	third->next = first;
	first->prev = third;
	second->next = first->next;
	first->next = second;
	second->prev = first;

	return (EXIT_SUCCESS);
}
