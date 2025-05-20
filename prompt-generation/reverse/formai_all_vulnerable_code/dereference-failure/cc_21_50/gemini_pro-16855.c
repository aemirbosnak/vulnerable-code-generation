//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define POP3_PORT 110

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char *username = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[1024];
    ret = read(sockfd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid POP3 response: %s\n", buf);
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    ret = write(sockfd, buf, strlen(buf));
    if (ret == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid POP3 response: %s\n", buf);
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "PASS *******\r\n");
    ret = write(sockfd, buf, strlen(buf));
    if (ret == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid POP3 response: %s\n", buf);
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "LIST\r\n");
    ret = write(sockfd, buf, strlen(buf));
    if (ret == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid POP3 response: %s\n", buf);
        return EXIT_FAILURE;
    }

    int num_messages = 0;
    int total_size = 0;
    char *line = NULL;
    while ((line = strsep(&buf, "\r\n")) != NULL) {
        if (strlen(line) == 0) {
            continue;
        }
        if (line[0] == '.') {
            break;
        }
        int message_num;
        int message_size;
        ret = sscanf(line, "%d %d", &message_num, &message_size);
        if (ret != 2) {
            fprintf(stderr, "Invalid POP3 response: %s\n", line);
            return EXIT_FAILURE;
        }
        num_messages++;
        total_size += message_size;
    }

    printf("Number of messages: %d\n", num_messages);
    printf("Total size: %d bytes\n", total_size);

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    ret = write(sockfd, buf, strlen(buf));
    if (ret == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid POP3 response: %s\n", buf);
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}