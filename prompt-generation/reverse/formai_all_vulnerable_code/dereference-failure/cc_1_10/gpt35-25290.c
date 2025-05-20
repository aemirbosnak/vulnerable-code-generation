//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PW_LENGTH 8
#define MAX_PW_LENGTH 16
#define SPECIAL_CHARS "`~!@#$%^&*()-=_+[]\\;',./{}|:\"<>?"
#define NUM_SPECIAL_CHARS strlen(SPECIAL_CHARS)

char *generate_password(int length);

int main(void) {
    srand(time(NULL));  // seed random number generator
    int password_length;

    printf("Welcome to the Secure Password Generator!\n");
    printf("How long would you like your password to be? (Enter a number between %d and %d): ", MIN_PW_LENGTH, MAX_PW_LENGTH);
    scanf("%d", &password_length);

    // validate user input
    if (password_length < MIN_PW_LENGTH || password_length > MAX_PW_LENGTH) {
        printf("Invalid input. Please enter a number between %d and %d.\n", MIN_PW_LENGTH, MAX_PW_LENGTH);
        return 1;
    }

    // generate password
    char *password = generate_password(password_length);

    // print password
    printf("\nYour new password is: %s\n", password);

    // free allocated memory
    free(password);

    return 0;
}

char *generate_password(int length) {
    // allocate memory for password string
    char *password = malloc((length + 1) * sizeof(char));

    // add random characters to password string
    for (int i = 0; i < length; i++) {
        int char_type = rand() % 4;  // random number between 0 and 3

        switch (char_type) {
            case 0:  // lowercase letter
                password[i] = 'a' + rand() % 26;
                break;
            case 1:  // uppercase letter
                password[i] = 'A' + rand() % 26;
                break;
            case 2:  // digit
                password[i] = '0' + rand() % 10;
                break;
            case 3:  // special character
                password[i] = SPECIAL_CHARS[rand() % NUM_SPECIAL_CHARS];
                break;
        }
    }

    password[length] = '\0';  // terminate string

    return password;
}