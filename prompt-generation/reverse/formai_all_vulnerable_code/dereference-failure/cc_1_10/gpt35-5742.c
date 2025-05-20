//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct metadata {
    char *title;
    char *artist;
    char *album;
    char *genre;
    int year;
} Metadata;

Metadata *create_metadata() {
    Metadata *data = malloc(sizeof(Metadata));
    data->title = NULL;
    data->artist = NULL;
    data->album = NULL;
    data->genre = NULL;
    data->year = 0;
    return data;
}

void free_metadata(Metadata *data) {
    free(data->title);
    free(data->artist);
    free(data->album);
    free(data->genre);
    free(data);
}

void print_metadata(Metadata *data) {
    printf("Title: %s\n", data->title);
    printf("Artist: %s\n", data->artist);
    printf("Album: %s\n", data->album);
    printf("Genre: %s\n", data->genre);
    printf("Year: %d\n", data->year);
}

void parse_metadata(char *line, Metadata *data) {

    char *key = strtok(line, ":");
    char *value = strtok(NULL, "");

    if(key && value) {
        // Remove leading/trailing spaces
        while(isspace(*value)) {
            value++;
        }
        if(value[strlen(value) - 1] == '\n') { 
            value[strlen(value) - 1] = '\0'; // Remove trailing newline
        }
        while(isspace(value[strlen(value)-1])) {
            value[strlen(value)-1]='\0';
        }

        if(!strcmp(key, "Title")) { 
            data->title = strdup(value); 
        }
        else if(!strcmp(key, "Artist")) { 
            data->artist = strdup(value); 
        }
        else if(!strcmp(key, "Album")) { 
            data->album = strdup(value); 
        }
        else if(!strcmp(key, "Year")) { 
            data->year = atoi(value); 
        }
        else if(!strcmp(key, "Genre")) { 
            data->genre = strdup(value); 
        }
    }
}

Metadata *extract_metadata(FILE *file) {
    char line[256];
    Metadata *data = create_metadata();
    while(fgets(line, sizeof(line), file)) {
        parse_metadata(line, data);
    }
    return data;
}

int main() {
    char filepath[256];
    printf("Enter the path of the audio file: ");
    fgets(filepath, sizeof(filepath), stdin);
    filepath[strlen(filepath) - 1] = '\0'; // Remove trailing newline

    FILE *file = fopen(filepath, "r");
    if(!file) {
        perror("Error opening file");
        return 1;
    }

    Metadata *data = extract_metadata(file);
    fclose(file);

    print_metadata(data);
    free_metadata(data);
    return 0;
}