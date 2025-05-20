//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 21

int main(int argc, char *argv[])
{
    // Variables declaration
    int sockfd, port = SERVER_PORT, newsockfd, client_len;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Checking arguments
    if (argc < 2) {
        printf("Usage: %s hostname [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc > 2) {
        port = atoi(argv[2]);
        if (port <= 0 || port > 65535) {
            printf("Invalid port %d\n", port);
            exit(EXIT_FAILURE);
        }
    }

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Resolving hostname to IP address
    server = gethostbyname(argv[1]);
    if (!server) {
        printf("Error: no such host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Setting server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Getting welcome message from server
    char buf[BUFSIZ];
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // User authentication
    printf("Name (%s): ", argv[1]);
    fgets(buf, sizeof(buf), stdin);
    if (buf[strlen(buf) - 1] == '\n') {
        buf[strlen(buf) - 1] = '\0';
    }
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    printf("Password: ");
    fgets(buf, sizeof(buf), stdin);
    if (buf[strlen(buf) - 1] == '\n') {
        buf[strlen(buf) - 1] = '\0';
    }
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Main loop
    while (1) {
        printf("ftp> ");
        fgets(buf, sizeof(buf), stdin);
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = '\0';
        }

        // Listing files on the server
        if (strcmp(buf, "ls") == 0) {
            send(sockfd, buf, strlen(buf), 0);
            recv(sockfd, buf, sizeof(buf), 0);
            printf("%s", buf);

        // Downloading a file from the server
        } else if (strncmp(buf, "get ", 4) == 0) {
            send(sockfd, buf, strlen(buf), 0);
            char filename[BUFSIZ];
            snprintf(filename, BUFSIZ, "%s", buf + 4);

            FILE *fp = fopen(filename, "wb");
            if (!fp) {
                printf("Error: could not create file %s\n", filename);
                continue;
            }

            int bytes_recv = 0;
            while ((bytes_recv = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
                fwrite(buf, 1, bytes_recv, fp);
            }
            fclose(fp);

        // Uploading a file to the server
        } else if (strncmp(buf, "put ", 4) == 0) {
            send(sockfd, buf, strlen(buf), 0);
            char filename[BUFSIZ];
            snprintf(filename, BUFSIZ, "%s", buf + 4);

            FILE *fp = fopen(filename, "rb");
            if (!fp) {
                printf("Error: could not open file %s\n", filename);
                continue;
            }

            int bytes_sent = 0;
            while ((bytes_sent = fread(buf, 1, sizeof(buf), fp)) > 0) {
                send(sockfd, buf, bytes_sent, 0);
            }
            fclose(fp);

        // Changing working directory on the server
        } else if (strncmp(buf, "cd ", 3) == 0) {
            send(sockfd, buf, strlen(buf), 0);
            recv(sockfd, buf, sizeof(buf), 0);
            printf("%s", buf);

        // Quitting
        } else if (strcmp(buf, "quit") == 0) {
            send(sockfd, buf, strlen(buf), 0);
            break;

        // Invalid command
        } else {
            printf("Error: invalid command\n");
        }
    }

    // Closing connection
    close(sockfd);

    printf("Thank you for using our FTP client!\n");

    return 0;
}