[?1049h[22;0;0t[>4;2m[?1h=[?2004h[1;36r[?12h[?12l[22;2t[22;1t[27m[23m[29m[m[H[2J[?25l[36;1H"functions.c" 229L, 3890C[1;1H[34m * @lineNum: current line number
 *
 * Return: Nothing
 */[m
[32mvoid[m add_head(stack_t **h, [32munsigned[m [32mint[m lineNum)
{[7;9Hstack_t *temp, *h2;[8;9H[32mint[m i = [31m0[m;[10;9Htemp = *h;[11;9H[33mwhile[m (temp != [31mNULL[m)[12;9H{[13;17Hi++;[14;17Htemp = temp->next;[15;9H}[16;9H[33mif[m (i < [31m2[m)[17;9H{[18;17Hdprintf([31m2[m, [31m"L[m[35m%u[m[31m: can't add, stack to short[m[35m\n[m[31m"[m, lineNum);[19;17Hexit([31mEXIT_FAILURE[m);[20;9H}[21;9Hh2 = (*h)->next;[22;9Hh2->n += (*h)->n;[23;9Hh2->prev = [31mNULL[m;[24;9Hfree(*h);[25;9Hh = &h2;
}
[34m/**
 * nop - does nothing
 * @h: head of stack
 * @lineNum: current line number
 *
 * Return: Nothing
 */[m
[32mvoid[m nop(stack_t **h, [32munsigned[m [32mint[m lineNum)
{[36;91H192,1-8[7C89%[18;8H[?25h[?25l[36;1HType  :qa  and press <Enter> to exit Vim[36;91H[K[36;91H192,1-8[7C89%[18;8H[?25h[?25l[36;91H[K[36;91H192,1-8[7C89%[18;8H[?25h[?25l[36;81Hq[18;8H[?25h[?25l[36;82Hg[18;8H[36;1H[1mrecording @g[m[36;13H[K[36;91H192,1-8[7C89%[18;8H[?25h[?25l[36;81Hg[18;8H[?25h[?25l[36;81H [18;8H[36;81Hgg[18;8H[36;81H  [1;1H[27m[23m[29m[m[H[2J[1;1H[35m#include [m[31m<stdio.h>[m
[35m#include [m[31m<string.h>[m
[35m#include [m[31m<stdlib.h>[m
[35m#include [m[31m<stddef.h>[m
[35m#include [m[31m"monty.h"[m

[34m/**
 * getsfunc - receives opcode as input and returns corresponding function
 * @opcode: command
 *
 * Return: function pointer
 */[m
[32mvoid[m (*getsfunc([32mchar[m *opcode, [32munsigned[m [32mint[m lineNum))(stack_t **, [32munsigned[m [32mint[m)
{[15;9H[32mint[m i;[16;9Hinstruction_t ins[[31m8[m] = {[17;17H{[31m"push"[m, push_head},[18;17H{[31m"pall"[m, print_stack},[19;17H{[31m"pint"[m, print_head},[20;17H{[31m"pop"[m, pop_head},[21;17H{[31m"nop"[m, nop},[22;17H{[31m"swap"[m, swap_head},[23;17H{[31m"add"[m, add_head},[24;17H{[31mNULL[m, [31mNULL[m}[25;9H};[27;9H[33mfor[m (i = [31m0[m; i < [31m7[m; i++)[28;9H{[29;17H[33mif[m (strcmp(opcode, ins[i].opcode) == [31m0[m)[30;25H[33mbreak[m;[31;9H}[32;9H[33mif[m (i == [31m7[m)[33;9H{[34;17Hdprintf([31m2[m, [31m"L[m[35m%u[m[31m: unknown instruction [m[35m%s\n[m[31m"[m, lineNum, opcode);[35;17Hexit([31mEXIT_FAILURE[m);
[1mrecording @g[m[78C1,1[11CTop[1;1H[?25h[?25l[36;81Hd[1;1H[?25h[?25l[36;81H [1;1H[?25h[?25l[36;81Hgd[1;1H[36;81H  [1;1H[?25h[?25l[36;1HType  :qa  and press <Enter> to exit Vim[36;91H[K[36;1H[1mrecording @g[m[36;13H[K[36;91H1,1[11CTop[1;1H[?25h[?25l[36;81H^L[1;1H[36;81H  [1;1H[27m[23m[29m[m[H[2J[1;1H[35m#include [m[31m<stdio.h>[m
[35m#include [m[31m<string.h>[m
[35m#include [m[31m<stdlib.h>[m
[35m#include [m[31m<stddef.h>[m
[35m#include [m[31m"monty.h"[m

[34m/**
 * getsfunc - receives opcode as input and returns corresponding function
 * @opcode: command
 *
 * Return: function pointer
 */[m
[32mvoid[m (*getsfunc([32mchar[m *opcode, [32munsigned[m [32mint[m lineNum))(stack_t **, [32munsigned[m [32mint[m)
{[15;9H[32mint[m i;[16;9Hinstruction_t ins[[31m8[m] = {[17;17H{[31m"push"[m, push_head},[18;17H{[31m"pall"[m, print_stack},[19;17H{[31m"pint"[m, print_head},[20;17H{[31m"pop"[m, pop_head},[21;17H{[31m"nop"[m, nop},[22;17H{[31m"swap"[m, swap_head},[23;17H{[31m"add"[m, add_head},[24;17H{[31mNULL[m, [31mNULL[m}[25;9H};[27;9H[33mfor[m (i = [31m0[m; i < [31m7[m; i++)[28;9H{[29;17H[33mif[m (strcmp(opcode, ins[i].opcode) == [31m0[m)[30;25H[33mbreak[m;[31;9H}[32;9H[33mif[m (i == [31m7[m)[33;9H{[34;17Hdprintf([31m2[m, [31m"L[m[35m%u[m[31m: unknown instruction [m[35m%s\n[m[31m"[m, lineNum, opcode);[35;17Hexit([31mEXIT_FAILURE[m);
[1mrecording @g[m[78C1,1[11CTop[1;1H[?25h[?25l[36;81H^L[1;1H[36;81H  [1;1H[27m[23m[29m[m[H[2J[1;1H[35m#include [m[31m<stdio.h>[m
[35m#include [m[31m<string.h>[m
[35m#include [m[31m<stdlib.h>[m
[35m#include [m[31m<stddef.h>[m
[35m#include [m[31m"monty.h"[m

[34m/**
 * getsfunc - receives opcode as input and returns corresponding function
 * @opcode: command
 *
 * Return: function pointer
 */[m
[32mvoid[m (*getsfunc([32mchar[m *opcode, [32munsigned[m [32mint[m lineNum))(stack_t **, [32munsigned[m [32mint[m)
{[15;9H[32mint[m i;[16;9Hinstruction_t ins[[31m8[m] = {[17;17H{[31m"push"[m, push_head},[18;17H{[31m"pall"[m, print_stack},[19;17H{[31m"pint"[m, print_head},[20;17H{[31m"pop"[m, pop_head},[21;17H{[31m"nop"[m, nop},[22;17H{[31m"swap"[m, swap_head},[23;17H{[31m"add"[m, add_head},[24;17H{[31mNULL[m, [31mNULL[m}[25;9H};[27;9H[33mfor[m (i = [31m0[m; i < [31m7[m; i++)[28;9H{[29;17H[33mif[m (strcmp(opcode, ins[i].opcode) == [31m0[m)[30;25H[33mbreak[m;[31;9H}[32;9H[33mif[m (i == [31m7[m)[33;9H{[34;17Hdprintf([31m2[m, [31m"L[m[35m%u[m[31m: unknown instruction [m[35m%s\n[m[31m"[m, lineNum, opcode);[35;17Hexit([31mEXIT_FAILURE[m);
[1mrecording @g[m[78C1,1[11CTop[1;1H[?25h[?25l[36;81Hl[1;1H[36;81H [1;2H[36;93H2[1;2H[?25h[?25l[36;81H^L[1;2H[36;81H  [1;2H[27m[23m[29m[m[H[2J[1;1H[35m#include [m[31m<stdio.h>[m
[35m#include [m[31m<string.h>[m
[35m#include [m[31m<stdlib.h>[m
[35m#include [m[31m<stddef.h>[m
[35m#include [m[31m"monty.h"[m

[34m/**
 * getsfunc - receives opcode as input and returns corresponding function
 * @opcode: command
 *
 * Return: function pointer
 */[m
[32mvoid[m (*getsfunc([32mchar[m *opcode, [32munsigned[m [32mint[m lineNum))(stack_t **, [32munsigned[m [32mint[m)
{[15;9H[32mint[m i;[16;9Hinstruction_t ins[[31m8[m] = {[17;17H{[31m"push"[m, push_head},[18;17H{[31m"pall"[m, print_stack},[19;17H{[31m"pint"[m, print_head},[20;17H{[31m"pop"[m, pop_head},[21;17H{[31m"nop"[m, nop},[22;17H{[31m"swap"[m, swap_head},[23;17H{[31m"add"[m, add_head},[24;17H{[31mNULL[m, [31mNULL[m}[25;9H};[27;9H[33mfor[m (i = [31m0[m; i < [31m7[m; i++)[28;9H{[29;17H[33mif[m (strcmp(opcode, ins[i].opcode) == [31m0[m)[30;25H[33mbreak[m;[31;9H}[32;9H[33mif[m (i == [31m7[m)[33;9H{[34;17Hdprintf([31m2[m, [31m"L[m[35m%u[m[31m: unknown instruction [m[35m%s\n[m[31m"[m, lineNum, opcode);[35;17Hexit([31mEXIT_FAILURE[m);
[1mrecording @g[m[78C1,2[11CTop[1;2H[?25h[?25l[36;81H^L[1;2H[36;81H  [1;2H[27m[23m[29m[m[H[2J[1;1H[35m#include [m[31m<stdio.h>[m
[35m#include [m[31m<string.h>[m
[35m#include [m[31m<stdlib.h>[m
[35m#include [m[31m<stddef.h>[m
[35m#include [m[31m"monty.h"[m

[34m/**
 * getsfunc - receives opcode as input and returns corresponding function
 * @opcode: command
 *
 * Return: function pointer
 */[m
[32mvoid[m (*getsfunc([32mchar[m *opcode, [32munsigned[m [32mint[m lineNum))(stack_t **, [32munsigned[m [32mint[m)
{[15;9H[32mint[m i;[16;9Hinstruction_t ins[[31m8[m] = {[17;17H{[31m"push"[m, push_head},[18;17H{[31m"pall"[m, print_stack},[19;17H{[31m"pint"[m, print_head},[20;17H{[31m"pop"[m, pop_head},[21;17H{[31m"nop"[m, nop},[22;17H{[31m"swap"[m, swap_head},[23;17H{[31m"add"[m, add_head},[24;17H{[31mNULL[m, [31mNULL[m}[25;9H};[27;9H[33mfor[m (i = [31m0[m; i < [31m7[m; i++)[28;9H{[29;17H[33mif[m (strcmp(opcode, ins[i].opcode) == [31m0[m)[30;25H[33mbreak[m;[31;9H}[32;9H[33mif[m (i == [31m7[m)[33;9H{[34;17Hdprintf([31m2[m, [31m"L[m[35m%u[m[31m: unknown instruction [m[35m%s\n[m[31m"[m, lineNum, opcode);[35;17Hexit([31mEXIT_FAILURE[m);
[1mrecording @g[m[78C1,2[11CTop[1;2H[?25h[?25l[36;1HType  :qa  and press <Enter> to exit Vim[36;91H[K[36;1H[1mrecording @g[m[36;13H[K[36;91H1,2[11CTop[1;2H[?25h[?25l[36;1HType  :qa  and press <Enter> to exit Vim[36;91H[K[36;1H[1mrecording @g[m[36;13H[K[36;91H1,2[11CTop[1;2H[?25h[?25l[36;81H^[[1;2H[36;81H  [1;2H[36;81H^[[1;2H[36;81H  [1;2H[?25h[?25l[36;81H:[1;2H[36;1H[K[36;1H:[?2004h[?25hq![?25l[?2004l[23;2t[23;1t[36;1H[K[36;1H[?2004l[?1l>[?25h[>4;m[?1049l[23;0;0t