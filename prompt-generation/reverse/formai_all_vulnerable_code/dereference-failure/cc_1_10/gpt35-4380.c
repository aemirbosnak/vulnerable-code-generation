//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct note { // structure to represent a diary note
    char date[11]; // date in dd/mm/yyyy format
    char content[250]; // diary content
};

int main() {
    struct note diary[365]; // diary for a year with 365 days
    int current_day = 0; // current day index
    char choice = ' '; // user's menu choice
    time_t t = time(NULL); // Get current time
    struct tm tm = *localtime(&t); // Convert time to local time
    sprintf(diary[current_day].date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900); // Save current date to the diary

    while (1) { // loop until user enters 'x'
        printf("**************************************************************\n");
        printf("***                     C Digital Diary                    ***\n");
        printf("***                                                          ***\n");
        printf("*** Current date: %s                             ***\n", diary[current_day].date);
        printf("***                                                          ***\n");
        printf("*** 1- View diary notes                                      ***\n");
        printf("*** 2- Add a new diary note                                  ***\n");
        printf("*** x- Exit                                                  ***\n");
        printf("**************************************************************\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': // View diary notes
                printf("**************************************************************\n");
                printf("***                    View Diary Notes                     ***\n");
                printf("***                                                          ***\n");
                for (int i = 0; i <= current_day; i++) {
                    printf("*** %s - %s\n", diary[i].date, diary[i].content);
                }
                printf("***                                                          ***\n");
                printf("**************************************************************\n");
                break;
            case '2': // Add a new diary note
                current_day++;
                printf("Enter your diary note: ");
                scanf(" %[^\n]s", diary[current_day].content);
                sprintf(diary[current_day].date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
                printf("Diary note added successfully!\n");
                break;
            case 'x': // Exit
                printf("Goodbye!\n");
                exit(1);
            default: // Invalid choice
                printf("Invalid choice! Please enter a number from 1 to 2 or x to exit.\n");
                break;
        }
    }
    return 0;
}