//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook {
    char name[50];
    char phone[15];
    struct PhoneBook *next;
};

struct PhoneBook *head = NULL;

void insert(char name[], char phone[]) {
    struct PhoneBook *temp = (struct PhoneBook*)malloc(sizeof(struct PhoneBook));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(temp->name, name);
    strcpy(temp->phone, phone);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct PhoneBook *ptr = head;
        while (ptr->next!= NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void search(char name[]) {
    struct PhoneBook *ptr = head;
    while (ptr!= NULL) {
        if (strcmp(ptr->name, name) == 0) {
            printf("Name: %s, Phone: %s\n", ptr->name, ptr->phone);
            return;
        }
        ptr = ptr->next;
    }
    printf("Name not found\n");
}

void print_all() {
    struct PhoneBook *ptr = head;
    while (ptr!= NULL) {
        printf("Name: %s, Phone: %s\n", ptr->name, ptr->phone);
        ptr = ptr->next;
    }
}

int main() {
    insert("John Doe", "1234567890");
    insert("Jane Doe", "0987654321");
    insert("Joe Doe", "987654321");
    search("Jane Doe");
    print_all();
    return 0;
}