#include "monty.h"

/**
 * op_pall - prints nodes of stack
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;
	for (temp = temp->next; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}

/**
 * op_pint - prints top value of stack
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp->next == NULL)
		op_pint_error(line_number);
	printf("%d\n", temp->next->n);
}

/**
 * op_pchar - prints top value of stack as char
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp->next == NULL)
		op_pint_error(line_number);
	if (1 <= temp->next->n && temp->next->n <= 127)
		printf("%c\n", temp->next->n);
	else
		op_pchar_value_error(line_number);
}

/**
 * op_pstr - prints stack as string
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	for (temp = temp->next; temp != NULL; temp = temp->next)
	{
		if (temp->n == 0)
			break;
		if (1 <= temp->next->n && temp->next->n <= 127)
			printf("%c\n", temp->n);
		else
			break;
	}
}