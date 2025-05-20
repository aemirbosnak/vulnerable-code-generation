//FormAI DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} Song;

typedef struct node {
    Song s;
    struct node* next;
} Node;

Node* head = NULL;
int size = 0;

void add_song() {
    printf("Enter song title: ");
    char title[50];
    scanf("%s", title);

    printf("Enter artist name: ");
    char artist[50];
    scanf("%s", artist);

    printf("Enter album name: ");
    char album[50];
    scanf("%s", album);

    printf("Enter year of release: ");
    int year;
    scanf("%d", &year);

    printf("Enter duration in seconds: ");
    int duration;
    scanf("%d", &duration);

    Song s = {title, artist, album, year, duration};
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->s = s;
    new_node->next = head;
    head = new_node;
    size++;
}

void display_library() {
    if (size == 0) {
        printf("Your library is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("Title: %s\n", temp->s.title);
        printf("Artist: %s\n", temp->s.artist);
        printf("Album: %s\n", temp->s.album);
        printf("Year: %d\n", temp->s.year);
        printf("Duration: %d seconds\n", temp->s.duration);
        printf("----------------------------\n");
        temp = temp->next;
    }
}

void search_song() {
    if (size == 0) {
        printf("Your library is empty.\n");
        return;
    }

    printf("Enter search term: ");
    char term[50];
    scanf("%s", term);

    Node* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strstr(temp->s.title, term) || strstr(temp->s.artist, term) || strstr(temp->s.album, term) || temp->s.year == atoi(term) || temp->s.duration == atoi(term)) {
            printf("Title: %s\n", temp->s.title);
            printf("Artist: %s\n", temp->s.artist);
            printf("Album: %s\n", temp->s.album);
            printf("Year: %d\n", temp->s.year);
            printf("Duration: %d seconds\n", temp->s.duration);
            printf("----------------------------\n");
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No results found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("Welcome to your C music library management system!\n");
        printf("1. Add a song to your library\n");
        printf("2. Display your library\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_library();
                break;
            case 3:
                search_song();
                break;
            case 4:
                printf("Thank you for using your C music library management system!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}