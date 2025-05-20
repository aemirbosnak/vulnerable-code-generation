//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 100

typedef struct entry{
    char name[50];
    char phone[15];
    struct entry *next;
}Entry;

Entry *head = NULL;

void addEntry(char *name, char *phone){
    Entry *newEntry = (Entry*) malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phone, phone);
    newEntry->next = NULL;

    if(head == NULL){
        head = newEntry;
    }
    else{
        Entry *temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newEntry;
    }
}

void searchEntry(char *name){
    Entry *temp = head;
    while(temp!= NULL){
        if(strcmp(temp->name, name) == 0){
            printf("Name: %s\nPhone: %s\n", temp->name, temp->phone);
        }
        temp = temp->next;
    }
}

void deleteEntry(char *name){
    Entry *temp = head;
    if(strcmp(temp->name, name) == 0){
        head = temp->next;
        free(temp);
        return;
    }

    Entry *prev = NULL;
    temp = temp->next;
    while(temp!= NULL){
        if(strcmp(temp->name, name) == 0){
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printEntries(){
    Entry *temp = head;
    while(temp!= NULL){
        printf("Name: %s\nPhone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

int main(){
    addEntry("John", "1234567890");
    addEntry("Jane", "0987654321");
    addEntry("Bob", "5555555555");

    printEntries();

    searchEntry("John");

    deleteEntry("Bob");

    printEntries();

    return 0;
}