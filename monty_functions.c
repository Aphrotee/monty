#include "monty.h"

/**
 * get_opcode_func - selects the correct function to perform the opcode
 * @s: opcode passed to the program
 * Return: a pointer to the function given the opcode or NULL if not found
 */

void (*get_opcode_func(char *s))(stack_t **stack, unsigned int ln)
{

	int i;
	instruction_t stk[] = {
		{"pall", stk_pall},
		{"push", stk_push},
		{"pop", stk_pop},
		{"add", stk_add},
		{"swap", stk_swap},
		{"pint", stk_pint},
		{"nop", stk_nop},
		{"pchar", stk_pchar},
		{"pstr", stk_pstr},
		{"rotl", stk_rotl},
		{"rotr", stk_rotr},
		{"sub", stk_sub},
		{"div", stk_div},
		{"mul", stk_mul},
		{"mod", stk_mod},
		{"queue", stk_queue},
		{"stack", stk_stack},
		{NULL, NULL}
	};

	i = 0;
	while (i < 17)
	{
		if (strcmp(s, (stk[i]).opcode) == 0)
		{
			return (*(stk[i]).f);
		}
		i++;
	}
	return (NULL);
}

/**
 * check_if_number - checks if a string is a number string
 * @str: string to check
 * Return: 1 if true or 0 if not a number string
 */

