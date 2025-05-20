//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NobleHouse {
    char name[100];
    char castle[100];
    int servants;
    char banner[100];
} NobleHouse;

void displayHouse(NobleHouse house) {
    printf("Behold the noble house of %s!\n", house.name);
    printf("Their mighty castle is called %s.\n", house.castle);
    printf("They command a loyal army of %d brave servants.\n", house.servants);
    printf("Their distinguished banner is that of %s.\n\n", house.banner);
}

void calculateSubnet(char *input, int *subnetMask, char *subnetClass) {
    char *token;
    int firstOctet;
    
    // Split the input by '.'
    token = strtok(input, ".");
    firstOctet = atoi(token);
    
    if (firstOctet >= 1 && firstOctet <= 126) {
        *subnetMask = 8;   // Class A
        strcpy(subnetClass, "A");
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        *subnetMask = 16;  // Class B
        strcpy(subnetClass, "B");
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        *subnetMask = 24;  // Class C
        strcpy(subnetClass, "C");
    } else {
        *subnetMask = 0;    // Invalid class
        strcpy(subnetClass, "Invalid");
    }
}

int main() {
    // A joyful proclamation from the Kingdom of C
    printf("Welcome, noble lords and ladies, to the Subnet Kingdom!\n");
    
    NobleHouse house1 = { "House of Compiler", "Castle of Syntax", 100, "Golden Scroll" };
    NobleHouse house2 = { "House of Debug", "Fortress of Errors", 75, "Crimson Shield" };
    
    // Display noble houses
    displayHouse(house1);
    displayHouse(house2);
    
    char ipAddress[16];
    int subnetMask;
    char subnetClass[2];

    // Request the lords for an IP address
    printf("Pray, type in an IP address to ascertain the subnet: ");
    scanf("%15s", ipAddress);

    calculateSubnet(ipAddress, &subnetMask, subnetClass);

    if (subnetMask != 0) {
        printf("The IP address %s is of Class %s with a subnet mask of /%d.\n", ipAddress, subnetClass, subnetMask);
    } else {
        printf("Alas, the provided IP address %s is invalid! Seek guidance from the sages.\n", ipAddress);
    }

    // A farewell message to the participants
    printf("May your packets travel swift and true, noble friends!\n");
    return 0;
}