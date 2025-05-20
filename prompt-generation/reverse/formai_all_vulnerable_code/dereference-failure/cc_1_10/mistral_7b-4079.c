//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000

typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber *next;
} Subscriber;

typedef struct MailingList {
    Subscriber *subscribers[26];
    int num_subscribers;
    char list_name[50];
    struct MailingList *next;
} MailingList;

void add_subscriber(MailingList *list, Subscriber *new_subscriber) {
    int first_letter = (int)new_subscriber->email[0] - 65;
    Subscriber *current = list->subscribers[first_letter];

    if (!current) {
        list->subscribers[first_letter] = new_subscriber;
    } else {
        while (current->next) {
            current = current->next;
        }
        current->next = new_subscriber;
    }

    list->num_subscribers++;
}

void remove_subscriber(MailingList *list, char *email) {
    int first_letter = (int)email[0] - 65;
    Subscriber *current = list->subscribers[first_letter];
    Subscriber *previous = NULL;

    while (current && strcmp(current->email, email)) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        printf("Error: Subscriber not found.\n");
        return;
    }

    if (previous) {
        previous->next = current->next;
    } else {
        list->subscribers[first_letter] = current->next;
    }

    list->num_subscribers--;
    free(current);
}

void print_mailing_list(MailingList *list) {
    printf("Mailing List: %s\n", list->list_name);
    printf("Number of Subscribers: %d\n", list->num_subscribers);
    int first_letter;
    Subscriber *subscriber;

    for (int i = 0; i < 26; i++) {
        first_letter = i + 65;
        printf("%c: ", first_letter);

        subscriber = list->subscribers[i];
        while (subscriber) {
            printf("%s, %s\n", subscriber->name, subscriber->email);
            subscriber = subscriber->next;
        }
    }
}

int main() {
    MailingList *music_list = malloc(sizeof(MailingList));
    strcpy(music_list->list_name, "Music Lovers");

    Subscriber john_doe = {"John Doe", "john.doe@example.com"};
    Subscriber jane_doe = {"Jane Doe", "jane.doe@example.com"};
    Subscriber bob_smith = {"Bob Smith", "bob.smith@example.com"};

    add_subscriber(music_list, &john_doe);
    add_subscriber(music_list, &jane_doe);
    add_subscriber(music_list, &bob_smith);

    print_mailing_list(music_list);

    remove_subscriber(music_list, "jane.doe@example.com");
    print_mailing_list(music_list);

    free(music_list);

    return 0;
}