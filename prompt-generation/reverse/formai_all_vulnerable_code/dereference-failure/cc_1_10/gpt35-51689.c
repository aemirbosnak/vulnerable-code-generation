//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generate_password(int length);
int is_unique(char* password, char c);

int main()
{
    int length = 0;
    printf("Welcome to the Secure Password Generator!\n");
    printf("How many characters would you like your password to be?\n");
    scanf("%d", &length);
    if(length <= 0){
        printf("Invalid length. Password must be at least 1 character in length.\n");
        return 1;
    }
    char* password = generate_password(length);
    printf("Your new password is: %s\n", password);
    free(password);
    return 0;
}

char* generate_password(int length)
{
    srand((unsigned int)time(NULL));
    char* password = malloc(sizeof(char) * length + 1);
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+-=";
    int i = 0;
    while(i < length){
        char c = letters[rand() % 68];
        if(is_unique(password, c)){
            password[i] = c;
            i++;
        }
    }
    password[length] = '\0';
    return password;
}

int is_unique(char* password, char c)
{
    int i = 0;
    while(password[i] != '\0'){
        if(password[i] == c){
            return 0;
        }
        i++;
    }
    return 1;
}