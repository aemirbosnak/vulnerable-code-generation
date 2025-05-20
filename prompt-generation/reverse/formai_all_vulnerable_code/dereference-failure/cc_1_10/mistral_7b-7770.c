//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Moment {
    int x;
    struct Moment *next;
    char *description;
} Moment;

void print_moments(Moment *current) {
    while (current != NULL) {
        printf("%s: x = %d\n", current->description, current->x);
        current = current->next;
    }
}

void travel_back_in_time(Moment **current, int days) {
    Moment *prev = *current;
    while (prev->next != NULL && days >= 0) {
        (*current) = prev;
        prev = prev->next;
        days--;
    }
}

void update_x_and_description(Moment **current, int new_x, char *new_description) {
    Moment *new_moment = (Moment *) malloc(sizeof(Moment));
    new_moment->x = new_x;
    new_moment->next = *current;
    new_moment->description = strdup(new_description);
    (*current) = new_moment;
}

int main() {
    Moment *current = NULL;
    int days = 0;

    update_x_and_description(&current, 5, "Initial state");

    for (int i = 1; i <= 10; i++) {
        travel_back_in_time(&current, days += 3);
        update_x_and_description(&current, i * 2, ("Three days later, x = ")[i]);
    }

    printf("Current state: x = %d\n", current->x);

    print_moments(current);

    travel_back_in_time(&current, days);
    free(current->description);
    free(current);

    current = NULL;

    update_x_and_description(&current, 10, "Reset state");

    print_moments(current);

    return 0;
}