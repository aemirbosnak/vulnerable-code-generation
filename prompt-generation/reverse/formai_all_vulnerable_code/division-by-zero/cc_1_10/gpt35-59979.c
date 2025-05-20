//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
#define MAX_LEN 20

void generate_password(char *password);
void shuffle(char *array, size_t n);

int main() {
    char password[MAX_LEN];
    int i;

    srand(time(NULL));

    printf("Your secure password is: ");

    generate_password(password);

    printf("%s\n\n", password);

    return 0;
}

void generate_password(char *password) {
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+{}|:?><=[]\\;,./";
    char charset[MAX_LEN + 1];

    int num_lowercase = 0, num_uppercase = 0, num_numbers = 0, num_symbols = 0;
    int total_chars, i, j;
    int num_lowercase_needed, num_uppercase_needed, num_numbers_needed, num_symbols_needed;

    // Determine how many characters of each type are needed for the password
    total_chars = rand() % (MAX_LEN - 5) + 6;
    num_lowercase_needed = rand() % (total_chars - 3) + 2;
    num_uppercase_needed = rand() % (total_chars - num_lowercase_needed - 2) + 1;
    num_numbers_needed = rand() % (total_chars - num_lowercase_needed - num_uppercase_needed - 1) + 1;
    num_symbols_needed = total_chars - num_lowercase_needed - num_uppercase_needed - num_numbers_needed;

    // Generate characters for each type as needed
    for (i = 0; i < num_lowercase_needed; i++) {
        charset[num_lowercase++] = lowercase[rand() % strlen(lowercase)];
    }
    for (i = 0; i < num_uppercase_needed; i++) {
        charset[num_uppercase++] = uppercase[rand() % strlen(uppercase)];
    }
    for (i = 0; i < num_numbers_needed; i++) {
        charset[num_numbers++] = numbers[rand() % strlen(numbers)];
    }
    for (i = 0; i < num_symbols_needed; i++) {
        charset[num_symbols++] = symbols[rand() % strlen(symbols)];
    }

    // Shuffle the characters
    shuffle(charset, strlen(charset));

    // Assign the password
    for (i = 0; i < total_chars; i++) {
        password[i] = charset[i];
    }
    password[i] = '\0';
}

void shuffle(char *array, size_t n) {
    int i, j;
    char temp;

    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}