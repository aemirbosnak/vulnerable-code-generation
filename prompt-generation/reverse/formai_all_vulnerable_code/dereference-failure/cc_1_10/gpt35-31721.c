//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LENGTH 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_data;

csv_data read_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error: Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    csv_data data;
    data.data = (char **) malloc(sizeof(char *) * MAX_ROWS);
    for (int i = 0; i < MAX_ROWS; i++) {
        data.data[i] = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH);
    }
    
    int row = 0;
    int col = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, file)) != -1 && row < MAX_ROWS) {
        line[strlen(line)-1] = '\0';  // Remove newline character
        char *token = strtok(line, ",");
        while (token != NULL && col < MAX_COLS) {
            strcpy(data.data[row * MAX_COLS + col], token);
            col++;
            token = strtok(NULL, ",");
        }
        data.cols = col;
        col = 0;
        row++;
    }
    data.rows = row;
    
    free(line);
    fclose(file);
    
    return data;
}

void print_csv(csv_data data) {
    for (int i = 0; i < data.rows; i++) {
        for (int j = 0; j < data.cols; j++) {
            printf("%s", data.data[i * MAX_COLS + j]);
            if (j != data.cols-1) {
                printf("%c", DELIMITER);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *filename = argv[1];
    
    csv_data data = read_csv(filename);
    printf("CSV data:\n");
    print_csv(data);
    
    for (int i = 0; i < data.rows; i++) {
        free(data.data[i]);
    }
    free(data.data);
    
    return 0;
}