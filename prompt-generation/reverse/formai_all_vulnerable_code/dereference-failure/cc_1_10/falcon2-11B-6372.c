//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <assert.h>

#define PORT 993

/* 
This function connects to the imap server and logs in. It takes a hostname, user name and password as parameters.
It returns a pointer to the connected socket on success, or NULL on failure.
*/
int imap_connect(const char *hostname, const char *user, const char *password)
{
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    /* get the server address */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    /* make the connection to the IMAP server */
    portno = htons(PORT);
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connection established to %s\n", hostname);

    /* authenticate the user */
    n = send(sockfd, user, strlen(user), 0);
    if (n < 0) {
        perror("ERROR sending username");
        exit(1);
    }
    n = send(sockfd, password, strlen(password), 0);
    if (n < 0) {
        perror("ERROR sending password");
        exit(1);
    }
    if (recv(sockfd, user, 1, 0) < 0) {
        perror("ERROR receiving username");
        exit(1);
    }
    if (strcmp(user, "OK")!= 0) {
        perror("ERROR: invalid username");
        exit(1);
    }
    if (recv(sockfd, password, 1, 0) < 0) {
        perror("ERROR receiving password");
        exit(1);
    }
    if (strcmp(password, "OK")!= 0) {
        perror("ERROR: invalid password");
        exit(1);
    }
    printf("Authentication successful\n");

    return sockfd;
}

/* 
This function retrieves all messages from the inbox. It takes a pointer to the socket as a parameter.
It returns a pointer to the next message on success, or NULL on failure.
*/
char *imap_get_messages(int sockfd)
{
    char response[1000];
    char *message = NULL;
    int i, n;

    bzero(response, sizeof(response));

    n = send(sockfd, "LIST", strlen("LIST"), 0);
    if (n < 0) {
        perror("ERROR sending LIST command");
        exit(1);
    }
    n = recv(sockfd, response, sizeof(response), 0);
    if (n < 0) {
        perror("ERROR receiving response to LIST command");
        exit(1);
    }
    if (strstr(response, "NO")!= NULL) {
        fprintf(stderr, "ERROR: no messages in inbox\n");
        exit(1);
    }
    if (strstr(response, "UNSEEN") == NULL) {
        fprintf(stderr, "ERROR: no unseen messages in inbox\n");
        exit(1);
    }

    /* retrieve all unseen messages */
    i = 0;
    while (strstr(response, "UNSEEN")!= NULL) {
        message = (char *)malloc(10000);
        if (message == NULL) {
            perror("ERROR allocating memory for message");
            exit(1);
        }
        bzero(message, sizeof(message));
        n = send(sockfd, "RETR " + i, strlen("RETR ") + strlen(i), 0);
        if (n < 0) {
            perror("ERROR sending RETR command");
            exit(1);
        }
        n = recv(sockfd, message, sizeof(message), 0);
        if (n < 0) {
            perror("ERROR receiving message");
            exit(1);
        }
        printf("%s\n", message);
        free(message);
        i++;
    }

    return message;
}

int main(int argc, char *argv[])
{
    int sockfd;
    char *message;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <user> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = imap_connect(argv[1], argv[2], argv[3]);
    if (sockfd == NULL) {
        perror("ERROR connecting to server");
        exit(1);
    }

    message = imap_get_messages(sockfd);
    if (message == NULL) {
        perror("ERROR retrieving messages");
        exit(1);
    }

    return 0;
}