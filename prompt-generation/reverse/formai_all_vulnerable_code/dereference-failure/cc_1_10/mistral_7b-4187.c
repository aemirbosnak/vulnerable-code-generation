//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 20

void generate_password(char *password) {
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/~`";
    int index1, index2, length = strlen(password);

    if (length >= LENGTH) {
        printf("Generated Password: %s\n", password);
        return;
    }

    srand(time(NULL));
    index1 = rand() % (sizeof(characters) / sizeof(characters[0]));
    password[length] = characters[index1];
    length++;

    for (int i = 0; i < length - 1; i++) {
        index2 = rand() % (sizeof(characters) / sizeof(characters[0]));
        password[length] = characters[index2];
        length++;

        if (password[i] != password[i + 1]) {
            i--;
        } else {
            i = length - 1;
            while (password[i - 1] == password[i]) {
                index2 = rand() % (sizeof(characters) / sizeof(characters[0]));
                password[i] = characters[index2];
                i--;
            }
        }
    }

    password[length] = '\0';
    generate_password(password);
}

int main(int argc, char **argv) {
    char password[LENGTH + 1];
    int random_number;

    printf("Generating a random password of length %d...\n", LENGTH);

    generate_password(password);

    printf("Generating another random password...\n");
    generate_password(password);

    printf("Exiting the program...\n");

    return 0;
}