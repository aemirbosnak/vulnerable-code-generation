//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024

// Function to connect to IMAP server
int connectImapServer(char *host, int port) {
     int sockfd = socket(AF_INET, SOCK_STREAM, 0);
     
     if (sockfd < 0) {
         printf("Error: Failed to open socket\n");
         return -1;
     }

     struct hostent *server = gethostbyname(host);
     
     if (server == NULL) {
         printf("Error: Failed to get host by name: %s\n", host);
         return -1;
     }

     struct sockaddr_in serv_addr;
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     bcopy((char *) server->h_addr, 
           (char *) &serv_addr.sin_addr.s_addr,
            server->h_length);
     serv_addr.sin_port = htons(port);

     if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
         printf("Error: Failed to connect to %s:%d\n", host, port);
         return -1;
     }

     char respBuff[MAX_BUFF_SIZE];
     int n = read(sockfd, respBuff, MAX_BUFF_SIZE-1);
     if (n < 0) {
         printf("Error: Failed to read from socket\n");
         return -1;
     }
     respBuff[n] = 0;
     printf("Server Response: %s\n", respBuff);

     return sockfd;
}

// Simple function to send commands to IMAP server.
bool sendCommand(int sockfd, char *command) {
    char cmdBuff[MAX_BUFF_SIZE];
    sprintf(cmdBuff, "%s\r\n", command);
    int n = write(sockfd, cmdBuff, strlen(cmdBuff));

    if (n < strlen(cmdBuff)) {
        printf("Error: Failed to send command to server\n");
        return false;
    }

    char respBuff[MAX_BUFF_SIZE];
    n = read(sockfd, respBuff, MAX_BUFF_SIZE-1);
    if (n < 0) {
        printf("Error: Failed to read from socket\n");
        return false;
    }
    respBuff[n] = 0;
    printf("Server Response: %s\n", respBuff);

    return true;
}

int main() {
    int sockfd = connectImapServer("imap.gmail.com", 993);
    if (sockfd < 0) {
        return 0;
    }

    // Login to server
    sendCommand(sockfd, "tag1 LOGIN user@gmail.com password");

    // Get list of mailboxes on server
    sendCommand(sockfd, "tag2 LIST \"\" *");

    // Select mailbox
    sendCommand(sockfd, "tag3 SELECT INBOX");

    // Fetch email
    sendCommand(sockfd, "tag4 FETCH 1 BODY[]");

    // Logout from server
    sendCommand(sockfd, "tag5 LOGOUT");

    close(sockfd);
    return 0;
}