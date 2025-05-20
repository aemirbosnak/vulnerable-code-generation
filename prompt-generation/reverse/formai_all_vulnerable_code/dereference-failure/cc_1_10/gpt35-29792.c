//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct phonebook_entry{
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    struct phonebook_entry *next;
}phonebook_entry;

phonebook_entry *head=NULL;

void insert_entry(char *name, char *number){
    phonebook_entry *new_entry = malloc(sizeof(phonebook_entry));
    memcpy(new_entry->name, name, MAX_NAME_LEN);
    memcpy(new_entry->number, number, MAX_NUM_LEN);
    new_entry->next = NULL;

    if(head == NULL){
        head = new_entry;
    }
    else{
        phonebook_entry *cur = head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new_entry;
    }
}

void search_entry(char *name){
    phonebook_entry *cur = head;

    while(cur != NULL){
        if(strcmp(cur->name, name) == 0){
            printf("Name: %s\tNumber: %s\n", cur->name, cur->number);
            return;
        }
        cur = cur->next;
    }
    printf("No entry found for %s.\n", name);
}

void delete_entry(char *name){
    phonebook_entry *cur = head;
    phonebook_entry *prev = NULL;

    while(cur != NULL){
        if(strcmp(cur->name, name) == 0){
            if(prev == NULL){
                head = cur->next;
            }
            else{
                prev->next = cur->next;
            }
            free(cur);
            printf("Entry deleted successfully.\n");
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("No entry found for %s.\n", name);
}

void print_phonebook(){
    phonebook_entry *cur = head;

    while(cur != NULL){
        printf("Name: %s\tNumber: %s\n", cur->name, cur->number);
        cur = cur->next;
    }
}

int main(){
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    int choice;

    while(1){
        printf("Phonebook menu:\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Print phonebook\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter number: ");
                fgets(number, MAX_NUM_LEN, stdin);
                number[strcspn(number, "\n")] = 0;
                insert_entry(name, number);
                printf("Entry added successfully.\n");
                break;
            case 2:
                printf("Enter name to search: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                search_entry(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                delete_entry(name);
                break;
            case 4:
                print_phonebook();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}