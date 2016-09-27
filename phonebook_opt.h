#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASHTABLE_SIZE 65537
/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
typedef struct __PHONEBOOK_DETAILS {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} details;

typedef struct __PHONEBOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONEBOOK_DETAILS *pDetails;
    struct __PHONEBOOK_ENTRY *pNext;
} entry;

typedef struct _PHONEBOOK_HASHTABLE {
    entry **list;
    unsigned int tableSize;
} hashTable;

hashTable *hashInitial();
//unsigned int hashFunction(char *lastName);
int hashAppend(char *lastName, hashTable *ht);
entry *hashFindName(char *lastName, hashTable *ht);
unsigned int hashFunction(char *str);
#endif
