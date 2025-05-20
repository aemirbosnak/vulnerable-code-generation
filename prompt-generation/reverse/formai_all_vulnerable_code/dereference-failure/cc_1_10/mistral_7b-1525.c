//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAMES 10
#define NUM_FORTUNES 5

// Struct to store fortune name and message
typedef struct {
    char name[20];
    char* message;
} Fortune;

Fortune fortunes[NUM_FORTUNES] = {
    {"The Enlightened Path", "Your future shines with wisdom and knowledge."},
    {"The Traveler's Blessing", "A journey of a thousand miles begins with a single step."},
    {"The Lucky Coin", "Good fortune awaits you; find happiness in the simple things."},
    {"The Wise Elder", "With age comes wisdom; trust in the experience of others."},
    {"The Secret Garden", "Seek out the hidden beauty in the world around you."}
};

void print_fortune(const char* name) {
    for (int i = 0; i < NUM_FORTUNES; i++) {
        if (strcmp(name, fortunes[i].name) == 0) {
            printf("\n%s\n", fortunes[i].message);
            return;
        }
    }

    printf("Sorry, I couldn't find a fortune for that name.\n");
}

int main() {
    srand(time(NULL));
    char* names[MAX_NAMES];
    int num_names = 0;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter the names of up to %d people to receive their fortunes (one at a time):\n", MAX_NAMES);

    while (num_names < MAX_NAMES) {
        printf("Name %d: ", num_names + 1);
        fgets(names[num_names], sizeof(names[num_names]), stdin);
        names[num_names][strcspn(names[num_names], "\n")] = '\0';
        num_names++;
    }

    printf("\nCalculating fortunes...\n");

    for (int i = 0; i < num_names; i++) {
        print_fortune(names[i]);

        if (i != num_names - 1) {
            printf("\nPress Enter to continue...\n");
            getchar();
        }
    }

    return 0;
}