//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: visionary
// Embark on a celestial epistolary voyage with "Celestial Mailing Manager"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// **Celestial Entities**

typedef struct Comet {
    char *name;
    long arrival;
    long departure;
    char *message;
} Comet;

typedef struct Planet {
    char *name;
    Comet **comets;
    int num_comets;
} Planet;

// **Celestial Functions**

Comet *create_comet(char *name, long arrival, long departure, char *message) {
    Comet *comet = malloc(sizeof(Comet));
    comet->name = strdup(name);
    comet->arrival = arrival;
    comet->departure = departure;
    comet->message = strdup(message);
    return comet;
}

Planet *create_planet(char *name) {
    Planet *planet = malloc(sizeof(Planet));
    planet->name = strdup(name);
    planet->comets = NULL;
    planet->num_comets = 0;
    return planet;
}

void add_comet_to_planet(Planet *planet, Comet *comet) {
    planet->comets = realloc(planet->comets, (planet->num_comets + 1) * sizeof(Comet *));
    planet->comets[planet->num_comets++] = comet;
}

void print_comets_by_arrival(Planet *planet) {
    for (int i = 0; i < planet->num_comets; i++) {
        printf("%s\n", planet->comets[i]->name);
    }
}

// **Celestial Main**

int main(int argc, char **argv) {
    // Seed the celestial tapestry with time
    srand(time(NULL));

    // Create cosmic entities
    Planet *earth = create_planet("Earth");
    Planet *pluto = create_planet("Pluto");

    // Generate ethereal messages
    char *messages[] = {
        "Greetings from the cosmic void",
        "Beware the encroaching darkness",
        "May your journey be guided by celestial light",
    };

    // Dispatch comets with celestial wisdom
    int num_comets = rand() % 100;
    for (int i = 0; i < num_comets; i++) {
        long arrival_time = rand() % 1000000000;
        long departure_time = arrival_time + (rand() % 5000000);
        char *name = malloc(10);
        sprintf(name, "Comet %d", i);
        char *message = messages[rand() % 3];
        Comet *comet = create_comet(name, arrival_time, departure_time, message);
        if (rand() % 2) {
            add_comet_to_planet(earth, comet);
        } else {
            add_comet_to_planet(pluto, comet);
        }
    }

    // Decode celestial messages on Earth
    printf("Comets arriving at Earth:\n");
    print_comets_by_arrival(earth);

    // Guide Pluto through its celestial solitude
    printf("Comets around Pluto:\n");
    print_comets_by_arrival(pluto);

    // Farewell, celestial wanderers
    printf("May your astral paths ever inspire celestial dreams.\n");

    return 0;
}