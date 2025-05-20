//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to get OS name
void get_os_name(char *os_name) {
    FILE *file = fopen("/etc/os-release", "r");
    char buffer[256];

    while (fgets(buffer, 256, file) != NULL) {
        if (strstr(buffer, "PRETTY_NAME")) {
            char *start = strchr(buffer, '=');
            strcpy(os_name, start + 1);
            os_name[strlen(os_name)-1] = '\0';
            break;
        }
    }

    fclose(file);
}

int main() {
    // Declare variables
    char os_name[100];
    int option;

    // Get OS name
    get_os_name(os_name);

    // Display menu options
    printf("Welcome to the %s System Administration Program!\n", os_name);
    printf("Please select an option:\n");
    printf("1. View system information\n");
    printf("2. Manage users\n");
    printf("3. Manage services\n");
    printf("4. Manage packages\n");
    printf("5. Exit\n");

    // Get user option
    scanf("%d", &option);

    // Perform action based on user option
    switch(option) {
        case 1:
            system("uname -a");
            break;
        case 2:
            system("sudo useradd -m -s /bin/bash newuser");
            printf("User created successfully!\n");
            break;
        case 3:
            system("sudo service nginx restart");
            printf("Nginx service restarted successfully!\n");
            break;
        case 4:
            system("sudo apt-get update && sudo apt-get upgrade");
            printf("Packages updated successfully!\n");
            break;
        case 5:
            printf("Exiting program...\n");
            sleep(2);
            exit(0);
        default:
            printf("Invalid option selected. Please try again.\n");
    }

    return 0;
}