//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define NUM_SPECIAL_CHARS 5
#define NUM_DIGITS 5

char* generate_password(int length);

int main() {
    int password_length;
    char* password;

    srand(time(NULL));

    printf("Enter length of password (between %d to %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &password_length);

    if(password_length < MIN_LENGTH || password_length > MAX_LENGTH) {
        printf("Invalid password length. Password must be between %d to %d characters in length.\n", MIN_LENGTH, MAX_LENGTH);
        exit(1);
    }

    password = generate_password(password_length);

    printf("Your new password is: %s\n", password);

    free(password);

    return 0;
}

char* generate_password(int length) {
    char* password = (char*)malloc((length + 1) * sizeof(char));
    int i, r;

    int num_letters = length - NUM_SPECIAL_CHARS - NUM_DIGITS;

    for(i = 0; i < num_letters; i++) {
        password[i] = 'A' + rand() % 26;
    }

    for(i = num_letters; i < num_letters + NUM_DIGITS; i++) {
        password[i] = '0' + rand() % 10;
    }

    for(i = num_letters + NUM_DIGITS; i < length; i++) {
        do {
            r = rand() % 26;
        } while (r == 0 || r == 4 || r == 8 || r == 14 || r == 20);
        password[i] = '!' + r;
    }

    password[length] = '\0';

    return password;
}