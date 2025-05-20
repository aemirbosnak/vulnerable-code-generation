//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
/**
* C Password Generator
* by [Your Name]
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random number between low and high
int random_number(int low, int high) {
    srand(time(NULL));
    int rand_num = rand() % (high - low + 1) + low;
    return rand_num;
}

// Function to generate a random uppercase letter
char random_uppercase() {
    int rand_num = random_number(65, 90);
    char letter = (char) rand_num;
    return letter;
}

// Function to generate a random lowercase letter
char random_lowercase() {
    int rand_num = random_number(97, 122);
    char letter = (char) rand_num;
    return letter;
}

// Function to generate a random digit
char random_digit() {
    int rand_num = random_number(48, 57);
    char digit = (char) rand_num;
    return digit;
}

// Function to generate a random special character
char random_special() {
    int specials[10] = {33, 35, 36, 37, 38, 42, 63, 64, 94, 126};
    int rand_index = random_number(0, 9);
    char special = (char) specials[rand_index];
    return special;
}

// Function to generate a secure password of specified length
char* generate_password(int length) {
    char password[length+1];
    password[length] = '\0';
    for(int i=0; i<length; i++) {
        int category = random_number(1, 4);
        if(category == 1)
            password[i] = random_uppercase();
        else if(category == 2)
            password[i] = random_lowercase();
        else if(category == 3)
            password[i] = random_digit();
        else
            password[i] = random_special();
    }
    char* result = (char*) malloc(length+1);
    strcpy(result, password);
    return result;
}

int main() {
    int password_length = 12;
    char* password = generate_password(password_length);
    printf("Your secure password is: %s\n", password);
    free(password);
    return 0;
}