//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct Entry {
    time_t timestamp;
    char message[500];
};

int main() {
    FILE *diary_file;
    struct Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    diary_file = fopen("diary.txt", "r");

    if (diary_file == NULL) {
        printf("Diary file does not exist. Creating new file...\n");
        diary_file = fopen("diary.txt", "w");
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("--------------------\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Maximum number of entries reached. Cannot write new entry.\n");
                } else {
                    printf("Enter your message: ");
                    fgets(entries[num_entries].message, 500, stdin);
                    time_t now = time(NULL);
                    entries[num_entries].timestamp = now;
                    fprintf(diary_file, "%s - %s", ctime(&entries[num_entries].timestamp), entries[num_entries].message);
                    num_entries++;
                    printf("Entry saved.\n");
                }
                break;

            case '2':
                rewind(diary_file);
                while (fgets(entries[num_entries].message, 500, diary_file)!= NULL) {
                    printf("%s", entries[num_entries].message);
                    num_entries++;
                }
                break;

            case '3':
                fclose(diary_file);
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}