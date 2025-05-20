//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sock_fd, file_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int num_bytes_sent, num_bytes_received;
    char input[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    char *token, *rest, *command;
    int port;
    char *ip_address;

    if(argc != 3)
    {
        printf("Usage: ./ftpclient <ip_address> <port>\n");
        exit(1);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port);

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    if(connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to server\n");

    while(1)
    {
        memset(input, 0, BUFFER_SIZE);
        memset(filename, 0, BUFFER_SIZE);
        printf("Enter a command: ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strlen(input) - 1] = '\0';

        token = strtok_r(input, " ", &rest);

        if(strcmp(token, "get") == 0)
        {
            token = strtok_r(NULL, " ", &rest);
            strcpy(filename, token);

            num_bytes_sent = send(sock_fd, input, strlen(input) + 1, 0);
            if(num_bytes_sent < 0)
            {
                perror("Error sending command to server");
                exit(1);
            }

            num_bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            if(num_bytes_received < 0)
            {
                perror("Error receiving response from server");
                exit(1);
            }

            if(strcmp(buffer, "File not found") == 0)
            {
                printf("File not found on server\n");
                continue;
            }

            file_fd = open(filename, O_CREAT | O_WRONLY, 0644);
            if(file_fd < 0)
            {
                perror("Error creating file");
                exit(1);
            }

            num_bytes_sent = send(sock_fd, "ACK", 4, 0);
            if(num_bytes_sent < 0)
            {
                perror("Error sending ACK to server");
                exit(1);
            }

            while(1)
            {
                num_bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
                if(num_bytes_received < 0)
                {
                    perror("Error receiving file from server");
                    exit(1);
                }

                if(num_bytes_received == 0)
                {
                    printf("File transfer completed\n");
                    break;
                }

                num_bytes_sent = write(file_fd, buffer, num_bytes_received);
                if(num_bytes_sent < 0)
                {
                    perror("Error writing file");
                    exit(1);
                }
            }

            close(file_fd);
        }
        else if(strcmp(token, "put") == 0)
        {
            token = strtok_r(NULL, " ", &rest);
            strcpy(filename, token);

            file_fd = open(filename, O_RDONLY);
            if(file_fd < 0)
            {
                printf("File not found\n");
                continue;
            }

            num_bytes_sent = send(sock_fd, input, strlen(input) + 1, 0);
            if(num_bytes_sent < 0)
            {
                perror("Error sending command to server");
                exit(1);
            }

            num_bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            if(num_bytes_received < 0)
            {
                perror("Error receiving response from server");
                exit(1);
            }

            if(strcmp(buffer, "File exists") == 0)
            {
                printf("File already exists on server\n");
                continue;
            }

            while(1)
            {
                num_bytes_received = read(file_fd, buffer, BUFFER_SIZE);
                if(num_bytes_received < 0)
                {
                    perror("Error reading file");
                    exit(1);
                }

                if(num_bytes_received == 0)
                    break;

                num_bytes_sent = send(sock_fd, buffer, num_bytes_received, 0);
                if(num_bytes_sent < 0)
                {
                    perror("Error sending file to server");
                    exit(1);
                }

                num_bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
                if(num_bytes_received < 0)
                {
                    perror("Error receiving ACK from server");
                    exit(1);
                }
            }

            close(file_fd);
            printf("File transfer completed\n");
        }
        else if(strcmp(token, "quit") == 0)
        {
            num_bytes_sent = send(sock_fd, input, strlen(input) + 1, 0);
            if(num_bytes_sent < 0)
            {
                perror("Error sending command to server");
                exit(1);
            }

            num_bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            if(num_bytes_received < 0)
            {
                perror("Error receiving response from server");
                exit(1);
            }

            if(strcmp(buffer, "OK") == 0)
            {
                printf("Connection closed by server\n");
                break;
            }
            else
            {
                printf("Error closing connection\n");
                exit(1);
            }
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    close(sock_fd);
    return 0;
}