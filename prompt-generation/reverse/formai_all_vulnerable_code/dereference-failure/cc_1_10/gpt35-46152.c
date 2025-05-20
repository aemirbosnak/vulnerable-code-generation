//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fileType[3];
    int fileSize;
    short int reserved1;
    short int reserved2;
    int dataOffset;
} Header;

typedef struct {
    int headerSize;
    int width;
    int height;
    short int planes;
    short int depth;
    int compression;
    int imageSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    int colorsUsed;
    int colorsImportant;
} ImageHeader;

int main(int argc, char *argv[]) {
    FILE *file;
    Header header;
    ImageHeader imageHeader;
    char fileTag[3];

    // open file in binary read mode
    file = fopen(argv[1], "rb");

    // read file header
    fread(header.fileType, 1, 2, file);
    header.fileType[2] = '\0';
    fread(&header.fileSize, 4, 1, file);
    fread(&header.reserved1, 2, 1, file);
    fread(&header.reserved2, 2, 1, file);
    fread(&header.dataOffset, 4, 1, file);

    // check file type
    if (strcmp(header.fileType, "BM") != 0) {
        printf("Unknown file type.\n");
        exit(1);
    }

    // read image header
    fread(&imageHeader.headerSize, 4, 1, file);
    fread(&imageHeader.width, 4, 1, file);
    fread(&imageHeader.height, 4, 1, file);
    fread(&imageHeader.planes, 2, 1, file);
    fread(&imageHeader.depth, 2, 1, file);
    fread(&imageHeader.compression, 4, 1, file);
    fread(&imageHeader.imageSize, 4, 1, file);
    fread(&imageHeader.xPixelsPerMeter, 4, 1, file);
    fread(&imageHeader.yPixelsPerMeter, 4, 1, file);
    fread(&imageHeader.colorsUsed, 4, 1, file);
    fread(&imageHeader.colorsImportant, 4, 1, file);

    // extract metadata
    printf("File type: %s\n", header.fileType);
    printf("File size: %d bytes\n", header.fileSize);
    printf("Width: %d pixels\n", imageHeader.width);
    printf("Height: %d pixels\n", imageHeader.height);
    printf("Color depth: %d bits\n", imageHeader.depth);

    // close file
    fclose(file);

    return 0;
}