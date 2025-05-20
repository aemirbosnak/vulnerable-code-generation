//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_FORTUNES 100
#define MAX_LENGTH 80
#define RANDOM_SEED 42

typedef struct {
    char *text;
    int length;
} Fortune;

Fortune fortunes[MAX_FORTUNES];
int num_fortunes;

void add_fortune(char *text) {
    if (num_fortunes >= MAX_FORTUNES) {
        return;
    }

    fortunes[num_fortunes].text = malloc(strlen(text) + 1);
    strcpy(fortunes[num_fortunes].text, text);
    fortunes[num_fortunes].length = strlen(text);

    num_fortunes++;
}

void generate_fortunes() {
    srand(RANDOM_SEED);

    for (int i = 0; i < num_fortunes; i++) {
        int length = rand() % MAX_LENGTH + 1;
        char *text = malloc(length + 1);

        for (int j = 0; j < length; j++) {
            text[j] = toupper(rand() % 26 + 'A');
        }

        text[length] = '\0';

        fortunes[i].text = text;
        fortunes[i].length = length;
    }
}

void print_fortune(Fortune *fortune) {
    printf("%s\n", fortune->text);
}

int main() {
    add_fortune("You will find happiness in unexpected places.");
    add_fortune("A new opportunity is waiting for you.");
    add_fortune("Your future is bright and full of possibilities.");

    generate_fortunes();

    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press 1 to get a random fortune.\n");
    printf("Press 2 to exit.\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int index = rand() % num_fortunes;
        print_fortune(&fortunes[index]);
    }

    return 0;
}