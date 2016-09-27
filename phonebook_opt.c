#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/*Construct hash talbe*/
hashTable *hashInitial()
{
    hashTable *ht = NULL;
    ht = (hashTable *)malloc(sizeof(hashTable));
    ht->list = (entry **)malloc(sizeof(entry *)*HASHTABLE_SIZE);
    for (int i = 0; i < HASHTABLE_SIZE; i++)
        ht->list[i] = NULL;

    return ht;
}

/*get the hash value
unsigned int hashFunction(char *lastName){
    unsigned int hashVal = 0;
    while (*lastName != '\0')
        hashVal = (hashVal << 5) + *lastName++;

    return hashVal % HASHTABLE_SIZE;
}*/

unsigned int hashFunction(char *str)
{
    unsigned int seed = 131;
    // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str)
        hash = hash * seed + (*str++);

    return hash % HASHTABLE_SIZE;
}

int hashAppend(char *lastName, hashTable *ht)
{
    entry *newEntry;
    newEntry = (entry *)malloc(sizeof(entry));
    strncpy(newEntry->lastName, lastName, MAX_LAST_NAME_SIZE);
    newEntry->pNext = ht->list[hashFunction(lastName)];
    ht->list[hashFunction(lastName)] = newEntry;
    return 0;
}

entry *hashFindName(char *lastName, hashTable *ht)
{
    entry *e;
    e = ht->list[hashFunction(lastName)];
    while (e->pNext != NULL) {
        if (strncasecmp(lastName, e->lastName, MAX_LAST_NAME_SIZE) == 0)
            return NULL;

        e = e->pNext;
    }
    return 0;
}

