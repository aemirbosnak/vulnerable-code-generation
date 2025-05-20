//Gemma-7B DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
    char **data = NULL;
    int i, j, k, l, n, m;

    // Allocate memory for the data
    data = (char **)malloc(MAX * sizeof(char *));
    for(i = 0; i < MAX; i++) {
        data[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the data from the file
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    n = 0;
    while(!feof(fp)) {
        fgets(data[n], MAX, fp);
        n++;
    }

    fclose(fp);

    // Analyze the data
    m = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < MAX; j++) {
            if(data[i][j] != '\0') {
                m++;
            }
        }
    }

    // Print the number of non-blank characters
    printf("The number of non-blank characters is: %d\n", m);

    // Free the memory
    for(i = 0; i < MAX; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}