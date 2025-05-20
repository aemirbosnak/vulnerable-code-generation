//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER 1024
#define MAX_COMMAND 256

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    struct hostent *hp;
    char buffer[MAX_BUFFER];
    char command[MAX_COMMAND];

    if(argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket");
        exit(1);
    }

    // Resolve the server hostname
    hp = gethostbyname(argv[1]);
    if(hp == NULL) {
        printf("Unknown host %s\n", argv[1]);
        exit(1);
    }

    // Configure the server address
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy(hp->h_addr, (char *)&server.sin_addr, hp->h_length);
    server.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if(connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    // Read the server greeting message
    bzero(buffer, MAX_BUFFER);
    if(recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buffer);

    // Authenticate with the server
    printf("Enter your login information:\n");
    printf("User: ");
    fgets(buffer, MAX_BUFFER, stdin);
    sprintf(command, "LOGIN %s", buffer);
    send(sock, command, strlen(command), 0);

    printf("Password: ");
    fgets(buffer, MAX_BUFFER, stdin);
    sprintf(command, "PASS %s", buffer);
    send(sock, command, strlen(command), 0);

    // Select the inbox folder
    sprintf(command, "SELECT INBOX");
    send(sock, command, strlen(command), 0);

    // Read the folder status
    bzero(buffer, MAX_BUFFER);
    if(recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close the socket
    close(sock);
    return 0;
}