#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "monty.h"

/**
 * getsfunc - receives opcode as input and returns corresponding function
 * @opcode: command
 *
 * Return: function pointer
 */
void (*getsfunc(char *opcode, unsigned int lineNum))(stack_t **, unsigned int)
{
	int i;
	instruction_t ins[8] = {
		{"push", push_head},
		{"pall", print_stack},
		{"pint", print_head},
		{"pop", pop_head},
		{"nop", nop},
		{"swap", swap_head},
		{"add", add_head},
		{NULL, NULL}
	};

	for (i = 0; i < 7; i++)
	{
		if (strcmp(opcode, ins[i].opcode) == 0)
			break;
	}
	if (i == 7)
	{
		dprintf(2, "L%u: unknown instruction %s\n", lineNum, opcode);
		exit(EXIT_FAILURE);
	}
	return (*(ins[i].f));
}
/**
 * add_to_head - adds a new node to the beginning of the stack
 * @head: doubly linked list
 * @n: integer data for new node
 *
 * Return: pointer
 */
stack_t *add_to_head(stack_t **head, const int n)
{
	stack_t *new, *temp;

	if (head == NULL)
		return (NULL);
	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
	{
		new->prev = NULL;
		new->n = n;
		new->next = *head;
		*head = new;
	}
	else
	{
		temp = *head;
		new->prev = NULL;
		new->n = n;
		new->next = *head;
		temp->prev = new;
		head = &new;
	}
	return (new);
}

/**
 * print_stack - prints the elements of a stack
 * @h: head of linked list
 * @lineNum: current line number
 *
 * Return: number of elements in list
 */
void print_stack(stack_t **h, unsigned int lineNum)
{
	const stack_t *current;

	if (lineNum)
	{
		current = *h;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}

/**
 * print_head - prints the element at the top of a stack
 * @h: head of linked list
 * @lineNum: current line number
 *
 * Return: Nothing
 */
void print_head(stack_t **h, unsigned int lineNum)
{
	int d = 0;
	stack_t *temp;

	temp = *h;
	while (temp != NULL)
	{
		d++;
		temp = temp->next;
	}
	if (d == 0)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", lineNum);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*h)->n);
	}
}
/**
 * swap_head - swaps the top two elements of the stack
 * @h: head of stack
 * @lineNum: current line number
 *
 * Return: Nothing
 */
void swap_head(stack_t **h, unsigned int lineNum)
{
	int d = 0;
	stack_t *current, *h2;

	current = *h;
	while (current != NULL)
	{
		d++;
		current = current->next;
	}
	if (d < 2)
	{
		dprintf(2, "L%u: Can't swap, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}
	h2 = (*h)->next;
	d = (*h)->n;
	(*h)->n = h2->n;
	h2->n = d;
}
/**
 * pop_head -  removes the top element of the stack
 * @h: head of stack
 * @lineNum: current line number
 *
 * Return: Nothing
 */
void pop_head(stack_t **h, unsigned int lineNum)
{
	stack_t *del;

	if (h == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", lineNum);
		exit(EXIT_FAILURE);
	}
	del = *h;
	h = &((*h)->next);
	(*h)->prev = NULL;
	free(del);
}
/**
 * add_head - adds the top two elements of the stack
 * @h: head of stack
 * @lineNum: current line number
 *
 * Return: Nothing
 */
void add_head(stack_t **h, unsigned int lineNum)
{
	stack_t *temp, *h2;
	int i = 0;

	temp = *h;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack to short\n", lineNum);
		exit(EXIT_FAILURE);
	}
	h2 = (*h)->next;
	h2->n += (*h)->n;
	h2->prev = NULL;
	free(*h);
	h = &h2;
}
/**
 * nop - does nothing
 * @h: head of stack
 * @lineNum: current line number
 *
 * Return: Nothing
 */
void nop(stack_t **h, unsigned int lineNum)
{
	if (h == NULL)
		exit(EXIT_FAILURE + lineNum);
}
/**
 * push_head - pushes an element to the stack
 * @h: head of stack
 * @lineNum: current line number
 *
 * Return: Nothing
 */
void push_head(stack_t **h, unsigned int lineNum)
{
	int value = atoi(intData);

	printf("%u\n", lineNum);
	add_to_head(h, value);
}
