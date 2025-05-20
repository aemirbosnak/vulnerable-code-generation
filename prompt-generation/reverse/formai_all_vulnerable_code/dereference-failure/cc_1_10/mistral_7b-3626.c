//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FORTUNES 10
#define WORD_SIZE 20
#define LINES 5

typedef struct {
    char *fortune;
    int number;
} fortune;

fortune fortunes[MAX_FORTUNES];

void setup() {
    int i, j;
    char temp[WORD_SIZE];

    srand(time(NULL));

    for (i = 0; i < MAX_FORTUNES; i++) {
        fortunes[i].number = i;

        gets(temp);
        fortunes[i].fortune = (char *)calloc(strlen(temp) + 1, sizeof(char));
        strcpy(fortunes[i].fortune, temp);
    }

    for (i = 0; i < MAX_FORTUNES; i++) {
        for (j = 0; j < i; j++) {
            if (rand() % (i + 1) == 0) {
                char *temp_fortune = fortunes[i].fortune;
                fortunes[i].fortune = fortunes[j].fortune;
                fortunes[j].fortune = temp_fortune;
                int temp_number = fortunes[i].number;
                fortunes[i].number = fortunes[j].number;
                fortunes[j].number = temp_number;
            }
        }
    }
}

void print_fortune(fortune f) {
    printf("\nFortune %d:\n", f.number);
    printf("%s\n", f.fortune);
}

int main() {
    int i, choice;

    setup();

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Type a number from 0 to %d to receive your fortune:\n", MAX_FORTUNES - 1);

    for (i = 0; i < LINES; i++) {
        printf("\n----------------------------------------------------");
    }

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 0 && choice < MAX_FORTUNES) {
            print_fortune(fortunes[choice]);
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}