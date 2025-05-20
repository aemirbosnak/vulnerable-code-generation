//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWERCASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()_-+=}{][:;?><,./~`"

int main() {
    int password_length;
    char password[50];
    char *letters;

    printf("Enter the desired length of the password: ");
    scanf("%d", &password_length);

    // Prompt user for desired character types
    printf("Do you want to include lowercase letters? (y/n): ");
    char include_lowercase = (scanf("%c", &letters) == 1 && letters == 'y');

    printf("Do you want to include uppercase letters? (y/n): ");
    char include_uppercase = (scanf("%c", &letters) == 1 && letters == 'y');

    printf("Do you want to include numbers? (y/n): ");
    char include_numbers = (scanf("%c", &letters) == 1 && letters == 'y');

    printf("Do you want to include special characters? (y/n): ");
    char include_special_chars = (scanf("%c", &letters) == 1 && letters == 'y');

    // Set the pool of characters based on user preferences
    char *pool = "";
    if (include_lowercase) {
        strcat(pool, LOWERCASE_LETTERS);
    }
    if (include_uppercase) {
        strcat(pool, UPPERCASE_LETTERS);
    }
    if (include_numbers) {
        strcat(pool, NUMBERS);
    }
    if (include_special_chars) {
        strcat(pool, SPECIAL_CHARACTERS);
    }

    // Generate a random password of the specified length
    srand(time(NULL));
    for (int i = 0; i < password_length; i++) {
        password[i] = pool[rand() % strlen(pool)];
    }

    printf("Your secure password is: %s\n", password);

    return 0;
}