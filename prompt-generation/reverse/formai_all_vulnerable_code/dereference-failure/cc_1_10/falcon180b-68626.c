//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} contact;

typedef struct {
    int size;
    contact* contacts;
} mailing_list;

void init_list(mailing_list* list) {
    list->size = 0;
    list->contacts = (contact*)malloc(MAX_LIST_SIZE * sizeof(contact));
}

void add_contact(mailing_list* list, char* name, char* email) {
    contact new_contact = {strcpy(name, ""), strcpy(email, "")};
    list->contacts[list->size++] = new_contact;
}

void remove_contact(mailing_list* list, char* email) {
    int i;
    for(i=0; i<list->size; i++) {
        if(strcmp(list->contacts[i].email, email) == 0) {
            list->size--;
            while(i<list->size) {
                list->contacts[i] = list->contacts[i+1];
                i++;
            }
        }
    }
}

void print_list(mailing_list* list) {
    int i;
    for(i=0; i<list->size; i++) {
        printf("Name: %s\n", list->contacts[i].name);
        printf("Email: %s\n\n", list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    init_list(&list);
    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Doe", "janedoe@example.com");
    print_list(&list);
    remove_contact(&list, "johndoe@example.com");
    print_list(&list);
    return 0;
}