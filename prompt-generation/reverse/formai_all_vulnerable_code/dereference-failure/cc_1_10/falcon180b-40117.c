//Falcon-180B DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        printf("Usage: %s <filename> <mode>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *mode = argv[2];

    FILE *file = NULL;
    char line[MAX_LINE_SIZE];
    char *error_message = NULL;

    if (strcmp(mode, "r") == 0) {
        // Open the file for reading
        file = fopen(filename, "r");
        if (file == NULL) {
            error_message = "Could not open file for reading";
            goto error;
        }
    } else if (strcmp(mode, "w") == 0) {
        // Open the file for writing
        file = fopen(filename, "w");
        if (file == NULL) {
            error_message = "Could not open file for writing";
            goto error;
        }
    } else {
        error_message = "Invalid mode";
        goto error;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        printf("%s", line);
    }

    if (ferror(file)) {
        error_message = "Error reading from file";
        goto error;
    }

    fclose(file);
    return 0;

error:
    if (file!= NULL) {
        fclose(file);
    }
    if (error_message == NULL) {
        error_message = "An error occurred";
    }
    perror(error_message);
    return 1;
}