//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 80       // default HTTP port

int main(int argc, char *argv[]) {
    char *target;
    if (argc == 2) {    // IP address or hostname given as command argument
        target = argv[1];
    } else {            // IP address or hostname entered during runtime
        printf("Enter target IP address or hostname: ");
        scanf("%s", target);
    }
    struct hostent *server = gethostbyname(target); // resolve hostname to IP address
    printf("Scanning wireless network of %s (%s)...\n", target, inet_ntoa(*(struct in_addr*)server->h_addr_list[0]));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);   // create socket
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int)) < 0) {
        perror("Error setting socket option");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));   // initialize structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    int num_ports = 1024;
    for (int i = 1; i < num_ports; i++) {
        serv_addr.sin_port = htons(i);
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d: OPEN\n", i);
        }
    }

    close(sockfd);
    printf("\nScan complete. Exiting...\n");

    return 0;
}