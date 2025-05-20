//FormAI DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    Date date;
    char *entry;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

int compare_dates(Date date1, Date date2) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        return 0;
    } else if (date1.year < date2.year || (date1.year == date2.year && date1.month < date2.month) || 
        (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)) {
        return -1;
    } else {
        return 1;
    }
}

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Diary is full. Cannot add any more entries.\n");
        return;
    }

    Entry e;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &e.date.day, &e.date.month, &e.date.year);

    printf("Enter entry:\n");
    getchar();
    e.entry = (char*) malloc(sizeof(char) * 1000);
    fgets(e.entry, 1000, stdin);

    if (num_entries == 0) {
        entries[0] = e;
        num_entries++;
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        if (compare_dates(e.date, entries[i].date) == 0) {
            printf("An entry for this date already exists. Do you want to replace it? (y/n)");
            char choice = getchar();

            if (choice == 'y') {
                entries[i] = e;
                printf("Entry updated.\n");
                return;
            } else {
                printf("Entry not added.\n");
                return;
            }
        } else if (compare_dates(e.date, entries[i].date) < 0) {
            for (int j = num_entries-1; j >= i; j--) {
                entries[j+1] = entries[j];
            }

            entries[i] = e;
            num_entries++;
            printf("Entry added.\n");
            return;
        }
    }

    entries[num_entries] = e;
    num_entries++;
    printf("Entry added.\n");
}

void edit_entry() {
    if (num_entries == 0) {
        printf("No entries to edit.\n");
        return;
    }

    Date date;

    printf("Enter date of entry to edit (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date.day, &date.month, &date.year);

    for (int i = 0; i < num_entries; i++) {
        if (compare_dates(date, entries[i].date) == 0) {
            printf("---\n%s\n---\n", entries[i].entry);

            printf("Enter new entry:\n");
            getchar();
            fgets(entries[i].entry, 1000, stdin);

            printf("Entry updated.\n");
            return;
        }
    }

    printf("No entry found for this date.\n");
}

void delete_entry() {
    if (num_entries == 0) {
        printf("No entries to delete.\n");
        return;
    }

    Date date;

    printf("Enter date of entry to delete (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date.day, &date.month, &date.year);

    for (int i = 0; i < num_entries; i++) {
        if (compare_dates(date, entries[i].date) == 0) {
            for (int j = i; j < num_entries-1; j++) {
                entries[j] = entries[j+1];
            }

            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("No entry found for this date.\n");
}

void list_entries() {
    if (num_entries == 0) {
        printf("No entries to display.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%d/%d/%d: %s\n", entries[i].date.day, entries[i].date.month, entries[i].date.year, entries[i].entry);
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf("No entries to search.\n");
        return;
    }

    char query[1000];

    printf("Enter search query: ");
    getchar();
    fgets(query, 1000, stdin);

    printf("Search results:\n");

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, query) != NULL) {
            printf("%d/%d/%d: %s\n", entries[i].date.day, entries[i].date.month, entries[i].date.year, entries[i].entry);
        }
    }
}

void display_menu() {
    printf("\nDigital Diary\n");
    printf("===============\n");
    printf("1. Add new entry\n");
    printf("2. Edit existing entry\n");
    printf("3. Delete existing entry\n");
    printf("4. List all entries\n");
    printf("5. Search entries\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                edit_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                list_entries();
                break;
            case 5:
                search_entries();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}