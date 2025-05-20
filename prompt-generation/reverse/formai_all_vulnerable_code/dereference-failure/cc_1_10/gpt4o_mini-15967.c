//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

char **parse_csv_line(char *line, int *num_columns) {
    char **tokens = malloc(MAX_COLUMNS * sizeof(char *));
    if (!tokens) {
        perror("Unable to allocate memory for tokens");
        exit(EXIT_FAILURE);
    }
    
    char *token = strtok(line, ",");
    *num_columns = 0;
    
    while (token != NULL && *num_columns < MAX_COLUMNS) {
        tokens[*num_columns] = malloc((strlen(token) + 1) * sizeof(char));
        if (!tokens[*num_columns]) {
            perror("Unable to allocate memory for token");
            exit(EXIT_FAILURE);
        }
        strcpy(tokens[*num_columns], token);
        (*num_columns)++;
        token = strtok(NULL, ",");
    }
    return tokens;
}

void free_tokens(char **tokens, int num_columns) {
    for (int i = 0; i < num_columns; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int row_count = 0;

    while (fgets(line, sizeof(line), file)) {
        trim_newline(line);
        int num_columns = 0;
        char **tokens = parse_csv_line(line, &num_columns);
        
        printf("Row %d: ", ++row_count);
        for (int i = 0; i < num_columns; i++) {
            printf("[%s]", tokens[i]);
            if (i < num_columns - 1) {
                printf(", ");
            }
        }
        printf("\n");

        free_tokens(tokens, num_columns);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_csv(argv[1]);
    
    return 0;
}