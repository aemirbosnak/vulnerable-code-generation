//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>

int connect_to_server(char *hostname, int port)
{
    struct hostent *he;
    struct sockaddr_in server_addr;
    int socket_fd;

    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    if (connect(socket_fd, (struct sockaddr *)&server_addr,
                sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    return socket_fd;
}

void download_file(int socket_fd, char *filename)
{
    FILE *fp;
    char buffer[1024];
    int bytes_received = 0;

    if ((fp = fopen(filename, "wb")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);
}

void upload_file(int socket_fd, char *filename)
{
    FILE *fp;
    char buffer[1024];
    int bytes_read = 0;

    if ((fp = fopen(filename, "rb")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        send(socket_fd, buffer, bytes_read, 0);
    }

    fclose(fp);
}

int main(int argc, char **argv)
{
    char *hostname;
    int port;
    int socket_fd;
    char command[1024];
    char filename[1024];
    char *token;

    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    socket_fd = connect_to_server(hostname, port);

    printf("Connected to %s:%d\n", hostname, port);

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command)-1] = '\0';

        if (strcmp(command, "quit") == 0) {
            printf("Exiting...\n");
            break;
        }

        if (strncmp(command, "get ", 4) == 0) {
            token = strtok(command, " ");
            token = strtok(NULL, " ");
            strcpy(filename, token);
            download_file(socket_fd, filename);
            printf("File downloaded: %s\n", filename);
        }

        if (strncmp(command, "put ", 4) == 0) {
            token = strtok(command, " ");
            token = strtok(NULL, " ");
            strcpy(filename, token);
            upload_file(socket_fd, filename);
            printf("File uploaded: %s\n", filename);
        }
    }

    close(socket_fd);

    return 0;
}