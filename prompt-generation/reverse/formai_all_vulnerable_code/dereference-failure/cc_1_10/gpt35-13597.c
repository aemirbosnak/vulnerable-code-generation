//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

int hasLowerCase(char *password){
    int i;
    for (i = 0; i < strlen(password); i++){
        if (password[i] >= 'a' && password[i] <= 'z'){
            return 1;
        }
    }
    return 0;
}

int hasUpperCase(char *password){
    int i;
    for (i = 0; i < strlen(password); i++){
        if (password[i] >= 'A' && password[i] <= 'Z'){
            return 1;
        }
    }
    return 0;
}

int hasDigit(char *password){
    int i;
    for (i = 0; i < strlen(password); i++){
        if (password[i] >= '0' && password[i] <= '9'){
            return 1;
        }
    }
    return 0;
}

int hasSpecial(char *password){
    int i;
    for (i = 0; i < strlen(password); i++){
        if (password[i] == '@' ||
            password[i] == '#' ||
            password[i] == '$' ||
            password[i] == '%'){
            return 1;
        }
    }
    return 0;
}

int isValid(char *password){
    if (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH){
        return 0;
    }

    if (!hasLowerCase(password)){
        return 0;
    }

    if (!hasUpperCase(password)){
        return 0;
    }

    if (!hasDigit(password)){
        return 0;
    }

    if (!hasSpecial(password)){
        return 0;
    }

    return 1;
}

int main(){
    int numPlayers, i, j;
    char *password;
    char **playerPasswords;
    int *playerScores;
    int maxScore, maxIndex, playerIndex;

    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    playerPasswords = (char **)malloc(numPlayers * sizeof(char *));
    playerScores = (int *)malloc(numPlayers * sizeof(int));

    for (i = 0; i < numPlayers; i++){
        password = (char *)malloc((MAX_LENGTH + 1) * sizeof(char));

        printf("Enter player %d's password: ", i + 1);
        scanf("%s", password);

        if (isValid(password)){
            printf("Player %d password is valid!\n", i + 1);
            playerPasswords[i] = password;
            playerScores[i] = 0;
        }
        else{
            printf("Player %d password is invalid! Please try again.\n", i + 1);
            i--;
        }
    }

    printf("Password strength checker game starting!\n");

    for (i = 0; i < numPlayers; i++){
        printf("Round %d starting!\n", i + 1);

        maxScore = 0;
        maxIndex = -1;

        for (j = 0; j < numPlayers; j++){
            if (playerPasswords[j] != NULL){
                printf("Player %d, enter your guess for player %d's password: ", j + 1, i + 1);
                scanf("%s", password);

                if (strcmp(playerPasswords[i], password) == 0){
                    printf("Player %d has correctly guessed player %d's password! They receive 10 points.\n", j + 1, i + 1);
                    playerScores[j] += 10;
                    playerPasswords[i] = NULL;
                }
                else{
                    int score = 0;

                    if (hasLowerCase(password)){
                        score++;
                    }

                    if (hasUpperCase(password)){
                        score++;
                    }

                    if (hasDigit(password)){
                        score++;
                    }

                    if (hasSpecial(password)){
                        score++;
                    }

                    printf("Player %d's guess for player %d's password receives a score of %d.\n", j + 1, i + 1, score);
                    playerScores[j] += score;

                    if (score > maxScore){
                        maxScore = score;
                        maxIndex = j;
                    }
                }
            }
        }

        if (maxIndex != -1){
            printf("Player %d had the best guess for password %d. They receive 5 bonus points.\n", maxIndex + 1, i + 1);
            playerScores[maxIndex] += 5;
        }
    }

    printf("Game over! Final scores:\n");

    for (i = 0; i < numPlayers; i++){
        printf("Player %d: %d points\n", i + 1, playerScores[i]);
    }

    for (i = 0; i < numPlayers; i++){
        free(playerPasswords[i]);
    }

    free(playerPasswords);
    free(playerScores);

    return 0;
}