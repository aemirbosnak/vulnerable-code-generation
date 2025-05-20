//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h> // for O_RDWR
#include <errno.h>

#define MAX_LINE 1024
#define DEFAULT_PORT 21

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_LINE];
    int file_fd;
    char filename[MAX_LINE];
    char file_content[MAX_LINE];
    int bytes_read;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    // get server by name
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        error("ERROR, no such host");
    }

    // set serv_addr
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR connecting");
    }

    // login to FTP server
    bzero(buffer, MAX_LINE);
    strcpy(buffer, "USER anonymous\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        error("ERROR writing to socket");
    }

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "PASS anonymous@example.com\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        error("ERROR writing to socket");
    }

    // get file from FTP server
    bzero(filename, MAX_LINE);
    strcpy(filename, "myfile.txt");

    bzero(buffer, MAX_LINE);
    strcpy(buffer, "RETR ");
    strcat(buffer, filename);
    strcat(buffer, "\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        error("ERROR writing to socket");
    }

    // open file for writing
    file_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_fd < 0)
    {
        error("ERROR opening file");
    }

    // read file contents from FTP server
    bzero(buffer, MAX_LINE);
    while ((bytes_read = read(sockfd, buffer, MAX_LINE)) > 0)
    {
        if (write(file_fd, buffer, bytes_read) < 0)
        {
            error("ERROR writing to file");
        }
        bzero(buffer, MAX_LINE);
    }

    // close file
    close(file_fd);

    // close socket
    close(sockfd);

    return 0;
}