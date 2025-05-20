//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    char address[50];
} Record;

typedef struct {
    int id;
    long offset;
} Index;

int compare(const void *a, const void *b) {
    return ((Index*)a)->id - ((Index*)b)->id;
}

int main() {
    FILE *fp, *ip;
    Record rec;
    Index idx[MAX_RECORDS];
    int i, n = 0;

    fp = fopen("data.db", "rb");
    if (fp == NULL) {
        printf("Error: Can't open the data file\n");
        exit(1);
    }

    ip = fopen("index.idx", "wb");
    if (ip == NULL) {
        printf("Error: Can't create the index file\n");
        exit(1);
    }

    while (fread(&rec, sizeof(rec), 1, fp) == 1) {
        idx[n].id = rec.id;
        idx[n].offset = ftell(fp) - sizeof(rec);
        n++;
    }
    qsort(idx, n, sizeof(Index), compare);
    fwrite(idx, sizeof(Index), n, ip);

    fclose(fp);
    fclose(ip);
    return 0;
}