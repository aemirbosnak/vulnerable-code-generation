//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    int sockfd, portno, ch;
    struct sockaddr_in servaddr;
    struct hostent *server;

    // Set the server IP address and port number
    char hostname[] = "mail.example.com";
    portno = 110;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address struct
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Initialize the session with username and password
    char username[] = "username";
    char password[] = "password";
    int login_result = send(sockfd, username, strlen(username), 0);
    if (login_result < 0)
    {
        perror("ERROR sending username");
        exit(1);
    }

    login_result = send(sockfd, password, strlen(password), 0);
    if (login_result < 0)
    {
        perror("ERROR sending password");
        exit(1);
    }

    printf("Login successful!\n");

    // Retrieve the list of messages
    int num_messages = 0;
    send(sockfd, "LIST", strlen("LIST"), 0);
    ch = recv(sockfd, &num_messages, sizeof(num_messages), 0);
    if (ch < 0)
    {
        perror("ERROR receiving message count");
        exit(1);
    }
    printf("Number of messages: %d\n", num_messages);

    // Retrieve the messages
    for (int i = 0; i < num_messages; i++)
    {
        send(sockfd, "RETR 1", strlen("RETR 1"), 0);
        ch = recv(sockfd, (char *)&ch, sizeof(ch), 0);
        if (ch < 0)
        {
            perror("ERROR receiving message body");
            exit(1);
        }
        printf("Message %d: %s\n", i+1, ch);
    }

    // Disconnect from the server
    send(sockfd, "QUIT", strlen("QUIT"), 0);
    close(sockfd);

    return 0;
}