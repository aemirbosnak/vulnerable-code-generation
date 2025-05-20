//FormAI DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char title[50];
    char artist[50];
    int year;
};

struct Node {
    struct Album data;
    struct Node* next;
};

struct Node* head = NULL;

void add_album(struct Node* node) {
    if(head == NULL) {
        head = node;
        return;
    }
    if(node->data.year < head->data.year) {
        node->next = head;
        head = node;
        return;
    }
    struct Node* curr = head;
    while(curr->next != NULL && curr->next->data.year <= node->data.year) {
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
}

void delete_album(char* title) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    while(curr != NULL) {
        if(strcmp(curr->data.title, title) == 0) {
            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Album deleted successfully.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Album not found.\n");
}

void display_recursively(struct Node* curr) {
    if(curr == NULL) {
        return;
    }
    printf("Title: %s\n", curr->data.title);
    printf("Artist: %s\n", curr->data.artist);
    printf("Year: %d\n\n", curr->data.year);
    display_recursively(curr->next);
}

int main() {
    int choice;
    char title[50];
    struct Album album;
    struct Node* node;
    while(1) {
        printf("Enter 1 to add an album, 2 to delete an album, 3 to display all albums, or 4 to exit.\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                node = (struct Node*) malloc(sizeof(struct Node));
                printf("Enter album title: ");
                scanf(" %[^\n]%*c", album.title);
                printf("Enter artist name: ");
                scanf(" %[^\n]%*c", album.artist);
                printf("Enter year: ");
                scanf("%d", &album.year);
                node->data = album;
                node->next = NULL;
                add_album(node);
                break;
            case 2:
                printf("Enter album title: ");
                scanf(" %[^\n]%*c", title);
                delete_album(title);
                break;
            case 3:
                display_recursively(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}