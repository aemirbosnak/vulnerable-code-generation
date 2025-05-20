//Gemma-7B DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_SESSIONS 10

typedef struct Session {
    char name[20];
    int session_id;
    struct Session* next;
} Session;

Session* create_session(char* name, int id) {
    Session* new_session = malloc(sizeof(Session));
    strcpy(new_session->name, name);
    new_session->session_id = id;
    new_session->next = NULL;
    return new_session;
}

void add_session(Session* head, char* name, int id) {
    Session* new_session = create_session(name, id);
    if (head == NULL) {
        head = new_session;
    } else {
        new_session->next = head;
        head = new_session;
    }
}

void start_session(Session* head) {
    if (head == NULL) {
        return;
    }
    printf("Welcome to session: %s\n", head->name);
    printf("Please enter your command: ");
    char command[20];
    scanf("%s", command);

    switch (command[0]) {
        case 'a':
            printf("Playing audio file...\n");
            break;
        case 'v':
            printf("Adjusting volume...\n");
            break;
        case 'l':
            printf("Launching lights...\n");
            break;
        default:
            printf("Invalid command.\n");
    }
}

int main() {
    Session* head = NULL;

    add_session(head, "Movie Night", 1);
    add_session(head, "Dinner Party", 2);
    add_session(head, "Gaming Night", 3);

    start_session(head);

    return 0;
}