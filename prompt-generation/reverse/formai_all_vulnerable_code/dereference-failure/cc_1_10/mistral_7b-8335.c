//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 100
#define BUFFER_SIZE 256

int main() {
    char input[MAX_LENGTH];
    char buffer[BUFFER_SIZE];
    FILE *file;
    int ch;
    int status;

    printf("Welcome to Error Handling Delight!\n");
    printf("This program reads a file and prints its content.\n");

    printf("Enter the file path: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    file = fopen(input, "r");
    if (file == NULL) {
        perror("Error opening file");
        printf("Error message: %s\n", strerror(errno));
        return 1;
    }

    printf("File %s opened successfully.\n", input);
    printf("Reading file content...\n");

    while ((ch = fgetc(file)) != EOF) {
        if (ferror(file)) {
            perror("Error reading file");
            printf("Error message: %s\n", strerror(errno));
            fclose(file);
            return 1;
        }
        if (fwrite(buffer, sizeof(char), 1, stdout) != 1) {
            perror("Error writing to stdout");
            printf("Error message: %s\n", strerror(errno));
            fclose(file);
            return 1;
        }
        buffer[strlen(buffer) - 1] = '\0';
        strcat(buffer, " ");
        strcat(buffer, &input[strlen(input) - strlen(input + strspn(input, "."))]);
        printf("%s", buffer);
    }

    fclose(file);
    printf("\nContent of file %s read successfully!\n", input);
    return 0;
}