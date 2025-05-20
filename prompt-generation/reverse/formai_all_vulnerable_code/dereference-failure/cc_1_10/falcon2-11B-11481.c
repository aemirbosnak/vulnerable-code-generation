//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a music piece
struct music_piece {
    char title[100];
    char composer[100];
    char genre[50];
};

// Define the structure for a musician
struct musician {
    char name[100];
    char instrument[50];
};

// Define the structure for a linked list node
struct node {
    struct music_piece *music_piece;
    struct musician *musician;
    struct node *next;
};

// Function to create a new music piece
struct music_piece *create_music_piece(const char *title, const char *composer, const char *genre) {
    struct music_piece *music_piece = (struct music_piece *) malloc(sizeof(struct music_piece));
    strcpy(music_piece->title, title);
    strcpy(music_piece->composer, composer);
    strcpy(music_piece->genre, genre);
    return music_piece;
}

// Function to create a new musician
struct musician *create_musician(const char *name, const char *instrument) {
    struct musician *musician = (struct musician *) malloc(sizeof(struct musician));
    strcpy(musician->name, name);
    strcpy(musician->instrument, instrument);
    return musician;
}

// Function to add a new music piece to the library
void add_music_piece(struct node **head, struct music_piece *music_piece) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->music_piece = music_piece;
    new_node->musician = NULL;
    new_node->next = *head;
    *head = new_node;
}

// Function to add a new musician to the library
void add_musician(struct node **head, struct musician *musician) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->music_piece = NULL;
    new_node->musician = musician;
    new_node->next = *head;
    *head = new_node;
}

// Function to remove a music piece from the library
void remove_music_piece(struct node **head, struct music_piece *music_piece) {
    struct node *current = *head;
    struct node *previous = NULL;

    while (current!= NULL && strcmp(current->music_piece->title, music_piece->title)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current!= NULL) {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current->music_piece);
        free(current);
    }
}

// Function to remove a musician from the library
void remove_musician(struct node **head, struct musician *musician) {
    struct node *current = *head;
    struct node *previous = NULL;

    while (current!= NULL && strcmp(current->musician->name, musician->name)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current!= NULL) {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current->musician);
        free(current);
    }
}

// Function to search for a music piece in the library
struct music_piece *search_music_piece(struct node *head, const char *title) {
    struct music_piece *music_piece = NULL;
    struct node *current = head;

    while (current!= NULL) {
        if (strcmp(current->music_piece->title, title) == 0) {
            music_piece = current->music_piece;
            break;
        }
        current = current->next;
    }

    return music_piece;
}

// Function to search for a musician in the library
struct musician *search_musician(struct node *head, const char *name) {
    struct musician *musician = NULL;
    struct node *current = head;

    while (current!= NULL) {
        if (strcmp(current->musician->name, name) == 0) {
            musician = current->musician;
            break;
        }
        current = current->next;
    }

    return musician;
}

int main() {
    struct node *head = NULL;

    struct music_piece *music_piece1 = create_music_piece("The Four Seasons", "Vivaldi", "Classical");
    struct music_piece *music_piece2 = create_music_piece("The Nutcracker", "Tchaikovsky", "Classical");
    struct music_piece *music_piece3 = create_music_piece("Symphony No. 9", "Beethoven", "Classical");

    struct musician *musician1 = create_musician("Bach", "Cello");
    struct musician *musician2 = create_musician("Mozart", "Piano");
    struct musician *musician3 = create_musician("Haydn", "Violin");

    add_music_piece(&head, music_piece1);
    add_music_piece(&head, music_piece2);
    add_music_piece(&head, music_piece3);
    add_musician(&head, musician1);
    add_musician(&head, musician2);
    add_musician(&head, musician3);

    printf("Search for music piece \"The Four Seasons\":\n");
    printf("Title: %s\n", search_music_piece(head, "The Four Seasons")->title);

    printf("Search for musician \"Bach\":\n");
    printf("Name: %s\n", search_musician(head, "Bach")->name);

    remove_music_piece(&head, music_piece1);
    remove_musician(&head, musician2);

    printf("Search for music piece \"The Four Seasons\":\n");
    printf("Title: %s\n", search_music_piece(head, "The Four Seasons")->title);

    printf("Search for musician \"Bach\":\n");
    printf("Name: %s\n", search_musician(head, "Bach")->name);

    return 0;
}