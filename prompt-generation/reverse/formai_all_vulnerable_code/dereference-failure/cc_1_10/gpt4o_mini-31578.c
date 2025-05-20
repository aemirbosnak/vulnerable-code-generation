//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate the subnet information
void calculate_subnet(char *ip_str, char *subnet_mask_str) {
    struct sockaddr_in ip_addr, subnet_mask;
    // Convert IP address and subnet mask from string to binary format
    inet_pton(AF_INET, ip_str, &(ip_addr.sin_addr));
    inet_pton(AF_INET, subnet_mask_str, &(subnet_mask.sin_addr));

    // Get binary representation
    unsigned int subnet = ntohl(subnet_mask.sin_addr.s_addr);
    unsigned int ip = ntohl(ip_addr.sin_addr.s_addr);

    // Calculate network and broadcast addresses
    unsigned int network_address = ip & subnet;
    unsigned int broadcast_address = network_address | ~subnet;

    // Output the results
    printf("IP Address:      %s\n", ip_str);
    printf("Subnet Mask:     %s\n", subnet_mask_str);
    printf("Network Address: %s\n", inet_ntoa(*(struct in_addr *)&network_address));
    printf("Broadcast Address:%s\n", inet_ntoa(*(struct in_addr *)&broadcast_address));

    // Calculate number of hosts
    unsigned int number_of_hosts = ~subnet + 1;
    printf("Number of Hosts: %u\n\n", number_of_hosts - 2); // subtracting network and broadcast addresses
}

// Function to prompt user for IP and subnet mask
void get_user_input() {
    char ip_str[16];
    char subnet_mask_str[16];

    // Loop until valid IP and subnet mask are given
    while (1) {
        printf("Enter an IP address (xxx.xxx.xxx.xxx): ");
        scanf("%s", ip_str);
        printf("Enter a subnet mask (xxx.xxx.xxx.xxx): ");
        scanf("%s", subnet_mask_str);

        // Validate IP and subnet mask
        if (inet_pton(AF_INET, ip_str, &(struct sockaddr_in) {{0}}) == 1 &&
            inet_pton(AF_INET, subnet_mask_str, &(struct sockaddr_in) {{0}}) == 1) {
            break;
        } else {
            printf("Invalid IP address or subnet mask. Please try again.\n");
        }
    }
    
    // Calculate the subnet information with valid inputs
    calculate_subnet(ip_str, subnet_mask_str);
}

int main() {
    printf("Welcome to the C Subnet Calculator!\n\n");
    
    // Keep asking for user input until they decide to exit
    char choice;
    do {
        get_user_input();
        printf("Would you like to calculate another subnet? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the C Subnet Calculator. Goodbye!\n");
    return 0;
}