//FormAI DATASET v1.0 Category: File handling ; Style: paranoid
/*
This C program reads and writes data to a file in paranoid mode.
The user must enter a secret password to access the data.
If the password is incorrect, the program will terminate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20
#define MAX_DATA_LEN 100
#define FILENAME "data.bin"

int main() {
    char password[MAX_PASSWORD_LEN];
    char data[MAX_DATA_LEN];

    // Get the password from the user
    printf("Enter the secret password: ");
    fgets(password, MAX_PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';  // remove newline character

    // Open the file for reading/writing in binary mode
    FILE* file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    // Verify the password
    char stored_password[MAX_PASSWORD_LEN];
    fread(stored_password, sizeof(char), MAX_PASSWORD_LEN, file);
    if (strcmp(password, stored_password) != 0) {
        printf("Incorrect password. Access denied.\n");
        exit(1);
    }

    // Get data to write to the file
    printf("Enter data to write to the file: ");
    fgets(data, MAX_DATA_LEN, stdin);
    data[strcspn(data, "\n")] = '\0';  // remove newline character

    // Write the data to the file
    fseek(file, MAX_PASSWORD_LEN, SEEK_SET);
    fwrite(data, sizeof(char), strlen(data), file);

    // Close the file
    fclose(file);

    printf("Data written to file. Exiting program.\n");
    return 0;
}