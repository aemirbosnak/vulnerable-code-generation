//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_YEAR 3000
#define MIN_YEAR 1900

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char location[50];
    char purpose[100];
} TimeTravelRecord;

TimeTravelRecord records[100];
int record_count = 0;

void travelToFuture(int years) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    
    tm_now->tm_year += years;  // Move to future year
    mktime(tm_now);  // Normalize the structure

    printf("You have traveled to: %d-%02d-%02d\n", tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday);
}

void travelToPast(int years) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    tm_now->tm_year -= years;  // Move to past year
    mktime(tm_now);  // Normalize the structure

    printf("You have traveled to: %d-%02d-%02d\n", tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday);
}

void saveRecord(int year, int month, int day, const char *location, const char *purpose) {
    if (record_count >= 100) {
        printf("Record limit reached. Cannot save more records.\n");
        return;
    }

    records[record_count].date.year = year;
    records[record_count].date.month = month;
    records[record_count].date.day = day;
    strncpy(records[record_count].location, location, sizeof(records[record_count].location) - 1);
    strncpy(records[record_count].purpose, purpose, sizeof(records[record_count].purpose) - 1);
    record_count++;

    printf("Record saved for %d-%02d-%02d at %s for %s.\n", year, month, day, location, purpose);
}

void viewRecords() {
    printf("\nTime Travel Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d: %d-%02d-%02d at %s for %s\n", 
            i + 1, records[i].date.year, records[i].date.month, records[i].date.day,
            records[i].location, records[i].purpose);
    }
}

void printMenu() {
    printf("\nTime Travel Simulator Menu:\n");
    printf("1. Travel to the Future\n");
    printf("2. Travel to the Past\n");
    printf("3. Save Travel Record\n");
    printf("4. View Travel Records\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice, years;
    char location[50], purpose[100];

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter years to travel into the future: ");
                scanf("%d", &years);
                if (years < 0 || years + (localtime(&(time_t){time(NULL)})->tm_year + 1900) > MAX_YEAR) {
                    printf("Invalid year range.\n");
                } else {
                    travelToFuture(years);
                }
                break;

            case 2:
                printf("Enter years to travel into the past: ");
                scanf("%d", &years);
                if (years < 0 || (localtime(&(time_t){time(NULL)})->tm_year + 1900) - years < MIN_YEAR) {
                    printf("Invalid year range.\n");
                } else {
                    travelToPast(years);
                }
                break;

            case 3:
                printf("Enter travel date (YYYY MM DD): ");
                int year, month, day;
                scanf("%d %d %d", &year, &month, &day);
                if (year < MIN_YEAR || year > MAX_YEAR || month < 1 || month > 12 || day < 1 || day > 31) {
                    printf("Invalid date. Please enter a valid date.\n");
                } else {
                    printf("Enter location: ");
                    scanf("%s", location);
                    printf("Enter purpose: ");
                    scanf(" %[^\n]s", purpose);
                    saveRecord(year, month, day, location, purpose);
                }
                break;

            case 4:
                viewRecords();
                break;

            case 5:
                printf("Exiting Time Travel Simulator. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}