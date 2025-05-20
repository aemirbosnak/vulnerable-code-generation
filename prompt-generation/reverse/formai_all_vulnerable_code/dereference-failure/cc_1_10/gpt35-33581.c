//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct diary_entry {
    int day;
    int month;
    int year;
    char *content;
} DiaryEntry;

void print_menu() {
    printf("===============================\n");
    printf("      Digital Diary Menu\n");
    printf("===============================\n");
    printf("1) Add Entry\n");
    printf("2) View All Entries\n");
    printf("3) Delete Entry\n");
    printf("4) Search Entries by Date\n");
    printf("5) Quit\n");
}

void shift_case(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    while(1) {
        print_menu();
        printf("Enter an option: ");
        int option;
        scanf("%d", &option);
        getchar(); // remove \n from buffer

        switch(option) {
            case 1: { // Add Entry
                printf("\nEnter date in format DD/MM/YYYY: ");
                char date_string[11];
                fgets(date_string, 11, stdin);

                printf("\nEnter diary entry content:\n");
                char *content = malloc(1000);
                fgets(content, 1000, stdin);
                shift_case(content);

                DiaryEntry new_entry;
                sscanf(date_string, "%d/%d/%d", &new_entry.day, &new_entry.month, &new_entry.year);
                new_entry.content = content;

                entries[num_entries++] = new_entry;
                printf("\nEntry added to diary!\n");

                break;
            }
            case 2: { // View All Entries
                if(num_entries == 0) {
                    printf("\nNo entries found. Add an entry first.\n");
                } else {
                    printf("\nAll entries in diary:\n\n");
                    for(int i = 0; i < num_entries; i++) {
                        DiaryEntry entry = entries[i];
                        printf("%d/%d/%d - %s\n\n", entry.day, entry.month, entry.year, entry.content);
                    }
                }

                break;
            }
            case 3: { // Delete Entry
                if(num_entries == 0) {
                    printf("\nNo entries found. Add an entry first.\n");
                } else {
                    printf("\nEnter date in format DD/MM/YYYY of entry to delete: ");
                    char date_string[11];
                    fgets(date_string, 11, stdin);

                    int entry_index = -1;
                    for(int i = 0; i < num_entries; i++) {
                        DiaryEntry entry = entries[i];
                        if(strcmp(date_string, 
                            sprintf("%d/%d/%d", entry.day, entry.month, entry.year)) == 0) {
                            entry_index = i;
                            break;
                        }
                    }

                    if(entry_index == -1) {
                        printf("\nEntry not found.\n");
                    } else {
                        DiaryEntry entry_to_delete = entries[entry_index];
                        free(entry_to_delete.content);

                        for(int i = entry_index+1; i < num_entries; i++) {
                            entries[i-1] = entries[i];
                        }

                        num_entries--;

                        printf("\nEntry deleted.\n");
                    }
                }

                break;
            }
            case 4: { // Search Entries by Date
                if(num_entries == 0) {
                    printf("\nNo entries found. Add an entry first.\n");
                } else {
                    printf("\nEnter date in format DD/MM/YYYY to search for: ");
                    char date_string[11];
                    fgets(date_string, 11, stdin);

                    int entries_found = 0;
                    for(int i = 0; i < num_entries; i++) {
                        DiaryEntry entry = entries[i];
                        if(strcmp(date_string, 
                            sprintf("%d/%d/%d", entry.day, entry.month, entry.year)) == 0) {
                            printf("\nEntry for %s:\n%s\n", date_string, entry.content);
                            entries_found = 1;
                            break;
                        }
                    }

                    if(!entries_found) {
                        printf("\nEntry not found.\n");
                    }
                }

                break;
            }
            case 5: { // Quit
                return 0;
            }
            default: {
                printf("\nInvalid option. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}