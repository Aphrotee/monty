#ifndef MONTY_H
#define MONTY_H
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern char *intData;
extern int lineNum;
extern void getqfunc(char *opcode);
extern void (*getsfunc(char *opcode, unsigned int lineNum))(stack_t **, unsigned int);
extern stack_t *add_dnodeint(stack_t **head, const int n);
extern void print_stack(stack_t **h, unsigned int lineNum);
extern void print_head(stack_t **h, unsigned int lineNum);
extern void swap_head(stack_t **h, unsigned int linenum);
extern void pop_head(stack_t **h, unsigned int lineNum);
extern void add_head(stack_t **h, unsigned int lineNum);
extern void nop(stack_t **h, unsigned int lineNum);
extern void push_head(stack_t **h, unsigned int lineNum);
#endif
