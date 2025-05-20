//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIME_TRAVELS 10

typedef struct {
    char *name;
    int year;
} time_traveler;

time_traveler *time_travelers[MAX_TIME_TRAVELS];

void add_time_traveler(char *name, int year) {
    for (int i = 0; i < MAX_TIME_TRAVELS; i++) {
        if (time_travelers[i] == NULL) {
            time_travelers[i] = malloc(sizeof(time_traveler));
            time_travelers[i]->name = strdup(name);
            time_travelers[i]->year = year;
            break;
        }
    }
}

void remove_time_traveler(char *name) {
    for (int i = 0; i < MAX_TIME_TRAVELS; i++) {
        if (time_travelers[i] != NULL && strcmp(time_travelers[i]->name, name) == 0) {
            free(time_travelers[i]->name);
            free(time_travelers[i]);
            time_travelers[i] = NULL;
            break;
        }
    }
}

void print_time_travelers() {
    for (int i = 0; i < MAX_TIME_TRAVELS; i++) {
        if (time_travelers[i] != NULL) {
            printf("%s (%d)\n", time_travelers[i]->name, time_travelers[i]->year);
        }
    }
}

int main() {
    add_time_traveler("John Smith", 1955);
    add_time_traveler("Jane Doe", 1980);
    add_time_traveler("John Doe", 1990);

    print_time_travelers();

    remove_time_traveler("John Smith");

    print_time_travelers();

    return 0;
}