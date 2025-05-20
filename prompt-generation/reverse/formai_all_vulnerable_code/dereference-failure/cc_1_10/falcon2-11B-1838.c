//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string by delimiter
char **strsplit(char *str, char delimiter) {
    char **result;
    int len = strlen(str);
    char *token;
    int i, j, n = 0;

    result = (char **)malloc(len * sizeof(char *));

    for (i = 0; i < len; i++) {
        if (str[i] == delimiter) {
            token = (char *)malloc((j + 1) * sizeof(char));
            strcpy(token, str + i);
            result[n] = token;
            n++;
            j = 0;
        } else {
            str[j++] = str[i];
        }
    }

    result[n] = NULL;
    return result;
}

// Function to read a CSV file
void read_csv(char *filename, int *rows, int *cols) {
    FILE *fp;
    char line[1000];
    char **fields;
    char *token;
    int i, j, n;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        n = 0;
        fields = strsplit(line, ",");
        for (i = 0; i < (*cols); i++) {
            (*rows)++;
            printf("%s", fields[i]);
            free(fields[i]);
        }
        free(fields);
    }

    fclose(fp);
}

int main() {
    int rows, cols;
    read_csv("data.csv", &rows, &cols);
    printf("Read %d rows and %d columns from the file\n", rows, cols);
    return 0;
}