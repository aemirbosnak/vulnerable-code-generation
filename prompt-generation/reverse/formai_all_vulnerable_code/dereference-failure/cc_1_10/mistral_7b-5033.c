//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10
#define MAX_NUM_ROWS 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    int age;
    char city[MAX_LINE_LENGTH];
} row_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    row_t data[MAX_NUM_ROWS];
    int row_count = 0;

    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (row_count >= MAX_NUM_ROWS) {
            printf("Error: Maximum number of rows reached\n");
            fclose(fp);
            return 1;
        }

        token = strtok(line, ",");
        strcpy(data[row_count].name, token);

        token = strtok(NULL, ",");
        data[row_count].age = atoi(token);

        token = strtok(NULL, ",");
        strcpy(data[row_count].city, token);

        row_count++;
    }

    fclose(fp);

    printf("CSV Data:\n");
    for (int i = 0; i < row_count; i++) {
        printf("Row %d: Name=%s, Age=%d, City=%s\n", i + 1, data[i].name, data[i].age, data[i].city);
    }

    return 0;
}