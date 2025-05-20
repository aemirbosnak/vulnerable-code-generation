//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_YEARS 100

struct Alien {
    int id;
    int year_of_invasion;
};

void generate_aliens(struct Alien aliens[], int num_aliens) {
    srand(time(NULL));
    for (int i = 0; i < num_aliens; i++) {
        aliens[i].id = i + 1;
        aliens[i].year_of_invasion = rand() % MAX_YEARS + 1;
    }
}

void sort_aliens(struct Alien aliens[], int num_aliens) {
    for (int i = 0; i < num_aliens - 1; i++) {
        for (int j = i + 1; j < num_aliens; j++) {
            if (aliens[j].year_of_invasion < aliens[i].year_of_invasion) {
                struct Alien temp = aliens[i];
                aliens[i] = aliens[j];
                aliens[j] = temp;
            }
        }
    }
}

int main() {
    int num_aliens;
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    if (num_aliens > MAX_ALIENS) {
        printf("Sorry, the maximum number of aliens is %d.\n", MAX_ALIENS);
        return 1;
    }

    struct Alien aliens[num_aliens];
    generate_aliens(aliens, num_aliens);
    sort_aliens(aliens, num_aliens);

    printf("Alien Invasion Probability Calculator\n");
    printf("Number of aliens: %d\n", num_aliens);
    printf("Year\tAlien ID\n");

    for (int i = 0; i < num_aliens; i++) {
        printf("%d\t%d\n", aliens[i].year_of_invasion, aliens[i].id);
    }

    return 0;
}