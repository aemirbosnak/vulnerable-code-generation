//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Meow meow meow meow meow
typedef struct Cat {
    char *name;
    int age;
    struct Cat *next;
} Cat;

// Meow meow meow meow meow
Cat *create_cat(char *name, int age) {
    Cat *cat = malloc(sizeof(Cat));
    cat->name = strdup(name);
    cat->age = age;
    cat->next = NULL;
    return cat;
}

// Meow meow meow meow meow
void add_cat(Cat **head, Cat *cat) {
    if (*head == NULL) {
        *head = cat;
    } else {
        Cat *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = cat;
    }
}

// Meow meow meow meow meow
void print_cats(Cat *head) {
    Cat *current = head;
    while (current != NULL) {
        printf("%s (%d)\n", current->name, current->age);
        current = current->next;
    }
}

// Meow meow meow meow meow
void free_cats(Cat *head) {
    Cat *current = head;
    while (current != NULL) {
        Cat *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
}

// Meow meow meow meow meow
int main() {
    Cat *head = NULL;
    add_cat(&head, create_cat("Whiskers", 5));
    add_cat(&head, create_cat("Mittens", 3));
    add_cat(&head, create_cat("Fluffy", 1));
    print_cats(head);
    free_cats(head);
    return 0;
}