//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    char *occupation;
} Person;

typedef struct {
    char name[20];
    int age;
    char *occupation;
    int ghost_level;
} Ghost;

int main() {
    Person *people;
    Ghost *ghosts;
    int num_people, num_ghosts;

    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    people = (Person *)malloc(num_people * sizeof(Person));

    printf("Enter the name, age, and occupation of each person:\n");

    for (int i = 0; i < num_people; i++) {
        printf("Person %d:", i + 1);
        scanf("%s %d %s", people[i].name, &people[i].age, people[i].occupation);
    }

    printf("\n");

    printf("Enter the number of ghosts: ");
    scanf("%d", &num_ghosts);

    ghosts = (Ghost *)malloc(num_ghosts * sizeof(Ghost));

    printf("Enter the name, age, occupation, and ghost level of each ghost:\n");

    for (int i = 0; i < num_ghosts; i++) {
        printf("Ghost %d:", i + 1);
        scanf("%s %d %s %d", ghosts[i].name, &ghosts[i].age, ghosts[i].occupation, &ghosts[i].ghost_level);
    }

    printf("\n");

    printf("Haunted House Simulator\n");

    for (int i = 0; i < num_people; i++) {
        for (int j = 0; j < num_ghosts; j++) {
            if (people[i].age < ghosts[j].ghost_level) {
                printf("Person %s is scared by Ghost %s.\n", people[i].name, ghosts[j].name);
            }
        }
    }

    return 0;
}