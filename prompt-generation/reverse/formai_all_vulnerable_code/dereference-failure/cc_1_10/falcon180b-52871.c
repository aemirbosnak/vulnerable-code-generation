//Falcon-180B DATASET v1.0 Category: Database querying ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1024
#define MAX_COLUMNS 16
#define MAX_ROWS 1024

typedef struct {
    char *name;
    int type;
} Column;

typedef struct {
    Column columns[MAX_COLUMNS];
    int num_rows;
    int num_columns;
    char **data;
} ResultSet;

void execute_query(char *query, ResultSet *result_set) {
    char *token = strtok(query, " ");
    while (token!= NULL) {
        if (strcmp(token, "SELECT") == 0) {
            token = strtok(NULL, " ");
            while (token!= NULL && result_set->num_columns < MAX_COLUMNS) {
                Column column;
                strcpy(column.name, token);
                result_set->columns[result_set->num_columns] = column;
                result_set->num_columns++;
                token = strtok(NULL, ",");
            }
        } else if (strcmp(token, "FROM") == 0) {
            token = strtok(NULL, " ");
            while (token!= NULL && result_set->num_rows < MAX_ROWS) {
                char *value = strtok(NULL, ",");
                if (value == NULL) {
                    printf("Error: Missing value for row.\n");
                    exit(1);
                }
                result_set->data[result_set->num_rows] = value;
                result_set->num_rows++;
            }
        }
        token = strtok(NULL, " ");
    }
}

void print_result_set(ResultSet *result_set) {
    printf("+----+");
    for (int i = 0; i < result_set->num_columns; i++) {
        printf("----+");
    }
    printf("\n");
    for (int i = 0; i < result_set->num_rows; i++) {
        for (int j = 0; j < result_set->num_columns; j++) {
            printf("| %s |", result_set->data[i]);
        }
        printf("\n+----+");
    }
}

int main() {
    char query[MAX_QUERY_LENGTH];
    printf("Enter a query:\n");
    fgets(query, MAX_QUERY_LENGTH, stdin);
    ResultSet result_set;
    execute_query(query, &result_set);
    print_result_set(&result_set);
    return 0;
}