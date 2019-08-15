#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct table_entry {
	char *key;
	union {
		int    iValue;
		char * sValue;
		double dValue;
	};
	char                isStr;
	struct table_entry *next;
} table_entry;

typedef struct table {
	table_entry **bucket;
	long          size;
	long          capacity;
} table;

table *      create_table(table *, size_t);
int          table_add_int(table *, char *, int);
int          table_add_double(table *, char *, double);
int          table_add_str(table *, char *, char *);
table_entry *table_get(table *, char *);
int          table_remove(table *, char *);

#endif    // !HASH_TABLE_H