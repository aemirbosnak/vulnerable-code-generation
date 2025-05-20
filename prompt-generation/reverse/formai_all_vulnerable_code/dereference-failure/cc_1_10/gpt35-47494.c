//FormAI DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given IP address is valid
int isValidIpAddress(char *ipAddress)
{
    int num, dots = 0;
    char *ptr;

    if (ipAddress == NULL)
        return 0;

    ptr = strtok(ipAddress, ".");
    if (ptr == NULL)
        return 0;

    while (ptr) {
        if (!isNumeric(ptr))
            return 0;

        num = atoi(ptr);

        // check if the number is between 0 and 255
        if (num >= 0 && num <= 255) {
            // move to the next octet
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                dots++;
        } 
        else
            return 0;
    }

    // there should be exactly 3 dots in the IP address
    if (dots != 3)
        return 0;

    return 1;
}

// Function to check if a given port number is valid
int isValidPort(char *port)
{
    int num;

    if (port == NULL)
        return 0;

    if (!isNumeric(port))
        return 0;

    num = atoi(port);

    // check if the number is between 1 and 65535
    if (num >= 1 && num <= 65535)
        return 1;

    return 0;
}

// Function to check if a given input string is numeric
int isNumeric(char *str)
{
    int i;

    for (i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return 0;

    return 1;
}

// Function to block an IP address and a port number
void blockIpAndPort(char *ipAddress, char *port)
{
    // Block the IP address and port
    printf("Blocked %s:%s\n", ipAddress, port);
}

int main()
{
    char input[256];
    char *ptr;
    char *ipAddress;
    char *port;

    printf("Enter IP address and port number to block (e.g., 127.0.0.1:8080): ");
    fgets(input, 256, stdin);

    // Remove the newline character at the end of the input
    input[strcspn(input, "\n")] = 0;

    // Tokenize the input string using colon as the delimiter
    ptr = strtok(input, ":");
    if (ptr != NULL)
        ipAddress = ptr;

    ptr = strtok(NULL, ":");
    if (ptr != NULL)
        port = ptr;

    // Check if the IP address and port number are valid
    if (!isValidIpAddress(ipAddress)) {
        printf("Invalid IP address\n");
        return 1;
    }

    if (!isValidPort(port)) {
        printf("Invalid port number\n");
        return 1;
    }

    // Block the IP address and port
    blockIpAndPort(ipAddress, port);

    return 0;
}