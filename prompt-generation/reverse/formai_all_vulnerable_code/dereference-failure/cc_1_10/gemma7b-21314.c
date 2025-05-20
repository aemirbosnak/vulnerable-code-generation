//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music library information
typedef struct Music_Library {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music_Library* next;
} Music_Library;

// Function to insert a new music into the library
void insert(Music_Library** head, char* title, char* artist, char* genre, int year) {
    Music_Library* new_node = (Music_Library*)malloc(sizeof(Music_Library));
    strcpy(new_node->title, title);
    strcpy(new_node->artist, artist);
    strcpy(new_node->genre, genre);
    new_node->year = year;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        insert((*head)->next, title, artist, genre, year);
    }
}

// Function to search for music in the library
Music_Library* search(Music_Library* head, char* title) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->title, title) == 0) {
        return head;
    } else {
        return search(head->next, title);
    }
}

// Function to delete music from the library
void delete(Music_Library** head, char* title) {
    Music_Library* prev = NULL;
    Music_Library* current = *head;

    if (current == NULL) {
        return;
    } else if (strcmp(current->title, title) == 0) {
        *head = current->next;
        free(current);
    } else {
        delete(&prev, title);
    }
}

int main() {
    Music_Library* head = NULL;

    // Insert some music into the library
    insert(&head, "The Darkest Hour", "The Who", "Rock", 1965);
    insert(&head, "Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    insert(&head, "Another One Bites the Dust", "Queen", "Rock", 1975);

    // Search for music in the library
    Music_Library* result = search(head, "Stairway to Heaven");
    if (result) {
        printf("Title: %s\n", result->title);
        printf("Artist: %s\n", result->artist);
        printf("Genre: %s\n", result->genre);
        printf("Year: %d\n", result->year);
    } else {
        printf("Music not found.\n");
    }

    // Delete music from the library
    delete(&head, "Another One Bites the Dust");

    // Search for music after deletion
    result = search(head, "Another One Bites the Dust");
    if (result) {
        printf("Title: %s\n", result->title);
        printf("Artist: %s\n", result->artist);
        printf("Genre: %s\n", result->genre);
        printf("Year: %d\n", result->year);
    } else {
        printf("Music not found.\n");
    }

    return 0;
}