//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_INTERFACES 10
#define MAX_BUFFER 1024

void clear_screen() {
    printf("\033[H\033[J");
}

void print_divider() {
    printf("\n=============================================\n");
}

void get_signal_strength(const char *interface) {
    char command[MAX_BUFFER];
    char buffer[MAX_BUFFER];
    FILE *fp;

    printf("Fetching signal strength for interface: %s\n", interface);
    // Preparing command to retrieve the signal strength using `iwconfig`
    snprintf(command, sizeof(command), "iwconfig %s | grep 'Signal level'", interface);
    
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        return;
    }

    int found = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        found = 1;
        printf("Signal Strength Info: %s", buffer);
    }

    if (!found) {
        printf("No signal strength info found for %s.\n", interface);
    }

    pclose(fp);
}

void list_wifi_interfaces() {
    printf("Scanning available Wi-Fi interfaces...\n");
    char *interfaces[MAX_INTERFACES];
    char buffer[MAX_BUFFER];
    FILE *fp = popen("iw dev | grep Interface", "r");
    
    if (fp == NULL) {
        fprintf(stderr, "Error fetching interfaces: %s\n", strerror(errno));
        return;
    }

    int i = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && i < MAX_INTERFACES) {
        strtok(buffer, "\n"); // Remove new line character
        interfaces[i] = strdup(buffer + 9); // Extract the interface name (skip "Interface ")
        i++;
    }

    pclose(fp);

    printf("Found %d Wi-Fi interfaces:\n", i);
    for (int j = 0; j < i; j++) {
        printf(" - %s\n", interfaces[j]);
    }

    // Analyze signal strength for each interface
    for (int j = 0; j < i; j++) {
        get_signal_strength(interfaces[j]);
        free(interfaces[j]); // Deallocate memory
    }
}

int main() {
    clear_screen();
    print_divider();
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    print_divider();

    list_wifi_interfaces();
    
    print_divider();
    printf("Thank you for using the analyzer. Have a great day!\n");
    print_divider();
    
    return 0;
}