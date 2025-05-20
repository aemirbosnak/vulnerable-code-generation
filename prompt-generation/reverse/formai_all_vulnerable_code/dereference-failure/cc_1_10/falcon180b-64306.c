//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_FILES 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char artist[MAX_FILE_NAME_LENGTH];
    char album[MAX_FILE_NAME_LENGTH];
    char genre[MAX_FILE_NAME_LENGTH];
    int duration_in_seconds;
} MusicFile;

void display_music_file(MusicFile* music_file) {
    printf("File name: %s\n", music_file->file_name);
    printf("Artist: %s\n", music_file->artist);
    printf("Album: %s\n", music_file->album);
    printf("Genre: %s\n", music_file->genre);
    printf("Duration: %d seconds\n", music_file->duration_in_seconds);
}

int main() {
    MusicFile music_files[MAX_MUSIC_FILES];
    int num_music_files = 0;

    char input_buffer[MAX_FILE_NAME_LENGTH];
    while (fgets(input_buffer, MAX_FILE_NAME_LENGTH, stdin)!= NULL) {
        if (num_music_files == MAX_MUSIC_FILES) {
            printf("Error: Maximum number of music files reached.\n");
            break;
        }

        char* token = strtok(input_buffer, ",");
        strcpy(music_files[num_music_files].file_name, token);
        token = strtok(NULL, ",");
        strcpy(music_files[num_music_files].artist, token);
        token = strtok(NULL, ",");
        strcpy(music_files[num_music_files].album, token);
        token = strtok(NULL, ",");
        strcpy(music_files[num_music_files].genre, token);
        music_files[num_music_files].duration_in_seconds = atoi(strtok(NULL, ","));

        num_music_files++;
    }

    printf("Number of music files: %d\n", num_music_files);

    for (int i = 0; i < num_music_files; i++) {
        display_music_file(&music_files[i]);
    }

    return 0;
}