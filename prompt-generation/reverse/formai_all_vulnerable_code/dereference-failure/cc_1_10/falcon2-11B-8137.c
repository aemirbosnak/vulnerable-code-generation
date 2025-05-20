//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to check if the host is up
int isHostUp(char *host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error opening socket");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to host");
        return -1;
    }

    close(sockfd);
    return 0;
}

// Main function to create a network topology mapper
int main() {
    int num_hosts = 10;
    int port = 12345;

    char **hosts = (char **) malloc(num_hosts * sizeof(char *));
    for (int i = 0; i < num_hosts; i++) {
        hosts[i] = (char *) malloc(128 * sizeof(char));
    }

    // Initialize hosts
    for (int i = 0; i < num_hosts; i++) {
        snprintf(hosts[i], 128, "192.168.1.%d", i);
    }

    // Check if hosts are up
    for (int i = 0; i < num_hosts; i++) {
        if (isHostUp(hosts[i], port)!= 0) {
            printf("Host %s is not up\n", hosts[i]);
        } else {
            printf("Host %s is up\n", hosts[i]);
        }
    }

    // Free memory
    for (int i = 0; i < num_hosts; i++) {
        free(hosts[i]);
    }
    free(hosts);

    return 0;
}