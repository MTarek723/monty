#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
int temp;
stack_t *top1, *top2;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top1 = *stack;
top2 = top1->next;
temp = top1->n;
top1->n = top2->n;
top2->n = temp;
}
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *top1, *top2;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top1 = *stack;
top2 = top1->next;
top2->n += top1->n;
*stack = top2;
(*stack)->prev = NULL;
free(top1);
}
/**
 * nop - does nothing
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
 * div_op - divides the second top element by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
stack_t *top1, *top2;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top1 = *stack;
top2 = top1->next;
if (top1->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
top2->n /= top1->n;
*stack = top2;
(*stack)->prev = NULL;
free(top1);
}
