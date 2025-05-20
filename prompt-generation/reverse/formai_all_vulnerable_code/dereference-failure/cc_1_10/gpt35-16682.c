//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
 
#define MAX_RECV_BUF 1024
#define MAX_SEND_BUF 1024
 
void error_handler(char *msg);
void send_msg(int sockfd, char *msg);
void recv_msg(int sockfd, char *msg);
void send_file(int sockfd, char *filename);
void recv_file(int sockfd, char *filename);
 
int main(int argc, char *argv[]) {
    int sockfd;
    char *ip_address;
    char *port_number;
    char username[MAX_SEND_BUF];
    char password[MAX_SEND_BUF];
    char message[MAX_SEND_BUF];
    char filename[MAX_SEND_BUF];
    char buffer[MAX_RECV_BUF];
 
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-ip> <port-number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
 
    ip_address = argv[1];
    port_number = argv[2];
 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_handler("socket error");
    }
 
    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port_number));
    if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0) {
        error_handler("inet_pton error");
    }
 
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error_handler("connect error");
    }
 
    printf("Connected to Server...\n");
 
    recv_msg(sockfd, message);
    printf("Server: %s", message);
 
    printf("\nEnter Username: ");
    fgets(username, MAX_SEND_BUF, stdin);
    send_msg(sockfd, username);
 
    recv_msg(sockfd, message);
    printf("Server: %s", message);
 
    printf("Enter Password: ");
    fgets(password, MAX_SEND_BUF, stdin);
    send_msg(sockfd, password);
 
    recv_msg(sockfd, message);
    printf("Server: %s", message);
 
    while (1) {
        printf("Enter the command (get/put/close): ");
        scanf("%s", message);
 
        if (strcmp(message, "get") == 0) {
            printf("Enter Filename: ");
            scanf("%s", filename);
            send_msg(sockfd, message);
            send_msg(sockfd, filename);
            recv_msg(sockfd, buffer);
            if (strcmp(buffer, "File does not exist.\n") == 0) {
                printf("Server: %s", buffer);
                continue;
            }
            recv_file(sockfd, filename);
            printf("Server: File Received.\n");
        } else if (strcmp(message, "put") == 0) {
            printf("Enter Filename: ");
            scanf("%s", filename);
            send_msg(sockfd, message);
            send_msg(sockfd, filename);
            send_file(sockfd, filename);
            printf("Server: File Sent.\n");
        } else if (strcmp(message, "close") == 0) {
            send_msg(sockfd, message);
            recv_msg(sockfd, buffer);
            printf("Server: %s", buffer);
            break;
        } else {
            printf("Invalid Command!\n");
        }
    }
    close(sockfd);
    return 0;
}
 
void send_msg(int sockfd, char *msg) {
    if (write(sockfd, msg, strlen(msg)) < 0) {
        error_handler("write error");
    }
}
 
void recv_msg(int sockfd, char *msg) {
    int n;
    if ((n = read(sockfd, msg, MAX_RECV_BUF - 1)) < 0) {
        error_handler("read error");
    }
    msg[n] = '\0';
}
 
void send_file(int sockfd, char *filename) {
    FILE *file;
    char buffer[MAX_SEND_BUF];
    int n;
 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist.\n");
        return;
    }
 
    while ((n = fread(buffer, sizeof(char), MAX_SEND_BUF, file)) > 0) {
        if (write(sockfd, buffer, n) < 0) {
            error_handler("write error");
        }
    }
    fclose(file);
}
 
void recv_file(int sockfd, char *filename) {
    FILE *file;
    char buffer[MAX_RECV_BUF];
    int n;
 
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("File could not be created.\n");
        return;
    }
 
    while ((n = read(sockfd, buffer, MAX_RECV_BUF)) > 0) {
        if (n == -1) {
            error_handler("read error");
        }
        fwrite(buffer, sizeof(char), n, file);
        if (feof(file)) {
            break;
        }
    }
    fclose(file);
}
 
void error_handler(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}