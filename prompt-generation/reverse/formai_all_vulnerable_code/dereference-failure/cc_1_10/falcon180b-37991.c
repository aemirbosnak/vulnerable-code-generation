//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME 100
#define MAX_EMAIL 100
#define MAX_SUBJECT 100
#define MAX_MESSAGE 1000

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
    time_t timestamp;
} message_t;

typedef struct {
    int size;
    int capacity;
    message_t* messages;
} mailing_list_t;

void init_mailing_list(mailing_list_t* list) {
    list->size = 0;
    list->capacity = 10;
    list->messages = (message_t*) malloc(list->capacity * sizeof(message_t));
}

void add_message(mailing_list_t* list, char* name, char* email, char* subject, char* message) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->messages = (message_t*) realloc(list->messages, list->capacity * sizeof(message_t));
    }

    strcpy(list->messages[list->size].name, name);
    strcpy(list->messages[list->size].email, email);
    strcpy(list->messages[list->size].subject, subject);
    strcpy(list->messages[list->size].message, message);
    list->messages[list->size].timestamp = time(NULL);

    list->size++;
}

void print_messages(mailing_list_t* list) {
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s\n", list->messages[i].name);
        printf("Email: %s\n", list->messages[i].email);
        printf("Subject: %s\n", list->messages[i].subject);
        printf("Message: %s\n", list->messages[i].message);
        printf("Timestamp: %s\n\n", ctime(&list->messages[i].timestamp));
    }
}

int main() {
    mailing_list_t list;
    init_mailing_list(&list);

    add_message(&list, "John Doe", "johndoe@example.com", "Test message", "Hello, this is a test message!");
    add_message(&list, "Jane Doe", "janedoe@example.com", "Another test message", "Hello again, this is another test message!");

    print_messages(&list);

    return 0;
}