#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};

	int i = 0;
	while (instruct[i].opcode != NULL)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
		{
			return instruct[i].f;
		}
		i++;
	}

	dprintf(2, "Unknown opcode: %s\n", opc);
	free_vglo();
	exit(EXIT_FAILURE);
}

