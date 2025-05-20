//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Array of funny words
char *funny_words[] = {
    "abracadabra", "alligator", "banana", "booger", "bubblegum", "coconuts", "dinosaur", "elephant", "funny", "giggle",
    "hippopotamus", "icecream", "jellyfish", "kangaroo", "lion", "monkey", "noodle", "octopus", "pineapple", "queen",
    "rainbow", "silly", "tiger", "umbrella", "violin", "watermelon", "xylophone", "zebra"
};

// Array of special characters
char *special_characters[] = {
    "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "-", "+", "=", "{", "}", "[", "]", "|", "\\", "/", "?", ".",
    ","
};

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random word from the funny_words array
char *random_word() {
    return funny_words[random_number(0, sizeof(funny_words) / sizeof(char *))];
}

// Function to generate a random special character from the special_characters array
char random_special_character() {
    return special_characters[random_number(0, sizeof(special_characters) / sizeof(char))];
}

// Function to generate a random password of length n
char *generate_password(int n) {
    char *password = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            password[i] = random_word()[random_number(0, strlen(random_word()) - 1)];
        } else {
            password[i] = random_special_character();
        }
    }
    password[n] = '\0';
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int n;
    printf("How many characters do you want in your password? ");
    scanf("%d", &n);

    // Generate a random password
    char *password = generate_password(n);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}