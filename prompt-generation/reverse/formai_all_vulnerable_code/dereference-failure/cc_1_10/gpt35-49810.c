//FormAI DATASET v1.0 Category: Firewall ; Style: Sherlock Holmes
/*
** THE ADVENTURE OF THE C FIREWALL
** By: Sherlock Holmes
** Version 1.0
**
** A firewall program that detects unwanted intrusions
** in a network was encountered by Sherlock Holmes. He
** was tasked to investigate the software and trace the
** source of the problem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate input
int validate_input(int argc, char *argv[])
{
    if (argc != 2) {
        printf("USAGE: %s [IP ADDRESS]\n", argv[0]);
        return -1;
    }

    // Check if the input is a valid IP address
    char *split_ip = strtok(argv[1], ".");
    int octet_count = 0;

    while (split_ip != NULL) {
        if (atoi(split_ip) < 0 || atoi(split_ip) > 255) {
            printf("Invalid IP address: %s\n", argv[1]);
            return -1;
        }

        octet_count++;
        split_ip = strtok(NULL, ".");
    }

    if (octet_count != 4) {
        printf("Invalid IP address: %s\n", argv[1]);
        return -1;
    }

    return 0;
}

// Function to check if the IP address is blocked
int check_ip_block(char *ip_address)
{
    // List of blocked IP address
    char *blocked_ips[] = {"10.10.10.10", "192.168.1.1", "172.16.2.3"};

    for (int i = 0; i < 3; i++) {
        if (strcmp(ip_address, blocked_ips[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    printf("The Adventure of the C Firewall\n");
    printf("By: Sherlock Holmes\n\n");

    if (validate_input(argc, argv) != 0) {
        return -1;
    }

    // Get the IP address from the command line
    char *ip_address = argv[1];

    // Check if the IP address is blocked
    if (check_ip_block(ip_address) == 1) {
        printf("Warning: %s is a blocked IP address!\n", ip_address);
        return -1;
    }

    printf("Connection is successful. Enjoy your browsing, mate!\n");

    return 0;
}