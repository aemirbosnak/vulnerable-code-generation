//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subnet_calculator(char **subnets, char *ip, int subnet_mask, int index);

int main()
{
    char *ip = "192.168.1.100";
    int subnet_mask = 24;
    char **subnets = malloc(sizeof(char *) * 256);  // max 256 subnets
    memset(subnets, 0, sizeof(char *) * 256);  // set all to NULL
    
    subnet_calculator(subnets, ip, subnet_mask, 0);
    
    // print all subnets
    for (int i = 0; i < 256; i++) {
        if (subnets[i] != NULL) {
            printf("%s\n", subnets[i]);
            free(subnets[i]);
        }
    }
    free(subnets);    
    
    return 0;
}

void subnet_calculator(char **subnets, char *ip, int subnet_mask, int index)
{
    if (index == subnet_mask) {
        // create subnet string
        char *subnet = malloc(sizeof(char) * 16);  // max 15 characters
        memset(subnet, 0, sizeof(char) * 16);
        
        for (int i = 0; i < index / 8; i++) {
            // convert each octet to a string and concatenate
            char octet[4];
            memset(octet, 0, sizeof(octet));
            strncpy(octet, ip + i * 4, 3);
            strcat(subnet, octet);
            strcat(subnet, ".");
        }
        
        // add last octet
        char last_octet[4];
        memset(last_octet, 0, sizeof(last_octet));
        sprintf(last_octet, "%d", (int) strtol(ip + index / 8 * 4, NULL, 10));
        strcat(subnet, last_octet);
        
        // add subnet to list
        for (int i = 0; i < 256; i++) {
            if (subnets[i] == NULL) {
                subnets[i] = subnet;
                return;
            }
        }
        
        // exceeded max subnets
        free(subnet);
        return;
    }
    
    // set 1 for the current bit
    ip[index / 8 * 4 + index % 8] = '1';
    subnet_calculator(subnets, ip, subnet_mask, index + 1);
    
    // set 0 for the current bit
    ip[index / 8 * 4 + index % 8] = '0';
    subnet_calculator(subnets, ip, subnet_mask, index + 1);
}