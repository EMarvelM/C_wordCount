#include "main.h"

hash_t *create_ht(unsigned long int size)
{
    hash_t *ht = NULL;

    ht = malloc(sizeof(hash_t));
if (ht == NULL)
    {
        printf("Malloc failure!");
        exit(-1);
    }

    ht->size = size;
    ht->array = malloc(sizeof(hash_n *) * size);
    if (ht->array == NULL)
    {
        printf("Malloc failed!");
        exit(-1);
    }

    int i = 0;
    for (i = 0; i < size; i++)
    {
        ht->array[i] = NULL;
        /*printf("%d, ", i);*/
    }

    return (ht);
}


/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/*take the entire hash table and the word to count*/
hash_n *addToNode(hash_t *ht, char *next_t)
{
    unsigned long int key;

    /*hash each word and get the key*/
    key = hash_djb2(next_t);
    unsigned long int idx = key % ht->size;

    if (ht->array[idx] == NULL) {
        ht->array[idx] = malloc(sizeof(hash_n));
        if (ht->array[idx] == NULL) {
            printf("Malloc failed!\n");
            exit(-1);
        }
        ht->array[idx]->key = strdup(next_t);
        ht->array[idx]->value = 1;
        ht->array[idx]->next = NULL;
    } else {
        /* You should also handle the case where ht->array[idx] is not NULL.
         * In this case, you may want to update the value or perform other operations. */
        ht->array[idx]->value += 1;
    }

    //printf("key == %s\n", ht->array[idx]->key);
    //printf("Read: %s == %d\n", next_t, ht->array[idx]->value);

    return ht->array[idx];
}


void printall(hash_t *ht)
{
    unsigned long int i = 0;
    unsigned long int j = 0;
    unsigned long int uniq = 0;

    printf("Word Count Summary:\n\n");

    while (true && i < ht->size)
    {
        if (ht->array[i] != NULL)
        {
            j += ht->array[i]->value;
            uniq += 1;

        }
        i++;
    }
    printf("Total words: %ld\n", j);
    printf("Unique words: %ld\n\n", uniq);
    printf("Word Frequency: \n");

    i = 0;
    while (true && i < ht->size)
    {
        if (ht->array[i] != NULL)
        {
            printf("\"%s\" - %d\n", ht->array[i]->key, ht->array[i]->value);
        }
        i++;
    }
}


void convertToLower(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}
