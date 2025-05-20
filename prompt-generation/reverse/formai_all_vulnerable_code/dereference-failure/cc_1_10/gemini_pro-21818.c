//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: imaginative
// A whimsical C program to manage a mailing list

// Like a grand tapestry woven with threads of words, our mailing list shall be!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our parchment shall hold the names of our correspondents
typedef struct Correspondent {
    char* name;
} Correspondent;

// A scrivener to manage our parchment
typedef struct MailingList {
    Correspondent** correspondents;
    int count;
} MailingList;

// A quill to inscribe new names upon our parchment
void add_correspondent(MailingList* list, char* name) {
    list->correspondents = realloc(list->correspondents, (list->count + 1) * sizeof(Correspondent*));
    list->correspondents[list->count] = malloc(sizeof(Correspondent));
    list->correspondents[list->count]->name = strdup(name);
    list->count++;
}

// A quill to remove names from our parchment
void remove_correspondent(MailingList* list, char* name) {
    int index = -1;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->correspondents[i]->name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        free(list->correspondents[index]->name);
        free(list->correspondents[index]);
        for (int i = index; i < list->count - 1; i++) {
            list->correspondents[i] = list->correspondents[i + 1];
        }
        list->count--;
    }
}

// A quill to print the names upon our parchment
void print_correspondents(MailingList* list) {
    printf("Our esteemed correspondents:\n");
    for (int i = 0; i < list->count; i++) {
        printf("- %s\n", list->correspondents[i]->name);
    }
}

// A quill to free our parchment when our task is done
void free_mailing_list(MailingList* list) {
    for (int i = 0; i < list->count; i++) {
        free(list->correspondents[i]->name);
        free(list->correspondents[i]);
    }
    free(list->correspondents);
    free(list);
}

int main() {
    // A new scroll to hold our list of correspondents
    MailingList* list = malloc(sizeof(MailingList));
    list->count = 0;
    list->correspondents = NULL;

    // Let us add some names to our parchment
    add_correspondent(list, "Lady Guinevere");
    add_correspondent(list, "Sir Lancelot");
    add_correspondent(list, "Merlin the Wizard");

    // Let us remove a name from our parchment
    remove_correspondent(list, "Merlin the Wizard");

    // Let us behold our list of correspondents
    print_correspondents(list);

    // Our task is done, let us free our parchment
    free_mailing_list(list);

    return 0;
}