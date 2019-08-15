#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash_str(char *str) {
	long hash = 0;
	int  c;

	while ((c = *str++)) hash = c + (hash << 6) + (hash << 16) - hash;

	return hash;
}

table *create_table(table *tbl, size_t capacity) {
	if (tbl) return tbl;

	tbl         = (table *) malloc(sizeof(table));
	tbl->bucket = (table_entry **) malloc(sizeof(table_entry *) * capacity);
	memset(tbl->bucket, 0, sizeof(table_entry *) * capacity);
	tbl->capacity = capacity;
	tbl->size     = 0;

	return tbl;
}

int table_add_int(table *tbl, char *key, int value) {
	long hash = hash_str(key) % tbl->capacity;

	table_entry *en = tbl->bucket[hash];

	while (en != 0) {
		if (strcmp(en->key, key) == 0) {    // Found the key
			if (en->iValue == value) {
				return -1;
			} else {
				en->iValue = value;
				return 0;
			}
		}
		en = en->next;
	}

	printf("key: %s, hash: %ld\n", key, hash);
	en      = (table_entry *) malloc(sizeof(table_entry));
	en->key = (char *) malloc(sizeof(char) * strlen(key));
	strcpy(en->key, key);
	en->iValue = value;
	en->isStr  = 0;

	tbl->bucket[hash] = en;
	tbl->size++;

	return 0;
}

int table_add_double(table *tbl, char *key, double value) {
	long hash = hash_str(key) % tbl->capacity;

	table_entry *en = tbl->bucket[hash];

	while (en != 0) {
		if (strcmp(en->key, key) == 0) {    // Found the key
			if (en->dValue == value) {
				return -1;
			} else {
				en->dValue = value;
				return 0;
			}
		}
		en = en->next;
	}

	printf("key: %s, hash: %ld\n", key, hash);
	en      = (table_entry *) malloc(sizeof(table_entry));
	en->key = (char *) malloc(sizeof(char) * strlen(key));
	strcpy(en->key, key);
	en->dValue = value;
	en->isStr  = 0;

	tbl->bucket[hash] = en;
	tbl->size++;

	return 0;
}

int table_add_str(table *tbl, char *key, char *value) {
	long hash = hash_str(key) % tbl->capacity;

	table_entry *en = tbl->bucket[hash];

	while (en != 0) {
		if (strcmp(en->key, key) == 0) {    // Found the key
			if (strcmp(en->sValue, value) == 0) {
				return -1;
			} else {
				en->sValue = value;    // FIX THIS SHIT LULW
				return 0;
			}
		}
		en = en->next;
	}

	printf("key: %s, hash: %ld\n", key, hash);
	en      = (table_entry *) malloc(sizeof(table_entry));
	en->key = (char *) malloc(sizeof(char) * strlen(key));
	strcpy(en->key, key);
	en->sValue = (char *) malloc(sizeof(char) * strlen(value));
	strcpy(en->sValue, value);
	en->next          = tbl->bucket[hash];
	en->isStr         = 1;
	tbl->bucket[hash] = en;
	tbl->size++;

	return 0;
}

table_entry *table_get(table *tbl, char *key) {
	long hash = hash_str(key) % tbl->capacity;

	table_entry *en = tbl->bucket[hash];

	while (en != 0) {
		if (strcmp(en->key, key) == 0) return en;
		en = en->next;
	}

	return 0;
}

int table_remove(table *tbl, char *key) {
	long hash = hash_str(key) % tbl->capacity;

	table_entry *en   = tbl->bucket[hash];
	table_entry *prev = 0;
	while (en != 0) {
		if (strcmp(en->key, key) == 0) {
			if (prev)
				prev->next = en->next;
			else
				tbl->bucket[hash] = en->next;
			if (en->isStr) free(en->sValue);
			free(en->key);
			free(en);
		}
		prev = en;
		en   = en->next;
	}

	return 0;
}