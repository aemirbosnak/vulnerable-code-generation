//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    bool subscribed;
} ListSubscriber;

typedef struct {
    char name[50];
    ListSubscriber** subscribers;
    int num_subscribers;
    int capacity;
} MailingList;

void initList(MailingList* list, char* name, int capacity) {
    strcpy(list->name, name);
    list->subscribers = malloc(capacity * sizeof(ListSubscriber*));
    list->num_subscribers = 0;
    list->capacity = capacity;
}

bool addSubscriber(MailingList* list, char* name) {
    if (list->num_subscribers == list->capacity) {
        list->capacity *= 2;
        list->subscribers = realloc(list->subscribers, list->capacity * sizeof(ListSubscriber*));
    }

    ListSubscriber newSubscriber = {0};
    strcpy(newSubscriber.name, name);

    list->subscribers[list->num_subscribers++] = &newSubscriber;
    return true;
}

void removeSubscriber(MailingList* list, char* name) {
    for (int i = 0; i < list->num_subscribers; ++i) {
        if (strcmp(list->subscribers[i]->name, name) == 0) {
            ListSubscriber* subscriberToRemove = list->subscribers[i];
            for (int j = i; j < list->num_subscribers - 1; ++j) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->num_subscribers--;
            free(subscriberToRemove);
            break;
        }
    }
}

void displaySubscribers(const MailingList* list) {
    printf("%s subscribers:\n", list->name);
    for (int i = 0; i < list->num_subscribers; ++i) {
        const ListSubscriber* subscriber = list->subscribers[i];
        printf("%s: %s\n", subscriber->name, subscriber->subscribed ? "Subscribed" : "Unsubscribed");
    }
}

int main() {
    MailingList techList = {0};
    initList(&techList, "Tech News", 5);

    addSubscriber(&techList, "John Doe");
    addSubscriber(&techList, "Jane Smith");
    addSubscriber(&techList, "Bob Johnson");
    addSubscriber(&techList, "Alice Brown");

    displaySubscribers(&techList);

    removeSubscriber(&techList, "Bob Johnson");

    printf("\nAfter removal of Bob Johnson:\n");
    displaySubscribers(&techList);

    return 0;
}