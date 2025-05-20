//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Brave warrior's phone book

struct phone_entry {
    char *name;
    char *number;
};

int main() {
    // Declare a brave phone book
    struct phone_entry *phone_book = malloc(10 * sizeof(struct phone_entry));

    // Fill the phone book with brave warriors
    phone_book[0].name = "Aragorn";
    phone_book[0].number = "555-1234";
    phone_book[1].name = "Legolas";
    phone_book[1].number = "555-5678";
    phone_book[2].name = "Gimli";
    phone_book[2].number = "555-9012";

    // Print the phone book
    for (int i = 0; i < 10; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
    }

    // Add a new brave warrior to the phone book
    struct phone_entry new_entry;
    new_entry.name = "Boromir";
    new_entry.number = "555-2345";
    phone_book = realloc(phone_book, (10 * sizeof(struct phone_entry)) + sizeof(struct phone_entry));
    phone_book[10] = new_entry;

    // Print the updated phone book
    for (int i = 0; i < 11; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
    }

    // Remove a brave warrior from the phone book
    int index = get_index(phone_book, "Legolas");
    if (index != -1) {
        phone_book[index].name = "Eowyn";
        phone_book[index].number = "555-5678";
    }

    // Print the updated phone book
    for (int i = 0; i < 11; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
    }

    // Free the brave phone book
    free(phone_book);

    return 0;
}

// Get the index of a brave warrior in the phone book
int get_index(struct phone_entry *phone_book, const char *name) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}