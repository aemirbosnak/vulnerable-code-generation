//FormAI DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct song {
    int id;
    char title[100];
    char artist[100];
    float duration;
    char genre[50];
} Song;
 
int main() {
    int choice, num_songs = 0;
    Song *song_list = NULL;

    while (1) {
        printf("---C MUSIC LIBRARY MANAGEMENT SYSTEM---\n");
        printf("1. Add song\n");
        printf("2. Delete song\n");
        printf("3. Edit song\n");
        printf("4. Display song list\n");
        printf("5. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
         
        scanf("%d", &choice);
         
        switch (choice) {
             
            case 1: {
                Song new_song;
 
                printf("\n---Adding new song---\n");
                printf("Enter song title: ");
                scanf("%s", new_song.title);
 
                printf("Enter artist: ");
                scanf("%s", new_song.artist);
 
                printf("Enter song duration (in minutes): ");
                scanf("%f", &new_song.duration);
 
                printf("Enter genre: ");
                scanf("%s", new_song.genre);

                num_songs++;

                if (song_list != NULL) {
                    song_list = (Song*) realloc(song_list, num_songs * sizeof(Song));
                } else {
                    song_list = (Song*) malloc(num_songs * sizeof(Song));
                }

                song_list[num_songs-1] = new_song;
 
                printf("\nSong added successfully!\n");
                break;
            }

            case 2: {
                char title[100];
                int found = 0;

                printf("\n---Deleting song---\n");
                printf("Enter song title: ");
                scanf("%s", title);

                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(song_list[i].title, title) == 0) {
                        found = 1;
                        for (int j = i; j < num_songs-1; j++) {
                            song_list[j] = song_list[j+1];
                        }
                        num_songs--;
                        song_list = (Song*) realloc(song_list, num_songs * sizeof(Song));
                        printf("\nSong deleted successfully!\n");
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nSong not found!\n");
                }

                break;
            }

            case 3: {
                char title[100];
                int found = 0, chosen_song;

                printf("\n---Editing song---\n");
                printf("Enter song title: ");
                scanf("%s", title);

                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(song_list[i].title, title) == 0) {
                        found = 1;
                        chosen_song = i;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nSong not found!\n");
                    break;
                }

                int option;
                printf("\n---Editing song %s---\n", song_list[chosen_song].title);
                printf("1. Edit title\n");
                printf("2. Edit artist\n");
                printf("3. Edit duration\n");
                printf("4. Edit genre\n");
                printf("5. Back to main menu\n");
                printf("Enter your choice: ");

                scanf("%d", &option);

                switch (option) {
                    case 1: {
                        printf("Enter new title: ");
                        scanf("%s", song_list[chosen_song].title);
                        printf("\nSong title edited successfully!\n");
                        break;
                    }

                    case 2: {
                        printf("Enter new artist: ");
                        scanf("%s", song_list[chosen_song].artist);
                        printf("\nArtist edited successfully!\n");
                        break;
                    }

                    case 3: {
                        printf("Enter new duration (in minutes): ");
                        scanf("%f", &song_list[chosen_song].duration);
                        printf("\nDuration edited successfully!\n");
                        break;
                    }

                    case 4: {
                        printf("Enter new genre: ");
                        scanf("%s", song_list[chosen_song].genre);
                        printf("\nGenre edited successfully!\n");
                        break;
                    }

                    case 5: {
                        break;
                    }

                    default: {
                        printf("\nInvalid option!\n");
                        break;
                    }
                }

                break;
            }

            case 4: {
                if (num_songs == 0) {
                    printf("\nNo songs found in library!\n");
                    break;
                }

                printf("\n---DISPLAYING SONG LIST---\n");
                printf("ID\tTitle\t\tArtist\t\tDuration\t\tGenre\n");
                for (int i = 0; i < num_songs; i++) {
                    printf("%d\t%s\t%s\t%f\t%s\n", 
                        song_list[i].id,
                        song_list[i].title,
                        song_list[i].artist,
                        song_list[i].duration,
                        song_list[i].genre);
                }

                break;
            }

            case 5: {
                printf("\n---THANK YOU FOR USING C MUSIC LIBRARY MANAGEMENT SYSTEM---\n");
                return 0;
            }

            default: {
                printf("\nInvalid option!\n");
                break;
            }
        }
    }

    return 0;
}