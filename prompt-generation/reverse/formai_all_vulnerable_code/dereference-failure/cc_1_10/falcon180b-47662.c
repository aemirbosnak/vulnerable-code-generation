//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define MAX_HOSTS 100

// Function to print the usage of the program
void print_usage(char *prog_name) {
    printf("Usage: %s <host_file>\n", prog_name);
    printf("Where <host_file> is a file containing the list of hosts to be mapped.\n");
}

// Function to map the network topology
void map_network(char *host_file) {
    FILE *fp;
    char line[1024];
    char hostname[256];
    int i = 0;

    // Open the host file
    fp = fopen(host_file, "r");
    if (fp == NULL) {
        printf("Error: Could not open host file.\n");
        exit(1);
    }

    // Read each line of the host file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Extract the hostname from the line
        sscanf(line, "%s", hostname);

        // Ping the host to check if it is reachable
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: Could not create socket.\n");
            exit(1);
        }

        struct addrinfo *result = NULL;
        struct addrinfo hints = {
           .ai_family = AF_INET,
           .ai_socktype = SOCK_STREAM
        };

        if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
            printf("Error: Could not resolve hostname.\n");
            exit(1);
        }

        if (connect(sock, result->ai_addr, result->ai_addrlen) == -1) {
            printf("Host %s is not reachable.\n", hostname);
        } else {
            printf("Host %s is reachable.\n", hostname);
        }

        close(sock);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        print_usage(argv[0]);
        exit(1);
    }

    map_network(argv[1]);

    return 0;
}