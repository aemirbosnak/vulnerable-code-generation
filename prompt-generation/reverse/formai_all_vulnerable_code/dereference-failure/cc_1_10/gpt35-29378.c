//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert IP address into binary number
char* convertToBinary(char* ipAddress) {
    
    // split the IP address into components
    char* token = strtok(ipAddress, ".");
    
    int i = 0;
    char* binaryIp = malloc(40);
    
    while(token != NULL) {
        // convert each component into binary and append to the binaryIP
        int decimal = atoi(token);
        
        if(decimal < 0 || decimal > 255) {
            printf("Error: Invalid IP Address\n");
            return "";
        }
        
        char binaryComponent[9];
        int j = 0;
        
        for(j=7; j>=0; j--) {
            if(decimal%2 == 0) {
                binaryComponent[j] = '0';
            } else {
                binaryComponent[j] = '1';
            }
            
            decimal = decimal/2;
        }
        binaryComponent[8] = '\0';
        
        strcat(binaryIp, binaryComponent);
        strcat(binaryIp, ".");
        
        token = strtok(NULL, ".");
        i++;
    }
    binaryIp[strlen(binaryIp) - 1] = '\0';
    return binaryIp;
}

// function to calculate the network address
char* calculateNetworkAddress(char* binaryIp, int cidr) {
    
    char* networkAddress = malloc(40);
    strcpy(networkAddress, binaryIp);
    
    // set the bits after the CIDR to 0
    int i;
    for(i = cidr; i < 32; i++) {
        networkAddress[i] = '0';
    }
    
    // convert the binary network address to decimal
    char* decimalNetworkAddress = malloc(16);
    for(i = 0; i < 32; i += 8) {
        char* binaryComponent = malloc(9);
        strncpy(binaryComponent, networkAddress+i, 8);
        binaryComponent[8] = '\0';
        
        int decimalComponent = strtol(binaryComponent, NULL, 2);
        char decimalComponentStr[4];
        sprintf(decimalComponentStr, "%d", decimalComponent);
        strcat(decimalNetworkAddress, decimalComponentStr);
        strcat(decimalNetworkAddress, ".");
    }
    decimalNetworkAddress[strlen(decimalNetworkAddress) - 1] = '\0';
    return decimalNetworkAddress;
}

int main() {
    char ipAddress[16];
    int cidr;
    
    printf("Enter the IP Address in the form of X.X.X.X : ");
    scanf("%s", ipAddress);
    fflush(stdin);
    
    printf("Enter the CIDR: ");
    scanf("%d", &cidr);
    fflush(stdin);
    
    char* binaryIp = convertToBinary(ipAddress);
    char* networkAddress = calculateNetworkAddress(binaryIp, cidr);
    
    printf("IP Address: %s\n", ipAddress);
    printf("CIDR: %d\n", cidr);
    printf("Binary IP Address: %s\n", binaryIp);
    printf("Network Address: %s\n", networkAddress);
    
    free(binaryIp);
    free(networkAddress);
    return 0;
}