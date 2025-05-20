//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 25
#define SPECIAL_CHARS "!@#$%^&*()-=_+[]{}|;:',.<>/?"
#define NUM_DIGITS "0123456789"
#define ALPHABETS_UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABETS_LOWER "abcdefghijklmnopqrstuvwxyz"

int main(void) {
    srand(time(NULL)); // seed the random number generator

    int length; // length of password
    char password[MAX_LENGTH] = ""; // password variable
    int num_digits, num_special_chars, num_uppercase, num_lowercase, num_remaining;
    char random_char;

    // Prompt user for password length
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);

    // Generate random characters
    num_digits = rand() % (length/4); // at least 1/4th of the password should be digits
    num_special_chars = rand() % ((length-num_digits)/4); // at least 1/4th of the remaining password should be special characters
    num_uppercase = rand() % ((length-num_digits-num_special_chars)/2); // at least 1/2 of the remaining password should be uppercase letters
    num_lowercase = length - (num_digits+num_special_chars+num_uppercase); // remaining characters should be lowercase letters

    // Ensure that the total number of characters generated equal to the password length
    num_remaining = length - num_digits - num_special_chars - num_uppercase - num_lowercase;
    if (num_remaining > 0) {
        num_lowercase += num_remaining;
    }

    // Add random digits to password
    for (int i = 0; i < num_digits; i++) {
        random_char = NUM_DIGITS[rand() % strlen(NUM_DIGITS)];
        password[i] = random_char;
    }

    // Add random special characters to password
    for (int i = num_digits; i < num_digits+num_special_chars; i++) {
        random_char = SPECIAL_CHARS[rand() % strlen(SPECIAL_CHARS)];
        password[i] = random_char;
    }

    // Add random uppercase letters to password
    for (int i = num_digits+num_special_chars; i < num_digits+num_special_chars+num_uppercase; i++) {
        random_char = ALPHABETS_UPPER[rand() % strlen(ALPHABETS_UPPER)];
        password[i] = random_char;
    }

    // Add random lowercase letters to password
    for (int i = num_digits+num_special_chars+num_uppercase; i < length; i++) {
        random_char = ALPHABETS_LOWER[rand() % strlen(ALPHABETS_LOWER)];
        password[i] = random_char;
    }

    // Shuffle the password characters randomly
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("\nYour secure password is: %s\n", password);

    return 0;
}