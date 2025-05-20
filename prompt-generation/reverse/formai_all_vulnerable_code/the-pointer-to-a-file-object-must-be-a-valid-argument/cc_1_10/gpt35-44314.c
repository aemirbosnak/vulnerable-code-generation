//FormAI DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Entry {
    char title[100];
    char content[1000];
    char date[20];
    int id;
};

void save_entry(struct Entry entry) {
    FILE *file_pointer;
    file_pointer = fopen("digital_diary.txt", "a");
    fprintf(file_pointer, "%d,%s,%s,%s\n", entry.id, entry.title, entry.content, entry.date);
    fclose(file_pointer);
}

void view_all_entries() {
    FILE *file_pointer;
    char input[1000];
    file_pointer = fopen("digital_diary.txt", "r");
    while(fgets(input, 1000, file_pointer) != NULL) {
        printf("%s", input);
    }
    fclose(file_pointer);
}

void view_entry(int id) {
    FILE *file_pointer;
    char input[1000], *entry_id, *title, *content, *date;
    file_pointer = fopen("digital_diary.txt", "r");
    while(fgets(input, 1000, file_pointer) != NULL) {
        entry_id = strtok(input, ",");
        if(atoi(entry_id) == id) {
            title = strtok(NULL, ",");
            printf("Title: %s\n", title);
            content = strtok(NULL, ",");
            printf("Content: %s\n", content);
            date = strtok(NULL, ",");
            printf("Date: %s\n", date);
            break;
        }
    }
    fclose(file_pointer);
}

int main() {
    int choice, id = 1;
    char title[100], content[1000], date[20];
    time_t now;

    struct tm *local_time;
    time(&now);
    local_time = localtime(&now);
    strftime(date, 20, "%m/%d/%Y", local_time);

    printf("Welcome to Your Digital Diary!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. View a specific entry\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the title of your entry: ");
                getchar();
                fgets(title, 100, stdin);
                printf("Enter the content of your entry: ");
                fgets(content, 1000, stdin);

                struct Entry entry;
                entry.id = id;
                strcpy(entry.title, title);
                strcpy(entry.content, content);
                strcpy(entry.date, date);

                save_entry(entry);
                id++;
                break;

            case 2:
                view_all_entries();
                break;

            case 3:
                printf("Enter the id of the entry you want to view: ");
                scanf("%d", &id);
                view_entry(id);
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }

    }
    return 0;
}