//FormAI DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int id;
    char name[50];
    char address[100];
    char phone[15];
} Data;

typedef struct index {
    int id;
    int offset;
} Index;

int main() {
    char filename[] = "data.db";
    FILE *fp;
    fp = fopen(filename, "wb+");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    Data d1 = {1, "John Doe", "123 Main St, Anytown USA", "555-1234"};
    Data d2 = {2, "Jane Smith", "456 Broadway, Somewhere USA", "555-5678"};

    fwrite(&d1, sizeof(Data), 1, fp);
    fwrite(&d2, sizeof(Data), 1, fp);

    int count = 2;
    Index *index = (Index *)malloc(sizeof(Index) * count);

    rewind(fp);

    for (int i = 0; i < count; i++) {
        fread(&index[i].id, sizeof(int), 1, fp);
        index[i].offset = ftell(fp);
        fseek(fp, sizeof(Data) - sizeof(int), SEEK_CUR); // skip over the name, address, and phone fields
    }

    printf("%-5s %-15s %-25s %-15s\n", "ID", "Name", "Address", "Phone");

    for (int i = 0; i < count; i++) {
        fseek(fp, index[i].offset, SEEK_SET);
        Data d;
        fread(&d, sizeof(Data), 1, fp);
        printf("%-5d %-15s %-25s %-15s\n", d.id, d.name, d.address, d.phone);
    }

    free(index);
    fclose(fp);

    return 0;
}