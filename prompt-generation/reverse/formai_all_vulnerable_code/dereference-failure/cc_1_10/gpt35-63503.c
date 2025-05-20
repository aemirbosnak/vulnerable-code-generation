//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_csv_file(char *filename) {
    char *content = NULL;
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long length = ftell(file);
        fseek(file, 0, SEEK_SET);
        content = malloc(length + 1);
        if (content) {
            fread(content, 1, length, file);
            content[length] = '\0';
        }
        fclose(file);
    }
    return content;
}

char **parse_csv(char *csv_content) {
    char **rows = malloc(sizeof(char*) * 100);
    int row_count = 0;
    char *token;
    char *line = strtok(csv_content, "\n");
    while (line != NULL) {
        rows[row_count] = malloc(sizeof(char) * 100);
        strcpy(rows[row_count], line);
        row_count++;
        line = strtok(NULL, "\n");
    }
    return rows;
}

void print_csv(char **rows) {
    int row_count = 0;
    while (rows[row_count] != NULL) {
        int col_count = 0;
        char *line = rows[row_count];
        char *token = strtok(line, ",");
        printf("Row %d: ", row_count + 1);
        while (token != NULL) {
            printf("| %s ", token);
            token = strtok(NULL, ",");
            col_count++;
        }
        printf("|\n");
        row_count++;
    }
}

void free_csv(char **rows) {
    int row_count = 0;
    while (rows[row_count] != NULL) {
        free(rows[row_count]);
        row_count++;
    }
    free(rows);
}

int main() {

    char *csv_content = read_csv_file("example.csv");
    if (csv_content == NULL) {
        printf("Oh no! The CSV file is missing!\n");
        return 1;
    }

    printf("\n\n$$$$$$$$$$ Parsing the CSV file. Hold on tight! $$$$$$$$$$\n\n");
    char **rows = parse_csv(csv_content);
    print_csv(rows);
    free_csv(rows);
    free(csv_content);

    printf("\n\nBA DUM TSSSS!!!! That's it folks. See you next time!\n");

    return 0;
}