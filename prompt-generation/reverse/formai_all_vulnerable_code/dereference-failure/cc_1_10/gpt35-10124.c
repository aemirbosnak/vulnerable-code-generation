//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <arpa/inet.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <netdb.h>  
  
#define BUFFER_SIZE 1024  
#define MAX_COMMAND_LENGTH 1024  
  
void ftp_get(int sock, char *filename) {  
    FILE *file = fopen(filename, "wb");  
    if (file == NULL) {  
        fprintf(stderr, "Failed to open file %s\n", filename);  
        return;  
    }  
  
    char buffer[BUFFER_SIZE];  
    ssize_t bytes_read;  
  
    while ((bytes_read = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {  
        fwrite(buffer, 1, bytes_read, file);  
    }  
  
    fclose(file);  
}  
  
void ftp_put(int sock, char *filename) {  
    FILE *file = fopen(filename, "rb");  
    if (file == NULL) {  
        fprintf(stderr, "Failed to open file %s\n", filename);  
        return;  
    }  
  
    char buffer[BUFFER_SIZE];  
    ssize_t bytes_read;  
  
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {  
        send(sock, buffer, bytes_read, 0);  
    }  
  
    fclose(file);  
}  
  
void ftp_list(int sock) {  
    char buffer[MAX_COMMAND_LENGTH];  
    ssize_t bytes_read;  
  
    while ((bytes_read = recv(sock, buffer, MAX_COMMAND_LENGTH, 0)) > 0) {  
        write(STDOUT_FILENO, buffer, bytes_read);  
        if (bytes_read < MAX_COMMAND_LENGTH) {  
            break;  
        }  
    }  
}  
  
void ftp_quit(int sock) {  
    send(sock, "QUIT\n", 5, 0);  
}  
  
void ftp_help(void) {  
    write(STDOUT_FILENO, "Commands:\n", 10);  
    write(STDOUT_FILENO, "get <filename>\tDownload file from FTP server\n", 47);  
    write(STDOUT_FILENO, "put <filename>\tUpload file to FTP server\n", 41);  
    write(STDOUT_FILENO, "list\t\tList files on FTP server\n", 32);  
    write(STDOUT_FILENO, "quit\t\tDisconnect from FTP server\n", 36);  
    write(STDOUT_FILENO, "help\t\tDisplay this help message\n", 34);  
}  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);  
        exit(EXIT_FAILURE);  
    }  
  
    char *hostname = argv[1];  
    char *port = argv[2];  
  
    struct addrinfo hints;  
    struct addrinfo *result, *rp;  
    int sockfd;  
  
    memset(&hints, 0, sizeof(hints));  
    hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */  
    hints.ai_socktype = SOCK_STREAM; /* TCP socket */  
    hints.ai_flags = 0;  
  
    if (getaddrinfo(hostname, port, &hints, &result) != 0) {  
        perror("getaddrinfo failed");  
        exit(EXIT_FAILURE);  
    }  
  
    for (rp = result; rp != NULL; rp = rp->ai_next) {  
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);  
        if (sockfd == -1)  
            continue;  
  
        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1)  
            break;  
  
        close(sockfd);  
    }  
  
    if (rp == NULL) {  
        fprintf(stderr, "Failed to connect to %s\n", hostname);  
        exit(EXIT_FAILURE);  
    }  
  
    freeaddrinfo(result);  
  
    char buffer[MAX_COMMAND_LENGTH];  
    ssize_t bytes_read;  
  
    while (1) {  
        write(STDOUT_FILENO, "> ", 2);  
        bytes_read = read(STDIN_FILENO, buffer, MAX_COMMAND_LENGTH);  
        if (bytes_read == -1) {  
            perror("Failed to read input");  
            continue;  
        }  
  
        buffer[bytes_read - 1] = '\0';  
  
        if (strcmp(buffer, "quit") == 0) {  
            ftp_quit(sockfd);  
            exit(EXIT_SUCCESS);  
        } else if (strcmp(buffer, "help") == 0) {  
            ftp_help();  
            continue;  
        }  
  
        char *command = strtok(buffer, " ");  
        char *filename = strtok(NULL, " ");  
  
        if (command == NULL) {  
            continue;  
        }  
  
        if (strcasecmp(command, "get") == 0) {  
            if (filename == NULL) {  
                write(STDOUT_FILENO, "Usage: get <filename>\n", 22);  
                continue;  
            }  
  
            send(sockfd, buffer, bytes_read, 0);  
            ftp_get(sockfd, filename);  
        } else if (strcasecmp(command, "put") == 0) {  
            if (filename == NULL) {  
                write(STDOUT_FILENO, "Usage: put <filename>\n", 22);  
                continue;  
            }  
  
            send(sockfd, buffer, bytes_read, 0);  
            ftp_put(sockfd, filename);  
        } else if (strcasecmp(command, "list") == 0) {  
            send(sockfd, buffer, bytes_read, 0);  
            ftp_list(sockfd);  
        } else {  
            write(STDOUT_FILENO, "Unrecognized command\n", 21);  
        }  
    }  
  
    return EXIT_SUCCESS;  
}