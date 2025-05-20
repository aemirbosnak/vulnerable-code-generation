//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10
#define MIN_FORTUNE_LEN 30
#define MAX_FORTUNE_LEN 80

char *fortunes[NUM_FORTUNES];

void generate_fortunes() {
    for (int i = 0; i < NUM_FORTUNES; i++) {
        size_t length = rand() % (MAX_FORTUNE_LEN - MIN_FORTUNE_LEN + 1) + MIN_FORTUNE_LEN;
        char *fortune = malloc(length * sizeof(char));
        
        for (int j = 0; j < length; j++) {
            fortune[j] = 'a' + rand() % 26;
        }
        
        fortune[length] = '\0';
        fortunes[i] = fortune;
    }
}

int main() {
    srand(time(NULL));

    generate_fortunes();

    int user_choice;
    int random_index;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter a number from 1 to %d to receive your fortune:\n", NUM_FORTUNES);
    scanf("%d", &user_choice);

    if (user_choice < 1 || user_choice > NUM_FORTUNES) {
        printf("Invalid choice. Please try again.\n");
        exit(EXIT_FAILURE);
    }

    random_index = rand() % NUM_FORTUNES;

    if (user_choice == random_index) {
        printf("Congratulations! You have chosen the same fortune as the Automated Fortune Teller.\n");
        printf("Your fortune: %s\n", fortunes[user_choice - 1]);
    } else {
        printf("Sorry, you did not choose the same fortune as the Automated Fortune Teller.\n");
        printf("Your fortune: %s\n", fortunes[random_index]);
    }

    for (int i = 0; i < NUM_FORTUNES; i++) {
        free(fortunes[i]);
    }

    printf("Goodbye and may your day be filled with luck!\n");

    return EXIT_SUCCESS;
}