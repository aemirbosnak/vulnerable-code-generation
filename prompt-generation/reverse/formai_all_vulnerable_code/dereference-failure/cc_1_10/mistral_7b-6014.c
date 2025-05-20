//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

typedef struct {
    char *msg;
    int prob;
} fortune;

fortune fortunes[] = {
    {"Your day will be as bright as the sun.", 50},
    {"Good things are on their way.", 30},
    {"Be prepared for a challenge.", 20},
    {"The stars are aligned in your favor.", 10},
    {"Your hard work will pay off.", 15},
    {"A pleasant surprise is coming your way.", 40},
    {"Better days are ahead.", 25},
    {"Take a leap of faith.", 15},
    {"You are destined for great things.", 5},
    {"Your future is uncertain, but you are strong.", 35},
};

int randrange(int min, int max) {
    int range = max - min + 1;
    int r = rand() % range;
    return r + min;
}

void tellFortune(fortune *fortunes, int size) {
    int roll = randrange(0, RAND_MAX);
    int i;
    fortune *match = NULL;

    for (i = 0; i < size; i++) {
        if (roll < fortunes[i].prob) {
            match = &fortunes[i];
            break;
        }
        roll -= fortunes[i].prob;
    }

    printf("%s\n", match->msg);
}

int main() {
    srand(time(NULL));
    fortune *fortunes = malloc(sizeof(fortune) * 10);
    int i;

    for (i = 0; i < 10; i++) {
        fortunes[i].prob = randrange(1, 100);
        fortunes[i].msg = malloc(MAX_LEN * sizeof(char));
        sprintf(fortunes[i].msg, "Fortune %d", i + 1);
    }

    tellFortune(fortunes, 10);

    for (i = 0; i < 10; i++) {
        free(fortunes[i].msg);
    }
    free(fortunes);

    return 0;
}