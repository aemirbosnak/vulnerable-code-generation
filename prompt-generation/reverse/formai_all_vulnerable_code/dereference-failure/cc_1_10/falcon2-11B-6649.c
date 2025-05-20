//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define POP3_USER "username"
#define POP3_PASSWORD "password"
#define POP3_MAX_LINE_LENGTH 1024

int main() {
    int sockfd, n;
    struct hostent *server;
    struct sockaddr_in serveraddr;
    char buffer[POP3_MAX_LINE_LENGTH];

    // Step 1: Resolve the server's IP address
    server = gethostbyname("example.com");
    if (server == NULL) {
        fprintf(stderr, "Error: Cannot resolve hostname\n");
        exit(1);
    }

    // Step 2: Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(1);
    }

    // Step 3: Connect to the POP3 server
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(POP3_PORT);
    bzero((char *)&(serveraddr.sin_addr), sizeof(serveraddr.sin_addr));
    if (inet_aton(server->h_addr, &(serveraddr.sin_addr)) == 0) {
        fprintf(stderr, "Error: Invalid server address\n");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(1);
    }

    // Step 4: Send the login command
    printf("Sending login command...\n");
    sprintf(buffer, "USER %s\r\n", POP3_USER);
    write(sockfd, buffer, strlen(buffer));

    // Step 5: Read the server's response
    printf("Reading response...\n");
    read(sockfd, buffer, POP3_MAX_LINE_LENGTH);

    // Step 6: Send the password command
    printf("Sending password command...\n");
    sprintf(buffer, "PASS %s\r\n", POP3_PASSWORD);
    write(sockfd, buffer, strlen(buffer));

    // Step 7: Read the server's response
    printf("Reading response...\n");
    read(sockfd, buffer, POP3_MAX_LINE_LENGTH);

    // Step 8: Send the CAPAB command
    printf("Sending CAPAB command...\n");
    sprintf(buffer, "CAPAB\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Step 9: Read the server's response
    printf("Reading response...\n");
    read(sockfd, buffer, POP3_MAX_LINE_LENGTH);

    // Step 10: Retrieve the email messages
    printf("Retrieving email messages...\n");
    while (1) {
        sprintf(buffer, "RETR %d\r\n", 1);
        write(sockfd, buffer, strlen(buffer));
        read(sockfd, buffer, POP3_MAX_LINE_LENGTH);

        // Step 11: Print the email message
        printf("Message 1:\n%s", buffer);
        printf("\n");
    }

    // Step 12: Disconnect from the server
    printf("Disconnecting from server...\n");
    close(sockfd);

    return 0;
}