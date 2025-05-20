//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_OCTETS 4

struct subnet {
    char ip[16];
    char mask[16];
    char broadcast[16];
    struct subnet *next;
};

struct subnet *head = NULL;
int num_subnets = 0;

void add_subnet(char *ip, char *mask) {
    struct subnet *new_subnet = malloc(sizeof(struct subnet));
    strcpy(new_subnet->ip, ip);
    strcpy(new_subnet->mask, mask);
    new_subnet->next = NULL;
    if (head == NULL) {
        head = new_subnet;
    } else {
        struct subnet *curr_subnet = head;
        while (curr_subnet->next!= NULL) {
            curr_subnet = curr_subnet->next;
        }
        curr_subnet->next = new_subnet;
    }
    num_subnets++;
}

void print_subnets() {
    struct subnet *curr_subnet = head;
    while (curr_subnet!= NULL) {
        printf("IP: %s\n", curr_subnet->ip);
        printf("Mask: %s\n", curr_subnet->mask);
        printf("Broadcast: %s\n\n", curr_subnet->broadcast);
        curr_subnet = curr_subnet->next;
    }
}

void calculate_broadcast(char *ip, char *mask) {
    int i = 0;
    char octet[3];
    strcpy(head->broadcast, ip);
    while (i < strlen(mask)) {
        if (mask[i] == '.') {
            strcat(head->broadcast, ".");
            i++;
        } else {
            strncat(octet, &mask[i], 1);
            int octet_num = atoi(octet);
            if (octet_num == 0) {
                strcat(head->broadcast, "0");
            } else if (octet_num == 255) {
                strcat(head->broadcast, "255");
            } else {
                strcat(head->broadcast, ".");
            }
            i++;
        }
    }
}

int main() {
    int i = 0;
    char ip[16];
    char mask[16];
    printf("Enter the IP address: ");
    scanf("%s", ip);
    printf("Enter the subnet mask: ");
    scanf("%s", mask);
    add_subnet(ip, mask);
    calculate_broadcast(ip, mask);
    printf("Broadcast address: %s\n", head->broadcast);
    print_subnets();
    return 0;
}