//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PHONEBOOK_MAX_NAME_LENGTH 50
#define PHONEBOOK_MAX_NUMBER_LENGTH 20
#define PHONEBOOK_MAX_ENTRIES 100

struct phonebook_entry {
    char name[PHONEBOOK_MAX_NAME_LENGTH];
    char number[PHONEBOOK_MAX_NUMBER_LENGTH];
};

static struct phonebook_entry phonebook[PHONEBOOK_MAX_ENTRIES];
static int current_entry = 0;

void add_entry(char *name, char *number) {
    if (current_entry == PHONEBOOK_MAX_ENTRIES) {
        printf("Error: Phonebook is full. Please delete some entries first.\n");
        return;
    }

    strcpy(phonebook[current_entry].name, name);
    strcpy(phonebook[current_entry].number, number);
    current_entry++;
}

void delete_entry(int index) {
    if (index < 0 || index >= PHONEBOOK_MAX_ENTRIES) {
        printf("Error: Invalid entry index.\n");
        return;
    }

    memset(&phonebook[index], 0, sizeof(struct phonebook_entry));
    current_entry--;
}

void search_entry(char *name) {
    int i;
    for (i = 0; i < current_entry; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Found entry: %s %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    srand(time(NULL));

    // Add some random entries
    for (int i = 0; i < 10; i++) {
        char name[PHONEBOOK_MAX_NAME_LENGTH];
        char number[PHONEBOOK_MAX_NUMBER_LENGTH];
        sprintf(name, "Person %d", i);
        sprintf(number, "0123456789%d", i);
        add_entry(name, number);
    }

    // Search for some entries
    char search_name[] = "John";
    search_entry(search_name);

    // Delete some entries
    int index = rand() % PHONEBOOK_MAX_ENTRIES;
    delete_entry(index);

    return 0;
}