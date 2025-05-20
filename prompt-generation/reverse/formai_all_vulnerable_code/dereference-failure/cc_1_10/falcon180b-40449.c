//Falcon-180B DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_RESULT_LENGTH 1024

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *results;
    int count;
} QueryResult;

void query_database(const char *query, QueryResult *result) {
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open database file.\n");
        exit(1);
    }

    char line[MAX_QUERY_LENGTH];
    while (fgets(line, MAX_QUERY_LENGTH, fp)!= NULL) {
        Person person;
        int fields_parsed = sscanf(line, "%s %d", person.name, &person.age);
        if (fields_parsed == 2) {
            if (strcmp(person.name, query) == 0) {
                result->results = realloc(result->results, sizeof(Person) * (result->count + 1));
                result->results[result->count] = person;
                result->count++;
            }
        }
    }

    fclose(fp);
}

void print_query_results(const QueryResult *result) {
    if (result->count == 0) {
        printf("No results found.\n");
    } else {
        printf("Query results:\n");
        for (int i = 0; i < result->count; i++) {
            printf("Name: %s, Age: %d\n", result->results[i].name, result->results[i].age);
        }
    }
}

int main() {
    char query[MAX_QUERY_LENGTH];
    printf("Enter a name to search for in the database: ");
    fgets(query, MAX_QUERY_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0';

    QueryResult result;
    query_database(query, &result);
    print_query_results(&result);

    for (int i = 0; i < result.count; i++) {
        free(result.results[i].name);
    }
    free(result.results);

    return 0;
}