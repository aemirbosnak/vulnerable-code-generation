//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORDLEN 25
#define PLAYERS 4
#define ROUNDS 3

char dictionary[][WORDLEN] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "huckleberry", "kiwi", "lemon"};

int word_count(){
    return (sizeof(dictionary)/sizeof(dictionary[0]));
}

int is_valid_word(char *word){
    int i, len, is_valid = 0;
    len = strlen(word);
    word[len-1] = '\0';
    for(i=0;i<word_count();i++){
        if(strcmp(dictionary[i], word)==0){
            is_valid = 1;
            break;
        }
    }
    return is_valid;
}

int main()
{
    int i, j, round, word_score, is_valid, min_players, total_score[PLAYERS]={0}, check_spelling[PLAYERS][ROUNDS];
    char word[WORDLEN], letter;

    for(round=0; round<ROUNDS; round++){
        printf("\nRound %d\n\n", round+1);
        for(i=0; i<PLAYERS; i++){
            printf("Player %d enter a word that starts with the letter %c: ", i+1, letter);
            scanf(" %s", word);
            printf("\n");
            is_valid = is_valid_word(word);
            if(is_valid){
                check_spelling[i][round] = 1;
                word_score = strlen(word);
                total_score[i] += word_score;
                letter = tolower(word[strlen(word)-2]);
            }
            else{
                printf("'%s' is not a valid word. Please try again.\n", word);
                check_spelling[i][round] = 0;
                i--;
            }
        }
    }

    printf("\n\nFinal Scores:\n");
    for(i=0;i<PLAYERS;i++){
        printf("Player %d: %d\n", i+1, total_score[i]);
    }

    printf("\n\nDid everyone spell their words correctly?\n");
    for(round=0; round<ROUNDS; round++){
        printf("\nRound %d:\n", round+1);
        min_players = 0;
        for(i=0; i<PLAYERS; i++){
            if(check_spelling[i][round]==0){
                printf("Player %d spelled their word incorrectly.\n", i+1);
            }
            else{
                min_players++;
            }
        }
        if(min_players < PLAYERS){
            printf("Not everyone spelled their word correctly this round. Penalty of -3 points for everyone.\n");
            for(i=0; i<PLAYERS; i++){
                if(check_spelling[i][round]==1){
                    total_score[i] -= 3;
                }
            }
        }
        else{
            printf("Everyone spelled their word correctly this round. +2 points for everyone.\n");
            for(i=0; i<PLAYERS; i++){
                total_score[i] += 2;
            }
        }
    }

    printf("\n\nFinal Scores (with penalties and bonuses included):\n");
    for(i=0;i<PLAYERS;i++){
        printf("Player %d: %d\n", i+1, total_score[i]);
    }
    return 0;
}