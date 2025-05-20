//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 1024

struct entry {
    time_t timestamp;
    char text[ENTRY_LENGTH];
};

void write_entry(FILE *file, const char *text) {
    struct entry entry = {time(NULL), text};
    fwrite(&entry, sizeof(entry), 1, file);
}

void read_entries(FILE *file, void (*callback)(const char *)) {
    struct entry entry;
    while (fread(&entry, sizeof(entry), 1, file) == 1) {
        callback(entry.text);
    }
}

int main() {
    char filename[32] = "diary.dat";
    FILE *file = fopen(filename, "a+");

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    srand(time(NULL));
    int choice = rand() % 4;

    switch (choice) {
        case 0:
            printf("Welcome to your Digital Diary.\n");
            break;
        case 1:
            printf("What's on your mind today?\n");
            char input[ENTRY_LENGTH];
            fgets(input, ENTRY_LENGTH, stdin);
            write_entry(file, input);
            printf("Entry saved.\n");
            break;
        case 2:
            printf("Let's reminisce about the past...\n");
            read_entries(file, printf);
            break;
        case 3:
            printf("It's time to say goodbye.\n");
            fclose(file);
            remove(filename);
            printf("Your diary has been deleted.\n");
            break;
    }

    return 0;
}