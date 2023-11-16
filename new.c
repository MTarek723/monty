#include "monty.h"
/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments it self
 * Return: 0
*/
int main(int argc, char *argv[])
{ stack_t *stack = NULL;
int found, i;
FILE *file;
char *opcode = malloc(MAX_OPCODE_LENGTH);
unsigned int line_number = 1;
instruction_t instructions[] = {
{"push", push}, {"pall", pall}, {"pint", pint},
{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
{"div", div_op}, {"mul", mul_op}, {"mod", mod_op}, {NULL, NULL} };
if (argc != 2)
{ fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE); }
file = fopen(argv[1], "r");
if (file == NULL)
{ fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE); }
while (fscanf(file, "%99s", opcode) != EOF)
{
if (opcode[0] == '#')
{ fgets(opcode, MAX_OPCODE_LENGTH, file);
line_number++;
continue; }
found = 0;
for (i = 0; instructions[i].opcode != NULL; i++)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{ set_shared(file, opcode);
instructions[i].f(&stack, line_number);
found = 1;
break; } }
if (!found)
{ fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
fclose(file);
free(opcode);
free(stack);
exit(EXIT_FAILURE); }
line_number++; }
fclose(file);
free(opcode);
free(stack);
return (0); }
