//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: retro
// Embark on a Retro Network Topology Mapping Adventure

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Mainframe Control Center
int main(int argc, char** argv) {

    // Initiate Transmission
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Establish a Commlink
    struct hostent* host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Host not found.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed.\n");
        exit(1);
    }

    // Connect to the Mainframe
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed.\n");
        exit(1);
    }

    // Retrieve Network Topology Data
    char* buf = malloc(1024);
    int n = read(sockfd, buf, 1024);
    if (n < 0) {
        printf("Data retrieval failed.\n");
        exit(1);
    }

    // Decipher the Network Map
    printf("Network Topology:\n");
    printf("%s\n", buf);

    // Terminate Transmission
    close(sockfd);
    free(buf);
    return 0;
}