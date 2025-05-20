//FormAI DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
    char date[20];
    char title[100];
    char content[500];
};

int main() {
    int choice, num_entries = 0;
    struct entry *entries = NULL;
    struct tm *time_info;
    time_t current_time;
    char date_str[20];

    while(1) {
        printf("\nWelcome to My Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add Entry
                printf("\nEnter Date (yyyy-mm-dd): ");
                scanf("%s", date_str);
                printf("Enter Title: ");
                char c;
                scanf("%c", &c);
                fgets(entries[num_entries].title, 100, stdin);
                printf("Enter Content: ");
                fgets(entries[num_entries].content, 500, stdin);
                
                strcpy(entries[num_entries].date, date_str);
                num_entries++;
                entries = (struct entry*) realloc(entries, (num_entries + 1) * sizeof(struct entry));
                
                // Get current time and date for add entry confirmation message
                time(&current_time);
                time_info = localtime(&current_time);
                strftime(date_str, sizeof(date_str), "%Y-%m-%d", time_info);

                printf("\nEntry added on %s\n", date_str);
                break;

            case 2: // View Entries
                if(num_entries == 0) {
                    printf("\nYou have no entries to view!\n");
                    break;
                }
                printf("\n");
                for(int i = 0; i < num_entries; i++) {
                    printf("Entry %d\nDate: %s\nTitle: %sContent: %s\n", i+1, entries[i].date, entries[i].title, entries[i].content);
                }
                break;

            case 3: // Quit
                free(entries);
                printf("\nThanks for using My Digital Diary!\n");
                return 0;

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
}