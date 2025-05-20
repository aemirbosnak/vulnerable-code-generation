//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void ftp_download(char *hostname, char *filename, char *username, char *password)
{
    int sockfd, data_sockfd;
    char recv_buffer[BUFFER_SIZE];

    struct sockaddr_in serv_addr, data_addr;
    struct hostent *server;

    // Create a socket for FTP connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Get the host IP address from hostname
    server = gethostbyname(hostname);

    if (server == NULL) 
    {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Initialize server address and port
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(21);

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    {
        perror("Error connecting to FTP server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP server\n");

    // Receive welcome message
    memset(recv_buffer, 0, sizeof(recv_buffer));
    if (recv(sockfd, recv_buffer, sizeof(recv_buffer), 0) < 0) 
    {
        perror("Error receiving welcome message");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    // Send username
    char username_buffer[BUFFER_SIZE];
    sprintf(username_buffer, "USER %s\r\n", username);
    if (send(sockfd, username_buffer, strlen(username_buffer), 0) < 0)
    {
        perror("Error sending username");
        exit(EXIT_FAILURE);
    }

    // Receive response to username
    memset(recv_buffer, 0, sizeof(recv_buffer));
    if (recv(sockfd, recv_buffer, sizeof(recv_buffer), 0) < 0) 
    {
        perror("Error receiving response to username");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    // Send password
    char password_buffer[BUFFER_SIZE]; 
    sprintf(password_buffer, "PASS %s\r\n", password);
    if (send(sockfd, password_buffer, strlen(password_buffer), 0) < 0)
    {
        perror("Error sending password");
        exit(EXIT_FAILURE);
    }

    // Receive response to password
    memset(recv_buffer, 0, sizeof(recv_buffer));
    if (recv(sockfd, recv_buffer, sizeof(recv_buffer), 0) < 0) 
    {
        perror("Error receiving response to password");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    // Enter passive mode
    if (send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0) < 0)
    {
        perror("Error entering passive mode");
        exit(EXIT_FAILURE);
    }

    // Receive response to passive mode
    memset(recv_buffer, 0, sizeof(recv_buffer));
    if (recv(sockfd, recv_buffer, sizeof(recv_buffer), 0) < 0)
    {
        perror("Error receiving response to passive mode");
        exit(EXIT_FAILURE);
    }

    // Parse passive mode response
    char *data_port_start = strchr(recv_buffer, '(') + 1;
    char *data_port_end = strchr(data_port_start, ')');
    *data_port_end = '\0';
    int data_port_val[6];
    sscanf(data_port_start, "%d,%d,%d,%d,%d,%d", &data_port_val[0], &data_port_val[1], &data_port_val[2], &data_port_val[3], &data_port_val[4], &data_port_val[5]);

    int data_port = data_port_val[4] * 256 + data_port_val[5];

    // Initialize data socket address and port
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    memcpy(&data_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    data_addr.sin_port = htons(data_port);

    // Connect to data socket
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sockfd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) 
    {
        perror("Error connecting to data socket");
        exit(EXIT_FAILURE);
    }

    // Send retrieve command
    char command_buffer[BUFFER_SIZE];
    sprintf(command_buffer, "RETR %s\r\n", filename);
    if (send(sockfd, command_buffer, strlen(command_buffer), 0) < 0)
    {
        perror("Error sending retrieve command");
        exit(EXIT_FAILURE);
    }

    // Receive response to retrieve command
    memset(recv_buffer, 0, sizeof(recv_buffer));
    if (recv(sockfd, recv_buffer, sizeof(recv_buffer), 0) < 0)
    {
        perror("Error receiving response to retrieve command");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    // Receive file data and write to stdout
    int bytes_received = 0;
    while((bytes_received = recv(data_sockfd, recv_buffer, sizeof(recv_buffer), 0)) > 0)
    {
        fwrite(recv_buffer, 1, bytes_received, stdout);
    }
    printf("\n");

    // Close sockets and exit
    close(data_sockfd);
    close(sockfd);

    printf("Download complete\n");
}

int main(int argc, char *argv[])
{
    if (argc != 5) 
    {
        fprintf(stderr, "Usage: %s [hostname] [filename] [username] [password]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ftp_download(argv[1], argv[2], argv[3], argv[4]);

    return 0;
}