//Gemma-7B DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_QUERY_LENGTH 256

int main() {

    // Database structure
    typedef struct Record {
        char name[256];
        int age;
        struct Record* next;
    } Record;

    // Allocate memory for the database
    Record* head = malloc(sizeof(Record));
    head->name[0] = '\0';
    head->age = 0;
    head->next = NULL;

    // Insert records into the database
    Record* current = head;
    current->next = malloc(sizeof(Record));
    current = current->next;
    current->name[0] = 'a';
    current->age = 20;
    current->next = malloc(sizeof(Record));
    current = current->next;
    current->name[0] = 'b';
    current->age = 25;
    current->next = NULL;

    // Query the database
    char query[MAX_QUERY_LENGTH];
    printf("Enter your query: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);

    // Parse the query
    char* keyword = strchr(query, ' ');
    char* name = strdup(keyword + 1);

    // Search for records matching the query
    Record* result = head;
    while (result) {
        if (strcmp(result->name, name) == 0) {
            printf("Name: %s, Age: %d\n", result->name, result->age);
        }
        result = result->next;
    }

    return 0;
}