//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

// constants
#define BUF_SIZE 1024
#define PORT 21

// function declarations
int connect_to_server(char *host);
int send_command(int sock, char *cmd);
int receive_response(int sock, char *buf);

int main(int argc, char **argv) {
    // check if the correct number of arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // connect to the FTP server
    int sock = connect_to_server(argv[1]);
    if (sock == -1) {
        fprintf(stderr, "Error connecting to the server.\n");
        return EXIT_FAILURE;
    }

    // send the USER command
    if (send_command(sock, "USER anonymous") == -1) {
        fprintf(stderr, "Error sending the USER command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // receive the response to the USER command
    char buf[BUF_SIZE];
    if (receive_response(sock, buf) == -1) {
        fprintf(stderr, "Error receiving the response to the USER command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // send the PASS command
    if (send_command(sock, "PASS ") == -1) {
        fprintf(stderr, "Error sending the PASS command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // receive the response to the PASS command
    if (receive_response(sock, buf) == -1) {
        fprintf(stderr, "Error receiving the response to the PASS command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // send the CWD command
    if (send_command(sock, "CWD /") == -1) {
        fprintf(stderr, "Error sending the CWD command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // receive the response to the CWD command
    if (receive_response(sock, buf) == -1) {
        fprintf(stderr, "Error receiving the response to the CWD command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // send the RETR command
    if (send_command(sock, "RETR ") == -1) {
        fprintf(stderr, "Error sending the RETR command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // receive the response to the RETR command
    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    while (1) {
        if (receive_response(sock, buf) == -1) {
            fprintf(stderr, "Error receiving the response to the RETR command.\n");
            close(sock);
            fclose(fp);
            return EXIT_FAILURE;
        }

        if (strncmp(buf, "226 Transfer complete.", 22) == 0) {
            break;
        }

        fwrite(buf, 1, strlen(buf), fp);
    }

    fclose(fp);

    // send the QUIT command
    if (send_command(sock, "QUIT") == -1) {
        fprintf(stderr, "Error sending the QUIT command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // receive the response to the QUIT command
    if (receive_response(sock, buf) == -1) {
        fprintf(stderr, "Error receiving the response to the QUIT command.\n");
        close(sock);
        return EXIT_FAILURE;
    }

    // close the socket
    close(sock);

    return EXIT_SUCCESS;
}

int connect_to_server(char *host) {
    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    // get the IP address of the server
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        close(sock);
        return -1;
    }

    // connect to the server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sock);
        return -1;
    }

    return sock;
}

int send_command(int sock, char *cmd) {
    // send the command to the server
    int len = strlen(cmd);
    if (send(sock, cmd, len, 0) != len) {
        perror("send");
        return -1;
    }

    // send a newline character
    if (send(sock, "\n", 1, 0) != 1) {
        perror("send");
        return -1;
    }

    return 0;
}

int receive_response(int sock, char *buf) {
    // receive the response from the server
    int len = recv(sock, buf, BUF_SIZE - 1, 0);
    if (len == -1) {
        perror("recv");
        return -1;
    }

    buf[len] = '\0';

    return 0;
}