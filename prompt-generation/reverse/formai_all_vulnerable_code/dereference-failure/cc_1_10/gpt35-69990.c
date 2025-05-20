//FormAI DATASET v1.0 Category: Firewall ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 15
#define BLOCKED_IP_LIMIT 1000

// Structure for storing a blocked IP address
struct BlockedIP {
    char ipAddress[MAX_IP_LENGTH + 1];
};

// Function to check if an IP address is valid
bool isValidIP(char *ipAddress) {
    int num, dots = 0;
    char *ptr;

    if (ipAddress == NULL || strlen(ipAddress) > MAX_IP_LENGTH) {
        return false;
    }

    ptr = strtok(ipAddress, ".");
    if (ptr == NULL) {
        return false;
    }

    while (ptr) {
        if (!isdigit(*ptr) || (num = atoi(ptr)) < 0 || num > 255) {
            return false;
        }
        dots++;
        ptr = strtok(NULL, ".");
    }

    if (dots != 4) {
        return false;
    }

    return true;
}

// Function to block an IP address
void blockIP(struct BlockedIP *blockedIPs, int *blockedIPCount, char *ipAddress) {
    if (*blockedIPCount >= BLOCKED_IP_LIMIT) {
        printf("Maximum number of blocked IPs reached.\n");
        return;
    }

    if (!isValidIP(ipAddress)) {
        printf("Invalid IP address. IP address must be in the format xxx.xxx.xxx.xxx where xxx is a number between 0 and 255.\n");
        return;
    }

    for (int i = 0; i < *blockedIPCount; i++) {
        if (strcmp(blockedIPs[i].ipAddress, ipAddress) == 0) {
            printf("IP address %s is already blocked.\n", ipAddress);
            return;
        }
    }

    struct BlockedIP blockedIP;
    strcpy(blockedIP.ipAddress, ipAddress);
    blockedIPs[*blockedIPCount] = blockedIP;
    (*blockedIPCount)++;
}

// Function to unblock an IP address
void unblockIP(struct BlockedIP *blockedIPs, int *blockedIPCount, char *ipAddress) {
    if (!isValidIP(ipAddress)) {
        printf("Invalid IP address. IP address must be in the format xxx.xxx.xxx.xxx where xxx is a number between 0 and 255.\n");
        return;
    }

    bool found = false;
    for (int i = 0; i < *blockedIPCount; i++) {
        if (strcmp(blockedIPs[i].ipAddress, ipAddress) == 0) {
            found = true;
            for (int j = i; j < *blockedIPCount - 1; j++) {
                blockedIPs[j] = blockedIPs[j + 1];
            }
            (*blockedIPCount)--;
            break;
        }
    }

    if (!found) {
        printf("IP address %s is not blocked.\n", ipAddress);
    }
}

// Function to check if an IP address is blocked
bool isBlocked(struct BlockedIP *blockedIPs, int blockedIPCount, char *ipAddress) {
    if (!isValidIP(ipAddress)) {
        printf("Invalid IP address. IP address must be in the format xxx.xxx.xxx.xxx where xxx is a number between 0 and 255.\n");
        return false;
    }

    for (int i = 0; i < blockedIPCount; i++) {
        if (strcmp(blockedIPs[i].ipAddress, ipAddress) == 0) {
            return true;
        }
    }

    return false;
}

// Function to run the firewall program
void runFirewall() {
    struct BlockedIP blockedIPs[BLOCKED_IP_LIMIT];
    int blockedIPCount = 0;

    char input[100];
    char *command, *ipAddress;

    printf("Welcome to the Firewall program!\n");
    printf("Enter 'help' for a list of commands.\n");

    while (true) {
        printf("\nEnter command: ");
        fgets(input, 100, stdin);

        command = strtok(input, " \n");

        if (strcmp(command, "block") == 0) {
            ipAddress = strtok(NULL, " \n");
            if (ipAddress == NULL) {
                printf("IP address is missing.\n");
            } else {
                blockIP(blockedIPs, &blockedIPCount, ipAddress);
            }
        } else if (strcmp(command, "unblock") == 0) {
            ipAddress = strtok(NULL, " \n");
            if (ipAddress == NULL) {
                printf("IP address is missing.\n");
            } else {
                unblockIP(blockedIPs, &blockedIPCount, ipAddress);
            }
        } else if (strcmp(command, "isblocked") == 0) {
            ipAddress = strtok(NULL, " \n");
            if (ipAddress == NULL) {
                printf("IP address is missing.\n");
            } else {
                bool blocked = isBlocked(blockedIPs, blockedIPCount, ipAddress);
                printf("IP address %s is %sblocked.\n", ipAddress, blocked ? "" : "not ");
            }
        } else if (strcmp(command, "help") == 0) {
            printf("Commands:\n");
            printf("  block <IP address>  - block an IP address\n");
            printf("  unblock <IP address> - unblock an IP address\n");
            printf("  isblocked <IP address> - check if an IP address is blocked\n");
            printf("  help - display this help message\n");
            printf("  exit - exit the program\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            return;
        } else {
            printf("Invalid command. Enter 'help' for a list of commands.\n");
        }
    }
}

int main() {
    runFirewall();
    return 0;
}