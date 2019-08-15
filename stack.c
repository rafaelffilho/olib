#include "stack.h"

#include <stdlib.h>
#include <string.h>

stack *create_stack() {
	stack *st;
	st = (stack *) malloc(sizeof(stack));

	memset(st->head, 0, sizeof(stack_entry));

	return st;
}

int stack_push_int(stack *st, int value) {

	stack_entry *en = (stack_entry *) malloc(sizeof(stack_entry));
	en->iValue      = value;
	en->next        = (st->head) ? st->head : NULL;

	st->head = en;

	return 0;
}

int stack_push_double(stack *st, double value) {

	stack_entry *en = (stack_entry *) malloc(sizeof(stack_entry));
	en->dValue      = value;
	en->next        = (st->head) ? st->head : NULL;

	st->head = en;

	return 0;
}

int stack_push_str(stack *st, char *value) {

	stack_entry *en = (stack_entry *) malloc(sizeof(stack_entry));
	en->sValue      = (char *) malloc(sizeof(char) * strlen(value));
	strcpy(en->sValue, value);
	en->next = (st->head) ? st->head : NULL;

	st->head = en;

	return 0;
}

stack_entry *stack_pop(stack *st) {

	if (!st->head) return 0;

	stack_entry *en = st->head;

	st->head = (st->head->next) ? st->head->next : NULL;

	return en;
}
