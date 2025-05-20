//FormAI DATASET v1.0 Category: Music Library Management System ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Song{
    char name[100];
    char artist[100];
    char album[100];
}Song;

void addSong(Song* library[], int* num_songs);
void viewLibrary(Song* library[], int num_songs);

int main(){
    Song* library[100];
    int num_songs = 0;
    int choice;
    while(1){
        printf("********** RETRO MUSIC LIBRARY ***********\n");
        printf("Select an option:\n");
        printf("1. Add a song\n");
        printf("2. View Library\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        if(choice==1)
            addSong(library, &num_songs);
        else if(choice==2)
            viewLibrary(library, num_songs);
        else if(choice==3)
            break;
        else
            printf("Invalid Choice! Please select a valid option.\n");

    }
    return 0;
}

void addSong(Song* library[], int* num_songs){
    printf("Enter song name: ");
    char temp_name[100];
    scanf(" %[^\n]", temp_name);
    printf("Enter artist name: ");
    char temp_artist[100];
    scanf(" %[^\n]", temp_artist);
    printf("Enter album name: ");
    char temp_album[100];
    scanf(" %[^\n]", temp_album);
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->name, temp_name);
    strcpy(new_song->artist, temp_artist);
    strcpy(new_song->album, temp_album);
    library[*num_songs] = new_song;
    (*num_songs)++;
    printf("Song added to the library successfully!\n");
}

void viewLibrary(Song* library[], int num_songs){
    if(num_songs==0){
        printf("The music library is empty!\n");
        return;
    }
    printf("********** MUSIC LIBRARY **********\n");
    for(int i=0; i<num_songs; i++){
        printf("Song %d: %s\n", i+1, library[i]->name);
        printf("Artist   : %s\n", library[i]->artist);
        printf("Album    : %s\n", library[i]->album);
        printf("***********************************\n");
    }
}