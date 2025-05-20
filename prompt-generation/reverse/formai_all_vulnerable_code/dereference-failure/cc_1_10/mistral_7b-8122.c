//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_LINE_LENGTH 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char **data;
    int rows = 0, cols = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (!fp) die("Could not open file");

    while (fgets(line, sizeof(line), fp)) {
        if (++rows > 1) {
            data = malloc(sizeof(char *) * cols);
            char *token = strtok(line, ",");
            for (int i = 0; i < cols; i++) {
                data[i] = malloc(strlen(token) + 1);
                strcpy(data[i], token);
                token = strtok(NULL, ",");
            }
            cols = (token == NULL) ? cols : cols + 1;
        }
    }

    if (rows == 0) {
        fprintf(stderr, "File is empty\n");
        exit(1);
    }

    printf("%d rows, %d columns\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s\t", data[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < cols; i++) free(data[i]);
    free(data);

    fclose(fp);
    return 0;
}