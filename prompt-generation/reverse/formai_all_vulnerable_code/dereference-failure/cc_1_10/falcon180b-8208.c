//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOWER 'a'
#define UPPER 'A'
#define NUM '0'
#define SYMB '!'

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define DEFAULT_LENGTH 12

int main(int argc, char *argv[]) {
    int length = DEFAULT_LENGTH;
    char *password = NULL;

    // Check if length argument is provided
    if (argc > 1) {
        length = atoi(argv[1]);
        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid password length. Must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
            return 1;
        }
    }

    // Generate random password
    password = (char *) malloc(length + 1);
    if (password == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    srand(time(NULL));
    password[0] = LOWER;
    for (int i = 1; i < length; i++) {
        int rand_type = rand() % 4; // 0 = lowercase, 1 = uppercase, 2 = number, 3 = symbol
        switch (rand_type) {
            case 0:
                password[i] = LOWER;
                break;
            case 1:
                password[i] = UPPER;
                break;
            case 2:
                password[i] = NUM;
                break;
            case 3:
                password[i] = SYMB;
                break;
        }
    }
    password[length] = '\0';

    // Print password
    printf("Secure Password: %s\n", password);

    // Free memory
    free(password);

    return 0;
}