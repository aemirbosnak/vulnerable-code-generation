//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct contact{
    char name[MAX];
    int phone_number;
};

void add_contact(struct contact* contacts[], int size, char* name, int phone_number){
    int i;
    for(i=0; i<size; i++){
        if(strcmp(contacts[i]->name, name) == 0){
            printf("Contact already exists!\n");
            return;
        }
    }
    if(size == MAX){
        printf("Phone book is full!\n");
        return;
    }
    contacts[size] = (struct contact*)malloc(sizeof(struct contact));
    strcpy(contacts[size]->name, name);
    contacts[size]->phone_number = phone_number;
    size++;
}

void search_contact(struct contact* contacts[], int size, char* name){
    int i;
    for(i=0; i<size; i++){
        if(strcmp(contacts[i]->name, name) == 0){
            printf("Name: %s\nPhone Number: %d\n", contacts[i]->name, contacts[i]->phone_number);
            return;
        }
    }
    printf("Contact not found!\n");
}

void delete_contact(struct contact* contacts[], int size, char* name){
    int i;
    for(i=0; i<size; i++){
        if(strcmp(contacts[i]->name, name) == 0){
            free(contacts[i]);
            contacts[i] = contacts[--size];
            return;
        }
    }
    printf("Contact not found!\n");
}

void display_contacts(struct contact* contacts[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("Name: %s\nPhone Number: %d\n", contacts[i]->name, contacts[i]->phone_number);
    }
}

int main(){
    struct contact* contacts[MAX];
    int size = 0;

    add_contact(contacts, size, "John", 1234567890);
    add_contact(contacts, size, "Jane", 9876543210);

    display_contacts(contacts, size);

    search_contact(contacts, size, "John");

    delete_contact(contacts, size, "John");

    display_contacts(contacts, size);

    return 0;
}