//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOWER 'a'
#define UPPER 'A'
#define NUMBER '0'
#define SPECIAL '!'

char *generate_password(int length, int complexity) {
    char *password = (char *) malloc(length + 1);
    if (password == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }

    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int chars_len = strlen(chars);

    int i = 0;
    if (complexity & 1) {
        password[i++] = LOWER;
        password[i++] = UPPER;
    }
    if (complexity & 2) {
        password[i++] = NUMBER;
    }
    if (complexity & 4) {
        password[i++] = SPECIAL;
    }

    int remaining_chars = length - i;
    for (int j = 0; j < remaining_chars; j++) {
        password[i++] = chars[rand() % chars_len];
    }

    password[length] = '\0';

    return password;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <password_length> <password_complexity>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);
    int complexity = atoi(argv[2]);

    char *password = generate_password(length, complexity);

    printf("Generated password: %s\n", password);

    free(password);
    return 0;
}