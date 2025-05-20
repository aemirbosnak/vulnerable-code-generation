//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char* password_generator() {

    srand(time(0));

    //Arrays containing all possible characters for the password
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special_chars[] = "!@#$%^&*()-_=+[]{};:,<.>/?";

    //Password config variables
    int lowercase_used = 0;
    int uppercase_used = 0;
    int number_used = 0;
    int special_char_used = 0;

    //Allocate memory for password string
    char* password = (char*)malloc(16*sizeof(char));

    while(!(lowercase_used && uppercase_used && number_used && special_char_used)) {

        //Randomly select a group of characters
        int group = rand() % 4;

        if(group == 0 && !lowercase_used) {
            //Add a lowercase letter to password
            int index = rand() % strlen(lowercase_letters);
            password[strlen(password)] = lowercase_letters[index];
            lowercase_used = 1;
        } 
        else if(group == 1 && !uppercase_used) {
            //Add an uppercase letter to password
            int index = rand() % strlen(uppercase_letters);
            password[strlen(password)] = uppercase_letters[index];
            uppercase_used = 1;
        } 
        else if(group == 2 && !number_used) {
            //Add a number to password
            int index = rand() % strlen(numbers);
            password[strlen(password)] = numbers[index];
            number_used = 1;
        }
        else if(group == 3 && !special_char_used) {
            //Add a special character to password
            int index = rand() % strlen(special_chars);
            password[strlen(password)] = special_chars[index];
            special_char_used = 1;
        }
    }

    //Add random characters to password until it reaches 16 characters
    while(strlen(password) < 16) {
        int group = rand() % 4;
        if(group == 0) {
            //Add a lowercase letter to password
            int index = rand() % strlen(lowercase_letters);
            password[strlen(password)] = lowercase_letters[index];
        } 
        else if(group == 1) {
            //Add an uppercase letter to password
            int index = rand() % strlen(uppercase_letters);
            password[strlen(password)] = uppercase_letters[index];
        } 
        else if(group == 2) {
            //Add a number to password
            int index = rand() % strlen(numbers);
            password[strlen(password)] = numbers[index];
        }
        else {
            //Add a special character to password
            int index = rand() % strlen(special_chars);
            password[strlen(password)] = special_chars[index];
        }
    }

    //Terminate password string with null character
    password[strlen(password)] = '\0';

    return password;
}

int main() {

    char* password = password_generator();

    printf("Generated Password: %s\n", password);

    free(password);

    return 0;
}