#include "monty.h"
/**
 * mul_op - multiplies the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
stack_t *top1, *top2;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top1 = *stack;
top2 = top1->next;
top2->n *= top1->n;
*stack = top2;
(*stack)->prev = NULL;
free(top1);
}
/**
 * mod_op - computes the rest of the division of the second top element
 *           by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
stack_t *top1, *top2;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top1 = *stack;
top2 = top1->next;
if (top1->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
top2->n %= top1->n;
*stack = top2;
(*stack)->prev = NULL;
free(top1);
}
/**
* free_stack - free the nodes in a stack list
* @head: first node of a dlistint link
* Return: void
*/
void free_stack(stack_t *head)
{
if (head == NULL)
return;
if (head->next != NULL)
{
free_stack(head->next);
}
free(head);
}
