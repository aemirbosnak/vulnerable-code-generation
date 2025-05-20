//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_USERS 10

typedef struct {
    char name[20];
    int score;
} User;

User users[MAX_USERS];

void generateWords(char *words[], int numWords) {
    FILE *fp;
    char line[100];
    int i = 0;
    fp = fopen("words.txt", "r");
    while (fgets(line, sizeof(line), fp)!= NULL && i < numWords) {
        strcpy(words[i], line);
        i++;
    }
    fclose(fp);
}

int main() {
    int numUsers, numWords;
    char input[20];
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);
    printf("Enter the number of words: ");
    scanf("%d", &numWords);

    srand(time(NULL));
    for (int i = 0; i < numUsers; i++) {
        strcpy(users[i].name, "User");
        sprintf(input, "Enter your name: ");
        scanf("%s", users[i].name);
        users[i].score = 0;
    }

    char *words[numWords];
    generateWords(words, numWords);

    printf("\nWelcome to the Typing Speed Test!\n");
    printf("You will be given %d words to type.\n", numWords);
    printf("Each correct word will earn you 1 point.\n");
    printf("The user with the highest score at the end will win!\n\n");

    for (int i = 0; i < numWords; i++) {
        printf("Word %d: %s\n", i+1, words[i]);
        for (int j = 0; j < numUsers; j++) {
            printf("\n%s, you're up!\n", users[j].name);
            printf("Type the word and press enter:\n");
            char word[MAX_WORD_LENGTH];
            scanf("%s", word);
            if (strcmp(word, words[i]) == 0) {
                users[j].score++;
            }
        }
    }

    printf("\nThe results are in!\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s: %d points\n", users[i].name, users[i].score);
    }

    return 0;
}