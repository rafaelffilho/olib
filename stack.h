#ifndef STACK_H
#define STACK_H

typedef struct stack_entry {
	union {
		int    iValue;
		char * sValue;
		double dValue;
	};
	struct stack_entry *next;
} stack_entry;

typedef struct stack {
	stack_entry *head;
} stack;

stack *      create_stack();
int          stack_push_int(stack *, int);
int          stack_push_double(stack *, double);
int          stack_push_str(stack *, char *);
stack_entry *stack_pop(stack *);

#endif    // !STACK_H