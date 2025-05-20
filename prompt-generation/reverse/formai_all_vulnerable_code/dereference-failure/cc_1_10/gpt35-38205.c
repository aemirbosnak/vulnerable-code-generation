//FormAI DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int age;
} Person;

typedef struct {
    char id[MAX_ID_LENGTH];
    long offset;
} Index;

void create_index(const char *filename, const char *index_filename) {
    FILE *fp, *index_fp;
    fp = fopen(filename, "rb");
    index_fp = fopen(index_filename, "wb");
    if (fp == NULL || index_fp == NULL) {
        fprintf(stderr, "Failed to open file '%s' or '%s'\n", filename, index_filename);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    long offset = 0;
    while (offset < file_size) {
        Person p;
        fread(&p, sizeof(Person), 1, fp);
        Index index;
        strcpy(index.id, p.id);
        index.offset = offset;
        fwrite(&index, sizeof(Index), 1, index_fp);
        offset = ftell(fp);
    }
    fclose(fp);
    fclose(index_fp);
}

void search(const char *filename, const char *index_filename, const char *id) {
    FILE *index_fp = fopen(index_filename, "rb");
    if (index_fp == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", index_filename);
        exit(EXIT_FAILURE);
    }
    Index index;
    while (fread(&index, sizeof(Index), 1, index_fp)) {
        if (strcmp(index.id, id) == 0) {
            FILE *fp = fopen(filename, "rb");
            if (fp == NULL) {
                fprintf(stderr, "Failed to open file '%s'\n", filename);
                exit(EXIT_FAILURE);
            }
            fseek(fp, index.offset, SEEK_SET);
            Person p;
            fread(&p, sizeof(Person), 1, fp);
            printf("Name: %s\nID: %s\nAge: %d\n", p.name, p.id, p.age);
            fclose(fp);
            fclose(index_fp);
            return;
        }
    }
    fprintf(stderr, "No record found for id '%s'\n", id);
    fclose(index_fp);
}

int main() {
    Person p1 = {"Alice", "12345", 25};
    Person p2 = {"Bob", "67890", 30};
    Person p3 = {"Charlie", "abcde", 20};
    Person p4 = {"David", "fghij", 22};
    Person p5 = {"Eve", "klmno", 27};
    Person p6 = {"Frank", "pqrst", 32};
    Person p7 = {"Grace", "uvwxy", 18};
    Person p8 = {"Henry", "zzzzz", 28};
    Person people[] = {p1, p2, p3, p4, p5, p6, p7, p8};
    const char *filename = "people.dat";
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    fwrite(people, sizeof(Person), 8, fp);
    fclose(fp);

    const char *index_filename = "people.idx";
    create_index(filename, index_filename);

    search(filename, index_filename, "12345");
    search(filename, index_filename, "67890");
    search(filename, index_filename, "zwxya");
    return 0;
}