#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv) {
	table *t1 = NULL;

	t1 = create_table(t1, 4);

	table_add_int(t1, "int", 1);
	table_add_double(t1, "double", 2.3);
	table_add_str(t1, "str", "test string :)");

	printf("int: %d\ndouble: %f\nstr: %s\n", table_get(t1, "int")->iValue,
	       table_get(t1, "double")->dValue, table_get(t1, "str")->sValue);

	table_remove(t1, "str");

	printf("again double: %f\n", table_get(t1, "double")->dValue);

	return 0;
}
