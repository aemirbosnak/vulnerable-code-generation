//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXSIZE 1024
#define MAXRESPONSE 8192

/*
 * This program is a simple IMAP client that connects to an IMAP server
 * and allows the user to log in, navigate folders, and read messages.
 * The user's password is securely stored using the getpass() function.
 * This program uses the IMAP protocol as described in RFC 3501.
 */

void error(char *msg) {
    perror(msg);
    exit(1);
}

void sendIMAP(int sockfd, char *msg) {
    if (send(sockfd, msg, strlen(msg), 0) == -1)
        error("ERROR sending IMAP command");
}

void recvIMAP(int sockfd, char *resp) {
    if (recv(sockfd, resp, MAXRESPONSE, 0) == -1)
        error("ERROR receiving IMAP response");
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[MAXSIZE];
    char response[MAXRESPONSE];
    char user[256];
    char pass[256];
    char folder[256];
    char search[256];
    char command[256];

    if (argc < 4) {
        fprintf(stderr,"usage: %s hostname port username\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) == -1)
        error("ERROR connecting");

    recvIMAP(sockfd, response);
    printf("%s", response);

    // Log in with username and password
    printf("Username: ");
    fgets(user, 255, stdin);
    printf("Password: ");
    getpass(pass);
    sprintf(buffer, "1 LOGIN %s %s\r\n", user, pass);
    sendIMAP(sockfd, buffer);

    recvIMAP(sockfd, response);
    printf("%s", response);

    // Check for successful login
    if (strstr(response, "OK") == NULL) {
        fprintf(stderr, "ERROR: login failed\n");
        exit(0);
    }

    while (1) {
        printf("IMAP> ");
        fgets(command, 255, stdin);
        strtok(command, "\n");

        if (strcmp(command, "quit") == 0) {
            // Log out and quit
            sprintf(buffer, "2 LOGOUT\r\n");
            sendIMAP(sockfd, buffer);
            recvIMAP(sockfd, response);
            printf("%s", response);
            break;
        }
        else if (strcmp(command, "list") == 0) {
            // List available folders
            sprintf(buffer, "2 LIST \"\" \"*\"\r\n");
            sendIMAP(sockfd, buffer);
            recvIMAP(sockfd, response);
            printf("%s", response);
        }
        else if (strcmp(command, "select") == 0) {
            // Select a folder
            printf("Folder: ");
            fgets(folder, 255, stdin);
            strtok(folder, "\n");
            sprintf(buffer, "2 SELECT %s\r\n", folder);
            sendIMAP(sockfd, buffer);
            recvIMAP(sockfd, response);
            printf("%s", response);
        }
        else if (strcmp(command, "search") == 0) {
            // Search for messages
            printf("Search term: ");
            fgets(search, 255, stdin);
            strtok(search, "\n");
            sprintf(buffer, "2 UID SEARCH BODY \"%s\"\r\n", search);
            sendIMAP(sockfd, buffer);
            recvIMAP(sockfd, response);
            printf("%s", response);
        }
        else if (strcmp(command, "fetch") == 0) {
            // Fetch a message
            printf("Message UID: ");
            fgets(buffer, 255, stdin);
            strtok(buffer, "\n");
            sprintf(buffer, "2 UID FETCH %s (RFC822)\r\n", buffer);
            sendIMAP(sockfd, buffer);
            recvIMAP(sockfd, response);
            printf("%s", response);
        }
        else {
            printf("Unknown command\n");
        }
    }

    close(sockfd);
    return 0;
}