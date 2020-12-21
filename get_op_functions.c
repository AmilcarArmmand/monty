#include "monty.h"

/**
 * get_op_func - a function that selects the function to perform the operation
 * @s: the operator passed as an argumant
 *
 * Return: the pointer to the function that performs the operation or NULL
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_func[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotr", op_rotr},
		{"rotl", op_rotl},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_func[i].opcode; i++)
	{
		if ((strcmp(op_func[i].opcode, opcode)) == 0)
			return ((op_func[i]).f);
		i++;
	}
	return (NULL);
}
