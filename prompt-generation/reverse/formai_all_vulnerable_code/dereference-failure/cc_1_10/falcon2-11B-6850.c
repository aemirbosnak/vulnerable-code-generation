//Falcon2-11B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Function to generate a random password
void generate_password(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        password[i] = 'A' + rand() % 26;
    }
}

// Function to store password in a file
void store_password(char *password, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(file, "%s\n", password);
    fclose(file);
}

// Function to read password from a file
char *read_password(char *filename) {
    char *password = (char *) malloc(10 * sizeof(char));
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    if (fgets(password, 10, file)!= NULL) {
        fclose(file);
        return password;
    }
    free(password);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <length> <filename>\n", argv[0]);
        return 1;
    }
    int length = atoi(argv[1]);
    char *filename = argv[2];

    // Generate a random password
    char *password = (char *) malloc(length * sizeof(char));
    generate_password(password, length);

    // Store the password in a file
    store_password(password, filename);

    // Read the password from the file
    char *stored_password = read_password(filename);

    // Print the stored password
    printf("Stored password: %s\n", stored_password);

    // Clean up
    free(password);
    free(stored_password);

    return 0;
}