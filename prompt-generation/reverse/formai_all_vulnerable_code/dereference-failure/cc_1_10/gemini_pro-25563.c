//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _Tome {
    char *title;
    char *author;
    int year;
    int pages;
} Tome;

typedef struct _Index {
    char *key;
    int *entries;
    int numEntries;
} Index;

void addTome(Tome **tomes, int *numTomes, Tome tome) {
    Tome *newTomes = realloc(*tomes, sizeof(Tome) * (*numTomes + 1));
    if (newTomes == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new tome.\n");
        return;
    }
    *tomes = newTomes;
    (*tomes)[*numTomes] = tome;
    (*numTomes)++;
}

void addIndexEntry(Index **indexes, int *numIndexes, Index index) {
    Index *newIndexes = realloc(*indexes, sizeof(Index) * (*numIndexes + 1));
    if (newIndexes == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new index.\n");
        return;
    }
    *indexes = newIndexes;
    (*indexes)[*numIndexes] = index;
    (*numIndexes)++;
}

int main() {
    Tome tomes[100];
    int numTomes = 0;

    Index indexes[100];
    int numIndexes = 0;

    // Add some tomes to the library
    Tome tome1 = {"The Canterbury Tales", "Geoffrey Chaucer", 1387, 173};
    addTome(&tomes, &numTomes, tome1);

    Tome tome2 = {"The Divine Comedy", "Dante Alighieri", 1310, 123};
    addTome(&tomes, &numTomes, tome2);

    Tome tome3 = {"The Iliad", "Homer", 800, 16634};
    addTome(&tomes, &numTomes, tome3);

    // Create an index on the tome titles
    Index titleIndex = {"title", malloc(sizeof(int) * numTomes), numTomes};
    for (int i = 0; i < numTomes; i++) {
        titleIndex.entries[i] = i;
    }
    addIndexEntry(&indexes, &numIndexes, titleIndex);

    // Create an index on the tome authors
    Index authorIndex = {"author", malloc(sizeof(int) * numTomes), numTomes};
    for (int i = 0; i < numTomes; i++) {
        authorIndex.entries[i] = i;
    }
    addIndexEntry(&indexes, &numIndexes, authorIndex);

    // Create an index on the tome years
    Index yearIndex = {"year", malloc(sizeof(int) * numTomes), numTomes};
    for (int i = 0; i < numTomes; i++) {
        yearIndex.entries[i] = i;
    }
    addIndexEntry(&indexes, &numIndexes, yearIndex);

    // Create an index on the tome pages
    Index pagesIndex = {"pages", malloc(sizeof(int) * numTomes), numTomes};
    for (int i = 0; i < numTomes; i++) {
        pagesIndex.entries[i] = i;
    }
    addIndexEntry(&indexes, &numIndexes, pagesIndex);

    // Search the library for tomes by title
    char *title = "The Canterbury Tales";
    int *titleEntries = titleIndex.entries;
    int numTitleEntries = titleIndex.numEntries;
    for (int i = 0; i < numTitleEntries; i++) {
        int tomeIndex = titleEntries[i];
        Tome tome = tomes[tomeIndex];
        printf("Found tome: %s by %s (%d, %d pages)\n", tome.title, tome.author, tome.year, tome.pages);
    }

    // Search the library for tomes by author
    char *author = "Geoffrey Chaucer";
    int *authorEntries = authorIndex.entries;
    int numAuthorEntries = authorIndex.numEntries;
    for (int i = 0; i < numAuthorEntries; i++) {
        int tomeIndex = authorEntries[i];
        Tome tome = tomes[tomeIndex];
        printf("Found tome: %s by %s (%d, %d pages)\n", tome.title, tome.author, tome.year, tome.pages);
    }

    // Search the library for tomes by year
    int year = 1387;
    int *yearEntries = yearIndex.entries;
    int numYearEntries = yearIndex.numEntries;
    for (int i = 0; i < numYearEntries; i++) {
        int tomeIndex = yearEntries[i];
        Tome tome = tomes[tomeIndex];
        printf("Found tome: %s by %s (%d, %d pages)\n", tome.title, tome.author, tome.year, tome.pages);
    }

    // Search the library for tomes by pages
    int pages = 16634;
    int *pagesEntries = pagesIndex.entries;
    int numPagesEntries = pagesIndex.numEntries;
    for (int i = 0; i < numPagesEntries; i++) {
        int tomeIndex = pagesEntries[i];
        Tome tome = tomes[tomeIndex];
        printf("Found tome: %s by %s (%d, %d pages)\n", tome.title, tome.author, tome.year, tome.pages);
    }

    return 0;
}