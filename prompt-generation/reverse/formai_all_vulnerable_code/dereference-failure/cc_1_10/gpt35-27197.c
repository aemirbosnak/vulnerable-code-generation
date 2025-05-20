//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    time_t timestamp;
    char* content;
} DiaryEntry;

int num_entries = 0;
DiaryEntry entries[MAX_ENTRIES];

void write_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, your diary is full.\n");
        return;
    }

    char* content = (char*)malloc(256 * sizeof(char));
    printf("Write your entry (max 256 characters):\n");
    fgets(content, 256, stdin);

    DiaryEntry entry;
    entry.timestamp = time(NULL);
    entry.content = content;
    entries[num_entries++] = entry;

    printf("Entry saved!\n\n");
}

void read_entries() {
    printf("Your diary:\n");
    for (int i = 0; i < num_entries; i++) {
        DiaryEntry entry = entries[i];
        char* time_str = ctime(&entry.timestamp);
        time_str[strlen(time_str)-1] = '\0'; // remove newline at the end
        printf("[%s] %s\n", time_str, entry.content);
    }
    printf("\n");
}

int main() {
    printf("Welcome to My Digital Diary!\n");

    while (1) {
        printf("What would you like to do? (write/read/exit)\n");
        char choice[10];
        fgets(choice, 10, stdin);

        if (strcmp(choice, "write\n") == 0) {
            write_entry();
        } else if (strcmp(choice, "read\n") == 0) {
            read_entries();
        } else if (strcmp(choice, "exit\n") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}