//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int password_strength(char* password);
int get_random_number(int min, int max);

int main() {
    char* password;
    int strength;

    password = (char*)malloc(16*sizeof(char));
    if(password == NULL) {
        printf("Error: Could not allocate memory for password.\n");
        exit(1);
    }

    /* Generate a random password */
    for(int i=0; i<16; i++) {
        password[i] = get_random_number(48, 57) + 1;
    }

    /* Get password strength */
    strength = password_strength(password);

    /* Print password and strength */
    printf("Generated password: %s\n", password);
    printf("Password strength: %d\n", strength);

    free(password);
    return 0;
}

int password_strength(char* password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            has_uppercase = 1;
        }
        else if(islower(password[i])) {
            has_lowercase = 1;
        }
        else if(isdigit(password[i])) {
            has_number = 1;
        }
        else {
            has_special_char = 1;
        }
    }

    int strength = 0;

    if(length >= 8) {
        strength++;
    }

    if(has_uppercase && has_lowercase) {
        strength++;
    }

    if(has_number && has_special_char) {
        strength++;
    }

    if(length >= 12) {
        strength++;
    }

    return strength;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}