//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    num_entries++;
    strcpy(entries[num_entries-1].date, date);
    strcpy(entries[num_entries-1].entry, entry);
}

void print_entries() {
    for(int i=0; i<num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    char* entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to the Digital Diary!\n");
    printf("Press enter to start.\n");
    getchar();

    while(num_entries < MAX_ENTRIES) {
        char date[20];
        sprintf(date, "%d-%02d-%02d", rand()%2021+2000, rand()%13+1, rand()%28+1);
        char* entry = malloc(MAX_ENTRY_LENGTH*sizeof(char));
        printf("Enter your thoughts for %s:\n", date);
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0';
        add_entry(date, entry);
        num_entries++;
        free(entry);
    }

    printf("Your diary is complete!\n");
    print_entries();

    return 0;
}