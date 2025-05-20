//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Message {
    char text[100];
    struct Message* next;
} Message;

Message* createMessage(const char* text) {
    Message* newMessage = (Message*)malloc(sizeof(Message));
    strncpy(newMessage->text, text, sizeof(newMessage->text) - 1);
    newMessage->text[sizeof(newMessage->text) - 1] = '\0'; // Ensure null-termination
    newMessage->next = NULL;
    return newMessage;
}

void appendMessage(Message** head_ref, const char* new_text) {
    Message* newMessage = createMessage(new_text);
    if (*head_ref == NULL) {
        *head_ref = newMessage;
        return;
    }
    Message* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newMessage;
}

void displayMessages(Message* node) {
    while (node != NULL) {
        printf("💕 %s 💕\n", node->text);
        node = node->next;
    }
}

void freeMessages(Message* node) {
    Message* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    Message* loveLetter = NULL;

    printf("A Love Story in Messages:\n\n");

    appendMessage(&loveLetter, "My dearest, every moment without you feels like an eternity.");
    appendMessage(&loveLetter, "Your smile shines brighter than the sun.");
    appendMessage(&loveLetter, "In your arms, I find my haven.");
    appendMessage(&loveLetter, "Every heartbeat calls out your name, my love!");
    appendMessage(&loveLetter, "Together, we can conquer the world.");
    appendMessage(&loveLetter, "You are the melody to my heart's song.");

    printf("Reading the messages...\n\n");
    displayMessages(loveLetter);

    freeMessages(loveLetter);
    printf("\nThe love story is eternal, but I must let these messages go...\n");

    return 0;
}