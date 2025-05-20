//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 12
#define NUM_CHARS 10
#define LOWER 97
#define UPPER 65
#define NUM 48
#define SPECIAL 33

int main() {
    char *password;
    int i, j, num_special, num_upper, num_lower, num_digit;

    srand(time(NULL));

    password = (char*) malloc(LENGTH+1);

    num_special = rand() % (NUM_CHARS/2 + 1);
    num_upper = rand() % (NUM_CHARS/2 + 1);
    num_lower = NUM_CHARS - num_special - num_upper;
    num_digit = rand() % (NUM_CHARS/3 + 1);

    for(i = 0; i < num_special; i++) {
        password[i] = (char)(rand() % (SPECIAL + NUM + NUM_CHARS) + LOWER);
        if(password[i] >= NUM && password[i] <= NUM+NUM_CHARS-1)
            password[i] -= NUM;
        if(password[i] == '\0') {
            i--;
            break;
        }
    }

    for(i = num_special; i < num_special+num_upper; i++) {
        password[i] = (char)(rand() % UPPER + LOWER);
        if(password[i] == '\0') {
            i--;
            break;
        }
    }

    for(i = num_special+num_upper; i < num_special+num_upper+num_lower; i++) {
        password[i] = (char)(rand() % NUM_CHARS + LOWER);
        if(password[i] == '\0') {
            i--;
            break;
        }
    }

    for(i = num_special+num_upper+num_lower; i < LENGTH; i++) {
        password[i] = (char)(rand() % NUM_CHARS + LOWER);
    }

    password[LENGTH] = '\0';

    printf("Generated Password: %s\n", password);

    free(password);

    return 0;
}