//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 8
#define UPPER 1
#define LOWER 2
#define DIGIT 4
#define SPECIAL 8

// Function to generate random password
char *generate_password(int length) {
    char *pw = (char *)malloc(length * sizeof(char));
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int random_char_type;
        switch (i % 4) {
            case 0:
                random_char_type = UPPER;
                break;
            case 1:
                random_char_type = LOWER;
                break;
            case 2:
                random_char_type = DIGIT;
                break;
            case 3:
                random_char_type = SPECIAL;
                break;
            default:
                random_char_type = rand() % 4;
        }
        int random_char_index = rand() % 5;
        switch (random_char_type) {
            case UPPER:
                pw[i] = 'A' + random_char_index;
                break;
            case LOWER:
                pw[i] = 'a' + random_char_index;
                break;
            case DIGIT:
                pw[i] = '0' + random_char_index;
                break;
            case SPECIAL:
                pw[i] = '!' + random_char_index;
                break;
            default:
                pw[i] = 'A' + random_char_index;
        }
    }

    return pw;
}

int main() {
    char *password = generate_password(LENGTH);
    printf("Generated Password: %s\n", password);
    free(password);
    return 0;
}