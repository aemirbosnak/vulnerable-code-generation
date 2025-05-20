//Gemma-7B DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the main function
int main() {

    // Declare variables
    char **data = NULL;
    int num_records = 0;
    int i = 0, j = 0, k = 0;

    // Open the data file
    FILE *fp = fopen("data.txt", "r");

    // Read the number of records from the file
    fscanf(fp, "Number of records: %d", &num_records);

    // Allocate memory for the data
    data = (char **)malloc(num_records * sizeof(char *));

    // Read the data from the file
    for (i = 0; i < num_records; i++) {
        data[i] = (char *)malloc(1024 * sizeof(char));
        fscanf(fp, "%s", data[i]);
    }

    // Close the data file
    fclose(fp);

    // Print the data
    for (i = 0; i < num_records; i++) {
        printf("%s\n", data[i]);
    }

    // Calculate the average length of each record
    double avg_length = 0.0;
    for (i = 0; i < num_records; i++) {
        int length = strlen(data[i]);
        avg_length += length;
    }

    // Print the average length of each record
    printf("Average length of each record: %.2lf\n", avg_length / num_records);

    // Free the memory allocated for the data
    for (i = 0; i < num_records; i++) {
        free(data[i]);
    }

    // Free the memory allocated for the data pointer
    free(data);

    return 0;
}