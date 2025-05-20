//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// function to generate random integers
int generateRandomInt(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// function to generate random lowercase letters
char generateRandomChar(){
    return (char) generateRandomInt((int) 'a', (int) 'z');
}

// function to generate random uppercase letters
char generateRandomCharUpper(){
    return (char) generateRandomInt((int) 'A', (int) 'Z');
}


// function to generate random special characters
char generateRandomSpecialChar(){
    const char specialChars[] = "!@#$%^&*()_+=-{}[]|\\;:'\"<>,./?";
    int index = generateRandomInt(0, strlen(specialChars) - 1);
    return specialChars[index];
}

// function to check if a string contains a digit
bool containsDigit(char* str){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            return true;
        }
    }
    return false;
}

// function to generate a secure password
char* generateSecurePassword(int length){
    char* password = (char*) malloc((length + 1) * sizeof(char));
    bool containsLowercase = false;
    bool containsUppercase = false;
    bool containsSpecialChar = false;
    for(int i=0; i<length; i++){
        int choice = generateRandomInt(0, 2);
        if(choice == 0){
            password[i] = generateRandomChar();
            containsLowercase = true;
        } else if(choice == 1){
            password[i] = generateRandomCharUpper();
            containsUppercase = true;
        } else {
            password[i] = generateRandomSpecialChar();
            containsSpecialChar = true;
        }
    }
    password[length] = '\0';
    if(!(containsLowercase && containsUppercase && containsSpecialChar && containsDigit(password))){
        free(password);
        return generateSecurePassword(length);
    }
    return password;
}

// main function
int main(){

    // seed the random number generator
    srand(time(0));

    // player count and password length
    int playerCount, passwordLength;
    printf("Enter the number of players: ");
    scanf("%d", &playerCount);
    printf("Enter the password length: ");
    scanf("%d", &passwordLength);

    // create an array to store the player passwords
    char** playerPasswords = (char**) malloc(playerCount * sizeof(char*));

    // generate passwords for each player
    for(int i=0; i<playerCount; i++){
        printf("Player %d enter your name: ", i+1);
        char playerName[100];
        scanf("%s", playerName);
        char* password = generateSecurePassword(passwordLength);
        playerPasswords[i] = (char*) malloc((passwordLength + 1) * sizeof(char));
        strcpy(playerPasswords[i], password);
        free(password);
        printf("\n%s your secure password is: %s\n", playerName, playerPasswords[i]);
    }

    // check if any two players have the same password
    for(int i=0; i<playerCount-1; i++){
        for(int j=i+1; j<playerCount; j++){
            if(strcmp(playerPasswords[i], playerPasswords[j]) == 0){
                printf("ERROR: Player %d and Player %d have the same password.\n", i+1, j+1);
                return 1;
            }
        }
    }

    // free memory
    for(int i=0; i<playerCount; i++){
        free(playerPasswords[i]);
    }
    free(playerPasswords);

    return 0;
}