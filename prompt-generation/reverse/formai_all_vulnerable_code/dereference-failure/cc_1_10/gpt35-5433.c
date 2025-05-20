//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

char* generate_password() {
    char* password = malloc(sizeof(char) * PASSWORD_LENGTH); // allocate memory for password

    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special_characters[] = "!@#$%^&*()_+";

    int lowercase_count = 0;
    int uppercase_count = 0;
    int number_count = 0;
    int special_count = 0;
    int i;

    // seed random number generator using time
    srand(time(NULL)); 

    // password generator loop
    for(i = 0; i < PASSWORD_LENGTH; i++) {
        switch(rand() % 4) {
            case 0: // lowercase letter
                password[i] = lowercase_letters[rand() % 26];
                lowercase_count++;
                break;
            case 1: // uppercase letter
                password[i] = uppercase_letters[rand() % 26];
                uppercase_count++;
                break;
            case 2: // number
                password[i] = numbers[rand() % 10];
                number_count++;
                break;
            case 3: // special character
                password[i] = special_characters[rand() % 10];
                special_count++;
                break;
        }
    }

    // check that password meets criteria
    if(lowercase_count < 2) { // at least two lowercase letters
        password[rand() % PASSWORD_LENGTH] = lowercase_letters[rand() % 26];
    }
    if(uppercase_count < 2) { // at least two uppercase letters
        password[rand() % PASSWORD_LENGTH] = uppercase_letters[rand() % 26];
    }
    if(number_count < 2) { // at least two numbers
        password[rand() % PASSWORD_LENGTH] = numbers[rand() % 10];
    }
    if(special_count < 2) { // at least two special characters
        password[rand() % PASSWORD_LENGTH] = special_characters[rand() % 10];
    }

    password[PASSWORD_LENGTH] = '\0'; // terminate string

    return password;
}

int main() {
    char* password = generate_password();
    printf("Your secure password is: %s\n", password);
    free(password); // free memory used by password
    return 0;
}