//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE sizeof(struct DiaryEntry)

struct DiaryEntry {
    time_t timestamp;
    char description[256];
};

int main(void) {
    FILE *diary_file;
    size_t file_size;
    int num_entries = 0;

    diary_file = fopen("digital_diary.txt", "a");

    if (diary_file == NULL) {
        perror("Error opening diary file.");
        exit(EXIT_FAILURE);
    }

    while (num_entries < MAX_ENTRIES) {
        struct DiaryEntry *new_entry = malloc(ENTRY_SIZE);
        if (new_entry == NULL) {
            fprintf(stderr, "Error allocating memory for new diary entry.\n");
            exit(EXIT_FAILURE);
        }

        time(&new_entry->timestamp);
        fseek(diary_file, 0, SEEK_END);
        if (fwrite(new_entry, ENTRY_SIZE, 1, diary_file) != 1) {
            perror("Error writing to diary file.");
            free(new_entry);
            exit(EXIT_FAILURE);
        }

        printf("Entry #%d saved: %s\n", num_entries + 1, ctime(&new_entry->timestamp));
        fflush(stdout);

        printf("Enter your diary entry (up to 256 characters): ");
        fgets(new_entry->description, sizeof(new_entry->description), stdin);
        fseek(stdin, strlen(new_entry->description), SEEK_CUR);
        getchar(); // consume newline character

        file_size = ftell(diary_file);
        fseek(diary_file, file_size - ENTRY_SIZE, SEEK_SET);
        if (fwrite(new_entry->description, strlen(new_entry->description), 1, diary_file) != 1) {
            perror("Error writing to diary file.");
            free(new_entry);
            exit(EXIT_FAILURE);
        }

        free(new_entry);
        num_entries++;
    }

    printf("Maximum number of entries (%d) reached. Exiting...\n", MAX_ENTRIES);
    fclose(diary_file);

    return EXIT_SUCCESS;
}