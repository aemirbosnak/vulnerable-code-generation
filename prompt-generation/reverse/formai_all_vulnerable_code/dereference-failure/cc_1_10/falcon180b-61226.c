//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char text[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES] = {
    {"You will have a great day today!"},
    {"You will find love soon."},
    {"You will have good luck in your endeavors."},
    {"You will receive unexpected news."},
    {"You will be successful in your career."},
    {"You will overcome any obstacles in your path."},
    {"You will have a peaceful and relaxing day."},
    {"You will have a fun and exciting day."},
    {"You will have a memorable experience today."},
    {"You will learn something new today."}
};

int main() {
    srand(time(NULL));

    int numFortunes = rand() % MAX_FORTUNES + 1;
    Fortune *selectedFortunes = malloc(sizeof(Fortune) * numFortunes);

    for (int i = 0; i < numFortunes; i++) {
        int index = rand() % MAX_FORTUNES;
        strcpy(selectedFortunes[i].text, fortunes[index].text);
    }

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I have selected %d fortunes for you:\n", numFortunes);

    for (int i = 0; i < numFortunes; i++) {
        printf("%d. %s\n", i + 1, selectedFortunes[i].text);
    }

    int choice;
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numFortunes) {
        printf("Your fortune is:\n%s\n", selectedFortunes[choice - 1].text);
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    free(selectedFortunes);
    return 0;
}