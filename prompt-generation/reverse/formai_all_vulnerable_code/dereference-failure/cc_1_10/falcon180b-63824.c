//Falcon-180B DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid IP address
int isValidIP(char *ip) {
    int i, j;
    char *ptr;
    int parts = 0;

    ptr = strtok(ip, ".");
    while (ptr!= NULL) {
        parts++;
        for (i = 0; i < strlen(ptr); i++) {
            if (!isdigit(ptr[i])) {
                return 0;
            }
        }
        ptr = strtok(NULL, ".");
    }

    if (parts!= 4) {
        return 0;
    }

    return 1;
}

// Function to check if a string is a valid port number
int isValidPort(char *port) {
    int i;

    for (i = 0; i < strlen(port); i++) {
        if (!isdigit(port[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to print usage instructions
void printUsage() {
    printf("Usage: firewall [allow|deny] [IP address] [port number]\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printUsage();
        exit(1);
    }

    if (strcmp(argv[1], "allow")!= 0 && strcmp(argv[1], "deny")!= 0) {
        printf("Invalid action specified. Please use 'allow' or 'deny'.\n");
        exit(1);
    }

    if (!isValidIP(argv[2])) {
        printf("Invalid IP address specified.\n");
        exit(1);
    }

    if (!isValidPort(argv[3])) {
        printf("Invalid port number specified.\n");
        exit(1);
    }

    printf("Firewall rule added: %s %s traffic from IP address %s on port %s.\n", argv[1], argv[1], argv[2], argv[3]);

    return 0;
}