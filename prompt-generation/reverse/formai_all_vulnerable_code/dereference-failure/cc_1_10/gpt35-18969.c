//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define length 12

char* generatePassword()
{
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}\\|;':\",./<>?";
    
    char availableChar[length];
    char *password = (char*) malloc((length+1)*sizeof(char));
    int i=0, j=0, k=0, l=0;
    
    //Use current time as seed for random generator
    srand(time(NULL));
    
    //Generate random lowercase letters
    for(i=0; i<2; i++)
        password[k++] = lowercase[rand() % (strlen(lowercase))];
    
    //Generate random uppercase letters
    for(i=0; i<2; i++)
        password[k++] = uppercase[rand() % (strlen(uppercase))];
    
    //Generate random digits
    for(i=0; i<2; i++)
        password[k++] = numbers[rand() % (strlen(numbers))];
    
    //Generate random symbols
    for(i=0; i<2; i++)
        password[k++] = symbols[rand() % (strlen(symbols))];
    
    //Generate remaining characters
    for(i=0; i<length-8; i++)
    {
        int choice = rand() % 4;
        switch(choice)
        {
            case 0:
                availableChar[j++] = lowercase[rand() % (strlen(lowercase))];
                break;
            case 1:
                availableChar[j++] = uppercase[rand() % (strlen(uppercase))];
                break;
            case 2:
                availableChar[j++] = numbers[rand() % (strlen(numbers))];
                break;
            case 3:
                availableChar[j++] = symbols[rand() % (strlen(symbols))];
                break;
        }
    }
    
    //Shuffle available characters
    for(i=0; i<length-8; i++)
    {
        int randomIndex = rand() % (length-8);
        char temp = availableChar[i];
        availableChar[i] = availableChar[randomIndex];
        availableChar[randomIndex] = temp;
    }
    
    //Place remaining characters in password
    for(i=0; i<length-8; i++)
        password[k++] = availableChar[i];
    
    //Add null terminator at the end
    password[k] = '\0';
    
    return password;
}

int main()
{
    printf("Generated Password: %s\n", generatePassword());
    return 0;
}