//FormAI DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_GENRE_LENGTH 20
#define MAX_SONG_LENGTH 50
#define MAX_YEAR 4

struct song {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char year[MAX_YEAR];
};

struct node {
    struct song data;
    struct node* next;
};

struct node* head = NULL;
int count = 0;

void list_songs() {
    struct node* current = head;
    int i = 1;
    if(current == NULL) {
        printf("List is empty.\n");
        return;
    }
    while(current != NULL) {
        printf("%d. Song: %s\n   Artist: %s\n   Album: %s\n   Genre: %s\n   Year: %s\n", i, current->data.name, current->data.artist, current->data.album, current->data.genre, current->data.year);
        current = current->next;
        i++;
    }
    printf("\n");
}

void add_song() {
    struct song new_song;
    printf("Enter song name: ");
    fgets(new_song.name, MAX_NAME_LENGTH, stdin);
    printf("Enter artist name: ");
    fgets(new_song.artist, MAX_ARTIST_LENGTH, stdin);
    printf("Enter album name: ");
    fgets(new_song.album, MAX_ALBUM_LENGTH, stdin);
    printf("Enter genre: ");
    fgets(new_song.genre, MAX_GENRE_LENGTH, stdin);
    printf("Enter year: ");
    fgets(new_song.year, MAX_YEAR, stdin);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_song;
    new_node->next = head;
    head = new_node;
    count++;
    printf("Song added successfully.\n\n");
}

void remove_song() {
    int index;
    printf("Enter index of song to remove: ");
    scanf("%d", &index);
    while(getchar() != '\n');
    if(index > count || index < 1) {
        printf("Invalid index.\n\n");
        return;
    }
    struct node* current = head;
    int i = 1;
    if(index == 1) {
        head = current->next;
        free(current);
        count--;
        printf("Song removed successfully.\n\n");
        return;
    }
    while(i < index - 1) {
        current = current->next;
        i++;
    }
    struct node* target = current->next;
    current->next = target->next;
    free(target);
    count--;
    printf("Song removed successfully.\n\n");
}

void search_song() {
    char search_str[MAX_SONG_LENGTH];
    printf("Enter name of song to search: ");
    fgets(search_str, MAX_SONG_LENGTH, stdin);
    struct node* current = head;
    int i = 1;
    while(current != NULL) {
        if(strstr(current->data.name, search_str) != NULL) {
            printf("%d. Song: %s\n   Artist: %s\n   Album: %s\n   Genre: %s\n   Year: %s\n", i, current->data.name, current->data.artist, current->data.album, current->data.genre, current->data.year);
        }
        current = current->next;
        i++;
    }
    printf("\n");
}

void sort_songs() {
    struct node* current = head;
    struct node* index = NULL;
    struct song temp;
    if(head == NULL) {
        printf("List is empty.\n\n");
        return;
    }
    while(current != NULL) {
        index = current->next;
        while(index != NULL) {
            if(strcmp(current->data.name, index->data.name) > 0) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    printf("Songs sorted successfully.\n\n");
}

int main() {
    int choice;
    printf("C Music Library Management System\n");
    printf("---------------------------------\n");
    while(1) {
        printf("1. List songs\n2. Add song\n3. Remove song\n4. Search song\n5. Sort songs\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        switch(choice) {
            case 1:
                list_songs();
                break;
            case 2:
                add_song();
                break;
            case 3:
                remove_song();
                break;
            case 4:
                search_song();
                break;
            case 5:
                sort_songs();
                break;
            case 6:
                printf("Thank you for using C Music Library Management System!");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}