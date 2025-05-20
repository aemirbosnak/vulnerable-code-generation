//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int length, uppercase, lowercase, digits, symbols, i, j, k, index;

    char* password;

    srand(time(NULL)); 

    printf("Welcome to the Secure Password Generator!\n");

    printf("Please enter the desired length of your password: ");

    scanf("%d", &length);

    printf("How many uppercase letters would you like in your password? ");

    scanf("%d", &uppercase);

    printf("How many lowercase letters would you like in your password? ");

    scanf("%d", &lowercase);

    printf("How many digits would you like in your password? ");

    scanf("%d", &digits);

    printf("How many symbols would you like in your password? ");

    scanf("%d", &symbols);

    password = (char*) malloc(length * sizeof(char));

    int upperIndex[length];
    int lowerIndex[length];
    int digitIndex[length];
    int symbolIndex[length];
    
    for (i = 0; i < length; i++) {
        password[i] = '_';
    }

    for (i = 0; i < uppercase; i++) {
        do {
            index = rand() % length;
        } while (password[index] != '_');
        password[index] = (rand() % 26) + 'A';
        upperIndex[i] = index;
    }

    for (i = 0; i < lowercase; i++) {
        do {
            index = rand() % length;
        } while (password[index] != '_');
        password[index] = (rand() % 26) + 'a';
        lowerIndex[i] = index;
    }

    for (i = 0; i < digits; i++) {
        do {
            index = rand() % length;
        } while (password[index] != '_');
        password[index] = (rand() % 10) + '0';
        digitIndex[i] = index;
    }

    char symbols_arr[] = {'!', '@', '#', '$', '%', '&', '*', '+', '-', '/', '=', '?', '^', '_', '{', '|', '}', '~'};

    for (i = 0; i < symbols; i++) {
        do {
            index = rand() % length;
        } while (password[index] != '_');
        password[index] = symbols_arr[rand() % 18];
        symbolIndex[i] = index;
    }

    for (i = 0; i < length; i++) {
        if (password[i] == '_') {
            int type = rand() % 4; 
            if (type == 0) {
                password[i] = (rand() % 26) + 'a';
            } else if (type == 1) {
                password[i] = (rand() % 26) + 'A';
            } else if (type == 2) {
                password[i] = (rand() % 10) + '0';
            } else {
                password[i] = symbols_arr[rand() % 18];
            }
        }
    }

    printf("\nYour password is: ");

    for (i = 0; i < length; i++) {
        printf("%c", password[i]);
    }

    printf("\n");

    printf("Uppercase Letters at indexes: ");
    for(i=0; i<uppercase; i++){
        printf("%d ", upperIndex[i]);
    }
    printf("\n");
    
    printf("Lowercase Letters at indexes: ");
    for(i=0; i<lowercase; i++){
        printf("%d ", lowerIndex[i]);
    }
    printf("\n");

    printf("Digits at indexes: ");
    for(i=0; i<digits; i++){
        printf("%d ", digitIndex[i]);
    }
    printf("\n");

    printf("Symbols at indexes: ");
    for(i=0; i<symbols; i++){
        printf("%d ", symbolIndex[i]);
    }
    printf("\n");
    
    return 0;
}