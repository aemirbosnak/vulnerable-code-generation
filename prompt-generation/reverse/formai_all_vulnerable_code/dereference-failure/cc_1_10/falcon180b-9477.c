//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Music{
    char title[100];
    char artist[50];
    char album[50];
    int year;
    int duration;
};

struct Music createMusic(char* title, char* artist, char* album, int year, int duration){
    struct Music music;
    strcpy(music.title, title);
    strcpy(music.artist, artist);
    strcpy(music.album, album);
    music.year = year;
    music.duration = duration;
    return music;
}

void displayMusic(struct Music music){
    printf("Title: %s\n", music.title);
    printf("Artist: %s\n", music.artist);
    printf("Album: %s\n", music.album);
    printf("Year: %d\n", music.year);
    printf("Duration: %d seconds\n", music.duration);
}

int main(){
    struct Music* library = NULL;
    int size = 0;

    library = (struct Music*)malloc(sizeof(struct Music));
    createMusic("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 240);
    library[size++] = *library;

    library = (struct Music*)realloc(library, sizeof(struct Music)*size);
    createMusic("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 530);
    library[size++] = *library;

    library = (struct Music*)realloc(library, sizeof(struct Music)*size);
    createMusic("Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 210);
    library[size++] = *library;

    printf("Library size: %d\n", size);

    for(int i=0; i<size; i++){
        displayMusic(library[i]);
    }

    free(library);
    return 0;
}