//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#define POP3_PORT 110

/* Function to handle errors */
void error(char *msg) {
    perror(msg);
    exit(1);
}

/* Function to read response from server */
void readResponse(int sockfd, char* buffer, int size) {
    int n = read(sockfd, buffer, size - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    buffer[n] = '\0';
}

/* Function to send command to server */
void sendCommand(int sockfd, char* buffer, char* cmd) {
    sprintf(buffer, "%s\r\n", cmd);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("ERROR sending command to server");
    }
}

int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    /* Check for command line arguments */
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname username\n", argv[0]);
        exit(1);
    }

    /* Set up the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    portno = POP3_PORT;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr_list[0], (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    /* Read initial server greeting */
    readResponse(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    /* Send username */
    sendCommand(sockfd, buffer, "USER USERNAME");
    readResponse(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    /* Send password */
    sendCommand(sockfd, buffer, "PASS PASSWORD");
    readResponse(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    /* List all messages */
    sendCommand(sockfd, buffer, "LIST");
    readResponse(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    /* Retrieve first message */
    sendCommand(sockfd, buffer, "RETR 1");
    readResponse(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    /* Quit */
    sendCommand(sockfd, buffer, "QUIT");
    readResponse(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    /* Close socket */
    close(sockfd);
    return 0;
}