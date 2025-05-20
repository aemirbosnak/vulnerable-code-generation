//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function generates a random lower case alphabet character
char generateLowercase() {
    return rand() % 26 + 'a';
}

// This function generates a random upper case alphabet character
char generateUppercase() {
    return rand() % 26 + 'A';
}

// This function generates a random number between 0 and 9
char generateNumber() {
    return rand() % 10 + '0';
}

// This function generates a random special character from a predefined list
char generateSpecial() {
    char special[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
    return special[rand() % 12];
}

// This function generates a random password of a given length using the above functions
char* generatePassword(int length) {
    char* password = (char*)malloc(sizeof(char) * (length + 1)); // allocate memory for password string
    int i;
    for (i = 0; i < length; i++) {
        int type = rand() % 4; // randomly select which type of character to generate
        switch (type) {
            case 0:
                password[i] = generateLowercase();
                break;
            case 1:
                password[i] = generateUppercase();
                break;
            case 2:
                password[i] = generateNumber();
                break;
            case 3:
                password[i] = generateSpecial();
                break;
        }
    }
    password[length] = '\0'; // add null terminator to end of password string
    return password;
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);
    char* password = generatePassword(length);
    printf("Your generated password is: %s\n", password);
    free(password); // free allocated memory
    return 0;
}