//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct Romeo {
    char name[10];
    int age;
    struct Juliet *next;
} Romeo;

typedef struct Juliet {
    char name[10];
    int age;
    struct Romeo *next;
} Juliet;

Romeo *romeo, *new_romeo;
Juliet *juliet, *new_juliet;

void create_romeo(char r_name[], int r_age) {
    new_romeo = (Romeo *) malloc(sizeof(Romeo));
    strcpy(new_romeo->name, r_name);
    new_romeo->age = r_age;
    new_romeo->next = romeo;
    romeo = new_romeo;
}

void create_juliet(char j_name[], int j_age) {
    new_juliet = (Juliet *) malloc(sizeof(Juliet));
    strcpy(new_juliet->name, j_name);
    new_juliet->age = j_age;
    new_juliet->next = juliet;
    juliet = new_juliet;
}

void display_romeo_and_juliet() {
    Romeo *temp_romeo = romeo;
    Juliet *temp_juliet = juliet;

    printf("\n----- Romeo's ------\n");
    while (temp_romeo != NULL) {
        printf("Name: %s, Age: %d\n", temp_romeo->name, temp_romeo->age);
        temp_romeo = temp_romeo->next;
    }

    printf("\n----- Juliet's ------\n");
    while (temp_juliet != NULL) {
        printf("Name: %s, Age: %d\n", temp_juliet->name, temp_juliet->age);
        temp_juliet = temp_juliet->next;
    }
}

void free_memory() {
    Romeo *temp_romeo = romeo;
    Juliet *temp_juliet = juliet;

    while (romeo != NULL) {
        juliet = juliet->next;
        free(temp_romeo);
        temp_romeo = romeo;
        romeo = romeo->next;
    }

    while (juliet != NULL) {
        free(temp_juliet);
        temp_juliet = juliet;
        juliet = juliet->next;
    }
}

int main() {
    romeo = NULL;
    juliet = NULL;

    create_romeo("Romeo", 20);
    create_juliet("Juliet", 18);
    create_romeo("Mercutio", 19);
    create_juliet("Tybalt", 21);

    display_romeo_and_juliet();

    free_memory();

    return 0;
}