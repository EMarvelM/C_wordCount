#ifndef MAIN_H
#define MAIN_H

/**
 * hash_node_t - nodes of array of a hash table
 * key: hash key
 * value: value of the key
 * next: pointer to next node
*/
typedef struct hash_node_t
{
    char *key;
    int value;
    struct hash_node_t *next;
}hash_n;

/**
 * hash_table_t - store the hash table in array
 * array: the array of the hash table
 * size: the size of the hash table
*/
typedef struct hash_table_t
{
    hash_n **array;
    unsigned long int size;
}hash_t;



#include <stdio.h>
#include <stdlib.h>/*exit,*/
#include <stdbool.h>/*true*/
#include <string.h>/*strtok*/
#include <ctype.h>/*tolower*/

hash_t *create_ht(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
hash_n *addToNode(hash_t *ht, char *next_t);
void convertToLower(char *str);
void printall(hash_t *ht);

#endif /* MAIN_H */