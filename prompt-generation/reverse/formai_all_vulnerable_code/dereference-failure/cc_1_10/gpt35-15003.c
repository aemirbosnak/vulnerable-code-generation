//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct virus {
    char name[32];
    unsigned int size;
    char signature[16];
} virus;

void scan_file(FILE *fp, virus *db, int db_size) {
    char buffer[1024];
    int found = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        for (int i = 0; i < db_size; i++) {
            virus *v = db + i;
            if (strstr(buffer, v->signature) != NULL) {
                found = 1;
                printf("Virus found: %s\n", v->name);
                break;
            }
        }
        if (found) {
            found = 0;
            break;
        }
    }
}

void load_database(virus **db, int *db_size) {
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Failed to open database file\n");
        exit(EXIT_FAILURE);
    }
    int size;
    if (fscanf(fp, "%d", &size) != 1) {
        printf("Failed to read database size\n");
        exit(EXIT_FAILURE);
    }
    *db = malloc(sizeof(virus) * size);
    if (*db == NULL) {
        printf("Failed to allocate database memory\n");
        exit(EXIT_FAILURE);
    }
    *db_size = size;
    for (int i = 0; i < size; i++) {
        virus *v = *db + i;
        if (fscanf(fp, "%s %u %s", v->name, &v->size, v->signature) != 3) {
            printf("Failed to read database entry %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
    fclose(fp);
}

int main() {
    virus *db = NULL;
    int db_size = 0;
    load_database(&db, &db_size);
    while (1) {
        printf("Enter filename to scan (or quit): ");
        char filename[1024];
        fgets(filename, sizeof(filename), stdin);
        if (strncmp(filename, "quit", 4) == 0) {
            break;
        }
        filename[strcspn(filename, "\n")] = '\0';
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Failed to open file\n");
            continue;
        }
        scan_file(fp, db, db_size);
        fclose(fp);
    }
    free(db);
    return 0;
}