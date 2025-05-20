//FormAI DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

/*
* This is a simple port scanner program that scans for open TCP ports on a given host.
* The program takes a hostname or IP address as input from the user and scans all ports between 1 and 65535.
* For each open port, the program prints the port number and the service name if available.
*/

// Function to print error message and exit.
void error_exit(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    // Check if hostname or IP address is provided by the user.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname/IP>\n", argv[0]);
        return 1;
    }

    char* target = argv[1];

    // Resolve hostname to IP address.
    struct hostent* hp;
    struct in_addr** addr_list;
    if ((hp = gethostbyname(target)) == NULL) {
        herror("gethostbyname");
        return 1;
    }
    addr_list = (struct in_addr**) hp->h_addr_list;
    if (addr_list[0] == NULL) {
        fprintf(stderr, "Could not resolve hostname.\n");
        return 1;
    }

    // Create a socket for each port and try to connect to it.
    struct sockaddr_in target_addr;
    int port;
    int sock;
    char service[100];
    struct servent* sp;
    for (port = 1; port <= 65535; ++port) {
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            error_exit("socket");
        }

        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        target_addr.sin_addr = *addr_list[0];
        memset(target_addr.sin_zero, '\0', sizeof(target_addr.sin_zero));

        // Try to connect to the port.
        if (connect(sock, (struct sockaddr*) &target_addr, sizeof(target_addr)) == 0) {
            // Port is open, print the port number and service name if available.
            printf("Port %d is open", port);
            if ((sp = getservbyport(htons(port), "tcp")) != NULL) {
                strcpy(service, sp->s_name);
                printf(" (%s service)", service);
            }
            printf("\n");
        }

        close(sock);
    }

    return 0;
}