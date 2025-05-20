//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char artist[50];
    char album[50];
    char genre[20];
    Date release_date;
} Metadata;

void extract_metadata(const char *filename, Metadata *metadata) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: file %s not found.\n", filename);
        exit(1);
    }

    fseek(file, -128, SEEK_END);
    char id3_header[3];
    fread(id3_header, sizeof(char), 3, file);
    if (strncmp(id3_header, "TAG", 3) != 0) {
        fprintf(stderr, "Error: ID3 tag not found.\n");
        exit(1);
    }

    char artist[31];
    fread(artist, sizeof(char), 30, file);
    artist[30] = '\0';
    strncpy(metadata->artist, artist, 50);

    char album[31];
    fread(album, sizeof(char), 30, file);
    album[30] = '\0';
    strncpy(metadata->album, album, 50);

    char year[5];
    fread(year, sizeof(char), 4, file);
    year[4] = '\0';
    metadata->release_date.year = atoi(year);

    char comment[29];
    fread(comment, sizeof(char), 28, file);
    comment[28] = '\0';
    char *genre_num = strtok(comment + 1, "\0");
    metadata->genre[0] = '\0';
    if (comment[0] == 0 && comment[1] == 0 && comment[2] == 0 && comment[3] != 0) {
        int genre = atoi(genre_num);
        switch (genre) {
            case 0: strncpy(metadata->genre, "Blues", 20); break;
            case 1: strncpy(metadata->genre, "Classic Rock", 20); break;
            case 2: strncpy(metadata->genre, "Country", 20); break;
            case 3: strncpy(metadata->genre, "Dance", 20); break;
            case 4: strncpy(metadata->genre, "Disco", 20); break;
            case 5: strncpy(metadata->genre, "Funk", 20); break;
            case 6: strncpy(metadata->genre, "Grunge", 20); break;
            case 7: strncpy(metadata->genre, "Hip-Hop", 20); break;
            case 8: strncpy(metadata->genre, "Jazz", 20); break;
            case 9: strncpy(metadata->genre, "Metal", 20); break;
            case 10: strncpy(metadata->genre, "New Age", 20); break;
            case 11: strncpy(metadata->genre, "Oldies", 20); break;
            case 12: strncpy(metadata->genre, "Other", 20); break;
            case 13: strncpy(metadata->genre, "Pop", 20); break;
            case 14: strncpy(metadata->genre, "R&B", 20); break;
            case 15: strncpy(metadata->genre, "Rap", 20); break;
            case 16: strncpy(metadata->genre, "Reggae", 20); break;
            case 17: strncpy(metadata->genre, "Rock", 20); break;
            case 18: strncpy(metadata->genre, "Techno", 20); break;
            case 19: strncpy(metadata->genre, "Industrial", 20); break;
            case 20: strncpy(metadata->genre, "Alternative", 20); break;
            case 21: strncpy(metadata->genre, "Ska", 20); break;
            case 22: strncpy(metadata->genre, "Death Metal", 20); break;
            case 23: strncpy(metadata->genre, "Pranks", 20); break;
            case 24: strncpy(metadata->genre, "Soundtrack", 20); break;
            case 25: strncpy(metadata->genre, "Euro-Techno", 20); break;
            case 26: strncpy(metadata->genre, "Ambient", 20); break;
            case 27: strncpy(metadata->genre, "Trip-Hop", 20); break;
            case 28: strncpy(metadata->genre, "Vocal", 20); break;
            case 29: strncpy(metadata->genre, "Jazz+Funk", 20); break;
            case 30: strncpy(metadata->genre, "Fusion", 20); break;
            case 31: strncpy(metadata->genre, "Trance", 20); break;
            case 32: strncpy(metadata->genre, "Classical", 20); break;
            case 33: strncpy(metadata->genre, "Instrumental", 20); break;
            case 34: strncpy(metadata->genre, "Acid", 20); break;
            case 35: strncpy(metadata->genre, "House", 20); break;
            case 36: strncpy(metadata->genre, "Game", 20); break;
            case 37: strncpy(metadata->genre, "Sound Clip", 20); break;
            case 38: strncpy(metadata->genre, "Gospel", 20); break;
            case 39: strncpy(metadata->genre, "Noise", 20); break;
            case 40: strncpy(metadata->genre, "Alternative Rock", 20); break;
            case 41: strncpy(metadata->genre, "Bass", 20); break;
            case 42: strncpy(metadata->genre, "Soul", 20); break;
            case 43: strncpy(metadata->genre, "Punk", 20); break;
            case 44: strncpy(metadata->genre, "Space", 20); break;
            case 45: strncpy(metadata->genre, "Meditative", 20); break;
            case 46: strncpy(metadata->genre, "Instrumental Pop", 20); break;
            case 47: strncpy(metadata->genre, "Instrumental Rock", 20); break;
            case 48: strncpy(metadata->genre, "Ethnic", 20); break;
            case 49: strncpy(metadata->genre, "Gothic", 20); break;
            case 50: strncpy(metadata->genre, "Darkwave", 20); break;
            case 51: strncpy(metadata->genre, "Techno-Industrial", 20); break;
            case 52: strncpy(metadata->genre, "Electronic", 20); break;
            case 53: strncpy(metadata->genre, "Pop-Folk", 20); break;
            case 54: strncpy(metadata->genre, "Eurodance", 20); break;
            case 55: strncpy(metadata->genre, "Dream", 20); break;
            case 56: strncpy(metadata->genre, "Southern Rock", 20); break;
            case 57: strncpy(metadata->genre, "Comedy", 20); break;
            case 58: strncpy(metadata->genre, "Cult", 20); break;
            case 59: strncpy(metadata->genre, "Gangsta", 20); break;
            case 60: strncpy(metadata->genre, "Top 40", 20); break;
            case 61: strncpy(metadata->genre, "Christian Rap", 20); break;
            case 62: strncpy(metadata->genre, "Pop/Funk", 20); break;
            case 63: strncpy(metadata->genre, "Jungle", 20); break;
            case 64: strncpy(metadata->genre, "Native American", 20); break;
            case 65: strncpy(metadata->genre, "Cabaret", 20); break;
            case 66: strncpy(metadata->genre, "New Wave", 20); break;
            case 67: strncpy(metadata->genre, "Psychedelic", 20); break;
            case 68: strncpy(metadata->genre, "Rave", 20); break;
            case 69: strncpy(metadata->genre, "Showtunes", 20); break;
            case 70: strncpy(metadata->genre, "Trailer", 20); break;
            case 71: strncpy(metadata->genre, "Lo-Fi", 20); break;
            case 72: strncpy(metadata->genre, "Tribal", 20); break;
            case 73: strncpy(metadata->genre, "Acid Punk", 20); break;
            case 74: strncpy(metadata->genre, "Acid Jazz", 20); break;
            case 75: strncpy(metadata->genre, "Polka", 20); break;
            case 76: strncpy(metadata->genre, "Vintage Rock", 20); break;
            case 77: strncpy(metadata->genre, "Hard Rock", 20); break;
            default: strncpy(metadata->genre, "Unknown", 20); break;
        }
    } else {
        strncpy(metadata->genre, comment, 20);
    }

    fclose(file);
}

int main() {
    Metadata metadata;
    char filename[] = "example.mp3";
    extract_metadata(filename, &metadata);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Genre: %s\n", metadata.genre);
    printf("Release Date: %d/%d/%d\n", metadata.release_date.day, metadata.release_date.month, metadata.release_date.year);
    return 0;
}