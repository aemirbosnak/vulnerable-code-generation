//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    printf("\n\nWelcome to the Claude Shannon inspired game: THE ENCRYPTOR\n");
    printf("\nIn this game, you are a hacker and your objective is to decrypt a secret code. Good luck!\n\n");

    char secret_code[] = "KJHJH HGHG DHJKL NMJJI JHJDO";
    char decrypted_code[] = "";
    char guess[100];

    srand(time(NULL));
    int random_number = rand() % 5;

    switch(random_number)
    {
        case 0:
            strcpy(decrypted_code, "WELCOME TO THE GAME");
            break;
        case 1:
            strcpy(decrypted_code, "THIS IS A SECRET MESSAGE");
            break;
        case 2:
            strcpy(decrypted_code, "LEARNING TO CODE IS FUN");
            break;
        case 3:
            strcpy(decrypted_code, "ENCRYPTOR IS AN AMAZING GAME");
            break;
        case 4:
            strcpy(decrypted_code, "HACKERMAN IS THE NAME");
            break;
    }

    printf("The secret code is: %s\n", secret_code);
    printf("Enter your guess: ");
    scanf("%s", guess);

    if(strcmp(guess, decrypted_code) == 0)
    {
        printf("\n\nCongratulations! You have successfully decrypted the code and won the game.\n\n");
    }
    else
    {
        printf("\n\nSorry, your guess is incorrect. Better luck next time!\n\n");
    }

    return 0;
}