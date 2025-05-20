//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define NUM_CHARS 94
#define NUM_SPECIAL_CHARS 12

char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
char special_chars[] = "!@#$%^&*()_+~`|}{[]\\:;?><,./-=";

void generate_password(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        int rand_charset = rand() % (NUM_CHARS - NUM_SPECIAL_CHARS);
        if (rand_charset == NUM_CHARS - NUM_SPECIAL_CHARS) {
            password[i] = special_chars[rand() % NUM_SPECIAL_CHARS];
        } else {
            password[i] = charset[rand() % NUM_CHARS];
        }
    }
    password[length] = '\0';
}

int main(int argc, char *argv[]) {
    int password_length;
    char *password;
    srand(time(NULL));

    if (argc!= 2) {
        printf("Usage: %s <password_length>\n", argv[0]);
        return 1;
    }

    password_length = atoi(argv[1]);

    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Password length must be between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    password = (char *) malloc((password_length + 1) * sizeof(char));
    if (password == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    generate_password(password, password_length);
    printf("Generated password: %s\n", password);

    free(password);
    return 0;
}