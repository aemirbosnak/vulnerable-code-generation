//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csvReader(char **arr, int *size, FILE *fp) {
    char line[1024];
    int i = 0, j = 0, flag = 0;
    char **tempArr = NULL;

    if (fscanf(fp, "%[^\n]", line) == EOF) {
        return;
    }

    // Allocate memory for the array
    *size = strlen(line) / 2 + 1;
    arr = (char **)malloc((*size) * sizeof(char *));

    // Split the line into cells
    while (line[i] != '\0') {
        if (line[i] == ',') {
            arr[j] = (char *)malloc((i - j) * sizeof(char));
            memcpy(arr[j], line + j, i - j);
            j++;
            flag = 1;
        } else if (flag) {
            arr[j] = (char *)realloc(arr[j], ++i - j);
            arr[j][i - j] = line[i];
        } else {
            arr[j] = (char *)malloc(sizeof(char));
            arr[j][0] = line[i];
            j++;
        }
        i++;
    }

    // Handle the remaining cell
    if (arr[j] != NULL) {
        arr[j] = (char *)realloc(arr[j], i - j);
        arr[j][i - j] = '\0';
    }

    // Recursively read the next line
    csvReader(arr, size, fp);
}

int main() {
    char **arr = NULL;
    int size = 0;
    FILE *fp = fopen("data.csv", "r");

    csvReader(arr, &size, fp);

    // Print the data
    for (int i = 0; i < size; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            printf("%s,", arr[i][j]);
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}