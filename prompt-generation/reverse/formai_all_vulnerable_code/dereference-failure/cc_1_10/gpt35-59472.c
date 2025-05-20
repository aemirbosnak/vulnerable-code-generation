//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>

struct node {
    char *name;
    char *ip_addr;
    struct node *next;
};

struct node *head = NULL;

// Function to add new node to the linked list
void add_node(char *name, char *ip_addr) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->name = name;
    new_node->ip_addr = ip_addr;
    new_node->next = head;
    head = new_node;
}

// Function to print the linked list
void print_list() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%s\t%s\n", temp->name, temp->ip_addr);
        temp = temp->next;
    }
}

int main() {
    struct ifaddrs *ifaddr, *ifa;

    if(getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Loop through all the network interfaces
    for(ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if(ifa->ifa_addr == NULL || strcmp(ifa->ifa_name, "lo") == 0) {
            continue;
        }

        int family = ifa->ifa_addr->sa_family;
        if(family == AF_INET) {
            // IPv4 address
            struct sockaddr_in *sa = (struct sockaddr_in *)(ifa->ifa_addr);
            char ip_addr[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(sa->sin_addr), ip_addr, INET_ADDRSTRLEN);
            add_node(ifa->ifa_name, ip_addr);
        } else if(family == AF_INET6) {
            // IPv6 address
            struct sockaddr_in6 *sa = (struct sockaddr_in6 *)(ifa->ifa_addr);
            char ip_addr[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, &(sa->sin6_addr), ip_addr, INET6_ADDRSTRLEN);
            add_node(ifa->ifa_name, ip_addr);
        }
    }

    // Print the linked list
    print_list();

    // Free the memory allocated for ifaddrs
    freeifaddrs(ifaddr);

    return 0;
}