int check_if_number(char *str)
{
	int i;

	if (str && *str == '-')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * check_if_push - checks if the opcode is str and sets value
 * @tok_line: line of opcode
 * @lineno: line number
 * Return: 1 if success and 0 if not push
 */

int check_if_push(char *tok_line[], int lineno)
{
	if (strcmp(tok_line[0], "push") == 0)
	{
		if (tok_line[1][0] != '\0' && check_if_number(tok_line[1]))
			value[0] = atoi(tok_line[1]);
		else
		{
			printf("L%d: usage: push integer\n", lineno);
			value[2] = 1;
			return (0);
		}

		return (1);
	}
	return (0);
}

/**
 * is_ascii - checks if a character is a valid ascii
 * @c: character to check
 * Return: 0 if not and 1 if it is an ascii
 */

int is_ascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

/**
 * check_data_structure - checks whether or not stack or queue opcode given
 * @opcode: opcode given
 * Description: If opcode is stack or queue, changes the the extern value to
 * 0 if stack and 1 if queue.
 */

void check_data_structure(char *opcode)
{
	if (strcmp(opcode, "stack") == 0)
		value[1] = 0;
	else if (strcmp(opcode, "queue") == 0)
		value[1] = 1;
}

/**
 * stk_push - pushes a value to the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void stk_push(stack_t **stack, unsigned int ln)
{
	int result;

	if (value[1] == 0)
		result = add_to_stack(stack, value[0]);
	else
		result = add_to_queue(stack, value[0]);
	if (result < 0)
	{
		printf("L%d: usage: push integer\n", ln);
		value[2] = 1;
		return;
	}
}

/**
 * stk_pall - prints all values of the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void stk_pall(stack_t **stack, unsigned int ln)
{
	int result;
	(void) ln;

	result = print_stack(stack);
	if (result != 0)
	{
		;
	}
}

/**
 * stk_pop - removes the top element of the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void stk_pop(stack_t **stack, unsigned int ln)
{
	int result;

	result = delete_stack_head(stack);
	if (result != 1)
	{
		printf("L%d: can't pop an empty stack\n", ln);
		value[2] = 1;
		return;
	}
}

/**
 * stk_add - adds the top two elements of the stack
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_add(stack_t **stack, unsigned int ln)
{
	stack_t *temp;
	stack_t *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", ln);
		value[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp->next->n + temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_pint - print value at top of stack followed by new line
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_pint(stack_t **stack, unsigned int ln)
{
	stack_t *head;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", ln);
		value[2] = 1;
		return;
	}

	printf("%d\n", head->n);
}

/**
 * stk_swap - swaps the value of the first two elements on the stack
 * @stack: head to the stack
 * @ln: line number where opcode is located
 */

void stk_swap(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;
	int temp_value;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", ln);
		value[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp_value = temp->n;
	temp->n = temp2->n;
	temp2->n = temp_value;
}

/**
 * stk_nop - operation does nothing
 * @stack: head to the stack
 * @ln: line number where opcode is located
 */
void stk_nop(stack_t **stack, unsigned int ln)
{
	(void) stack;
	(void) ln;
}

/**
 * stk_pchar - prints teh char at the top of the stack
 * @stack: head to the stack
 * @ln: line number where opcode is located
 */

void stk_pchar(stack_t **stack, unsigned int ln)
{
	int c;
	stack_t *temp;

	temp = (*stack);
	if (temp == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", ln);
		value[2] = 1;
		return;
	}
	c = temp->n;
	if (!(is_ascii(c)))
	{
		printf("L%d: can't pchar, value out of range\n", ln);
		value[2] = 1;
		return;
	}
	putchar(c);
	putchar('\n');
}

/**
 * stk_pstr - prints the string starting at the stack
 * @stack: head to the top of the stack
 * @ln: line number of the opcode
 * Description: string stops where stack is over, the value is 0 or the value
 * is not an ascii value
 */

void stk_pstr(stack_t **stack, unsigned int ln)
{
	stack_t *temp;
	int c;

	(void) ln;
	temp = (*stack);
	while (temp != NULL && temp->n != 0 && is_ascii(temp->n))
	{
		c = temp->n;
		putchar(c);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * stk_rotl - rotates the top element of the stack to the bottom
 * @stack: head of the stack
 * @ln: line number
 */

void stk_rotl(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	(void) ln;
	temp = (*stack);
	if (temp == NULL)
		return;
	temp2 = temp;
	if (temp->next == NULL)
		;
	else
	{
		(*stack) = (*stack)->next;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
		temp->prev = temp2;
		temp->next->prev = NULL;
		temp->next = NULL;
	}
}

/**
 * stk_rotr - rotates the last element of the stack to the top
 * @stack: head of the stack
 * @ln: line number
 */

void stk_rotr(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	(void) ln;
	temp = (*stack);
	if (temp == NULL)
		return;
	temp2 = temp;
	if (temp->next == NULL)
		;
	else
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		temp2->next = temp;
		temp->prev = temp2;
		(*stack) = temp2;
	}
}

/**
 * stk_stack - sets the format of the data to a stack
 * @stack: head of the stack
 * @ln: line number
 */


void stk_stack(stack_t **stack, unsigned int ln)
{
	(void) stack;
	(void) ln;
}

/**
 * stk_queue - sets teh format of the data to a queue
 * @stack: head of the stack
 * @ln: line number of the opcode
 */

void stk_queue(stack_t **stack, unsigned int ln)
{
	(void) stack;
	(void) ln;
}

/**
 * stk_sub - subtracts the top element of stack from the second element
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_sub(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", ln);
		value[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n - temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_div - divides the second top element of stack from the top element
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_div(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", ln);
		value[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		value[2] = 1;
		return;
	}

	temp->n = (int)(temp2->n / temp->n);
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_mul - multiplies the top two elements of the stack
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_mul(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", ln);
		value[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n * temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_mod - divides second top element by top element and gets remainder
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_mod(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", ln);
		value[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		value[2] = 1;
		return;
	}
	temp->n = temp2->n % temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * add_to_stack - adds the node to the beginning of the stack
 * @head: head of the stack
 * @n: number value for the stack
 * Return: 1 if success and -1 if fail
 */

int add_to_stack(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (1);
}

/**
 * free_stack - frees the stack
 * @head: head of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * delete_stack_head - deletes the head node of the stack
 * @head: head of the stack
 * Return: 1 if true, -1 if false
 */

int delete_stack_head(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return (-1);
	temp = (*head);
	if (temp->next == NULL)
	{
		free(temp);
		(*head) = NULL;
		return (1);
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
	return (1);
}

/**
 * delete_stack_end - deletes the end of the stack
 * @head: head of the stack
 * Return: 1 if success and -1 if failed
 */

int delete_stack_end(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return (-1);
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	free(temp);
	return (1);
}

/**
 * print_stack - prints the stack
 * @head: head of the stack
 * Return: 1 if success and 0 if not
 */

int print_stack(stack_t **head)
{
	stack_t *temp;

	temp = (*head);
	if (temp == NULL)
		return (-1);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (0);
}

/**
 * add_to_queue - adds the nodes to the end of the queue
 * @head: head of the queue
 * @n: number value for the queue
 * Return: 1 if success and -1 if fail
 */

int add_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	return (1);
}

/**
 * tokenize_line - Tokenize command and any arguments
 * @s: line to parse
 * @tokens: buffer to fill
 * Return: 1 if success, 0 if failed
 */

int tokenize_line(char *s, char *tokens[])
{
	int i, status;
	char *token, *hold;

	token = strtok_r(s, " \t\n", &hold);
	status = check_if_comment(&token);
	if (status == 1)
		return (0);

	for (i = 0; token && i < 2; i++)
	{
		tokens[i] = token;

		token = strtok_r(NULL, " \t\n", &hold);
	}

	return (1);
}

/**
 * clear_strings - Reset strings in an array
 * @tokens: array of strings
 */

void clear_strings(char *tokens[])
{
	int i;

	for (i = 0; tokens[i]; i++)
		tokens[i][0] = '\0';
}

/**
 * check_empty - Checks if a string is empty
 * @s: string to check
 * Return: 1 if empty, 0 otherwise
 */

int check_empty(const char *s)
{
	while (*s != '\0')
	{
		if (!isspace((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * check_if_comment - Checks if line is comment and changes it accordingly
 * @token: pointer to token string
 * Return: 1 if comment, 0 if not a comment
 */

int check_if_comment(char **token)
{
	if (*token[0] == '#')
	{
		*token[0] = '\0';
		return (1);
	}
	return (0);
}

/**
 * check_argc - Function to check whether correct # arguments are given
 * @argc: argument count
 */

void check_argc(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_valid_file - Check if file given is valid
 * @filename: path to file
 */

void check_valid_file(char *filename)
{
	char *ext;

	ext = strrchr(filename, '.');
	if (ext == NULL)
		return;
	if (!(strcmp(".txt", ext) == 0 || strcmp(".m", ext) == 0))
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file_stream - Check if file stream is valid
 * @fp: file stream
 * @filename: name of file
 */

void check_file_stream(FILE *fp, char *filename)
{
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_opcode - Check if opcode function pointer is NULL
 * @opcode: opcode function pointer
 * @lineno: line number
 * @cmd: command given
 */

void check_opcode(void (*opcode)(), int lineno, char *cmd)
{
	if (opcode == NULL)
	{
		printf("L%d: unknown instruction %s\n", lineno, cmd);
		value[2] = 1;
		return;
	}
}

/**
 * check_fail - check if a fail has been raised. If so, free memory and exit
 * @line: buffer to free
 * @fp: file stream to close
 * @head: head of the stack
 * Return: return 1 if exit triggered, else 0 for false
 */

void check_fail(char *line, FILE *fp, stack_t *head)
{
	if (value[2] == 1)
	{
		free(line);
		fclose(fp);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
