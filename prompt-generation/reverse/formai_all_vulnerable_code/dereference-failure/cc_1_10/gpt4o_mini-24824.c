//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <ifaddrs.h>

#define MAX_BUF_SIZE 1024
#define SIGNAL_STRENGTH_CMD "iwconfig 2>/dev/null | grep -i --color signal"

void clearScreen() {
    printf("\033[H\033[J");
}

void displaySignalStrength() {
    FILE *fp;
    char path[MAX_BUF_SIZE];
    
    fp = popen(SIGNAL_STRENGTH_CMD, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(1);
    }
    
    printf("Fetching Wi-Fi signal strength...\n");
    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("%s", path);
    }
    
    pclose(fp);
}

void displayMenu() {
    printf("=== Wi-Fi Signal Strength Analyzer ===\n");
    printf("1. Display Signal Strength\n");
    printf("2. Exit\n");
    printf("======================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        clearScreen();
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySignalStrength();
                printf("\nPress Enter to continue...");
                getchar(); // consume leftover newline
                getchar(); // wait for user to press enter
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                printf("Press Enter to continue...");
                getchar(); // consume leftover newline
                getchar(); // wait for user to press enter
        }
    }

    return 0;
}