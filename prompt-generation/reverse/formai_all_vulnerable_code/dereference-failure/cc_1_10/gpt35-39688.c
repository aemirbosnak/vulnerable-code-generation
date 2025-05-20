//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_BUFFER 1024

char **read_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s", filename);
        exit(1);
    }

    char buffer[MAX_BUFFER];
    char *token;
    int row = 0;
    int column = 0;
    
    // allocate memory for data
    char **data = (char **) malloc(sizeof(char *) * MAX_BUFFER);
    for (int i=0; i<MAX_BUFFER; i++) {
        data[i] = (char *) malloc(sizeof(char) * MAX_COLUMNS);
    }

    while (fgets(buffer, MAX_BUFFER, file)) {
        column = 0;
        token = strtok(buffer, ",\n");
        while (token != NULL) {
            data[row][column] = *token;
            column++;
            token = strtok(NULL, ",\n");
        }
        row++;
    }

    fclose(file);
    return data;
}

int main() {
    char **data = read_csv("example.csv");
    
    // print data
    for (int i=0; i<MAX_BUFFER; i++) {
        for (int j=0; j<MAX_COLUMNS; j++) {
            if (data[i][j] == '\0') {
                break;
            }
            printf("%c ", data[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i=0; i<MAX_BUFFER; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}