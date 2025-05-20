//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10
#define MIN_FORTUNE_LENGTH 20
#define MAX_FORTUNE_LENGTH 80

// Structure to store a fortune
typedef struct {
    char* fortune;
    int length;
} Fortune;

void generate_fortunes(Fortune fortunes[NUM_FORTUNES]);
int get_random_index(int limit);
void print_fortune(Fortune fortune);

int main() {
    Fortune fortunes[NUM_FORTUNES];
    srand(time(NULL));

    generate_fortunes(fortunes);

    int user_choice;
    int fortune_index;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter a number between 1 and %d to receive your fortune:\n", NUM_FORTUNES);
    scanf("%d", &user_choice);

    if (user_choice < 1 || user_choice > NUM_FORTUNES) {
        printf("Invalid choice! Please try again.\n");
        main();
    }

    fortune_index = get_random_index(NUM_FORTUNES);

    if (fortune_index == user_choice) {
        printf("You have chosen the same fortune as the fortune teller! Here is your fortune:\n");
        print_fortune(fortunes[user_choice - 1]);
    } else {
        printf("The fortune teller has chosen a different fortune for you:\n");
        print_fortune(fortunes[fortune_index]);
    }

    return 0;
}

void generate_fortunes(Fortune fortunes[NUM_FORTUNES]) {
    for (int i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].length = rand() % (MAX_FORTUNE_LENGTH - MIN_FORTUNE_LENGTH + 1) + MIN_FORTUNE_LENGTH;
        fortunes[i].fortune = malloc(fortunes[i].length * sizeof(char));

        for (int j = 0; j < fortunes[i].length; j++) {
            fortunes[i].fortune[j] = 'a' + rand() % 26;
        }

        fortunes[i].fortune[fortunes[i].length] = '\0';

        printf("Fortune %d generated with a length of %d:\n", i + 1, fortunes[i].length);
        printf("%s\n", fortunes[i].fortune);
    }
}

int get_random_index(int limit) {
    return rand() % (limit + 1);
}

void print_fortune(Fortune fortune) {
    printf("%s\n", fortune.fortune);
}