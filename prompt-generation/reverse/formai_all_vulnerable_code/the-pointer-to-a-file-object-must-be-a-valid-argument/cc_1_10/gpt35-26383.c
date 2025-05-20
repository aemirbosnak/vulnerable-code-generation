//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
// Romeo and Juliet inspired Music Library Management System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int option;
    char artist[50], song_title[50];
    FILE *library_file;
    library_file = fopen("library.txt", "a+");

    // Romeo's initial prompt to Juliet
    printf("My dearest Juliet, may I have the honor of managing our music library? \n");

    do {
        // Juliet's response
        printf("Of course, Romeo! What can I do to assist you? \n");
        printf("1. Add a song to the library \n");
        printf("2. Search for a song in the library \n");
        printf("3. Exit \n");

        // Romeo's choices
        printf("Please choose a number option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                // Romeo adds a new song to the library
                printf("Please enter the artist name: ");
                scanf(" %[^\n]s", artist);
                printf("Please enter the song title: ");
                scanf(" %[^\n]s", song_title);

                // add new song to file
                fprintf(library_file, "%s - %s\n", artist, song_title);

                // Juliet's reaction to new song added
                printf("Well done, my love! You have added \"%s\" by %s to the library. \n", song_title, artist);

                break;
            case 2: 
                // Juliet searches for a song in the library
                printf("Please enter the name of the song or artist: ");
                scanf(" %[^\n]s", artist);

                // search for song in file
                char buffer[1024];
                int line_num = 1, found = 0;
                rewind(library_file);

                while(fgets(buffer, 1024, library_file)) {
                    if(strstr(buffer, artist) != NULL) {
                        printf("%d. %s", line_num, buffer);
                        found++;
                    }
                    line_num++;
                }

                // Romeo's response to search results
                if(found == 0) {
                    printf("Alas, my love, \"%s\" is not in our library. \n", artist);
                } else {
                    printf("Ah, my love! Here are the results of \"%s\" in our library. \n", artist);
                }

                break;
            case 3:
                // Romeo bids Juliet farewell
                printf("My sweet Juliet, our library will forever be filled with the sweetest melodies. Farewell! \n");
                fclose(library_file);
                exit(0);
            default:
                // Juliet didn't understand Romeo's request
                printf("Pardon me, my love. I did not understand your request. \n");
                break;
        }

    } while(option != 3);

    return 0;
}