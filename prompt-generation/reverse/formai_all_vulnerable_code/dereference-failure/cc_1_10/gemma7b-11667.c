//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct ResumeEntry {
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    struct ResumeEntry* next;
} ResumeEntry;

int main() {
    ResumeEntry* head = NULL;
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter address: ");
    scanf("%s", address);

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter email address: ");
    scanf("%s", email);

    ResumeEntry* newEntry = malloc(sizeof(ResumeEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->address, address);
    strcpy(newEntry->phone, phone);
    strcpy(newEntry->email, email);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }

    printf("Data stored:\n");
    printf("Name: %s\n", head->name);
    printf("Address: %s\n", head->address);
    printf("Phone number: %s\n", head->phone);
    printf("Email address: %s\n", head->email);

    return 0;
}