//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timeline {
    int year;
    char *description;
    struct timeline *next;
};

struct timeline *create_timeline(int year, char *description) {
    struct timeline *new_timeline = malloc(sizeof(struct timeline));
    new_timeline->year = year;
    new_timeline->description = description;
    new_timeline->next = NULL;
    return new_timeline;
}

void add_to_timeline(struct timeline **timeline, int year, char *description) {
    struct timeline *new_timeline = create_timeline(year, description);
    if (*timeline == NULL) {
        *timeline = new_timeline;
    } else {
        struct timeline *current = *timeline;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_timeline;
    }
}

void print_timeline(struct timeline *timeline) {
    struct timeline *current = timeline;
    while (current != NULL) {
        printf("%d: %s\n", current->year, current->description);
        current = current->next;
    }
}

void free_timeline(struct timeline *timeline) {
    struct timeline *current = timeline;
    while (current != NULL) {
        struct timeline *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}

int main() {
    srand(time(NULL));

    struct timeline *timeline = NULL;

    add_to_timeline(&timeline, 2023, "The present day. The world is a cyberpunk dystopia, where corporations rule and the streets are filled with violence and crime.");
    add_to_timeline(&timeline, 2042, "A new technology called the neuralink is invented, which allows people to connect their brains to the internet.");
    add_to_timeline(&timeline, 2077, "The world is plunged into a nuclear war, and the cyberpunk dystopia becomes a reality.");
    add_to_timeline(&timeline, 2102, "A new society emerges from the ashes of the old, and the cyberpunk dystopia is no more.");

    int year = 2023;
    while (year != 2102) {
        year += rand() % 10;

        struct timeline *current = timeline;
        while (current != NULL) {
            if (current->year == year) {
                printf("You have traveled to the year %d.\n", year);
                printf("%s\n", current->description);
                break;
            }
            current = current->next;
        }
    }

    free_timeline(timeline);

    return 0;
}