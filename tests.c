#include "hash_table.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv) {

	printf("\n--- Hash table tests begins ---\n");

	table *t1 = NULL;

	t1 = create_table(t1, 4);

	table_add_int(t1, "int", 1);
	table_add_double(t1, "double", 2.3);
	table_add_str(t1, "str", "test string :)");

	printf("int: %d\ndouble: %.2f\nstr: %s\n", table_get(t1, "int")->iValue,
	       table_get(t1, "double")->dValue, table_get(t1, "str")->sValue);

	table_remove(t1, "str");

	printf("again double: %.2f\n", table_get(t1, "double")->dValue);

	printf("\n--- Hash table tests ends ---\n\n");

	printf("\n--- Stack tests begins ---\n");

	stack *s1 = NULL;

	s1 = create_stack();

	printf("Pushing (int): 1\n");
	stack_push_int(s1, 1);

	printf("Pushing (int): 2\n");
	stack_push_int(s1, 2);

	printf("Pushing (int): 3\n");
	stack_push_int(s1, 3);

	printf("Pushing (str): test string :)\n");
	stack_push_str(s1, "test string :)");

	printf("Pushing (double): 1.23\n");
	stack_push_double(s1, 1.23);

	printf("\nPoping: %.2f\n", stack_pop(s1)->dValue);
	printf("Poping: %s\n", stack_pop(s1)->sValue);
	printf("Poping: %d\n", stack_pop(s1)->iValue);
	printf("Poping: %d\n", stack_pop(s1)->iValue);
	printf("Poping: %d\n", stack_pop(s1)->iValue);

	printf("\n--- Stack tests ends ---\n\n");

	return 0;
}
