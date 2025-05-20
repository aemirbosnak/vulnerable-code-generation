//FormAI DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
    char* date;
    char* content;
};

void add_entry(struct entry *diary, int *num_of_entries) {
    char date[50], content[1000];
    time_t t = time(NULL);
    struct tm *timeptr = localtime(&t);

    printf("\nEnter today's date (MM/DD/YYYY): ");
    scanf("%s", date);

    printf("Enter your diary entry:\n");
    getchar();
    fgets(content, 1000, stdin);

    diary[*num_of_entries].date = malloc(strlen(date)+1);
    strcpy(diary[*num_of_entries].date, date);
    diary[*num_of_entries].content = malloc(strlen(content)+1);
    strcpy(diary[*num_of_entries].content, content);

    printf("\nEntry added to your digital diary!\n");
    (*num_of_entries)++;
}

void view_entries(struct entry *diary, int num_of_entries) {
    if (num_of_entries == 0) {
        printf("\nYour digital diary is empty!\n");
        return;
    }

    printf("\n==========================\n");
    for (int i=0; i<num_of_entries; i++) {
        printf("%s\n", diary[i].date);
        printf("--------------------------\n");
        printf("%s", diary[i].content);
        printf("==========================\n");
    }
}

void delete_entry(struct entry *diary, int *num_of_entries) {
    char date[50], ans;

    printf("\nEnter the date of the entry you want to delete (MM/DD/YYYY): ");
    scanf("%s", date);

    for (int i=0; i<*num_of_entries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("\nAre you sure you want to delete this entry? (Y/N)\n");
            printf("--------------------------\n");
            printf("%s\n", diary[i].date);
            printf("--------------------------\n");
            printf("%s", diary[i].content);
            printf("==========================\n");
            scanf(" %c", &ans);

            if (ans == 'Y' || ans == 'y') {
                free(diary[i].date);
                free(diary[i].content);
                for (int j=i; j<(*num_of_entries)-1; j++) {
                    diary[j] = diary[j+1];
                }
                (*num_of_entries)--;
                printf("\nEntry deleted from your digital diary!\n");
            }

            return;
        }
    }

    printf("\nNo entries found on this date.\n");
}

int main() {
    struct entry diary[100];
    int num_of_entries = 0;
    int option;

    printf("Welcome to your digital diary!");
    while (1) {
        printf("\n\nWhat would you like to do today?");
        printf("\n1. Add a new diary entry");
        printf("\n2. View all diary entries");
        printf("\n3. Delete an entry");
        printf("\n4. Quit\n");
        printf("--------------------------\n");

        scanf("%d", &option);
        switch (option) {
            case 1:
                add_entry(diary, &num_of_entries);
                break;
            case 2:
                view_entries(diary, num_of_entries);
                break;
            case 3:
                delete_entry(diary, &num_of_entries);
                break;
            case 4:
                printf("\nThank you for using your digital diary!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }
    return 0;
}