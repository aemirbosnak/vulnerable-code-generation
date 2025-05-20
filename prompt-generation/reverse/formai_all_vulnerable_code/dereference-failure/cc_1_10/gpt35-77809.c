//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char* generatePassword(int length, int includeLowerCase, int includeUpperCase, int includeNumeric, int includeSpecialChars) {

    //don't include chars that are ambiguous
    const char* lowercase = "abcdefghijkmnopqrstuvwxyz";
    const char* uppercase = "ABCDEFGHJKMNPQRSTUVWXYZ";
    const char* numeric = "23456789";
    const char* specialChars = "!@#$%^&*_+=-";

    //determine length of each character set
    int lcaseLen = includeLowerCase ? strlen(lowercase) : 0;
    int ucaseLen = includeUpperCase ? strlen(uppercase) : 0;
    int numLen = includeNumeric ? strlen(numeric) : 0;
    int specialLen = includeSpecialChars ? strlen(specialChars) : 0;

    //total length of set
    int totalLen = lcaseLen + ucaseLen + numLen + specialLen;

    //initialize random seed
    srand(time(NULL));

    //allocate memory for password
    char* password = (char*) malloc(length * sizeof(char));

    int i;
    for(i = 0; i < length; i++) {
        int randomIndex = rand() % totalLen;

        //determine if character is lowercase, uppercase, numeric or special
        if(randomIndex < lcaseLen) {
            password[i] = lowercase[randomIndex];
        } else if(randomIndex < lcaseLen + ucaseLen) {
            password[i] = uppercase[randomIndex - lcaseLen];
        } else if(randomIndex < lcaseLen + ucaseLen + numLen) {
            password[i] = numeric[randomIndex - lcaseLen - ucaseLen];
        } else {
            password[i] = specialChars[randomIndex - lcaseLen - ucaseLen - numLen];
        }
    }

    return password;

}

int main() {

    int length = 10;
    int includeLowerCase = 1;
    int includeUpperCase = 1;
    int includeNumeric = 1;
    int includeSpecialChars = 1;

    char* password = generatePassword(length, includeLowerCase, includeUpperCase, includeNumeric, includeSpecialChars);

    printf("Generated Password: %s\n", password);

    free(password); 

    return 0;

}