//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_SIZE 100
#define MAX_MSG_SIZE 1024

void send_msg(int sock_fd, char *msg) {
    if (send(sock_fd, msg, strlen(msg), 0) < 0) {
        perror("Error sending message to server");
        exit(1);
    }
}

char *receive_msg(int sock_fd) {
    static char response[MAX_MSG_SIZE];
    int bytes_received = recv(sock_fd, response, MAX_MSG_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error receiving message from server");
        exit(1);
    }
    response[bytes_received] = '\0';
    return response;
}

void ftp(int sock_fd) {
    char command[MAX_COMMAND_SIZE], response[MAX_MSG_SIZE];
    while (1) {
        printf("ftp> ");
        fgets(command, MAX_COMMAND_SIZE, stdin);

        if (strncmp(command, "SYST", 4) == 0) {
            send_msg(sock_fd, "SYST\r\n");
            printf("%s", receive_msg(sock_fd));
        } else if (strncmp(command, "USER", 4) == 0) {
            send_msg(sock_fd, "USER anonymous\r\n");
            printf("%s", receive_msg(sock_fd));
        } else if (strncmp(command, "PASS", 4) == 0) {
            send_msg(sock_fd, "PASS \r\n");
            printf("%s", receive_msg(sock_fd));
        } else if (strncmp(command, "QUIT", 4) == 0) {
            send_msg(sock_fd, "QUIT\r\n");
            printf("%s", receive_msg(sock_fd));
            exit(0);
        } else if (strncmp(command, "PWD", 3) == 0) {
            send_msg(sock_fd, "PWD\r\n");
            printf("%s", receive_msg(sock_fd));
        } else if (strncmp(command, "TYPE", 4) == 0) {
            send_msg(sock_fd, "TYPE I\r\n");
            printf("%s", receive_msg(sock_fd));
        } else if (strncmp(command, "PASV", 4) == 0) {
            send_msg(sock_fd, "PASV\r\n");
            char *response = receive_msg(sock_fd);
            printf("%s", response);
            int h1, h2, h3, h4, p1, p2;
            sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
                   &h1, &h2, &h3, &h4, &p1, &p2);
            struct sockaddr_in data_addr;
            data_addr.sin_family = AF_INET;
            data_addr.sin_port = htons(p1 * 256 + p2);
            char ip_addr[INET_ADDRSTRLEN];
            sprintf(ip_addr, "%d.%d.%d.%d", h1, h2, h3, h4);
            if (inet_pton(AF_INET, ip_addr, &(data_addr.sin_addr)) <= 0) {
                perror("Invalid IP address");
                exit(1);
            }
            int data_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (data_sock_fd < 0) {
                perror("Error creating data socket");
                exit(1);
            }
            if (connect(data_sock_fd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
                perror("Error connecting to data socket");
                exit(1);
            }
            printf("Data connection established\n");
            while (1) {
                char data_response[MAX_MSG_SIZE];
                int bytes_received = recv(data_sock_fd, data_response, MAX_MSG_SIZE, 0);
                if (bytes_received < 0) {
                    perror("Error receiving message from server");
                    exit(1);
                }
                if (bytes_received == 0) {
                    close(data_sock_fd);
                    printf("Data connection closed\n");
                    break;
                }
                printf("%s", data_response);
            }
        } else if (strncmp(command, "RETR", 4) == 0) {
            char *filename = strtok(command + 4, " \r\n");
            if (filename == NULL) {
                printf("No filename specified\n");
                continue;
            }
            char retr_command[MAX_COMMAND_SIZE];
            sprintf(retr_command, "RETR %s\r\n", filename);
            send_msg(sock_fd, retr_command);
            char *response = receive_msg(sock_fd);
            printf("%s", response);
            if (response[0] == '4' || response[0] == '5') {
                printf("Failed to retrieve file\n");
                continue;
            }
            printf("Retrieving file...\n");
            int file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
            if (file_fd < 0) {
                perror("Error creating file");
                exit(1);
            }
            int bytes_received = 0;
            while ((bytes_received = recv(sock_fd, response, MAX_MSG_SIZE, 0)) > 0) {
                if (write(file_fd, response, bytes_received) < 0) {
                    perror("Error writing to file");
                    exit(1);
                }
            }
            close(file_fd);
            printf("File retrieved successfully\n");
        } else {
            printf("Invalid command\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(hostname, NULL, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "Error looking up IP address: %s\n", gai_strerror(status));
        exit(1);
    }

    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = ((struct sockaddr_in *) res->ai_addr)->sin_addr;
    freeaddrinfo(res);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("%s", receive_msg(sock_fd));

    ftp(sock_fd);

    return 0;
}