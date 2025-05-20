//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;
} IPv4;

typedef struct {
    unsigned char subnet_mask;
    IPv4 address;
} Subnet;

IPv4 get_ip_address(char *ip_address_string) {
    IPv4 ip_address;
    char *token = strtok(ip_address_string, ".");
    ip_address.octet1 = atoi(token);
    token = strtok(NULL, ".");
    ip_address.octet2 = atoi(token);
    token = strtok(NULL, ".");
    ip_address.octet3 = atoi(token);
    token = strtok(NULL, ".");
    ip_address.octet4 = atoi(token);
    return ip_address;
}

Subnet get_subnet(char *subnet_string) {
    Subnet subnet;
    char *token = strtok(subnet_string, "/");
    subnet.address = get_ip_address(token);
    token = strtok(NULL, "/");
    subnet.subnet_mask = atoi(token);
    return subnet;
}

int main() {
    char ip_address_string[20], subnet_string[20];
    printf("Enter IP address: ");
    scanf("%s", ip_address_string);
    printf("Enter Subnet: ");
    scanf("%s", subnet_string);
    IPv4 ip_address = get_ip_address(ip_address_string);
    Subnet subnet = get_subnet(subnet_string);

    printf("IP address entered is: %d.%d.%d.%d \n", 
           ip_address.octet1, ip_address.octet2, ip_address.octet3, ip_address.octet4);
    printf("Subnet entered is: %d / %d \n", subnet.address, subnet.subnet_mask);
    
    return 0;
}