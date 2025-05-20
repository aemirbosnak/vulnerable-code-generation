//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEYWORDS 10
#define KEYWORD_LENGTH 20

char *keywords[MAX_KEYWORDS];

void initialize_keywords() {
    int i;
    for (i = 0; i < MAX_KEYWORDS; i++) {
        keywords[i] = malloc(KEYWORD_LENGTH * sizeof(char));
        strcpy(keywords[i], "");
        strcat(keywords[i], "Moon landing was a hoax");
        strcat(keywords[i], "Illuminati controls the world");
        strcat(keywords[i], "Reptilian aliens among us");
        strcat(keywords[i], "Flat Earth Society");
        strcat(keywords[i], "JFK assassination was a false flag");
        strcat(keywords[i], "Area 51 is a government cover-up");
        strcat(keywords[i], "9/11 was an inside job");
        strcat(keywords[i], "Big Pharma suppresses the cure for cancer");
        strcat(keywords[i], "Chemtrails are a form of population control");
    }
}

int main() {
    srand(time(NULL));
    int i, j, length, index;
    char theory[100];

    initialize_keywords();

    printf("Here's your conspiracy theory for today:\n");

    for (i = 0; i < 5; i++) {
        length = rand() % (strlen(keywords[rand() % MAX_KEYWORDS]) + 1);
        strncat(theory, keywords[rand() % MAX_KEYWORDS], length);
        strcat(theory, " ");

        index = rand() % 5;
        strcat(theory, keywords[index]);
        strcat(theory, " ");

        if (i != 4) {
            strcat(theory, "and ");
        }
    }

    puts(theory);

    return 0;
}