//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_LENGTH 1024

int main(int argc , char *argv[])
{
    int sock_desc;
    struct sockaddr_in server;
    struct hostent *hp;
    char buffer[MAX_MSG_LENGTH];
    char hostname[128] = "";

    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Getting the server address from hostname */
    printf("Enter server hostname: ");
    scanf("%s", hostname);
    hp = gethostbyname(hostname);
    if(hp == NULL)
    {
        fprintf(stderr, "Unknown host %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    /* Creating socket */
    sock_desc = socket(AF_INET , SOCK_STREAM , 0);
    if(sock_desc == -1)
    {
        fprintf(stderr, "Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    /* Setting the server address and port */
    server.sin_addr = *((struct in_addr*)hp->h_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(143);

    /* Connect to server */
    if(connect(sock_desc, (struct sockaddr*)&server, sizeof(server)) == -1)
    {
        fprintf(stderr, "Connect failed\n");
        exit(EXIT_FAILURE);
    }

    /* Login to server */
    sprintf(buffer, ". login %s %s\n", argv[1], argv[2]);
    send(sock_desc, buffer, strlen(buffer), 0);

    /* Select INBOX */
    sprintf(buffer, ". select INBOX\n");
    send(sock_desc, buffer, strlen(buffer), 0);

    /* Search for all messages */
    sprintf(buffer, ". search ALL\n");
    send(sock_desc, buffer, strlen(buffer), 0);

    /* Read in messages */
    while(1) 
    {
        char *msg = malloc(MAX_MSG_LENGTH + 1);
        ssize_t len = recv(sock_desc, msg, MAX_MSG_LENGTH, 0);

        if (len == -1)
        {
            fprintf(stderr, "recv failed\n");
            exit(EXIT_FAILURE);
        }
        else if (len == 0)
        {
            break;
        }

        msg[len] = '\0';
        printf("%s", msg);
        free(msg);
    }

    /* Logout and disconnect */
    sprintf(buffer, ". logout\n");
    send(sock_desc, buffer, strlen(buffer), 0);
    close(sock_desc);

    return 0;
}