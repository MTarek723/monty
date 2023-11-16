#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
int n;
stack_t *new_node;
if (fscanf(file, "%d", &n) != 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(file);
free(opcode);
free_stack(*stack);
exit(EXIT_FAILURE);
}
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc() failed.\n");
fclose(file);
free(opcode);
free_stack(*stack);
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->prev = NULL;
if (*stack == NULL)
{
new_node->next = NULL;
*stack = new_node;
}
else
{
new_node->next = *stack;
(*stack)->prev = new_node;
*stack = new_node;
}
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
temp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
{
(*stack)->prev = NULL;
}
free(temp);
}

/**
 * sub - subtracts the top element from the second top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
stack_t *top1, *top2;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top1 = *stack;
top2 = top1->next;
top2->n -= top1->n;
*stack = top2;
(*stack)->prev = NULL;
free(top1);
}
