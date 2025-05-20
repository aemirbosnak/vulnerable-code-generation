//FormAI DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for each music file
typedef struct Music {
    char title[50];
    char artist[50];
    char album[50];
    int duration;
} Music;

// Struct for each node in the linked list
typedef struct Node {
    Music music;
    struct Node* next;
} Node;

// Function to print all music files in the library
void print_library(Node* head) {
    printf("\n======== MUSIC LIBRARY ========\n");
    Node* current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->music.title);
        printf("Artist: %s\n", current->music.artist);
        printf("Album: %s\n", current->music.album);
        printf("Duration (seconds): %d\n", current->music.duration);
        printf("==============================\n");
        current = current->next;
    }
}

// Function to insert a new music file into the library
Node* insert_music(Node* head, Music music) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->music = music;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

int main() {
    Node* library = NULL;
    int choice = 0;

    while (choice != 3) {
        printf("\n======== MUSIC LIBRARY ========\n");
        printf("1. Add a new music file\n");
        printf("2. View music library\n");
        printf("3. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Music new_music;
                printf("\nEnter Music Title: ");
                scanf("%s", new_music.title);
                printf("Enter Artist Name: ");
                scanf("%s", new_music.artist);
                printf("Enter Album Name: ");
                scanf("%s", new_music.album);
                printf("Enter Duration (in seconds): ");
                scanf("%d", &new_music.duration);

                library = insert_music(library, new_music);
                printf("Music file successfully added to library!\n");
                break;
            }
            case 2: {
                print_library(library);
                break;
            }
            case 3: {
                printf("\nGoodbye!\n");
                break;
            }
            default: {
                printf("\nInvalid choice! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}