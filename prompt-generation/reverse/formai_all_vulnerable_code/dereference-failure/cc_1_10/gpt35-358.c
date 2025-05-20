//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *csv;
    char filename[50], line[1024];

    printf("Enter the file name: ");
    scanf("%s", filename);

    csv = fopen(filename, "r");

    if (csv == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the header row
    fgets(line, 1024, csv);

    // Count the columns
    int num_cols = 1;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == ',')
            num_cols++;
    }

    // Store the data in arrays
    char **data = malloc(100 * sizeof(char*));
    for (int i = 0; i < 100; i++) {
        data[i] = malloc(num_cols+1);
    }

    int i = 0;
    while (fgets(line, 1024, csv)) {
        int j = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            strcpy(data[i][j], token);
            j++;
            token = strtok(NULL, ",");
        }
        i++;
    }

    // Print the data
    for (int j = 0; j < num_cols; j++) {
        for (int i = 0; i < 100; i++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    fclose(csv);

    return 0;
}