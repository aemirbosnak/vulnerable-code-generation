//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_LENGTH 256

typedef struct {
    char *subject;
    char *conspiracy;
} Theory;

void initialize_theories(Theory theories[]) {
    const char *subjects[] = {
        "the moon landing", "Bigfoot", "Area 51", "the Bermuda Triangle", 
        "aliens", "vaccines", "the Illuminati", "climate change", 
        "Elvis Presley", "January 6th insurrection", "5G technology", 
        "secret government mind control", "AI takeover", "Hollywood elites", 
        "flat Earth", "reptilian overlords", "chemtrails"
    };

    const char *conspiracies[] = {
        "was staged by NASA to distract from the Vietnam War.",
        "is a government-funded project to suppress human evolution.",
        "is hiding alien technology that could end world hunger.",
        "contains portals to other dimensions, exploited by secret societies.",
        "is secretly a cover-up for an interstellar alien invasion.",
        "are actually microchips implanted for mind control by corporations.",
        "have been manipulated by powerful families to control world events.",
        "is an elaborate ruse to install a one-world government.",
        "never actually happened; it's just a CGI holiday.",
        "is a distraction created by pharmaceutical companies.",
        "were invented by politicians to control the populace's behavior.",
        "is being orchestrated by social media companies to sow discontent.",
        "is merely a performance to keep us distracted from real issues.",
        "is funded by billionaires to enforce their control over society.",
        "is really just an advanced simulation designed by tech companies.",
        "are meant to awaken humanity to hidden truths, but it's kept quiet.",
        "is no longer a conspiracy; it is a reality being accepted globally.",
        "is the result of an ancient prophecy that is now unfolding."
    };

    int num_subjects = sizeof(subjects) / sizeof(subjects[0]);
    int num_conspiracies = sizeof(conspiracies) / sizeof(conspiracies[0]);

    for (int i = 0; i < MAX_THEORIES; i++) {
        theories[i].subject = strdup(subjects[rand() % num_subjects]);
        theories[i].conspiracy = strdup(conspiracies[rand() % num_conspiracies]);
    }
}

void free_theories(Theory theories[]) {
    for (int i = 0; i < MAX_THEORIES; i++) {
        free(theories[i].subject);
        free(theories[i].conspiracy);
    }
}

void generate_and_print_theories(Theory theories[]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_THEORIES; i++) {
        printf("Theory %d: %s %s\n", i + 1, theories[i].subject, theories[i].conspiracy);
    }
}

int main() {
    Theory theories[MAX_THEORIES];
    
    // Initialize the theories with random subjects and conspiracies
    initialize_theories(theories);

    // Generate and print the theories
    generate_and_print_theories(theories);

    // Free allocated memory
    free_theories(theories);

    return 0;
}