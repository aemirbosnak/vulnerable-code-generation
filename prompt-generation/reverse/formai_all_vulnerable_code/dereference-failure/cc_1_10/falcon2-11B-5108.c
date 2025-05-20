//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

int main() {
    int socket_fd, rc;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char command[100], buf[1024];

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // initialize server address
    server = gethostbyname("example.com");
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(110);

    // connect to server
    rc = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (rc < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // login
    printf("Username: ");
    scanf("%s", command);
    bzero(buf, sizeof(buf));
    strcpy(buf, "USER ");
    strcat(buf, command);
    write(socket_fd, buf, strlen(buf));
    printf("Enter password: ");
    scanf("%s", command);
    bzero(buf, sizeof(buf));
    strcpy(buf, "PASS ");
    strcat(buf, command);
    write(socket_fd, buf, strlen(buf));

    // retrieve emails
    printf("Retrieving emails...\n");
    while (1) {
        bzero(buf, sizeof(buf));
        read(socket_fd, buf, sizeof(buf));
        if (strncmp(buf, "OK", 2) == 0) {
            printf("Email received:\n%s\n", buf);
        } else if (strncmp(buf, "NO", 2) == 0) {
            printf("No more emails available.\n");
            break;
        } else if (strncmp(buf, "ERR", 3) == 0) {
            printf("Error: %s\n", buf);
            break;
        }
    }

    // logout
    printf("Logging out...\n");
    bzero(buf, sizeof(buf));
    strcpy(buf, "QUIT");
    write(socket_fd, buf, strlen(buf));

    close(socket_fd);
    return 0;
}