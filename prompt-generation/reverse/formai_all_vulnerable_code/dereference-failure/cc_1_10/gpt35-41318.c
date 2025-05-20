//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_FIELDS 100

/* Function declarations */
void parse_csv(char *filename);
char **split_line(char *line, const char *delimiter, int *num_fields);
void free_fields(char **fields, int num_fields);

int main()
{
    char filename[MAX_LEN];
    printf("Enter the name of the CSV file: ");
    fgets(filename, MAX_LEN, stdin);

    // Remove newline character
    filename[strcspn(filename, "\n")] = 0;

    parse_csv(filename);

    return 0; // End program
}

/* Function to parse CSV file */
void parse_csv(char *filename) {
    FILE *fp;
    char line[MAX_LEN];
    const char *delimiter = ",";
    char **fields;

    fp = fopen(filename, "r"); // Open file in read mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1); // Exit program
    }

    printf("\nCSV File Contents: \n");

    // Read each line of the file and split it by delimiter
    while (fgets(line, MAX_LEN, fp) != NULL) {
        int num_fields;
        fields = split_line(line, delimiter, &num_fields);

        // Print each field of the line
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }

        printf("\n");

        free_fields(fields, num_fields);
    }

    fclose(fp); // Close the file
}

/* Function to split line by delimiter */
char **split_line(char *line, const char *delimiter, int *num_fields) {
    char **fields = (char **) malloc(sizeof(char *) * MAX_FIELDS);
    char *token;

    token = strtok(line, delimiter);

    int i = 0;
    while (token != NULL) {
        // Allocate space for field and copy token into it
        fields[i] = (char *) malloc(strlen(token) + 1);
        strcpy(fields[i], token);

        i++;
        token = strtok(NULL, delimiter);
    }

    *num_fields = i; // Set number of fields

    return fields; // Return array of fields
}

/* Function to free fields array */
void free_fields(char **fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }

    free(fields);
}