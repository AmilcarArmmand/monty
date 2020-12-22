#include "monty.h"

/**
 * op_add - adds top node to second top node
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp->next == NULL || temp->next->next == NULL)
		op_add_error(line_number);
	
	temp->next->next->n = temp->next->next->n + temp->next->n;
	op_pop(stack, line_number);
}

/**
 * op_sub - subs top node to second top node
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp->next == NULL || temp->next->next == NULL)
		op_add_error(line_number);
	
	temp->next->next->n = temp->next->next->n - temp->next->n;
	op_pop(stack, line_number);
}

/**
 * op_div - divs top node to second top node
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp->next == NULL || temp->next->next == NULL)
		op_div_error(line_number);
	
	if (temp->next->n == 0)
		op_div_zero_error(line_number);

	temp->next->next->n = temp->next->next->n / temp->next->n;
	op_pop(stack, line_number);
}

/**
 * op_mul - muls top node to second top node
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp->next == NULL || temp->next->next == NULL)
		op_mul_error(line_number);
	
	temp->next->next->n = temp->next->next->n * temp->next->n;
	op_pop(stack, line_number);
}

/**
 * op_mod - mods top node to second top node
 * @stack: pointer to head of doubly linked list
 * @line_number: current line number
 * Return: address of new nodes or NULL on failure
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp->next == NULL || temp->next->next == NULL)
		op_mod_error(line_number);
	
	if (temp->next->n == 0)
		op_div_zero_error(line_number);

	temp->next->next->n = temp->next->next->n % temp->next->n;
	op_pop(stack, line_number);
}
