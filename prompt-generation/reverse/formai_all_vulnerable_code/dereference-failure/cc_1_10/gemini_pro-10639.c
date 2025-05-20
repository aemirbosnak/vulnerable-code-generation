//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Structure to store host information
typedef struct host_info {
    char hostname[256];
    char ip_address[32];
    int port;
    struct host_info *next;
} host_info;

// Function to add a host to the list
host_info *add_host(host_info *head, char *hostname, char *ip_address, int port) {
    host_info *new_host = (host_info *)malloc(sizeof(host_info));
    strcpy(new_host->hostname, hostname);
    strcpy(new_host->ip_address, ip_address);
    new_host->port = port;
    new_host->next = NULL;

    if (head == NULL) {
        return new_host;
    } else {
        host_info *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_host;
        return head;
    }
}

// Function to print the list of hosts
void print_hosts(host_info *head) {
    if (head == NULL) {
        printf("No hosts in the list\n");
    } else {
        host_info *current = head;
        while (current != NULL) {
            printf("%s (%s:%d)\n", current->hostname, current->ip_address, current->port);
            current = current->next;
        }
    }
}

// Function to free the memory allocated for the list
void free_hosts(host_info *head) {
    if (head == NULL) {
        return;
    } else {
        host_info *current = head;
        while (current != NULL) {
            host_info *next = current->next;
            free(current);
            current = next;
        }
    }
}

// Function to resolve a hostname to an IP address
char *resolve_hostname(char *hostname) {
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        return NULL;
    } else {
        return inet_ntoa(*((struct in_addr *)host->h_addr));
    }
}

// Function to scan a port on a host
int scan_port(char *ip_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    close(sockfd);
    return result;
}

// Function to map the network topology
host_info *map_network(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[256];
    host_info *head = NULL;
    while (fgets(line, sizeof(line), file)) {
        char hostname[256];
        char ip_address[32];
        int port;
        sscanf(line, "%s %s %d", hostname, ip_address, &port);

        host_info *new_host = add_host(head, hostname, ip_address, port);
        if (new_host != NULL) {
            head = new_host;
        }
    }

    fclose(file);
    return head;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    host_info *head = map_network(argv[1]);
    if (head == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    print_hosts(head);
    free_hosts(head);

    return 0;
}