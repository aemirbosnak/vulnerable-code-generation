//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 12
#define MAX_LEN 20

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    int range = max - min + 1;
    int random = rand() % range;
    return random + min;
}

// Function to generate a random character from a given set
char random_char(int set) {
    if (set & 1) // lowercase
        return rand() % 26 + 'a';
    if (set & 2) // uppercase
        return rand() % 26 + 'A';
    if (set & 4) // digits
        return rand() % 10 + '0';
    if (set & 8) // special characters
        return rand() % 33 + '!';
    return '\0';
}

// Function to generate a random password
void generate_password(char* password, int len) {
    int i;
    for (i = 0; i < len; i++) {
        password[i] = random_char(rand() % 15); // Generate a random character from the given set
    }
    password[len] = '\0'; // Null terminate the string
}

int main(int argc, char* argv[]) {
    srand(time(NULL)); // Seed the random number generator with the current time

    if (argc < 2) {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    int len = atoi(argv[1]);
    if (len < MIN_LEN || len > MAX_LEN) {
        printf("Invalid length. Must be between %d and %d.\n", MIN_LEN, MAX_LEN);
        return 1;
    }

    char password[len + 1]; // Allocate memory for the password string
    generate_password(password, len); // Generate the password
    printf("Generated password: %s\n", password);

    return 0;
}