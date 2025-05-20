//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 0;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    printf("Connecting to %s:%d\n", hostname, port);

    /* Create a socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    /* Get the hostent struct */
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL)
    {
        printf("Unknown host %s\n", hostname);
        return 1;
    }

    /* Set up the server address */
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, he->h_addr, he->h_length);

    /* Connect to the server */
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        return 1;
    }

    /* Send the IMAP command */
    char *command = "LOGIN username password";
    int len = strlen(command);
    if (send(sock, command, len, 0) != len)
    {
        perror("send");
        return 1;
    }

    /* Receive the response */
    char response[1024];
    int num_bytes = recv(sock, response, sizeof(response), 0);
    if (num_bytes < 0)
    {
        perror("recv");
        return 1;
    }

    /* Print the response */
    response[num_bytes] = '\0';
    printf("%s\n", response);

    /* Close the socket */
    close(sock);

    return 0;
}