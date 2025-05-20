//Gemma-7B DATASET v1.0 Category: Database querying ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUERY_SIZE 10

typedef struct Query {
    char query_type;
    char field_name[20];
    int condition_type;
    union {
        int value;
        char *string_value;
    } value_union;
} Query;

void execute_query(Query *queries, int num_queries) {
    for (int i = 0; i < num_queries; i++) {
        switch (queries[i].query_type) {
            case 'S':
                printf("Value of field '%s' is: %s\n", queries[i].field_name, queries[i].value_union.string_value);
                break;
            case 'I':
                printf("Value of field '%s' is: %d\n", queries[i].field_name, queries[i].value_union.value);
                break;
            default:
                printf("Invalid query type\n");
                break;
        }
    }
}

int main() {
    int num_queries = 5;
    Query *queries = (Query *)malloc(num_queries * sizeof(Query));

    queries[0].query_type = 'S';
    strcpy(queries[0].field_name, "name");
    queries[0].condition_type = 1;
    queries[0].value_union.string_value = "John Doe";

    queries[1].query_type = 'I';
    strcpy(queries[1].field_name, "age");
    queries[1].condition_type = 2;
    queries[1].value_union.value = 25;

    queries[2].query_type = 'S';
    strcpy(queries[2].field_name, "address");
    queries[2].condition_type = 1;
    queries[2].value_union.string_value = "123 Main St";

    queries[3].query_type = 'I';
    strcpy(queries[3].field_name, "phone");
    queries[3].condition_type = 2;
    queries[3].value_union.value = 123456;

    queries[4].query_type = 'S';
    strcpy(queries[4].field_name, "email");
    queries[4].condition_type = 1;
    queries[4].value_union.string_value = "john.doe@example.com";

    execute_query(queries, num_queries);

    free(queries);

    return 0;
}