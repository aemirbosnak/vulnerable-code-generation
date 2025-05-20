//FormAI DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entry {
    char date[20];
    char title[50];
    char content[500];
} myDiary[365];

int main() {
    int choice;
    int entryNum = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to your Digital Diary!\n\n");

    do {
        printf("Select an option:\n");
        printf("1. Create a new entry\n");
        printf("2. View existing entry\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nNew Entry:\n\n");
                printf("Date (MM/DD/YYYY): ");
                scanf("%s", myDiary[entryNum].date);
                printf("Title: ");
                scanf("%s", myDiary[entryNum].title);
                printf("Content:\n");
                scanf("%s", myDiary[entryNum].content);
                printf("\nEntry added!\n\n");
                entryNum++;
                break;
            case 2:
                printf("\nView Entry:\n\n");
                printf("Enter date to view (MM/DD/YYYY): ");
                char searchDate[20];
                scanf("%s", searchDate);
                int i;
                for(i=0;i<entryNum;i++) {
                    if(strcmp(myDiary[i].date, searchDate) == 0) {
                        printf("Date: %s\n", myDiary[i].date);
                        printf("Title: %s\n", myDiary[i].title);
                        printf("Content:\n%s\n", myDiary[i].content);
                        break;
                    }
                }
                if(i == entryNum) {
                    printf("\nNo entry found for that date.\n\n");
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n\n");
                break;
        }
    } while(choice != 3);

    return 0;
}