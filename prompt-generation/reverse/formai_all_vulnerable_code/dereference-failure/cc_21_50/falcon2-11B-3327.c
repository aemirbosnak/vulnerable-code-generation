//Falcon2-11B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_theory(int length) {
    char* theory = malloc(length + 1);
    strcpy(theory, "The ");
    srand(time(0));
    int num = rand() % 100;
    if (num < 10) {
        strcat(theory, "first ");
    } else if (num < 20) {
        strcat(theory, "second ");
    } else if (num < 30) {
        strcat(theory, "third ");
    } else if (num < 40) {
        strcat(theory, "fourth ");
    } else if (num < 50) {
        strcat(theory, "fifth ");
    } else if (num < 60) {
        strcat(theory, "sixth ");
    } else if (num < 70) {
        strcat(theory, "seventh ");
    } else if (num < 80) {
        strcat(theory, "eighth ");
    } else if (num < 90) {
        strcat(theory, "ninth ");
    } else {
        strcat(theory, "tenth ");
    }
    strcat(theory, "planet ");
    int num2 = rand() % 6;
    switch (num2) {
        case 0:
            strcat(theory, "Earth");
            break;
        case 1:
            strcat(theory, "Mars");
            break;
        case 2:
            strcat(theory, "Jupiter");
            break;
        case 3:
            strcat(theory, "Saturn");
            break;
        case 4:
            strcat(theory, "Uranus");
            break;
        case 5:
            strcat(theory, "Neptune");
            break;
    }
    int num3 = rand() % 6;
    switch (num3) {
        case 0:
            strcat(theory, "is being controlled by ");
            break;
        case 1:
            strcat(theory, "is secretly inhabited by ");
            break;
        case 2:
            strcat(theory, "has a secret moon that is ");
            break;
        case 3:
            strcat(theory, "is sending out secret signals to ");
            break;
        case 4:
            strcat(theory, "is being watched by ");
            break;
        case 5:
            strcat(theory, "is hiding a ");
            break;
    }
    int num4 = rand() % 6;
    switch (num4) {
        case 0:
            strcat(theory, "alien ");
            break;
        case 1:
            strcat(theory, "government agency ");
            break;
        case 2:
            strcat(theory, "lizard people ");
            break;
        case 3:
            strcat(theory, "Nazi scientist ");
            break;
        case 4:
            strcat(theory, "evil corporation ");
            break;
        case 5:
            strcat(theory, "mystery organization ");
            break;
    }
    int num5 = rand() % 6;
    switch (num5) {
        case 0:
            strcat(theory, "military ");
            break;
        case 1:
            strcat(theory, "government ");
            break;
        case 2:
            strcat(theory, "intelligence agency ");
            break;
        case 3:
            strcat(theory, "secret society ");
            break;
        case 4:
            strcat(theory, "corporation ");
            break;
        case 5:
            strcat(theory, "mystery organization ");
            break;
    }
    int num6 = rand() % 6;
    switch (num6) {
        case 0:
            strcat(theory, "is planning to ");
            break;
        case 1:
            strcat(theory, "is being used to ");
            break;
        case 2:
            strcat(theory, "is secretly protecting ");
            break;
        case 3:
            strcat(theory, "is being controlled by ");
            break;
        case 4:
            strcat(theory, "is secretly attacking ");
            break;
        case 5:
            strcat(theory, "is being used to ");
            break;
    }
    int num7 = rand() % 6;
    switch (num7) {
        case 0:
            strcat(theory, "take over the world ");
            break;
        case 1:
            strcat(theory, "destroy the planet ");
            break;
        case 2:
            strcat(theory, "spread a virus ");
            break;
        case 3:
            strcat(theory, "create a zombie apocalypse ");
            break;
        case 4:
            strcat(theory, "start a war ");
            break;
        case 5:
            strcat(theory, "cause a natural disaster ");
            break;
    }
    int num8 = rand() % 6;
    switch (num8) {
        case 0:
            strcat(theory, "to ");
            break;
        case 1:
            strcat(theory, "from ");
            break;
        case 2:
            strcat(theory, "in ");
            break;
        case 3:
            strcat(theory, "for ");
            break;
        case 4:
            strcat(theory, "at ");
            break;
        case 5:
            strcat(theory, "by ");
            break;
    }
    int num9 = rand() % 6;
    switch (num9) {
        case 0:
            strcat(theory, "to take over the world ");
            break;
        case 1:
            strcat(theory, "to destroy the planet ");
            break;
        case 2:
            strcat(theory, "to spread a virus ");
            break;
        case 3:
            strcat(theory, "to create a zombie apocalypse ");
            break;
        case 4:
            strcat(theory, "to start a war ");
            break;
        case 5:
            strcat(theory, "to cause a natural disaster ");
            break;
    }
    strcat(theory, ".");
    strcat(theory, " ");
    strcat(theory, "Theory generated by C Random Conspiracy Theory Generator. ");
    printf("%s\n", theory);
    free(theory);
}

int main() {
    int length = 100;
    generate_theory(length);
    return 0;
}