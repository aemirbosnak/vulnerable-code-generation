//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char text[ENTRY_LENGTH];
};

FILE *diary_file = NULL;

void init_diary() {
    diary_file = fopen("diary.txt", "a+");
    if (diary_file == NULL) {
        printf("Error: Failed to open diary file.\n");
        exit(1);
    }
}

void close_diary() {
    fclose(diary_file);
}

void write_entry(const char *text) {
    struct entry entry = { time(NULL), text };
    if (fwrite(&entry, sizeof(entry), 1, diary_file)!= 1) {
        printf("Error: Failed to write entry to diary file.\n");
        exit(1);
    }
}

void print_entries() {
    rewind(diary_file);
    struct entry entry;
    while (fread(&entry, sizeof(entry), 1, diary_file) == 1) {
        printf("%s\n", ctime(&entry.timestamp));
        printf("%s\n", entry.text);
        printf("\n");
    }
}

int main() {
    init_diary();

    char input[ENTRY_LENGTH];
    while (fgets(input, ENTRY_LENGTH, stdin)!= NULL) {
        write_entry(input);
    }

    close_diary();
    print_entries();

    return 0;
}