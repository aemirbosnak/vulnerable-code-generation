//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber* data;
    int capacity;
    int size;
} List;

void create_list(List* list, int initial_size){
    list->data = (Subscriber*) malloc(sizeof(Subscriber) * initial_size);
    list->capacity = initial_size;
    list->size = 0;
}

void add_subscriber(List* list, Subscriber subscriber){
    if(list->size == list->capacity){
        list->data = (Subscriber*) realloc(list->data, sizeof(Subscriber) * list->capacity * 2);
        list->capacity *= 2;
    }
    strcpy(list->data[list->size].name, subscriber.name);
    strcpy(list->data[list->size].email, subscriber.email);
    list->size++;
}

int remove_subscriber(List* list, char* email){
    int removed = 0;
    for(int i=0; i<list->size; i++){
        if(strcmp(list->data[i].email, email) == 0){
            for(int j=i+1; j<list->size; j++){
                strcpy(list->data[j-1].name, list->data[j].name);
                strcpy(list->data[j-1].email, list->data[j].email);
            }
            list->size--;
            removed = 1;
            break;
        }
    }
    return removed;
}

void print_subscribers(List* list){
    printf("List of subscribers:\n");
    for(int i=0; i<list->size; i++){
        printf("Name: %s, Email: %s\n", list->data[i].name, list->data[i].email);
    }
    printf("\n");
}

int main(){
    List mailing_list;
    create_list(&mailing_list, 10);

    Subscriber alice = {"Alice", "alice@gmail.com"};
    Subscriber bob = {"Bob", "bob@hotmail.com"};
    Subscriber charlie = {"Charlie", "charlie@yahoo.com"};

    add_subscriber(&mailing_list, alice);
    add_subscriber(&mailing_list, bob);
    add_subscriber(&mailing_list, charlie);

    print_subscribers(&mailing_list);

    char email[MAX_EMAIL_LENGTH] = "bob@hotmail.com";
    int removed = remove_subscriber(&mailing_list, email);

    if(removed){
        printf("Subscriber with email %s was removed.\n", email);
    } else {
        printf("Subscriber with email %s was not found.\n", email);
    }

    print_subscribers(&mailing_list);

    return 0;
}