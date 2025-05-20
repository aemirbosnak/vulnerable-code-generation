//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_SUBSCRIBERS 100

typedef struct subscriber subscriber_t; //forward declaration of struct subscriber

//subscriber node for linked list
struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    subscriber_t* next;
};

subscriber_t* subscribers = NULL;  //head of the subscriber linked list
pthread_mutex_t list_mutex;       //mutex for synchronizing access to the linked list

// adds a new subscriber to the mailing list
void subscribe(char* name, char* email) {
    subscriber_t* new_subscriber = (subscriber_t*)malloc(sizeof(subscriber_t));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;
    pthread_mutex_lock(&list_mutex);
    if (subscribers == NULL) {
        subscribers = new_subscriber;
    }
    else {
        subscriber_t* current = subscribers;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_subscriber;
    }
    pthread_mutex_unlock(&list_mutex);
    printf("%s <%s> has subscribed to the mailing list.\n", name, email);
}

// removes a subscriber from the mailing list
void unsubscribe(char* email) {
    pthread_mutex_lock(&list_mutex);
    subscriber_t* current = subscribers;
    subscriber_t* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                subscribers = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            printf("%s has been unsubscribed from the mailing list.\n", email);
            pthread_mutex_unlock(&list_mutex);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("%s is not subscribed to the mailing list.\n", email);
    pthread_mutex_unlock(&list_mutex);
}

// prints the list of subscribers
void list_subscribers() {
    pthread_mutex_lock(&list_mutex);
    subscriber_t* current = subscribers;
    printf("Subscribers:\n");
    while (current != NULL) {
        printf("%s <%s>\n", current->name, current->email);
        current = current->next;
    }
    pthread_mutex_unlock(&list_mutex);
}

// sends a message to all the subscribers
void send_message(char* subject, char* message) {
    printf("Sending message with subject '%s' to all subscribers:\n", subject);
    pthread_mutex_lock(&list_mutex);
    subscriber_t* current = subscribers;
    while (current != NULL) {
        printf("To: %s <%s>\n", current->name, current->email);
        printf("%s\n", message);
        current = current->next;
    }
    pthread_mutex_unlock(&list_mutex);
}

// sample usage of mailing list manager
int main() {
    pthread_mutex_init(&list_mutex, NULL);
    subscribe("John Doe", "johndoe@example.com");
    subscribe("Jane Smith", "janesmith@example.com");
    list_subscribers();
    unsubscribe("johndoe@example.com");
    list_subscribers();
    send_message("Important Announcement", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    pthread_mutex_destroy(&list_mutex);
    return 0;
}