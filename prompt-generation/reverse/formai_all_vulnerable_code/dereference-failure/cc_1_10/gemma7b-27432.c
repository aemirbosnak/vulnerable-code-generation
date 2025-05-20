//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char **metadata = NULL;
    char **key_value_pair = NULL;
    char key[256], value[256];
    int i = 0, j = 0, k = 0, n = 0;

    // Assuming the metadata is stored in a text file named "metadata.txt"
    FILE *fp = fopen("metadata.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for the metadata and key-value pair arrays
    metadata = malloc(n * sizeof(char *));
    key_value_pair = malloc(n * sizeof(char *));

    // Read the metadata from the file line by line
    while (getline(fp, key, 256) != -1)
    {
        // Remove the trailing newline character from the key
        key[strcspn(key, "\n")] = '\0';

        // Store the key-value pair
        key_value_pair[i] = malloc(strlen(key) + strlen(value) + 1);
        strcpy(key_value_pair[i], key);

        // Get the value for the key
        getline(fp, value, 256);

        // Remove the trailing newline character from the value
        value[strcspn(value, "\n")] = '\0';

        // Store the value
        key_value_pair[i][strlen(key) + 1] = value;

        i++;
    }

    // Print the key-value pairs
    for (j = 0; j < i; j++)
    {
        printf("%s: %s\n", key_value_pair[j], key_value_pair[j][strlen(key_value_pair[j]) - 1]);
    }

    // Free the memory allocated for the metadata and key-value pair arrays
    for (k = 0; k < i; k++)
    {
        free(key_value_pair[k]);
    }
    free(key_value_pair);
    free(metadata);

    fclose(fp);

    return 0;
}