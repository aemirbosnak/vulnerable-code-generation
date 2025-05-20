//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

typedef struct {
    char *fortune;
    int happiness;
} Fortune;

Fortune *fortunes;

void generate_fortunes() {
    int i;
    fortunes = (Fortune *) calloc(NUM_FORTUNES, sizeof(Fortune));

    for (i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].fortune = malloc(30 * sizeof(char));

        switch (rand() % 5) {
            case 0:
                strcpy(fortunes[i].fortune, "Your future is bright, like the sun.");
                fortunes[i].happiness = 10;
                break;
            case 1:
                strcpy(fortunes[i].fortune, "The stars align for you today.");
                fortunes[i].happiness = 9;
                break;
            case 2:
                strcpy(fortunes[i].fortune, "You will find success in unconventional ways.");
                fortunes[i].happiness = 8;
                break;
            case 3:
                strcpy(fortunes[i].fortune, "Your future is full of surprises.");
                fortunes[i].happiness = 7;
                break;
            case 4:
                strcpy(fortunes[i].fortune, "Your past mistakes will not define your future.");
                fortunes[i].happiness = 6;
                break;
            default:
                strcpy(fortunes[i].fortune, "Your future is uncertain, but you are strong enough to face it.");
                fortunes[i].happiness = 5;
                break;
        }
    }
}

void print_fortune() {
    int index;
    srand(time(NULL));
    index = rand() % NUM_FORTUNES;

    printf("Fortune %d:\n", index + 1);
    printf("%s\n", fortunes[index].fortune);
    printf("Happiness level: %d\n", fortunes[index].happiness);
}

int main() {
    int choice;

    generate_fortunes();

    do {
        print_fortune();
        printf("Do you want to draw another fortune? (1) Yes or (0) No: ");
        scanf("%d", &choice);
    } while (choice != 0);

    for (int i = 0; i < NUM_FORTUNES; i++) {
        free(fortunes[i].fortune);
    }

    free(fortunes);

    return 0;
}