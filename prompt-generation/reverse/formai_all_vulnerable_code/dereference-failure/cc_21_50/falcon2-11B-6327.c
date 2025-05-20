//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random password
void generatePassword(int length) {
    srand(time(NULL));

    char* pwd = malloc(length * sizeof(char));
    int i;

    for (i = 0; i < length; i++) {
        int num = rand() % 62;

        if (num >= 10 && num <= 35) {
            pwd[i] = 'A' + (num - 10);
        }
        else if (num >= 36 && num <= 61) {
            pwd[i] = 'a' + (num - 36);
        }
        else if (num == 62) {
            pwd[i] = '!';
        }
        else if (num == 63) {
            pwd[i] = '@';
        }
        else if (num == 64) {
            pwd[i] = '#';
        }
        else if (num == 65) {
            pwd[i] = '$';
        }
        else if (num == 66) {
            pwd[i] = '%';
        }
        else if (num == 67) {
            pwd[i] = '^';
        }
        else if (num == 68) {
            pwd[i] = '&';
        }
        else if (num == 69) {
            pwd[i] = '*';
        }
        else if (num == 70) {
            pwd[i] = '(';
        }
        else if (num == 71) {
            pwd[i] = ')';
        }
        else if (num == 72) {
            pwd[i] = '_';
        }
        else if (num == 73) {
            pwd[i] = '+';
        }
        else if (num == 74) {
            pwd[i] = '-';
        }
        else if (num == 75) {
            pwd[i] = '=';
        }
        else if (num == 76) {
            pwd[i] = ':';
        }
        else if (num == 77) {
            pwd[i] = ';';
        }
        else if (num == 78) {
            pwd[i] = '"';
        }
        else if (num == 79) {
            pwd[i] = '\'';
        }
        else if (num == 80) {
            pwd[i] = '|';
        }
        else if (num == 81) {
            pwd[i] = '}';
        }
        else if (num == 82) {
            pwd[i] = '{';
        }
        else if (num == 83) {
            pwd[i] = '~';
        }
        else if (num == 84) {
            pwd[i] = '`';
        }
        else if (num == 85) {
            pwd[i] = '?';
        }
        else if (num == 86) {
            pwd[i] = '/';
        }
        else if (num == 87) {
            pwd[i] = '<';
        }
        else if (num == 88) {
            pwd[i] = '>';
        }
        else if (num == 89) {
            pwd[i] = '!';
        }
        else if (num == 90) {
            pwd[i] = '\"';
        }
        else if (num == 91) {
            pwd[i] = '\'';
        }
        else if (num == 92) {
            pwd[i] = '|';
        }
        else if (num == 93) {
            pwd[i] = '}';
        }
        else if (num == 94) {
            pwd[i] = '{';
        }
        else if (num == 95) {
            pwd[i] = '~';
        }
        else if (num == 96) {
            pwd[i] = '`';
        }
        else if (num == 97) {
            pwd[i] = '?';
        }
        else if (num == 98) {
            pwd[i] = '/';
        }
        else if (num == 99) {
            pwd[i] = '<';
        }
        else if (num == 100) {
            pwd[i] = '>';
        }
        else if (num == 101) {
            pwd[i] = '-';
        }
        else if (num == 102) {
            pwd[i] = '_';
        }
        else if (num == 103) {
            pwd[i] = '=';
        }
        else if (num == 104) {
            pwd[i] = '+';
        }
        else if (num == 105) {
            pwd[i] = '{';
        }
        else if (num == 106) {
            pwd[i] = '}';
        }
        else if (num == 107) {
            pwd[i] = '|';
        }
        else if (num == 108) {
            pwd[i] = ';';
        }
        else if (num == 109) {
            pwd[i] = ':';
        }
        else if (num == 110) {
            pwd[i] = '\"';
        }
        else if (num == 111) {
            pwd[i] = '\'';
        }
        else if (num == 112) {
            pwd[i] = ',';
        }
        else if (num == 113) {
            pwd[i] = '.';
        }
        else if (num == 114) {
            pwd[i] = '!';
        }
        else if (num == 115) {
            pwd[i] = '\'';
        }
        else if (num == 116) {
            pwd[i] = '\\';
        }
        else if (num == 117) {
            pwd[i] = '(';
        }
        else if (num == 118) {
            pwd[i] = ')';
        }
        else if (num == 119) {
            pwd[i] = '*';
        }
        else if (num == 120) {
            pwd[i] = '+';
        }
        else if (num == 121) {
            pwd[i] = '=';
        }
        else if (num == 122) {
            pwd[i] = '0';
        }
        else if (num == 123) {
            pwd[i] = '1';
        }
        else if (num == 124) {
            pwd[i] = '2';
        }
        else if (num == 125) {
            pwd[i] = '3';
        }
        else if (num == 126) {
            pwd[i] = '4';
        }
        else if (num == 127) {
            pwd[i] = '5';
        }
        else if (num == 128) {
            pwd[i] = '6';
        }
        else if (num == 129) {
            pwd[i] = '7';
        }
        else if (num == 130) {
            pwd[i] = '8';
        }
        else if (num == 131) {
            pwd[i] = '9';
        }
        else {
            printf("Error: Invalid number\n");
            free(pwd);
            exit(1);
        }
    }

    printf("Your password is: %s\n", pwd);
}

int main(int argc, char* argv[]) {
    int length;

    printf("Please enter a password length (1-25): ");
    scanf("%d", &length);

    if (length < 1 || length > 25) {
        printf("Error: Password length must be between 1 and 25\n");
        exit(1);
    }

    generatePassword(length);

    printf("Do you want to generate another password? (y/n): ");
    char c;
    scanf(" %c", &c);

    if (c == 'y') {
        main(argc, argv);
    }

    return 0;
}