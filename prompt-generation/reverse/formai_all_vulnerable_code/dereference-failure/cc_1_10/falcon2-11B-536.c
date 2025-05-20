//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent *serverHost;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    serverHost = gethostbyname(argv[1]);
    if (serverHost == NULL) {
        fprintf(stderr, "Error: %s is not a valid hostname\n", argv[1]);
        return 1;
    }

    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    bcopy((char *) serverHost->h_addr, (char *) &serverAddr.sin_addr.s_addr, serverHost->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Failed to create socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error: Failed to connect to server");
        return 1;
    }

    char command[256];
    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);
    printf("Sending command: %s\n", command);

    int numBytes;
    if ((numBytes = send(sockfd, command, strlen(command), 0)) < 0) {
        perror("Error: Failed to send command");
        return 1;
    }

    char response[256];
    if ((numBytes = recv(sockfd, response, sizeof(response), 0)) < 0) {
        perror("Error: Failed to receive response");
        return 1;
    }
    printf("Received response: %s\n", response);

    close(sockfd);
    return 0;
}