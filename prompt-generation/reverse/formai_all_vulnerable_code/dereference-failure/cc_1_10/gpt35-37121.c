//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 25 // SMTP port

char *get_response(int sockfd);
void send_command(int sockfd, char *command);

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char *server_name = "smtp.gmail.com"; // Server name to connect to

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(server_name); // Get server information
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Get initial server response
    get_response(sockfd);

    // Send HELO command
    send_command(sockfd, "HELO example.com");

    // Send MAIL FROM command
    send_command(sockfd, "MAIL FROM:<sender@example.com>");

    // Send RCPT TO command
    send_command(sockfd, "RCPT TO:<recipient@example.com>");

    // Send DATA command
    send_command(sockfd, "DATA");

    // Send message body
    send_command(sockfd, "Subject: Example Subject\n\nThis is the message body.");

    // End message body
    send_command(sockfd, ".");

    // Send QUIT command
    send_command(sockfd, "QUIT");

    // Close socket
    close(sockfd);

    return 0;
}

/*
 * Function to get response from the server
 */
char *get_response(int sockfd)
{
    const int bufsize = 1024;
    char *buffer = malloc(bufsize);
    int n;

    bzero(buffer, bufsize);
    n = read(sockfd, buffer, bufsize - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    return buffer;
}

/*
 * Function to send commands to the server
 */
void send_command(int sockfd, char *command)
{
    int n;

    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    printf("Sent: %s\n", command);

    get_response(sockfd);
}