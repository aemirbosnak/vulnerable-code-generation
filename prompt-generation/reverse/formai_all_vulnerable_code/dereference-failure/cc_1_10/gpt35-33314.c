//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a secure password */
char* generate_password(int length) {
    /* Array of characters that can be in the password */
    char* charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]<>?,.\|/";

    /* Create a dynamic character array for the password */
    char* password = malloc(sizeof(char) * (length + 1));

    /* Set the random seed */
    srand(time(NULL));

    /* Populate the password array with random characters from the charset */
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    /* Add a null terminator to the end of the password array */
    password[length] = '\0';

    return password;
}

/* Main function */
int main() {
    int length;

    /* Get the desired length of the password from the user */
    printf("Enter the length of your desired password (minimum 6 characters): ");
    scanf("%d", &length);

    /* Make sure the length is at least 6 characters */
    if (length < 6) {
        printf("Invalid length. Password must be at least 6 characters long.\n");
        return 1;
    }

    /* Generate a secure password */
    char* password = generate_password(length);

    /* Display the password to the user */
    printf("Your secure password is: %s\n", password);

    /* Free the memory allocated for the password */
    free(password);

    return 0;
}