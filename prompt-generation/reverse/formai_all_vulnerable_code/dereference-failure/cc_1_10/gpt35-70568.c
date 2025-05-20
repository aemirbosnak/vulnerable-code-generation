//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char* generate_password(int length);
void shuffle(char* str);

int main() {

    //Seed random number generator with time
    srand((unsigned int) time(NULL));
    
    //Generate a password of length 12
    char* password = generate_password(12);
    
    //Output password to console
    printf("Generated Password: %s", password);
    
    //Free memory for password
    free(password);
    
    return 0;
}

char* generate_password(int length) {

    //Allocate memory for password
    char* password = (char*) malloc((length + 1) * sizeof(char));
    
    //Possible characters to use in password generation
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^*()_+{}[]|\\:;<>,.?/~`";
    
    //Length of charset
    int len = sizeof(charset) / sizeof(char);
    
    //Generate random password of given length
    for(int i = 0; i < length; i++) {
        password[i] = charset[rand() % len];
    }
    password[length] = '\0';
    
    //Shuffle the password
    shuffle(password);
    
    return password;
}

void shuffle(char* str) {

    int length = strlen(str);
    
    //Fisher-Yates Shuffle Algorithm
    for(int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}