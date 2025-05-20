//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10 // Maximum number of threads that will be created
#define MAX_MAILS 50 // Maximum number of mails that can be stored in the list

// Structure representing a mail
typedef struct {
    char* recipient;
    char* message;
} Mail;

// Structure representing a mailing list
typedef struct {
    int count; // Current number of mails in the list
    Mail* mails[MAX_MAILS]; // Array of pointers to Mail structs
    pthread_mutex_t lock; // Mutex to protect the list from concurrent access
} MailingList;

// Function to add a mail to the mailing list
void add_mail(MailingList* list, Mail* mail) {
    pthread_mutex_lock(&list->lock); // Acquire lock to prevent concurrent access
    if (list->count < MAX_MAILS) {
        list->mails[list->count++] = mail;
        printf("Mail added to list\n");
    } else {
        printf("Mailing list is full\n");
    }
    pthread_mutex_unlock(&list->lock); // Release lock
}

// Function to remove a mail from the mailing list
void remove_mail(MailingList* list, int index) {
    pthread_mutex_lock(&list->lock); // Acquire lock to prevent concurrent access
    if (index >= 0 && index < list->count) {
        free(list->mails[index]); // Free memory allocated for the mail
        for (int i = index + 1; i < list->count; i++) {
            list->mails[i - 1] = list->mails[i]; // Shift all elements one position to the left
        }
        list->count--;
        printf("Mail removed from list\n");
    } else {
        printf("Invalid index\n");
    }
    pthread_mutex_unlock(&list->lock); // Release lock
}

// Function to print all mails in the mailing list
void print_mails(MailingList* list) {
    pthread_mutex_lock(&list->lock); // Acquire lock to prevent concurrent access
    printf("Mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Recipient: %s\n", list->mails[i]->recipient);
        printf("Message: %s\n", list->mails[i]->message);
    }
    pthread_mutex_unlock(&list->lock); // Release lock
}

// Function executed by each thread
void* thread_func(void* arg) {
    MailingList* list = (MailingList*) arg;
    for (int i = 0; i < 3; i++) {
        Mail* mail = (Mail*) malloc(sizeof(Mail)); // Allocate memory for a new mail
        mail->recipient = "Example Recipient";
        mail->message = "Example Message";
        add_mail(list, mail); // Add the new mail to the mailing list
    }
    for (int i = 0; i < 2; i++) {
        remove_mail(list, 0); // Remove the first mail from the mailing list
    }
    print_mails(list); // Print all mails in the mailing list
    return NULL;
}

int main() {
    MailingList list = { 0, {}, PTHREAD_MUTEX_INITIALIZER };
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    while (num_threads < MAX_THREADS) {
        if (pthread_create(&threads[num_threads], NULL, thread_func, &list) != 0) {
            fprintf(stderr, "Error creating thread\n");
            break;
        }
        num_threads++;
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }
    return 0;
}