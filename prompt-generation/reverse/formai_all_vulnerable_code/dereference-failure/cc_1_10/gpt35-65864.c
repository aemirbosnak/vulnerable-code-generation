//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    char genre[50];
    struct song *next_song;
} Song;

Song *head_song = NULL;

void add_song() {
    printf("Enter song title: ");
    char title[100];
    scanf("%s", title);

    printf("\nEnter artist name: ");
    char artist[100];
    scanf("%s", artist);

    printf("\nEnter album name: ");
    char album[100];
    scanf("%s", album);

    printf("\nEnter year: ");
    int year;
    scanf("%d", &year);

    printf("\nEnter genre: ");
    char genre[50];
    scanf("%s", genre);

    Song *new_song = (Song *)malloc(sizeof(Song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    strcpy(new_song->album, album);
    new_song->year = year;
    strcpy(new_song->genre, genre);
    new_song->next_song = NULL;

    if (head_song == NULL) {
        head_song = new_song;
    } else {
        Song *temp = head_song;
        while (temp->next_song != NULL) {
            temp = temp->next_song;
        }
        temp->next_song = new_song;
    }
}

void display_all_songs() {
    if (head_song == NULL) {
        printf("No songs found!\n");
    } else {
        printf("\n");
        Song *temp = head_song;
        int count = 1;
        while (temp != NULL) {
            printf("Song %d: %s\n", count, temp->title);
            printf("Artist: %s\n", temp->artist);
            printf("Album: %s\n", temp->album);
            printf("Year: %d\n", temp->year);
            printf("Genre: %s\n\n", temp->genre);
            count++;
            temp = temp->next_song;
        }
    }
}

void search_song() {
  char title[100];
  printf("Enter the title of the song you want to search: ");
  scanf("%s", title);
  
  if(head_song==NULL) {
    printf("No songs found!\n");
  } else {
    int flag = 0;
    Song *temp = head_song;
    while(temp!=NULL) {
      if(strcmp(temp->title, title)==0) {
        flag = 1;
        printf("Song Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\nGenre: %s\n\n", temp->title, temp->artist, temp->album, temp->year, temp->genre);
        break;
      }
      temp = temp->next_song;
    }
    if(flag==0) {
      printf("Song not found!\n");
    }
  }
}

void delete_song() {
  char title[100];
  printf("Enter the title of the song you want to delete: ");
  scanf("%s", title);
  
  if(head_song==NULL) {
    printf("No songs found!\n");
  } else {
    Song *current = head_song;
    Song *previous = NULL;
    int flag = 0;
    
    while(current!=NULL) {
      if(strcmp(current->title, title)==0) {
        flag = 1;
        if(previous==NULL) {
          head_song = current->next_song;
        } else {
          previous->next_song = current->next_song;
        }
        free(current);
        printf("%s deleted from the library!\n", title);
        break;
      }
      previous = current;
      current = current->next_song;
    }
    
    if(flag==0) {
      printf("Song not found!\n");
    }
  }
}

int main() {
    int choice;
    do {
        printf("\n-----C MUSIC LIBRARY MANAGEMENT SYSTEM-----\n");
        printf("1. Add song\n");
        printf("2. Display all songs\n");
        printf("3. Search song\n");
        printf("4. Delete song\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                add_song();
                break;
            }

            case 2: {
                display_all_songs();
                break;
            }

            case 3: {
                search_song();
                break;
            }

            case 4: {
                delete_song();
                break;
            }

            case 5: {
                printf("\nThank you for using the music library management system!\n\n");
                return 0;
            }

            default: {
                printf("\nInvalid choice!\n");
                break;
            }
        }
    } while (1);
    return 0;
}