//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *text;
    int length;
} Message;

typedef struct {
    Message **messages;
    int size;
} MessageList;

MessageList *createMessageList() {
    MessageList *list = malloc(sizeof(MessageList));
    list->messages = malloc(sizeof(Message *));
    list->size = 0;
    return list;
}

void addMessage(MessageList *list, char *text) {
    list->messages = realloc(list->messages, sizeof(Message *) * (list->size + 1));
    list->messages[list->size] = malloc(sizeof(Message));
    list->messages[list->size]->text = text;
    list->messages[list->size]->length = strlen(text);
    list->size++;
}

int containsSpam(Message *message) {
    char *spamWords[] = {"free", "money", "click", "offer"};
    int i, j;
    for (i = 0; i < strlen(message->text); i++) {
        for (j = 0; j < sizeof(spamWords) / sizeof(char *); j++) {
            if (strstr(&message->text[i], spamWords[j]) != NULL) {
                return 1;
            }
        }
    }
    return 0;
}

void filterSpam(MessageList *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (containsSpam(list->messages[i])) {
            printf("Message %d is spam: %s\n", i + 1, list->messages[i]->text);
        }
    }
}

void freeMessageList(MessageList *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        free(list->messages[i]->text);
        free(list->messages[i]);
    }
    free(list->messages);
    free(list);
}

int main() {
    MessageList *list = createMessageList();
    addMessage(list, "This is a normal message.");
    addMessage(list, "This is a spam message: free money!");
    addMessage(list, "This is another normal message.");
    addMessage(list, "This is another spam message: click here for a great offer!");
    filterSpam(list);
    freeMessageList(list);
    return 0;
}