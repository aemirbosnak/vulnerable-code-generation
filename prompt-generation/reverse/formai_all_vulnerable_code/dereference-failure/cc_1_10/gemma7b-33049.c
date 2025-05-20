//Gemma-7B DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 255

typedef struct Record {
    char name[255];
    int age;
    struct Record* next;
} Record;

void insertRecord(Record** head, char* name, int age) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (*head == NULL) {
        *head = newRecord;
    } else {
        (*head)->next = newRecord;
    }
}

void queryRecords(Record* head, char* query) {
    char* queryLower = strdup(query);
    char* nameLower = strdup(head->name);

    // Case-insensitive name search
    if (strstr(nameLower, queryLower) != NULL) {
        printf("%s is %d years old.\n", head->name, head->age);
    }

    // Traverse the linked list
    Record* currentRecord = head->next;
    while (currentRecord) {
        nameLower = strdup(currentRecord->name);
        if (strstr(nameLower, queryLower) != NULL) {
            printf("%s is %d years old.\n", currentRecord->name, currentRecord->age);
        }
        currentRecord = currentRecord->next;
    }
}

int main() {
    Record* head = NULL;

    insertRecord(&head, "John Doe", 25);
    insertRecord(&head, "Jane Doe", 30);
    insertRecord(&head, "Bill Smith", 40);

    char query[MAX_QUERY_LENGTH];

    printf("Enter your query: ");
    scanf("%s", query);

    queryRecords(head, query);

    return 0;
}