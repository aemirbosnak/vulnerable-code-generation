//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

struct contact {
    char name[50];
    char phone[15];
};

struct contact *contact_list = NULL;
int contact_count = 0;
pthread_mutex_t contact_list_mutex = PTHREAD_MUTEX_INITIALIZER;

void add_contact(struct contact *new_contact) {
    pthread_mutex_lock(&contact_list_mutex);
    contact_list = realloc(contact_list, sizeof(struct contact) * ++contact_count);
    memcpy(&contact_list[contact_count - 1], new_contact, sizeof(struct contact));
    pthread_mutex_unlock(&contact_list_mutex);
}

void search_contact(const char *name) {
    pthread_mutex_lock(&contact_list_mutex);
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contact_list[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", contact_list[i].name, contact_list[i].phone);
        }
    }
    pthread_mutex_unlock(&contact_list_mutex);
}

void print_contact_list() {
    pthread_mutex_lock(&contact_list_mutex);
    for (int i = 0; i < contact_count; i++) {
        printf("Contact %d: %s - %s\n", i + 1, contact_list[i].name, contact_list[i].phone);
    }
    pthread_mutex_unlock(&contact_list_mutex);
}

void *thread_add_contact(void *arg) {
    struct contact new_contact;
    strcpy(new_contact.name, "John Doe");
    strcpy(new_contact.phone, "123-456-7890");
    add_contact(&new_contact);
    return NULL;
}

void *thread_search_contact(void *arg) {
    search_contact("John Doe");
    return NULL;
}

int main() {
    pthread_t thread_id_add_contact, thread_id_search_contact;

    pthread_create(&thread_id_add_contact, NULL, thread_add_contact, NULL);
    pthread_create(&thread_id_search_contact, NULL, thread_search_contact, NULL);

    pthread_join(thread_id_add_contact, NULL);
    pthread_join(thread_id_search_contact, NULL);

    print_contact_list();

    return 0;
}