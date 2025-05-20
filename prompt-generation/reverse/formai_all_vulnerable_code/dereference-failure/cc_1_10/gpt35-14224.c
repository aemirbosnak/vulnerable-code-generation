//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
/* 
    A decentralized Secure Password Generator Example program in C. 
    Generates a password string consisting of lowercase, uppercase, numbers, and special characters.

    By: [Your Name]

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 20
#define NUM_LETTERS 26
#define NUM_DIGITS 10
#define NUM_SPECIAL 11

char* generatePassword();

int main(){
    char* password = generatePassword();
    printf("Generated Password: %s\n", password);
    return 0;
}

char* generatePassword(){
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()_+-=~`|\\{}[]:;\"'<>,.?/";

    char* password = (char*)malloc((PASSWORD_LENGTH + 1) * sizeof(char)); 
    srand(time(0));

    int i;
    for(i = 0; i < PASSWORD_LENGTH; i++){
        int randomNum = rand() % 4; // generates a random number between 0-3

        switch(randomNum){
            case 0: // lowercase letter
                password[i] = letters[rand() % NUM_LETTERS];
                break;
            case 1: // uppercase letter
                password[i] = letters[rand() % NUM_LETTERS] - 32; // ascii conversion
                break;
            case 2: // digit
                password[i] = digits[rand() % NUM_DIGITS];
                break;
            case 3: // special character
                password[i] = special[rand() % NUM_SPECIAL];
                break;
        }
    }
    password[i] = '\0'; // adding null character to mark end of string
    return password;
}