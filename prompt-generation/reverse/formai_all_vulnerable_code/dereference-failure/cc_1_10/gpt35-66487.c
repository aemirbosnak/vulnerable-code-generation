//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length, choice;
    int numCount = 0, charCount = 0, specialCharCount = 0;
    char password[100], newPassword[100];
    const char* digits = "0123456789";
    const char* letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* specialChars = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
    srand(time(NULL));

    printf("Welcome to the Secure Password Generator\n");
    printf("Please enter the desired length of your password: ");
    scanf("%d", &length);

    printf("Would you like to include numbers in your password? (Enter 1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    numCount = choice ? (rand() % (length/4)) + 1 : 0;

    printf("Would you like to include letters in your password? (Enter 1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    charCount = choice ? ((rand() % (length/4)) + (length/4)) - numCount : 0;

    printf("Would you like to include special characters in your password? (Enter 1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    specialCharCount = choice ? length - numCount - charCount : 0;

    if(numCount + charCount + specialCharCount < length)
    {
        charCount += length - (numCount + charCount + specialCharCount);
    }

    for(int i=0; i<numCount; i++)
    {
        newPassword[i] = digits[rand() % 10];
    }

    for(int i=0; i<charCount; i++)
    {
        newPassword[numCount + i] = letters[rand() % 52];
    }

    for(int i=0; i<specialCharCount; i++)
    {
        newPassword[numCount + charCount + i] = specialChars[rand() % 32];        
    }

    for(int i=0; i<length; i++)
    {
        int j = rand() % (length-i);
        password[i] = newPassword[j];
        for(int k=j; k<(length-i); k++)
        {
            newPassword[k] = newPassword[k+1];
        }
    }

    printf("Your new password is: %s\n", password);

    return 0;
}