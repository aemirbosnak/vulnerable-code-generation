//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 10

struct DiaryEntry {
    char title[50];
    char content[100];
    time_t timestamp;
};

void save_entry(struct DiaryEntry *diary, int index) {
    diary[index].timestamp = time(NULL);
    printf("Enter Title for Entry %d: ", index + 1);
    fgets(diary[index].title, sizeof(diary[index].title), stdin);
    diary[index].title[strlen(diary[index].title) - 1] = '\0';
    printf("Enter Content for Entry %d: ", index + 1);
    fgets(diary[index].content, sizeof(diary[index].content), stdin);
    diary[index].content[strlen(diary[index].content) - 1] = '\0';
}

void load_entry(struct DiaryEntry *diary, int index) {
    printf("\nEntry %d:\n", index + 1);
    printf("Title: %s\n", diary[index].title);
    printf("Content: %s\n", diary[index].content);
    printf("Timestamp: %s\n", ctime(&diary[index].timestamp));
}

void print_menu() {
    printf("\nDigital Diary\n");
    printf("1. Save Entry\n");
    printf("2. Load Entry\n");
    printf("3. Exit\n");
}

int main() {
    struct DiaryEntry *diary = (struct DiaryEntry *) malloc(DIARY_SIZE * sizeof(struct DiaryEntry));
    int choice, index = -1;

    if (diary == NULL) {
        printf("Error: Unable to allocate memory\n");
        return 1;
    }

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (index >= DIARY_SIZE - 1) {
                    printf("Error: Diary is full\n");
                    break;
                }
                index++;
                save_entry(diary, index);
                break;
            case 2:
                if (index < 0) {
                    printf("Error: No entry to load\n");
                    break;
                }
                load_entry(diary, index);
                index--;
                break;
            case 3:
                free(diary);
                return 0;
            default:
                printf("Error: Invalid choice\n");
        }
    }

    free(diary);
    return 0;
}