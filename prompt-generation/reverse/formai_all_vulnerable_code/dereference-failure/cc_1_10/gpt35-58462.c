//FormAI DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char name[50];
    char artist[50];
    int year;
};

struct Node {
    struct Album data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(struct Album album) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = album;
    new_node->next = head;
    head = new_node;
}

void display() {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("Name: %s\n", ptr->data.name);
        printf("Artist: %s\n", ptr->data.artist);
        printf("Year: %d\n", ptr->data.year);
        ptr = ptr->next;
    }
}

void search(char name[]) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->data.name, name) == 0) {
            printf("Album found:\n");
            printf("Name: %s\n", ptr->data.name);
            printf("Artist: %s\n", ptr->data.artist);
            printf("Year: %d\n", ptr->data.year);
            return;
        }
        ptr = ptr->next;
    }
    printf("Album %s not found.\n", name);
}

void delete(char name[]) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->data.name, name) == 0) {
            if (prev == NULL) {
                head = curr->next;
                free(curr);
            } else {
                prev->next = curr->next;
                free(curr);
            }
            printf("Album %s deleted.\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Album %s not found.\n", name);
}

int main() {
    while (1) {
        int choice;
        struct Album album;
        printf("Enter your choice (1-4):\n");
        printf("1. Add an album\n");
        printf("2. Display all albums\n");
        printf("3. Search for an album\n");
        printf("4. Delete an album\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name of album: ");
                scanf("%s", album.name);
                printf("Enter name of artist: ");
                scanf("%s", album.artist);
                printf("Enter year of release: ");
                scanf("%d", &album.year);
                insert(album);
                printf("\nAlbum added successfully!\n\n");
                break;
            case 2:
                printf("\nAlbums:\n\n");
                display();
                printf("\n");
                break;
            case 3:
                printf("Enter name of album to search: ");
                char search_name[50];
                scanf("%s", search_name);
                search(search_name);
                printf("\n");
                break;
            case 4:
                printf("Enter name of album to delete: ");
                char delete_name[50];
                scanf("%s", delete_name);
                delete(delete_name);
                printf("\n");
                break;
            default:
                printf("Invalid choice!\n");
                exit(0);
        }
    }
    return 0;
}