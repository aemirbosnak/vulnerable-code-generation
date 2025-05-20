//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256
#define MAX_EMAIL_LEN 256
#define MAX_LIST_LEN 1024

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts[MAX_LIST_LEN];
    int num_contacts;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_contacts = 0;
    return list;
}

void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_contacts; i++) {
        free(list->contacts[i]);
    }
    free(list);
}

int add_contact(mailing_list *list, char *name, char *email) {
    if (list->num_contacts >= MAX_LIST_LEN) {
        return -1;
    }
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts[list->num_contacts++] = new_contact;
    return 0;
}

int remove_contact(mailing_list *list, char *name) {
    for (int i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i]->name, name) == 0) {
            free(list->contacts[i]);
            list->num_contacts--;
            for (int j = i; j < list->num_contacts; j++) {
                list->contacts[j] = list->contacts[j+1];
            }
            return 0;
        }
    }
    return -1;
}

void print_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("%s (%s)\n", list->contacts[i]->name, list->contacts[i]->email);
    }
}

int main() {
    mailing_list *list = create_mailing_list();
    add_contact(list, "Alan Turing", "turing@comp.cam.ac.uk");
    add_contact(list, "Ada Lovelace", "ada@comp.ox.ac.uk");
    add_contact(list, "Grace Hopper", "hopper@comp.yale.edu");
    print_mailing_list(list);
    return 0;
}