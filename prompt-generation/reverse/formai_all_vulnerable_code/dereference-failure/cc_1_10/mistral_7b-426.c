//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct crime_scene {
    char name[MAX_NAME_LENGTH];
    char occupation[MAX_NAME_LENGTH];
    int involved;
    struct crime_scene *next;
} CrimeScene;

void print_crime_scene(CrimeScene *head) {
    CrimeScene *current = head;

    printf("\nCrime Scene:\n");

    while (current != NULL) {
        printf("%s, %s: ", current->name, current->occupation);

        if (current->involved)
            printf("INVOLVED\n");
        else
            printf("NOT INVOLVED\n");

        current = current->next;
    }
}

void add_suspect(CrimeScene **head, const char *name, const char *occupation, int involved) {
    CrimeScene *new_suspect = (CrimeScene *)malloc(sizeof(CrimeScene));

    strncpy(new_suspect->name, name, MAX_NAME_LENGTH);
    strncpy(new_suspect->occupation, occupation, MAX_NAME_LENGTH);
    new_suspect->involved = involved;
    new_suspect->next = *head;

    *head = new_suspect;
}

int main() {
    CrimeScene *crime_scene = NULL;

    add_suspect(&crime_scene, "John Watson", "Doctor", 0);
    add_suspect(&crime_scene, "Sherlock Holmes", "Consulting Detective", 1);
    add_suspect(&crime_scene, "Moriarty", "Professor of Chemistry", 1);

    print_crime_scene(crime_scene);

    CrimeScene *current = crime_scene;

    while (current != NULL) {
        if (current->involved) {
            printf("\n%s with %s is under arrest!\n", current->name, current->occupation);
            free(current);
            current = crime_scene;
            crime_scene = crime_scene->next;
            continue;
        }

        current = current->next;
    }

    printf("\nAll suspects are free.\n");

    return 0;
}