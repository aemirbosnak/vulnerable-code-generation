//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: peaceful
// A tranquil and serene C Mailing List Manager program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A calming data structure to hold our mailing list
struct MailingList {
    char **emails;
    int capacity;
    int size;
};

// A soothing function to create a new mailing list
struct MailingList *createList(int initialCapacity) {
    struct MailingList *list = malloc(sizeof(struct MailingList));
    list->capacity = initialCapacity;
    list->size = 0;
    list->emails = malloc(sizeof(char *) * list->capacity);
    return list;
}

// A tranquil function to add an email to the mailing list
void addEmail(struct MailingList *list, char *email) {
    if (list->size == list->capacity) {
        // Gentle expansion of our list
        list->capacity *= 2;
        list->emails = realloc(list->emails, sizeof(char *) * list->capacity);
    }
    list->emails[list->size++] = strdup(email);
}

// A serene function to send a message to all subscribers
void sendMessage(struct MailingList *list, char *message) {
    for (int i = 0; i < list->size; i++) {
        printf("Sending message to: %s\n", list->emails[i]);
        // (Pretend we are actually sending the message here)
    }
}

// A peaceful function to free the resources of our mailing list
void freeList(struct MailingList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
    free(list->emails);
    free(list);
}

// Our main function, where serenity begins
int main() {
    struct MailingList *list = createList(10);
    addEmail(list, "serene@example.com");
    addEmail(list, "tranquil@example.com");
    addEmail(list, "peaceful@example.com");
    sendMessage(list, "Greetings, gentle souls!");
    freeList(list);
    return 0;
}