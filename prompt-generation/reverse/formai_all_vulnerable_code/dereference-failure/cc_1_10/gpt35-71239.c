//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Structures */

struct planet {
    char name[20];
    int distance;
    int resources;
};

/* Function Prototypes */

void welcome();
void spaceship();
int travel(int current_location, int destination);
void generate_planets(struct planet **planet_ptr);
void display_planets(struct planet *planet_ptr, int num_planets);
void landing(struct planet current_planet);

/* Main Function */

int main() {
    int current_location = 0;
    int destination = -1;
    int num_planets = 10;
    struct planet *planet_ptr;

    welcome();

    spaceship();

    generate_planets(&planet_ptr);

    display_planets(planet_ptr, num_planets);

    while(destination < 0 || destination >= num_planets) {
        printf("\nEnter the number of the planet you would like to travel to (0-9): ");
        scanf("%d", &destination);
    }

    current_location = travel(current_location, destination);

    landing(planet_ptr[current_location]);

    free(planet_ptr);

    return 0;
}

/* Function Definitions */

void welcome() {
    printf("Welcome to our Procedural Space Adventure Program!\n");
    printf("You are the captain of a spaceship and are about to embark on an adventure to explore the galaxy!\n");
    printf("Your mission is to travel to different planets, collect resources, and upgrade your ship to reach the final planet!\n\n");
}

void spaceship() {
    printf("(*_*)\n");
    printf(" | |\n");
    printf("/   \\\n");
    printf("\n");
}

int travel(int current_location, int destination) {
    int i;
    printf("Launching in 3, 2, 1...\n");
    for(i=0; i<3; i++) {
        printf("* * *\n");
        sleep(1);
    }
    printf("\nArrived at Planet %d!\n", destination);
    return destination;
}

void generate_planets(struct planet **planet_ptr) {
    (*planet_ptr) = (struct planet *) malloc(10 * sizeof(struct planet));
    strcpy((*planet_ptr)[0].name, "Mars");
    strcpy((*planet_ptr)[1].name, "Venus");
    strcpy((*planet_ptr)[2].name, "Jupiter");
    strcpy((*planet_ptr)[3].name, "Saturn");
    strcpy((*planet_ptr)[4].name, "Neptune");
    strcpy((*planet_ptr)[5].name, "Uranus");
    strcpy((*planet_ptr)[6].name, "Mercury");
    strcpy((*planet_ptr)[7].name, "Pluto");
    strcpy((*planet_ptr)[8].name, "Earth");
    strcpy((*planet_ptr)[9].name, "Final Planet");

    srand(time(0));

    for(int i=0; i<10; i++) {
        (*planet_ptr)[i].distance = rand() % 200;
        (*planet_ptr)[i].resources = rand() % 1000 + 500;
    }
}

void display_planets(struct planet *planet_ptr, int num_planets) {
    printf("Here are the planets you can travel to:\n\n");
    printf("#  Name                 Distance (Light Years)     Resources Available (Metric Tons)\n");
    for(int i=0; i<num_planets; i++) {
        printf("%d. %-20s %10d %30d\n", i, planet_ptr[i].name, planet_ptr[i].distance, planet_ptr[i].resources);
    }
}

void landing(struct planet current_planet) {
    printf("\nWelcome to %s!\n", current_planet.name);
    printf("Current Resource Stockpile: %d metric tons\n\n", current_planet.resources);
    printf("  O\n");
    printf("-XXX-\n");
    printf(" / \\\n");
}