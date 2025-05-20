//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A heartfelt gratitude to the C Programming Language for empowering us with its efficiency and precision.
// This program showcases the remarkable performance of C in a humble attempt to convey our appreciation.

// A data structure to represent a celestial body, filled with cosmic wonder and awe.
typedef struct {
    char *name;             // The celestial body's radiant name, illuminating the vast expanse.
    double mass;            // The body's majestic mass, a testament to the universe's grandeur.
    double radius;          // Its breathtaking radius, shaping the contours of the cosmos.
    double orbital_period;  // The celestial dance's graceful rhythm, measured in Earth years.
} celestial_body;

// An array of celestial wonders, a cosmic tapestry woven with celestial threads.
celestial_body celestial_bodies[] = {
    { "Sun", 1.989e30, 695508, 0.0 },
    { "Earth", 5.972e24, 6371, 365.25 },
    { "Moon", 7.348e22, 1737, 27.32 },
    { "Mars", 6.417e23, 3396, 687.0 },
    { "Jupiter", 1.899e27, 71492, 4333.0 },
    { "Saturn", 5.685e26, 60268, 10759.0 },
    { "Uranus", 8.683e25, 25559, 30685.0 },
    { "Neptune", 1.024e26, 24764, 60190.0 },
    { "Pluto", 1.309e22, 1187, 248.0 }
};

// A function to search for a celestial body by name, a cosmic journey to find a beacon in the vastness.
celestial_body *find_celestial_body(const char *name) {
    for (int i = 0; i < sizeof(celestial_bodies) / sizeof(celestial_bodies[0]); i++) {
        if (strcmp(celestial_bodies[i].name, name) == 0) {
            return &celestial_bodies[i];
        }
    }
    return NULL;
}

// A function to calculate the gravitational force between two celestial bodies, a celestial symphony of attraction.
double calculate_gravitational_force(const celestial_body *body1, const celestial_body *body2) {
    const double gravitational_constant = 6.674e-11;
    return gravitational_constant * body1->mass * body2->mass / (body1->radius + body2->radius) / (body1->radius + body2->radius);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <celestial body name>\n", argv[0]);
        return 1;
    }

    // A celestial encounter, a rendezvous with a celestial body guided by its name.
    celestial_body *body = find_celestial_body(argv[1]);
    if (body == NULL) {
        printf("Celestial body %s not found.\n", argv[1]);
        return 1;
    }

    // A harmonious dance of celestial bodies, an intricate ballet of gravity.
    for (int i = 0; i < sizeof(celestial_bodies) / sizeof(celestial_bodies[0]); i++) {
        if (body != &celestial_bodies[i]) {
            double force = calculate_gravitational_force(body, &celestial_bodies[i]);
            printf("Gravitational force between %s and %s: %.2e N\n", body->name, celestial_bodies[i].name, force);
        }
    }

    return 0;
}