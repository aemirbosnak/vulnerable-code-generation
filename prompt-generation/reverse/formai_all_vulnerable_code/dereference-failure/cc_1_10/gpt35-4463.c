//FormAI DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song{
    char name[50];
    char artist[50];
    char genre[20];
    int year;
};

struct Node{
    struct Song song;
    struct Node* prev;
    struct Node* next;
};

struct Library{
    struct Node* head;
};

//function to add a song to the library
void addSong(struct Library* library, struct Song song){
    //creating a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    //if the library is empty
    if(library->head == NULL){
        library->head = newNode;
    }
    //if the library is not empty
    else{
        newNode->next = library->head;
        library->head->prev = newNode;
        library->head = newNode;
    }
}

//function to display all songs in the library
void displayLibrary(struct Library* library){
    struct Node* current = library->head;
    //if the library is empty
    if(current == NULL){
        printf("The library is empty!");
    }
    //if the library is not empty
    else{
        while(current != NULL){
            printf("%s - %s (%s, %d)\n", current->song.name, current->song.artist, current->song.genre, current->song.year);
            current = current->next;
        }
    }
}

//function to search for a song by name
void searchByName(struct Library* library, char name[50]){
    struct Node* current = library->head;
    //if the library is empty
    if(current == NULL){
        printf("The library is empty!");
    }
    //if the library is not empty
    else{
        while(current != NULL){
            if(strcmp(current->song.name, name) == 0){
                printf("%s - %s (%s, %d)\n", current->song.name, current->song.artist, current->song.genre, current->song.year);
                return;
            }
            current = current->next;
        }
        printf("Song not found!");
    }
}

//function to search for songs by artist
void searchByArtist(struct Library* library, char artist[50]){
    struct Node* current = library->head;
    //if the library is empty
    if(current == NULL){
        printf("The library is empty!");
    }
    //if the library is not empty
    else{
        while(current != NULL){
            if(strcmp(current->song.artist, artist) == 0){
                printf("%s - %s (%s, %d)\n", current->song.name, current->song.artist, current->song.genre, current->song.year);
            }
            current = current->next;
        }
    }
}

//function to search for songs by genre
void searchByGenre(struct Library* library, char genre[20]){
    struct Node* current = library->head;
    //if the library is empty
    if(current == NULL){
        printf("The library is empty!");
    }
    //if the library is not empty
    else{
        while(current != NULL){
            if(strcmp(current->song.genre, genre) == 0){
                printf("%s - %s (%s, %d)\n", current->song.name, current->song.artist, current->song.genre, current->song.year);
            }
            current = current->next;
        }
    }
}

//function to search for songs by year
void searchByYear(struct Library* library, int year){
    struct Node* current = library->head;
    //if the library is empty
    if(current == NULL){
        printf("The library is empty!");
    }
    //if the library is not empty
    else{
        while(current != NULL){
            if(current->song.year == year){
                printf("%s - %s (%s, %d)\n", current->song.name, current->song.artist, current->song.genre, current->song.year);
            }
            current = current->next;
        }
    }
}

int main(){
    struct Library library;
    library.head = NULL;
    struct Song song1 = {"Bohemian Rhapsody", "Queen", "Rock", 1975};
    struct Song song2 = {"Thriller", "Michael Jackson", "Pop", 1982};
    struct Song song3 = {"Livin' on a Prayer", "Bon Jovi", "Rock", 1986};
    struct Song song4 = {"How Deep Is Your Love", "Bee Gees", "Disco", 1977};
    struct Song song5 = {"Like a Virgin", "Madonna", "Pop", 1984};
    
    //adding songs to the library
    addSong(&library, song1);
    addSong(&library, song2);
    addSong(&library, song3);
    addSong(&library, song4);
    addSong(&library, song5);
    
    //displaying the library
    printf("All songs in the library:\n");
    displayLibrary(&library);
    printf("\n");
    
    //searching for a song by name
    char songName[50] = "Thriller";
    printf("Searching for song: %s\n", songName);
    searchByName(&library, songName);
    printf("\n");
    
    //searching for songs by artist
    char songArtist[50] = "Queen";
    printf("Searching for songs by artist: %s\n", songArtist);
    searchByArtist(&library, songArtist);
    printf("\n");
    
    //searching for songs by genre
    char songGenre[20] = "Pop";
    printf("Searching for songs by genre: %s\n", songGenre);
    searchByGenre(&library, songGenre);
    printf("\n");
    
    //searching for songs by year
    int songYear = 1977;
    printf("Searching for songs from year: %d\n", songYear);
    searchByYear(&library, songYear);
    printf("\n");
    
    return 0;
}