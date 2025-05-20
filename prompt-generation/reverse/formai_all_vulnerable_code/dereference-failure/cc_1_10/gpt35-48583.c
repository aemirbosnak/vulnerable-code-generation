//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN_LENGTH 8 // Minimum length of password
#define MIN_DIGITS 1 // Minimum number of digits in password
#define MIN_UPPER 1 // Minimum number of uppercase alphabets in password
#define MIN_LOWER 1 // Minimum number of lowercase alphabets in password
#define MIN_SPECIAL 1 // Minimum number of special characters in password
#define ASCII_DIGIT_START 48 // ASCII value of '0'
#define ASCII_DIGIT_END 57 // ASCII value of '9'
#define ASCII_UPPER_START 65 // ASCII value of 'A'
#define ASCII_UPPER_END 90 // ASCII value of 'Z'
#define ASCII_LOWER_START 97 // ASCII value of 'a'
#define ASCII_LOWER_END 122 // ASCII value of 'z'
#define ORD_SPECIAL " ~!@#$%^&*()_+-=[]{};:'\"\\|,.<>?/" // List of allowed special characters

int check_password_strength(char* password) {
    int len = strlen(password);
    if(len < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }
    int digits = 0, upper = 0, lower = 0, special = 0;
    for(int i = 0; i < len; i++) {
        if(password[i] >= ASCII_DIGIT_START && password[i] <= ASCII_DIGIT_END)
            digits++;
        else if(password[i] >= ASCII_UPPER_START && password[i] <= ASCII_UPPER_END)
            upper++;
        else if(password[i] >= ASCII_LOWER_START && password[i] <= ASCII_LOWER_END)
            lower++;
        else if(strchr(ORD_SPECIAL, password[i])) // Checking if character is allowed special character
            special++;
        else {
            printf("Invalid character found in the password.\n");
            return 0;
        }
    }
    if(digits < MIN_DIGITS) {
        printf("Password must contain atleast %d digits.\n", MIN_DIGITS);
        return 0;
    }
    if(upper < MIN_UPPER) {
        printf("Password must contain atleast %d uppercase alphabets.\n", MIN_UPPER);
        return 0;
    }
    if(lower < MIN_LOWER) {
        printf("Password must contain atleast %d lowercase alphabets.\n", MIN_LOWER);
        return 0;
    }
    if(special < MIN_SPECIAL) {
        printf("Password must contain atleast %d special characters.\n", MIN_SPECIAL);
        return 0;
    }
    printf("Password is strong.\n");
    return 1;
}

int main() {
    char* password = (char*)malloc(100*sizeof(char));
    printf("Enter your password: ");
    scanf("%s", password);
    check_password_strength(password);
    free(password);
    return 0;
}