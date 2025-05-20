//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAT_NAME_MAX_LENGTH 32
#define CAT_SOUND_MAX_LENGTH 128

typedef struct cat {
    char name[CAT_NAME_MAX_LENGTH];
    char sound[CAT_SOUND_MAX_LENGTH];
    int age;
    struct cat *next;
} cat_t;

cat_t *head = NULL;

void add_cat(char *name, char *sound, int age) {
    cat_t *new_cat = malloc(sizeof(cat_t));
    strcpy(new_cat->name, name);
    strcpy(new_cat->sound, sound);
    new_cat->age = age;
    new_cat->next = NULL;

    if (head == NULL) {
        head = new_cat;
    } else {
        cat_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_cat;
    }
}

void print_cats() {
    cat_t *current = head;
    while (current != NULL) {
        printf("%s says %s and is %d years old\n", current->name, current->sound, current->age);
        current = current->next;
    }
}

void free_cats() {
    cat_t *current = head;
    while (current != NULL) {
        cat_t *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    add_cat("Fluffy", "Meow", 5);
    add_cat("Whiskers", "Purr", 3);
    add_cat("Mittens", "Hiss", 1);

    print_cats();

    free_cats();

    return 0;
}