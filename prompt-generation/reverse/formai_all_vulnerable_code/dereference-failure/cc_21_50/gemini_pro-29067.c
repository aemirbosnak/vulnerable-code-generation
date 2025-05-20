//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *server_type, *user, *pass, *command, *response;
    int num_messages, message_size;

    if (argc < 5) {
        fprintf(stderr, "Usage: %s <server_type> <server_name> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    server_type = argv[1];
    const char *server_name = argv[2];
    portno = atoi(argv[3]);
    user = argv[4];
    pass = argv[5];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server = gethostbyname(server_name);
    if (server == NULL) {
        perror("gethostbyname");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (strcmp(server_type, "imap") == 0) {
        command = "A1 LOGIN %s %s";
    } else if (strcmp(server_type, "pop") == 0) {
        command = "USER %s\r\nPASS %s\r\n";
    } else {
        fprintf(stderr, "Unsupported server type: %s\n", server_type);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    response = malloc(1024);
    memset(response, 0, 1024);
    if (recv(sockfd, response, 1024, 0) < 0) {
        perror("recv");
        return 1;
    }

    if (strstr(response, "+OK") == NULL) {
        fprintf(stderr, "Server error: %s\n", response);
        return 1;
    }

    snprintf(response, 1024, command, user, pass);
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send");
        return 1;
    }

    memset(response, 0, 1024);
    if (recv(sockfd, response, 1024, 0) < 0) {
        perror("recv");
        return 1;
    }

    if (strstr(response, "+OK") == NULL) {
        fprintf(stderr, "Authentication error: %s\n", response);
        return 1;
    }

    if (strcmp(server_type, "imap") == 0) {
        command = "A2 SELECT INBOX";
    } else if (strcmp(server_type, "pop") == 0) {
        command = "LIST";
    }

    snprintf(response, 1024, command);
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send");
        return 1;
    }

    memset(response, 0, 1024);
    if (recv(sockfd, response, 1024, 0) < 0) {
        perror("recv");
        return 1;
    }

    if (strcmp(server_type, "imap") == 0) {
        if (strstr(response, "+OK") == NULL) {
            fprintf(stderr, "Mailbox selection error: %s\n", response);
            return 1;
        }
    } else if (strcmp(server_type, "pop") == 0) {
        if (strstr(response, "+OK") == NULL) {
            fprintf(stderr, "Message listing error: %s\n", response);
            return 1;
        }

        num_messages = 0;
        message_size = 0;
        while (strstr(response, "+OK") == NULL) {
            memset(response, 0, 1024);
            if (recv(sockfd, response, 1024, 0) < 0) {
                perror("recv");
                return 1;
            }

            num_messages++;
            message_size += atoi(strtok(response, " "));
        }

        printf("Number of messages: %d\n", num_messages);
        printf("Total message size: %d bytes\n", message_size);
    }

    if (strcmp(server_type, "imap") == 0) {
        command = "A4 LOGOUT";
    } else if (strcmp(server_type, "pop") == 0) {
        command = "QUIT";
    }

    snprintf(response, 1024, command);
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send");
        return 1;
    }

    memset(response, 0, 1024);
    if (recv(sockfd, response, 1024, 0) < 0) {
        perror("recv");
        return 1;
    }

    if (strstr(response, "+OK") == NULL) {
        fprintf(stderr, "Logout error: %s\n", response);
        return 1;
    }

    close(sockfd);
    free(response);
    return 0;
}