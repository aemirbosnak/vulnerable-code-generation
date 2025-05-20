//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define LOWER_CASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPER_CASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMERIC_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~"

char *generate_password(int length) {
    char *password = malloc(length + 1);
    if (password == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++) {
        int rand_int = rand() % 4;
        switch (rand_int) {
            case 0:
                password[i] = LOWER_CASE_CHARS[rand() % strlen(LOWER_CASE_CHARS)];
                break;
            case 1:
                password[i] = UPPER_CASE_CHARS[rand() % strlen(UPPER_CASE_CHARS)];
                break;
            case 2:
                password[i] = NUMERIC_CHARS[rand() % strlen(NUMERIC_CHARS)];
                break;
            case 3:
                password[i] = SPECIAL_CHARS[rand() % strlen(SPECIAL_CHARS)];
                break;
        }
    }

    password[length] = '\0';
    return password;
}

int main() {
    int length;
    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    char *password = generate_password(length);
    printf("Generated password: %s\n", password);

    free(password);
    return 0;
}