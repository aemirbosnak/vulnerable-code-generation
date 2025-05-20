//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Linus Torvalds style:
// - No semicolons
// - No curly braces
// - Indentation is 8 spaces
// - No error checking

#define MAX_TIME_TRAVELERS 100

struct time_traveler {
    char *name;
    int year_of_birth;
    int year_of_death;
};

struct time_traveler time_travelers[MAX_TIME_TRAVELERS];

int num_time_travelers = 0;

void add_time_traveler(char *name, int year_of_birth, int year_of_death)
{
    if (num_time_travelers == MAX_TIME_TRAVELERS) {
        printf("Error: Too many time travelers\n");
        return;
    }

    time_travelers[num_time_travelers].name = strdup(name);
    time_travelers[num_time_travelers].year_of_birth = year_of_birth;
    time_travelers[num_time_travelers].year_of_death = year_of_death;

    num_time_travelers++;
}

void print_time_travelers()
{
    for (int i = 0; i < num_time_travelers; i++) {
        printf("%s (%d-%d)\n", time_travelers[i].name, time_travelers[i].year_of_birth, time_travelers[i].year_of_death);
    }
}

void time_travel(int year)
{
    for (int i = 0; i < num_time_travelers; i++) {
        if (time_travelers[i].year_of_birth <= year && time_travelers[i].year_of_death >= year) {
            printf("%s was alive in %d\n", time_travelers[i].name, year);
        }
    }
}

int main()
{
    add_time_traveler("Albert Einstein", 1879, 1955);
    add_time_traveler("Isaac Newton", 1643, 1727);
    add_time_traveler("Marie Curie", 1867, 1934);
    add_time_traveler("Galileo Galilei", 1564, 1642);
    add_time_traveler("Nicolaus Copernicus", 1473, 1543);

    print_time_travelers();

    time_travel(1900);

    return 0;
}