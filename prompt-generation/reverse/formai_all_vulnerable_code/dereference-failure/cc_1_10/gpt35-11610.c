//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    char title[100];
    char artist[50];
    char album[50];
    char genre[20];
    int year;
};

void extractMetadata(char* fileName, struct Metadata* metaData) {
    // code to extract metadata from the file goes here
    // assume that the metadata is stored in ID3v2 tags
    
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("ERROR: Failed to open file %s\n", fileName);
        return;
    }

    // jump to the ID3v2 tag header
    fseek(file, 0, SEEK_SET);
    char tag[3];
    fread(tag, sizeof(char), 3, file);
    if (tag[0] != 'I' || tag[1] != 'D' || tag[2] != '3') {
        printf("ERROR: No ID3v2 tag found in file %s\n", fileName);
        return;
    }
    int majorVersion = fgetc(file);
    int minorVersion = fgetc(file);
    int flags = fgetc(file);
    int tagSize = 0;
    for (int i = 0; i < 4; i++) {
        tagSize <<= 7;
        tagSize |= fgetc(file) & 0x7F;
    }

    // read the tag header
    char header[10];
    fread(header, sizeof(char), 10, file);

    // read the frames
    while (ftell(file) < tagSize + 10) {
        char frameID[5];
        fread(frameID, sizeof(char), 4, file);
        frameID[4] = '\0';
        int frameSize = 0;
        for (int i = 0; i < 4; i++) {
            frameSize <<= 8;
            frameSize |= fgetc(file);
        }
        int flags = fgetc(file);

        if (strcmp(frameID, "TALB") == 0) { // album
            fread(metaData->album, sizeof(char), frameSize, file);
            metaData->album[frameSize] = '\0';
        }
        else if (strcmp(frameID, "TIT2") == 0) { // title
            fread(metaData->title, sizeof(char), frameSize, file);
            metaData->title[frameSize] = '\0';
        }
        else if (strcmp(frameID, "TPE1") == 0) { // artist
            fread(metaData->artist, sizeof(char), frameSize, file);
            metaData->artist[frameSize] = '\0';
        }
        else if (strcmp(frameID, "TYER") == 0) { // year
            char year[5];
            fread(year, sizeof(char), frameSize, file);
            year[frameSize] = '\0';
            metaData->year = atoi(year);
        }
        else if (strcmp(frameID, "TCON") == 0) { // genre
            fread(metaData->genre, sizeof(char), frameSize, file);
            metaData->genre[frameSize] = '\0';
        }
        else {
            // skip over the frame
            fseek(file, frameSize, SEEK_CUR);
        }
    }

    fclose(file);
}

int main() {
    struct Metadata metaData = { "", "", "", "", 0 };
    extractMetadata("example.mp3", &metaData);
    printf("Title: %s\n", metaData.title);
    printf("Artist: %s\n", metaData.artist);
    printf("Album: %s\n", metaData.album);
    printf("Year: %d\n", metaData.year);
    printf("Genre: %s\n", metaData.genre);
    return 0;
}