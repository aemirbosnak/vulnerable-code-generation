//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct alien{
    char name[MAX_SIZE];
    char symbol;
    int intellegence_level;
}Alien;

void create_alien(Alien *alien, char *name, char symbol, int intellegence_level){
    strcpy(alien->name, name);
    alien->symbol = symbol;
    alien->intellegence_level = intellegence_level;
}

void print_alien(Alien alien){
    printf("\nName: %s, Symbol: %c, Intellegence Level: %d", alien.name, alien.symbol, alien.intellegence_level);
}

void translate_earth_to_alien(char *earth_word, char *alien_word, int alien_intellegence_level){
    if(alien_intellegence_level < 50){
        int length = strlen(earth_word);
        for(int i = 0; i < length; i++){
            alien_word[i] = earth_word[i] + 2;
        }
        alien_word[length] = '\0';
    }
    else if(alien_intellegence_level > 90){
        int length = strlen(earth_word);
        for(int i = 0; i < length; i++){
            alien_word[i] = earth_word[length - i - 1];
        }
        alien_word[length] = '\0';
    }
    else{
        int length = strlen(earth_word);
        for(int i = 0; i < length/2; i++){
            char temp = earth_word[i];
            earth_word[i] = earth_word[length - i - 1];
            earth_word[length - i - 1] = temp;
        }
        strcpy(alien_word, earth_word);
    }
}

int main(int argC, char *argV[])
{
    Alien my_alien;
    char earth_word[MAX_SIZE];
    char alien_word[MAX_SIZE];

    if(argC < 3 || argC % 2 != 0){
        printf("Usage: %s <alien_name> <symbol> <earth_word>\n", argV[0]);
        return 1;
    }

    create_alien(&my_alien, argV[1], argV[2][0], atoi(argV[3]));

    printf("\nAlien Name: %s, Alien Symbol: %c", my_alien.name, my_alien.symbol);

    if(argC > 4){
        strcpy(earth_word, argV[4]);

        translate_earth_to_alien(earth_word, alien_word, my_alien.intellegence_level);
        print_alien(my_alien);
        printf("\nTranslated Word: %s", alien_word);
    }

    return 0;
}