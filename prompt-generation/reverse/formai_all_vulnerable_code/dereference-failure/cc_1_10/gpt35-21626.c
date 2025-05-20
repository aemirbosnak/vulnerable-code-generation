//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 80 // default port for HTTP

struct node {
    char *ip;
    struct node *next;
};

struct node *head = NULL; // head node for linked list

// function to print the linked list
void print_list() { 
    struct node *current = head;
    while (current != NULL) {
        printf("%s\n", current->ip);
        current = current->next;
    }
}

// function to add a node to the linked list
void add_node(char *ip) { 
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->ip = ip;
    new_node->next = head;
    head = new_node;
}

// function to scan for wireless networks
void* network_scan(void *arg) { 
    char *subnet = (char*)arg; // subnet to scan
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(1);
    }
    struct hostent *host = gethostbyname(subnet); // convert subnet to IP address struct
    if (host == NULL) {
        perror("Could not retrieve host info");
        exit(1);
    }
    struct in_addr **addr_list = (struct in_addr**)host->h_addr_list; // get the list of IP addresses
    for (int i = 0; addr_list[i] != NULL; i++) {
        struct sockaddr_in addr; // create socket address struct
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        addr.sin_addr = *addr_list[i]; // set IP address
        if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == 0) { // if connection is successful, add IP address to linked list
            add_node(inet_ntoa(*addr_list[i]));
        }
    }
    close(sockfd);
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[2]; // array of threads
    char *subnets[2] = {"192.168.1", "192.168.2"}; // subnets to scan
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, network_scan, subnets[i]); // start the threads
        usleep(500000); // wait for half a second before starting the next thread
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL); // wait for the threads to finish
    }
    printf("Wireless networks:\n");
    print_list(); // print the linked list of IP addresses
    return 0;
}