//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(char arr[], int length, int uppercase, int lowercase, int numbers, int symbols);

int main(){
    int length, uppercase, lowercase, numbers, symbols;
    char password[100];
    
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    
    printf("Enter the number of uppercase letters in the password: ");
    scanf("%d", &uppercase);
    
    printf("Enter the number of lowercase letters in the password: ");
    scanf("%d", &lowercase);
    
    printf("Enter the number of numbers in the password: ");
    scanf("%d", &numbers);
    
    printf("Enter the number of symbols in the password: ");
    scanf("%d", &symbols);
    
    // Check if the input is valid
    if (length < (uppercase + lowercase + numbers + symbols)) {
        printf("Invalid input! The length should be greater than the sum of the uppercase, lowercase, numbers, and symbols.\n");
        exit(0);
    }
    
    // Generate the password recursively
    generatePassword(password, length, uppercase, lowercase, numbers, symbols);
    
    printf("\nGenerated password: %s\n", password);
    
    return 0;
}

void generatePassword(char arr[], int length, int uppercase, int lowercase, int numbers, int symbols) {
    if(length == 0) {   // Base case
        return;
    }
    else {
        int type = rand() % 4;  // Generate a random number between 0 and 3
        
        switch(type) {
            case 0: // Uppercase
                if(uppercase > 0) {
                    arr[length - 1] = rand() % 26 + 65;
                    generatePassword(arr, length - 1, uppercase - 1, lowercase, numbers, symbols);
                }
                else {
                    generatePassword(arr, length, uppercase, lowercase, numbers, symbols);
                }
                break;
            
            case 1: // Lowercase
                if(lowercase > 0) {
                    arr[length - 1] = rand() % 26 + 97;
                    generatePassword(arr, length - 1, uppercase, lowercase - 1, numbers, symbols);
                }
                else {
                    generatePassword(arr, length, uppercase, lowercase, numbers, symbols);
                }
                break;
            
            case 2: // Numbers
                if(numbers > 0) {
                    arr[length - 1] = rand() % 10 + 48;
                    generatePassword(arr, length - 1, uppercase, lowercase, numbers - 1, symbols);
                }
                else {
                    generatePassword(arr, length, uppercase, lowercase, numbers, symbols);
                }
                break;
            
            case 3: // Symbols
                if(symbols > 0) {
                    int symbolType = rand() % 4;
                    switch(symbolType) {
                        case 0:
                            arr[length - 1] = rand() % 16 + 33;
                            break;
                        case 1:
                            arr[length - 1] = rand() % 7 + 58;
                            break;
                        case 2:
                            arr[length - 1] = rand() % 6 + 123;
                            break;
                        case 3:
                            arr[length - 1] = rand() % 5 + 91;
                            break;
                    }
                    generatePassword(arr, length - 1, uppercase, lowercase, numbers, symbols - 1);
                }
                else {
                    generatePassword(arr, length, uppercase, lowercase, numbers, symbols);
                }
                break;
        }
    }
}