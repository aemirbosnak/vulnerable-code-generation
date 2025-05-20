//FormAI DATASET v1.0 Category: Digital Diary ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Entry{
    char date[20];
    char content[100];
};

struct Entry diary[365];  // Assuming a diary with 365 entries

int entry_count=0;  // To keep track of number of entries in the diary

void add_entry(){
    printf("\n----- Add Entry -----\n");

    if(entry_count == 365){  // Diary is already full
        printf("Oops, your diary is full. Cannot add any more entries.");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    sprintf(diary[entry_count].date, "%d-%d-%d", t->tm_mday, t->tm_mon+1, t->tm_year+1900);

    printf("Enter your entry for the day: ");
    fgets(diary[entry_count].content, 100, stdin);

    printf("\nEntry added successfully!\n");

    entry_count++;
}

void view_entry(){
    printf("\n----- View Entry -----\n");

    if(entry_count == 0){
        printf("Your diary is empty. No entries to view.\n");
        return;
    }

    printf("Enter the date of the entry you want to view (dd-mm-yyyy): ");
    char date_to_view[20];
    fgets(date_to_view, 20, stdin);

    int i;
    int entry_found = 0;
    for(i=0; i<entry_count; i++){
        if(strcmp(diary[i].date, date_to_view) == 0){
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].content);
            entry_found = 1;
            break;
        }
    }

    if(!entry_found){
        printf("No entry was found for the given date.\n");
    }
}

void view_all_entries(){
    printf("\n----- View All Entries -----\n");

    if(entry_count == 0){
        printf("Your diary is empty. No entries to view.\n");
        return;
    }

    printf("Total entries in your diary: %d\n\n", entry_count);

    int i;
    for(i=0; i<entry_count; i++){
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].content);
    }
}

void menu(){
    printf("---------- My Digital Diary ----------\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. View All Entries\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main(){
    int choice;

    while(1){
        menu();

        char user_input[20];
        fgets(user_input, 20, stdin);

        choice = atoi(user_input);

        switch(choice){
            case 1: add_entry(); break;
            case 2: view_entry(); break;
            case 3: view_all_entries(); break;
            case 4: printf("Thanks for using the digital diary. Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}