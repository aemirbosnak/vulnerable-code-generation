//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
void welcome() {
    printf("***********************************************************************\n");
    printf("*                Welcome to the Data Recovery Tool!                    *\n");
    printf("***********************************************************************\n\n");
}

// Get user input
char *get_input(char *prompt) {
    char *input = NULL;
    size_t len = 0;
    printf("%s", prompt);
    getline(&input, &len, stdin);
    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;
    return input;
}

// Recover data from a file
char *recover_data(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    // Read the file contents
    char *data = malloc(filesize);
    if (data == NULL) {
        printf("Error: Could not allocate memory to read file %s\n", filename);
        fclose(fp);
        return NULL;
    }
    fread(data, filesize, 1, fp);
    fclose(fp);

    // Return the data
    return data;
}

// Save data to a file
void save_data(char *filename, char *data, size_t length) {
    // Open the file
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Write the data to the file
    fwrite(data, length, 1, fp);
    fclose(fp);

    // Success message
    printf("Data successfully saved to file %s\n", filename);
}

// Main function
int main() {
    // Welcome the user
    welcome();

    // Get the filename
    char *filename = get_input("Enter the filename: ");

    // Recover the data from the file
    char *data = recover_data(filename);
    if (data == NULL) {
        printf("Error: Could not recover data from file %s\n", filename);
        return EXIT_FAILURE;
    }

    // Get the new filename
    char *new_filename = get_input("Enter the new filename: ");

    // Save the data to the new file
    save_data(new_filename, data, strlen(data));

    // Free the memory
    free(data);
    free(filename);
    free(new_filename);

    return EXIT_SUCCESS;
}