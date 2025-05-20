//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

#define MAX_MAILS 100
#define MAX_RECIPIENTS 10

typedef struct {
    char *sender;
    char *subject;
    char *body;
} Email;

typedef struct {
    Email emails[MAX_MAILS];
    int num_emails;
    sem_t sem;
    pthread_mutex_t mutex;
} MailList;

MailList *mail_list;

void *email_sender(void *arg) {
    char *sender = (char *)arg;

    while (true) {
        // Simulate sending an email
        Email email;
        email.sender = sender;
        email.subject = "Important update";
        email.body = "This is an important update for all recipients.";

        // Acquire the semaphore to access the mail list
        sem_wait(&mail_list->sem);

        // Lock the mutex to protect the mail list
        pthread_mutex_lock(&mail_list->mutex);

        // Add the email to the mail list
        mail_list->emails[mail_list->num_emails++] = email;

        // Unlock the mutex
        pthread_mutex_unlock(&mail_list->mutex);

        // Release the semaphore
        sem_post(&mail_list->sem);
    }

    return NULL;
}

void *email_receiver(void *arg) {
    char *recipient = (char *)arg;

    while (true) {
        // Acquire the semaphore to access the mail list
        sem_wait(&mail_list->sem);

        // Lock the mutex to protect the mail list
        pthread_mutex_lock(&mail_list->mutex);

        // Check if there are any emails for the recipient
        for (int i = 0; i < mail_list->num_emails; i++) {
            Email email = mail_list->emails[i];

            // If the email is for the recipient, print it
            if (strcmp(email.sender, recipient) == 0) {
                printf("From: %s\n", email.sender);
                printf("Subject: %s\n", email.subject);
                printf("Body: %s\n\n", email.body);
            }
        }

        // Unlock the mutex
        pthread_mutex_unlock(&mail_list->mutex);

        // Release the semaphore
        sem_post(&mail_list->sem);
    }

    return NULL;
}

int main() {
    // Create the mail list
    mail_list = malloc(sizeof(MailList));
    mail_list->num_emails = 0;
    sem_init(&mail_list->sem, 0, 1);
    pthread_mutex_init(&mail_list->mutex, NULL);

    // Create the email sender threads
    pthread_t sender_threads[MAX_RECIPIENTS];
    for (int i = 0; i < MAX_RECIPIENTS; i++) {
        char *sender = malloc(10);
        sprintf(sender, "sender%d", i);
        pthread_create(&sender_threads[i], NULL, email_sender, sender);
    }

    // Create the email receiver threads
    pthread_t receiver_threads[MAX_RECIPIENTS];
    for (int i = 0; i < MAX_RECIPIENTS; i++) {
        char *recipient = malloc(10);
        sprintf(recipient, "recipient%d", i);
        pthread_create(&receiver_threads[i], NULL, email_receiver, recipient);
    }

    // Join the threads
    for (int i = 0; i < MAX_RECIPIENTS; i++) {
        pthread_join(sender_threads[i], NULL);
        pthread_join(receiver_threads[i], NULL);
    }

    // Destroy the mail list
    free(mail_list);

    return 0;
}