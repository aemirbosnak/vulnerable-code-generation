//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct MusicData {
    char title[100];
    char artist[50];
    char album[50];
    int year;
} MusicData;

typedef struct HashNode {
    MusicData data;
    struct HashNode *next;
} HashNode;

HashNode *table[TABLE_SIZE] = {0};

int hash_func(char *str) {
    int hash = 0;
    for (int i = 0; str[i]; i++) {
        hash += tolower(str[i]);
    }
    return hash % TABLE_SIZE;
}

void add_song(char *title, char *artist, char *album, int year) {
    int index = hash_func(title);
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));
    strcpy(new_node->data.title, title);
    strcpy(new_node->data.artist, artist);
    strcpy(new_node->data.album, album);
    new_node->data.year = year;
    new_node->next = table[index];
    table[index] = new_node;
}

HashNode *find_song(char *title) {
    int index = hash_func(title);
    HashNode *current = table[index];
    while (current) {
        if (strcmp(current->data.title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_song(HashNode *song) {
    printf("Title: %s\n", song->data.title);
    printf("Artist: %s\n", song->data.artist);
    printf("Album: %s\n", song->data.album);
    printf("Year: %d\n", song->data.year);
}

int main() {
    add_song("Moonlight Sonata", "Beethoven", "Written in 1801", 1802);
    add_song("Clair de Lune", "Debussy", "Printemps", 1892);
    add_song("Rhapsody in Blue", "Gershwin", "Rhapsody in Blue", 1924);

    HashNode *song = find_song("Rhapsody in Blue");
    if (song) {
        print_song(song);
    }

    return 0;
}