//Falcon-180B DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_QUERY_LEN 1000

struct query_result {
    int num_rows;
    int num_cols;
    char **row_data;
};

struct query_result execute_query(char *query) {
    struct query_result result;
    char delimiter = ',';
    char *token = strtok(query, &delimiter);
    int num_rows = 0;
    int num_cols = 0;
    char **row_data = NULL;

    while (token!= NULL) {
        if (num_cols == 0) {
            num_cols = strlen(token);
        } else if (strlen(token)!= num_cols) {
            printf("Error: Query result has inconsistent number of columns.\n");
            exit(1);
        }

        num_rows++;
        token = strtok(NULL, &delimiter);
    }

    row_data = malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        row_data[i] = malloc(num_cols * sizeof(char));
    }

    rewind(stdin);
    fgets(query, MAX_QUERY_LEN, stdin);
    token = strtok(query, &delimiter);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            strncpy(row_data[i], token, num_cols);
            row_data[i][num_cols] = '\0';
            token = strtok(NULL, &delimiter);
        }
    }

    result.num_rows = num_rows;
    result.num_cols = num_cols;
    result.row_data = row_data;

    return result;
}

int main() {
    char query[MAX_QUERY_LEN];
    printf("Enter query:\n");
    fgets(query, MAX_QUERY_LEN, stdin);

    struct query_result result = execute_query(query);

    printf("Result:\n");
    for (int i = 0; i < result.num_rows; i++) {
        for (int j = 0; j < result.num_cols; j++) {
            printf("%s ", result.row_data[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < result.num_rows; i++) {
        free(result.row_data[i]);
    }
    free(result.row_data);

    return 0;
}