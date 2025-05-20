//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256
#define MAX_CSV_COLUMNS 10

struct row {
    char data[MAX_CSV_COLUMNS][MAX_LINE_LENGTH];
};

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int columns = 0;
    struct row *data = NULL;

    file = fopen("data.csv", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    data = malloc(sizeof(struct row));

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (columns == 0) {
            token = strtok(line, ",");
            while (token != NULL) {
                strcpy(data[0].data[columns], token);
                columns++;
                token = strtok(NULL, ",");
            }
        } else {
            token = strtok(line, ",");
            for (int i = 0; i < columns; i++) {
                strcpy(data[1].data[i], token);
                token = strtok(NULL, ",");
            }
            data = realloc(data, sizeof(struct row) * (columns + 1));
            columns++;
        }
    }

    fclose(file);

    // Display data in a medieval-style table
    printf("|------------------------------------|\n");
    printf("|  %s |\n", data[0].data[0]);
    for (int i = 1; i < columns; i++) {
        printf("| %-25s |", data[0].data[i]);
    }
    printf("|\n|------------------------------------|\n");

    for (int i = 0; i < columns; i++) {
        printf("| %-25s |", data[1].data[i]);
    }
    printf("|\n");

    free(data);

    return 0;
}