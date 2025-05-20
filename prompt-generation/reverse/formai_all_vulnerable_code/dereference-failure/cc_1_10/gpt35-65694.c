//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
   char title[50];
   char artist[50];
   char album[50];
   int year;
   int duration;
} Song;

typedef struct node {
   Song data;
   struct node *next;
} Node;

Node *head = NULL;

void insertSong() {
   Node *newNode = (Node *)malloc(sizeof(Node));
   printf("Enter song title: ");
   scanf("%s", newNode->data.title);
   printf("Enter song artist: ");
   scanf("%s", newNode->data.artist);
   printf("Enter song album: ");
   scanf("%s", newNode->data.album);
   printf("Enter song release year: ");
   scanf("%d", &newNode->data.year);
   printf("Enter song duration (in seconds): ");
   scanf("%d", &newNode->data.duration);
   newNode->next = head;
   head = newNode;
}

void deleteSong(char title[50]) {
   Node *current = head;
   Node *previous = NULL;
   while (current != NULL) {
      if (strcmp(current->data.title, title) == 0) {
         if (previous == NULL) {
            head = current->next;
         }
         else {
            previous->next = current->next;
         }
         free(current);
         printf("Song successfully deleted!\n");
         return;
      }
      previous = current;
      current = current->next;
   }
   printf("Song not found.\n");
}

void displaySongs() {
   Node *current = head;
   printf("\n");
   printf("Title | Artist | Album | Year Released | Duration (seconds)\n");
   while (current != NULL) {
      printf("%s | %s | %s | %d | %d\n", current->data.title, current->data.artist, 
             current->data.album, current->data.year, current->data.duration);
      current = current->next;
   }
   printf("\n");
}

int main() {
   int choice;
   char title[50];
   while (1) {
      printf("Enter choice:\n");
      printf("1. Add a new song\n");
      printf("2. Delete an existing song\n");
      printf("3. Display all songs\n");
      printf("4. Exit\n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            insertSong();
            break;
         case 2:
            printf("Enter the title of the song to be deleted: ");
            scanf("%s", title);
            deleteSong(title);
            break;
         case 3:
            displaySongs();
            break;
         case 4:
            return 0;
         default:
            printf("Invalid choice. Try again.\n");
            break;
      }
   }
}