//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the type of a cat
typedef struct cat {
    char *name;
    int age;
    bool is_male;
} cat;

// Create a new cat
cat *create_cat(char *name, int age, bool is_male) {
    cat *new_cat = malloc(sizeof(cat));
    new_cat->name = name;
    new_cat->age = age;
    new_cat->is_male = is_male;
    return new_cat;
}

// Print the details of a cat
void print_cat(cat *cat) {
    printf("Name: %s\n", cat->name);
    printf("Age: %d\n", cat->age);
    printf("Is male: %s\n", cat->is_male ? "true" : "false");
}

// Create a list of cats
cat **create_cat_list(int num_cats) {
    cat **cat_list = malloc(sizeof(cat *) * num_cats);
    for (int i = 0; i < num_cats; i++) {
        char *name = malloc(10);
        sprintf(name, "Cat %d", i + 1);
        cat *new_cat = create_cat(name, i + 1, i % 2 == 0);
        cat_list[i] = new_cat;
    }
    return cat_list;
}

// Print the list of cats
void print_cat_list(cat **cat_list, int num_cats) {
    for (int i = 0; i < num_cats; i++) {
        print_cat(cat_list[i]);
        printf("\n");
    }
}

// Free the memory allocated for a cat
void free_cat(cat *cat) {
    free(cat->name);
    free(cat);
}

// Free the memory allocated for a list of cats
void free_cat_list(cat **cat_list, int num_cats) {
    for (int i = 0; i < num_cats; i++) {
        free_cat(cat_list[i]);
    }
    free(cat_list);
}

// Main function
int main() {
    // Create a list of 10 cats
    cat **cat_list = create_cat_list(10);

    // Print the list of cats
    print_cat_list(cat_list, 10);

    // Free the memory allocated for the list of cats
    free_cat_list(cat_list, 10);

    return 0;
}