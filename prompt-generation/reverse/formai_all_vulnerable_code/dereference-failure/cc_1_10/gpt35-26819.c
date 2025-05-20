//FormAI DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Ebook {
    char* title;
    char* author;
    char* format;
    char* content;
} Ebook;

typedef struct EbookNode {
    Ebook ebook;
    struct EbookNode* next;
} EbookNode;

typedef struct EbookList {
    EbookNode* head;
    EbookNode* tail;
} EbookList;

EbookList* createEbookList() {
    EbookList* list = (EbookList*)malloc(sizeof(EbookList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

EbookNode* createEbookNode(Ebook ebook) {
    EbookNode* node = (EbookNode*)malloc(sizeof(EbookNode));
    node->ebook = ebook;
    node->next = NULL;
    return node;
}

void addEbook(EbookList* list, Ebook ebook) {
    EbookNode* node = createEbookNode(ebook);

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;
    }
}

void displayEbookList(EbookList* list) {
    EbookNode* current = list->head;

    while (current != NULL) {
        printf("Title: %s\nAuthor: %s\nFormat: %s\nContent: %s\n\n", current->ebook.title, current->ebook.author, current->ebook.format, current->ebook.content);
        current = current->next;
    }
}

void readEbook(EbookList* list, char* title) {
    EbookNode* current = list->head;
    bool foundEbook = false;

    while (current != NULL) {
        if (strcmp(current->ebook.title, title) == 0) {
            printf("Reading ebook: %s\n%s", current->ebook.title, current->ebook.content);
            foundEbook = true;
            break;
        }
        current = current->next;
    }

    if (!foundEbook) {
        printf("Ebook with title '%s' not found.\n", title);
    }
}

int main() {
    EbookList* list = createEbookList();

    Ebook ebook1 = { "The Great Gatsby", "F. Scott Fitzgerald", "PDF", "Lorem ipsum dolor sit amet" };
    Ebook ebook2 = { "To Kill a Mockingbird", "Harper Lee", "ePub", "consectetur adipiscing elit" };
    Ebook ebook3 = { "1984", "George Orwell", "MOBI", "sed do eiusmod tempor incididunt" };
    Ebook ebook4 = { "Pride and Prejudice", "Jane Austen", "PDF", "ut labore et dolore magna aliqua" };

    addEbook(list, ebook1);
    addEbook(list, ebook2);
    addEbook(list, ebook3);
    addEbook(list, ebook4);

    displayEbookList(list);

    readEbook(list, "1984");

    return 0;
}