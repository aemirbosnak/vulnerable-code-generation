//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define PUZZLE_PIECE_SIZE 32

typedef struct _puzzle_piece {
    char name[PUZZLE_PIECE_SIZE];
    int x, y;
} puzzle_piece;

typedef struct _metadata {
    char author[MAX_SIZE];
    char title[MAX_SIZE];
    int num_pieces;
    puzzle_piece pieces[MAX_SIZE];
} metadata;

void extract_metadata(char *filename, metadata *meta) {
    FILE *file = fopen(filename, "rb");
    char signature[4] = { 'M', 'E', 'T', 'A' };
    char magic[4];
    int i;

    if (!file) {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }

    fread(magic, sizeof(char), 4, file);

    if (memcmp(magic, signature, 4) != 0) {
        printf("Error: File is not a valid metadata file\n");
        fclose(file);
        return;
    }

    fread(meta->author, sizeof(char), MAX_SIZE, file);
    fread(meta->title, sizeof(char), MAX_SIZE, file);
    fread(&meta->num_pieces, sizeof(int), 1, file);

    for (i = 0; i < meta->num_pieces; i++) {
        fread(meta->pieces[i].name, sizeof(char), PUZZLE_PIECE_SIZE, file);
        fread(&meta->pieces[i].x, sizeof(int), 1, file);
        fread(&meta->pieces[i].y, sizeof(int), 1, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    metadata meta;
    char filename[MAX_SIZE];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    extract_metadata(filename, &meta);

    printf("Metadata:\n");
    printf("Author: %s\n", meta.author);
    printf("Title: %s\n", meta.title);
    printf("Number of pieces: %d\n", meta.num_pieces);

    for (int i = 0; i < meta.num_pieces; i++) {
        puzzle_piece piece = meta.pieces[i];
        printf("Piece %d: Name=%s, X=%d, Y=%d\n", i+1, piece.name, piece.x, piece.y);
    }

    return 0;
}