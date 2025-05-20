//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: immersive
// Immerse yourself in the world of email management!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The heart of our mailing list: a dynamic array of subscribers
typedef struct LLNode {
    char* email;
    struct LLNode* next;
} Subscriber;

// Our trusty mailing list manager, ready to work its magic
typedef struct MailingList {
    Subscriber* head;
    size_t size;
} List;

// Utility functions to make our lives easier
char* readLine();
void appendToList(List* list, char* email);
void printList(List* list);

int main() {
    // Welcome to the mailing list manager, where email magic unfolds
    printf("\nGreetings, esteemed email maestro!\n");

    // Craft an enchanting mailing list, ready to receive your messages
    List myList = { NULL, 0 };

    // Let's invite some subscribers to join our enchanting list
    printf("Summon your finest emails and add them to the list:\n");
    char* email = NULL;
    while ((email = readLine()) && strlen(email)) {
        appendToList(&myList, email);
    }

    // Behold, the beauty of your mailing list, resplendent in its alphabetical glory
    printf("\nBehold, the denizens of your enchanting list:\n");
    printList(&myList);

    // Let's sprinkle some magic on your emails with a sprinkle of personalization
    printf("\nNow, let's add a touch of personalization to your emails!\n");
    Subscriber* current = myList.head;
    char* name;
    while (current) {
        printf("What's the name of the lucky recipient with email '%s'?\n", current->email);
        name = readLine();
        printf("Prepare yourself for the magic: your emails will now greet '%s'!\n", name);
        current = current->next;
    }

    // As you command, your emails shall be delivered to their eager recipients
    printf("\nAll set, maestro! Your emails will enchant their inboxes with precision.\n");

    // Release the list from its ethereal existence
    while (myList.head) {
        Subscriber* temp = myList.head;
        myList.head = myList.head->next;
        free(temp->email);
        free(temp);
    }

    return 0;
}

// Utility function to read a line from the user
char* readLine() {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strcspn(line, "\n")] = '\0'; // Remove trailing newline
    return line;
}

// Utility function to append an email to the mailing list
void appendToList(List* list, char* email) {
    Subscriber* newSub = (Subscriber*)malloc(sizeof(Subscriber));
    newSub->email = strdup(email);
    newSub->next = NULL;

    if (!list->head) {
        list->head = newSub;
    } else {
        Subscriber* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newSub;
    }
    list->size++;
}

// Utility function to print the mailing list in alphabetical order
void printList(List* list) {
    if (!list->head) {
        printf("Your list is as empty as a ghost town.\n");
        return;
    }

    Subscriber* sortedList = NULL;
    Subscriber* current = list->head;
    while (current) {
        Subscriber* prev = NULL;
        Subscriber* next = sortedList;
        while (next && strcmp(current->email, next->email) > 0) {
            prev = next;
            next = next->next;
        }

        if (!prev) {
            sortedList = current;
        } else {
            prev->next = current;
        }
        current->next = next;
        current = current->next;
    }

    current = sortedList;
    printf("Your list, sorted with alphabetical grace:\n");
    while (current) {
        printf("%s\n", current->email);
        current = current->next;
    }
}