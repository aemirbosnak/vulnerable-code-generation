//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[50];
    char artist[50];
    char genre[20];
    char album[50];
    int year;
} Song;

void add(Song* songs[], int* num_songs) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    printf("Enter song title: ");
    fgets(new_song->title, 50, stdin);
    printf("Enter artist name: ");
    fgets(new_song->artist, 50, stdin);
    printf("Enter genre: ");
    fgets(new_song->genre, 20, stdin);
    printf("Enter album name: ");
    fgets(new_song->album, 50, stdin);
    printf("Enter year: ");
    scanf("%d", &new_song->year);
    getchar(); // remove newline character from buffer
    songs[*num_songs] = new_song;
    (*num_songs)++;
    printf("Song added successfully.\n");
}

void display(Song* songs[], int num_songs) {
    if (num_songs <= 0) {
        printf("No songs found.\n");
        return;
    }
    printf("%-50s %-50s %-20s %-50s %-4s\n", "Title", "Artist", "Genre", "Album", "Year");
    for (int i = 0; i < num_songs; i++) {
        Song* curr_song = songs[i];
        printf("%-50s %-50s %-20s %-50s %-4d\n", curr_song->title, curr_song->artist, curr_song->genre, curr_song->album, curr_song->year);
    }
}

void search(Song* songs[], int num_songs) {
    if (num_songs <= 0) {
        printf("No songs found.\n");
        return;
    }
    char search_term[50];
    printf("Enter search term: ");
    fgets(search_term, 50, stdin);
    for (int i = 0; i < num_songs; i++) {
        Song* curr_song = songs[i];
        if (strstr(curr_song->title, search_term) != NULL || strstr(curr_song->artist, search_term) != NULL 
            || strstr(curr_song->genre, search_term) != NULL || strstr(curr_song->album, search_term) != NULL 
            || curr_song->year == atoi(search_term)) {
            printf("%-50s %-50s %-20s %-50s %-4d\n", curr_song->title, curr_song->artist, curr_song->genre, curr_song->album, curr_song->year);
        }
    }
}

void save(Song* songs[], int num_songs) {
    if (num_songs <= 0) {
        printf("No songs found.\n");
        return;
    }
    FILE* fp = fopen("music_library.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    for (int i = 0; i < num_songs; i++) {
        Song* curr_song = songs[i];
        fprintf(fp, "%s|%s|%s|%s|%d\n", curr_song->title, curr_song->artist, curr_song->genre, curr_song->album, curr_song->year);
    }
    fclose(fp);
    printf("Music library saved to file.\n");
}

void load(Song* songs[], int* num_songs) {
    FILE* fp = fopen("music_library.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    char buffer[200];
    while (fgets(buffer, 200, fp)) {
        Song* new_song = (Song*)malloc(sizeof(Song));
        char* token = strtok(buffer, "|");
        strcpy(new_song->title, token);
        token = strtok(NULL, "|");
        strcpy(new_song->artist, token);
        token = strtok(NULL, "|");
        strcpy(new_song->genre, token);
        token = strtok(NULL, "|");
        strcpy(new_song->album, token);
        token = strtok(NULL, "|");
        new_song->year = atoi(token);
        songs[*num_songs] = new_song;
        (*num_songs)++;
    }
    fclose(fp);
    printf("Music library loaded from file.\n");
}

void delete(Song* songs[], int* num_songs) {
    if (num_songs <= 0) {
        printf("No songs found.\n");
        return;
    }
    char search_term[50];
    printf("Enter search term for song to delete: ");
    fgets(search_term, 50, stdin);
    int delete_count = 0; // keep track of how many songs have been deleted
    for (int i = 0; i < *num_songs; i++) {
        Song* curr_song = songs[i];
        if (strstr(curr_song->title, search_term) != NULL || strstr(curr_song->artist, search_term) != NULL 
            || strstr(curr_song->genre, search_term) != NULL || strstr(curr_song->album, search_term) != NULL 
            || curr_song->year == atoi(search_term)) {
            free(curr_song);
            // move all songs in array one position to the left
            for (int j = i+1; j < *num_songs; j++) {
                songs[j-1] = songs[j];
            }
            (*num_songs)--;
            delete_count++;
            i--; // adjust counter since we moved array elements to the left
        }
    }
    if (delete_count == 0) {
        printf("No songs matching search term found.\n");
    } else {
        printf("%d song(s) deleted successfully.\n", delete_count);
    }
}

int main() {
    Song* songs[1000];
    int num_songs = 0;
    char command;
    do {
        printf("[A]dd song, [D]isplay all songs, [S]earch, [L]oad from file, [Sa]ve to file, [De]lete song, [Q]uit\n");
        printf("Enter command: ");
        scanf("%c", &command);
        getchar(); // remove newline character from buffer
        switch (command) {
            case 'A': add(songs, &num_songs); break;
            case 'D': display(songs, num_songs); break;
            case 'S': search(songs, num_songs); break;
            case 'L': load(songs, &num_songs); break;
            case 'Sa': save(songs, num_songs); break;
            case 'De': delete(songs, &num_songs); break;
            case 'Q': printf("Exiting program.\n"); break;
            default: printf("Invalid command, please try again.\n");
        }
    } while (command != 'Q');
    return 0;
}