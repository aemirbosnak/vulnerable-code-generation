//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 12
#define LOWER 97
#define UPPER 90
#define NUM 48
#define SPECIAL 33

char *generatePassword() {
    char *password = (char *)malloc(LENGTH + 1);
    int index1, index2, index3;
    int randomNum;

    time_t seed = time(NULL);
    srand(seed);

    password[LENGTH] = '\0';

    password[0] = rand() % (UPPER - LOWER + 1) + LOWER;
    password[1] = rand() % 10 + NUM;
    password[2] = rand() % 32 + SPECIAL;

    for (int i = 3; i < LENGTH; i++) {
        index1 = rand() % 3;
        index2 = rand() % 3;

        if (index1 == index2) {
            i--;
            continue;
        }

        switch (index1) {
            case 0:
                randomNum = rand() % (UPPER - LOWER + 1) + LOWER;
                password[i] = randomNum;
                break;
            case 1:
                randomNum = rand() % 10 + NUM;
                password[i] = randomNum;
                break;
            case 2:
                randomNum = rand() % 32 + SPECIAL;
                password[i] = randomNum;
                break;
        }
    }

    return password;
}

int main() {
    char *password = generatePassword();
    printf("Generated password: %s\n", password);
    free(password);

    return 0;
}