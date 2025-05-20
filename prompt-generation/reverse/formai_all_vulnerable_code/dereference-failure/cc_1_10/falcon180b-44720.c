//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to read a line from a CSV file
char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Allocate memory for the line
    line = malloc(100);
    if (line == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    // Read a line from the file
    while ((read = getline(&line, &len, fp))!= -1) {
        if (read > 0) {
            // Remove the newline character from the end of the line
            line[read - 1] = '\0';
            break;
        }
        // Reallocate memory if the line is too long
        line = realloc(line, len + 100);
    }

    return line;
}

// Function to read a CSV file recursively
void read_csv_file(FILE *fp) {
    char *line;

    // Read the first line of the file
    line = read_line(fp);

    // Print the first line (header)
    printf("%s\n", line);

    // Read the rest of the file recursively
    while ((line = read_line(fp))!= NULL) {
        // Split the line into fields
        char **fields = NULL;
        int count = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            fields = realloc(fields, sizeof(char *) * ++count);
            fields[count - 1] = token;
            token = strtok(NULL, ",");
        }

        // Print the fields
        for (int i = 0; i < count; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        // Free the memory allocated for the fields
        for (int i = 0; i < count; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    read_csv_file(fp);

    fclose(fp);
    return 0;
}