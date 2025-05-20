//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
// A TCP/IP bowman, ready to shoot packets across the digital realm

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Function to provide the bowman with a socket
int socket_get(char *host, int port)
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Find the host's address
    server = gethostbyname(host);
    if (server == NULL)
    {
        fprintf(stderr, "Could not find host %s\n", host);
        exit(1);
    }

    // Initialize the socket address
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Cannot create socket");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Cannot connect to server");
        exit(1);
    }

    return sockfd;
}

// Function to prepare the bowman's message
int message_prepare(char *msg, int size)
{
    printf("Bowman, what message wouldst thou send?\n");
    fgets(msg, size, stdin);
    msg[strcspn(msg, "\n")] = 0; // Remove newline character
    return strlen(msg);
}

// Function for the bowman to send his message
void message_send(int sockfd, char *msg, int len)
{
    if (send(sockfd, msg, len, 0) < 0)
    {
        perror("Bowman's message could not be sent");
        exit(1);
    }
    printf("Thou hast sent thy message, brave bowman!\n");
}

// Function for the bowman to receive a message
void message_receive(int sockfd)
{
    char buffer[256];
    int n;

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0)
    {
        perror("Bowman could not receive message");
        exit(1);
    }
    printf("Bowman, thou hast received a message:\n%s", buffer);
}

// Function for the bowman to end his communication
void message_end(int sockfd)
{
    close(sockfd);
    printf("Farewell, bowman. May thy arrows fly true in the digital realm.\n");
}

int main(int argc, char *argv[])
{
    int sockfd;
    char msg[256];
    int len;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket_get(argv[1], atoi(argv[2]));
    len = message_prepare(msg, sizeof(msg));
    message_send(sockfd, msg, len);
    message_receive(sockfd);
    message_end(sockfd);

    return 0;
}