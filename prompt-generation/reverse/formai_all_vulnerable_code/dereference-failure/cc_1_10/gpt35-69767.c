//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER 1024

struct hostent *server;
struct sockaddr_in server_address;

int create_socket()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully.\n");
    return sockfd;
}

void connect_socket(int sockfd, char *hostname, int port)
{
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr, "Error: no such host as %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy((char *)&server_address.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_address.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server %s:%d.\n", hostname, port);
}

void send_command(int sockfd, char *command)
{
    if (send(sockfd, command, strlen(command), 0) < 0)
    {
        perror("Error sending command");
        exit(EXIT_FAILURE);
    }
    printf("Command sent: %s", command);
}

void read_response(int sockfd)
{
    char buffer[MAX_BUFFER];
    int n;
    while ((n = read(sockfd, buffer, MAX_BUFFER - 1)) > 0)
    {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (n < MAX_BUFFER - 1)
        {
            break;
        }
    }
    if (n < 0)
    {
        perror("Error reading response");
        exit(EXIT_FAILURE);
    }
}

void download_file(int sockfd, char *filename)
{
    int fd = open(filename, O_CREAT | O_WRONLY, 0666);
    if (fd < 0)
    {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    int n;
    while ((n = read(sockfd, buffer, MAX_BUFFER)) > 0)
    {
        if (write(fd, buffer, n) < 0)
        {
            perror("Error writing to file");
            exit(EXIT_FAILURE);
        }
    }
    if (n < 0)
    {
        perror("Error downloading file");
        exit(EXIT_FAILURE);
    }
    printf("File downloaded successfully.\n");
    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s hostname port filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = create_socket();
    connect_socket(sockfd, argv[1], atoi(argv[2]));
    send_command(sockfd, "USER anonymous\n");
    read_response(sockfd);
    send_command(sockfd, "PASS ftp@example.com\n");
    read_response(sockfd);
    send_command(sockfd, "TYPE I\n");
    read_response(sockfd);
    char command[MAX_BUFFER];
    sprintf(command, "RETR %s\n", argv[3]);
    send_command(sockfd, command);
    read_response(sockfd);
    download_file(sockfd, argv[3]);

    close(sockfd);
    return 0;
}