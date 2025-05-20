//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT "21" /* FTP server port */
#define BUFFER_SIZE 1024 /* buffer size for file transfer */

void send_command(int sockfd, char* buffer, char* cmd) {
    char response[BUFFER_SIZE];
    int code = 0;
    /* send command to FTP server */
    printf(">> %s", cmd);
    write(sockfd, cmd, strlen(cmd));

    /* get server response */
    bzero(response, BUFFER_SIZE);
    while (1) {
        read(sockfd, response, BUFFER_SIZE);
        printf("%s", response);
        sscanf(response, "%d", &code); /* get response code */
        if (response[3] == ' ') break; /* check if end of response */
        bzero(response, BUFFER_SIZE); /* clear buffer */
    }

    /* check response code */
    if (code != 200 && code != 220 && code != 226 && code != 250 && code != 331 && code != 530) {
        fprintf(stderr, "Error: %s\n", response);
        close(sockfd); /* close socket if error occurs */
        exit(EXIT_FAILURE);
    }

    strcpy(buffer, response); /* copy server response to buffer */
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET_ADDRSTRLEN];
    char buffer[BUFFER_SIZE], cmd[BUFFER_SIZE], username[BUFFER_SIZE], password[BUFFER_SIZE];
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr,"Usage: ftp-client hostname\n");
        exit(EXIT_FAILURE);
    }

    /* initialize hints struct */
    bzero(&hints, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    /* get server info */
    if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    /* loop through all the results and connect to the first one */
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return 2;
    }

    /* convert IP address to string */
    inet_ntop(p->ai_family, &((struct sockaddr_in*)p->ai_addr)->sin_addr, s, sizeof s);
    printf("Connecting to %s...\n", s);

    freeaddrinfo(servinfo); /* free server info */

    /* get server banner */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    /* get username and password */
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);

    /* send username */
    sprintf(cmd, "USER %s", username);
    send_command(sockfd, buffer, cmd);

    /* send password */
    sprintf(cmd, "PASS %s", password);
    send_command(sockfd, buffer, cmd);

    /* enter passive mode */
    sprintf(cmd, "PASV\r\n");
    send_command(sockfd, buffer, cmd);

    /* parse server response to get IP address and port number for data transfer */
    char *pos = strchr(buffer, '(');
    int numbers[6];
    sscanf(++pos, "%d,%d,%d,%d,%d,%d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5]);
    char ip_address[16];
    sprintf(ip_address, "%d.%d.%d.%d", numbers[0], numbers[1], numbers[2], numbers[3]);
    int port = (numbers[4] << 8) + numbers[5];

    /* connect to data transfer port */
    struct sockaddr_in data_addr;
    bzero(&data_addr, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &(data_addr.sin_addr));

    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket == -1) {
        perror("data_socket");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (connect(data_socket, (struct sockaddr *)&data_addr, sizeof(data_addr)) == -1) {
        perror("data connect");
        close(sockfd);
        close(data_socket);
        exit(EXIT_FAILURE);
    }

    printf("Logged in.\n");

    /* send command to list files */
    sprintf(cmd, "LIST\r\n");
    send_command(sockfd, buffer, cmd);

    /* receive list of files */
    printf("File List:\n");
    bzero(buffer, BUFFER_SIZE);
    while ((n = read(data_socket, buffer, BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    close(sockfd);
    close(data_socket);

    printf("Connection closed.\n");

    return 0;
}