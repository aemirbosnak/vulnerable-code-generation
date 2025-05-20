//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    struct node *next;
} node;

node *add_song(node *head, char *title, char *artist, char *album, int year) {
    if (head == NULL) {
        head = malloc(sizeof(node));
        strcpy(head->title, title);
        strcpy(head->artist, artist);
        strcpy(head->album, album);
        head->year = year;
        head->next = NULL;
    } else {
        head->next = add_song(head->next, title, artist, album, year);
    }
    return head;
}

void print_songs(node *head) {
    if (head != NULL) {
        printf("%s - %s (%s, %d)\n", head->title, head->artist, head->album, head->year);
        print_songs(head->next);
    }
}

node *find_song(node *head, char *title) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->title, title) == 0) {
        return head;
    } else {
        return find_song(head->next, title);
    }
}

node *delete_song(node *head, char *title) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->title, title) == 0) {
        node *temp = head->next;
        free(head);
        return temp;
    } else {
        head->next = delete_song(head->next, title);
        return head;
    }
}

int main() {
    node *head = NULL;

    head = add_song(head, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    head = add_song(head, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    head = add_song(head, "Hotel California", "Eagles", "Hotel California", 1976);
    head = add_song(head, "Imagine", "John Lennon", "Imagine", 1971);
    head = add_song(head, "Hey Jude", "The Beatles", "Hey Jude", 1968);

    print_songs(head);

    node *song = find_song(head, "Stairway to Heaven");
    if (song != NULL) {
        printf("Found song: %s - %s (%s, %d)\n", song->title, song->artist, song->album, song->year);
    } else {
        printf("Song not found.\n");
    }

    head = delete_song(head, "Hotel California");

    print_songs(head);

    return 0;
}