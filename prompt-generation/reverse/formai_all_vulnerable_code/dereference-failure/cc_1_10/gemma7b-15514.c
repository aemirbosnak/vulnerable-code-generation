//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct CelestialObject {
    char name[MAX_SIZE];
    int x, y, z;
    double mass;
    struct CelestialObject *next;
} CelestialObject;

CelestialObject *create_object(char *name, int x, int y, int z, double mass)
{
    CelestialObject *new_object = malloc(sizeof(CelestialObject));

    strcpy(new_object->name, name);
    new_object->x = x;
    new_object->y = y;
    new_object->z = z;
    new_object->mass = mass;
    new_object->next = NULL;

    return new_object;
}

void destroy_object(CelestialObject *object)
{
    free(object);
}

int main()
{
    CelestialObject *solar_system = NULL;

    // Create the sun
    CelestialObject *sun = create_object("Sun", 0, 0, 0, 1000000);
    solar_system = sun;

    // Create the planets
    CelestialObject *earth = create_object("Earth", 1, 0, 0, 5);
    solar_system->next = earth;
    CelestialObject *mars = create_object("Mars", 2, 0, 0, 0.6);
    earth->next = mars;

    // Simulate a meteor impact
    time_t t = time(NULL);
    int rand_x = rand() % MAX_SIZE;
    int rand_y = rand() % MAX_SIZE;
    CelestialObject *meteor = create_object("Meteor", rand_x, rand_y, 0, 100);
    meteor->next = solar_system;

    // Destroy the meteor
    destroy_object(meteor);

    // Print the remaining objects
    CelestialObject *object = solar_system;
    while (object)
    {
        printf("%s (%d, %d, %d) with mass %.2lf\n", object->name, object->x, object->y, object->z, object->mass);
        object = object->next;
    }

    return 0;
}