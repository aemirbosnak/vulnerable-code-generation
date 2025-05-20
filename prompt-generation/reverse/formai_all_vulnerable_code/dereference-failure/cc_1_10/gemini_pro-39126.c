//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void write_log(char *msg)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char time_str[256];
    strftime(time_str, 256, "%Y-%m-%d %H:%M:%S", tm);
    fprintf(stderr, "[%s] %s\n", time_str, msg);
}

int main(int argc, char *argv[])
{
    // Parse arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port filename\n", argv[0]);
        exit(1);
    }
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *filename = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get the IP address of the server
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        error("ERROR, no such host");
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset((void *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Send the filename to the server
    if (send(sockfd, filename, strlen(filename), 0) < 0) {
        error("ERROR writing to socket");
    }

    // Receive the file from the server
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        error("ERROR opening file");
    }

    char buffer[1024];
    int n;
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        if (write(fd, buffer, n) < 0) {
            error("ERROR writing to file");
        }
    }
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Close the socket and file
    close(sockfd);
    close(fd);

    write_log("File downloaded successfully");

    return 0;
}