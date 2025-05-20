//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32

// Function to generate a random password
char* generate_password(int length) {
    char* password = (char*)malloc(length + 1);
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password.\n");
        exit(1);
    }
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 94 + 33;
    }
    password[length] = '\0';
    return password;
}

// Function to securely store the password in a file
void store_password(char* password) {
    FILE* file = fopen("password.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        exit(1);
    }
    fprintf(file, "%s", password);
    fclose(file);
}

// Function to retrieve the password from the file
char* retrieve_password() {
    FILE* file = fopen("password.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        exit(1);
    }
    char* password = (char*)malloc(MAX_PASSWORD_LENGTH + 1);
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password.\n");
        exit(1);
    }
    fgets(password, MAX_PASSWORD_LENGTH + 1, file);
    fclose(file);
    return password;
}

int main() {
    // Generate a random password
    char* password = generate_password(8);

    // Store the password in a file
    store_password(password);

    // Retrieve the password from the file
    char* retrieved_password = retrieve_password();

    // Compare the original and retrieved passwords
    if (strcmp(password, retrieved_password) == 0) {
        printf("Passwords match.\n");
    } else {
        printf("Passwords do not match.\n");
    }

    free(password);
    free(retrieved_password);

    return 0;
}