//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024
#define SMTP_PORT 25

// write a line to a socket
void write_line(int sockfd, char *line) {
    int len = strlen(line);
    if (send(sockfd, line, len, 0) < 0) {
        perror("send");
        exit(-1);
    }
    if (send(sockfd, "\r\n", 2, 0) < 0) {
        perror("send");
        exit(-1);
    }
}

// read a line from a socket
char *read_line(int sockfd) {
    char *buf = malloc(MAX_BUF_SIZE);
    int len = 0;
    while (1) {
        int r = recv(sockfd, &buf[len], 1, 0);
        if (r < 0) {
            perror("recv");
            exit(-1);
        }
        if (r == 0) {
            break;
        }
        if (buf[len] == '\r') {
            continue;
        }
        if (buf[len] == '\n') {
            break;
        }
        len++;
    }
    buf[len] = '\0';
    return buf;
}

// connect to a SMTP server
int connect_to_server(char *hostname) {
    struct hostent *hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(-1);
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(-1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)hostinfo->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }
    return sockfd;
}

// send an email message
int send_email(int sockfd, char *from, char *to, char *subject, char *message) {
    // write the HELO command
    write_line(sockfd, "HELO localhost");
    char *line = read_line(sockfd);
    if (strncmp(line, "250", 3) != 0) {
        fprintf(stderr, "HELO failed: %s\n", line);
        return -1;
    }

    // write the MAIL FROM command
    char buf[MAX_BUF_SIZE];
    sprintf(buf, "MAIL FROM: <%s>", from);
    write_line(sockfd, buf);
    line = read_line(sockfd);
    if (strncmp(line, "250", 3) != 0) {
        fprintf(stderr, "MAIL FROM failed: %s\n", line);
        return -1;
    }

    // write the RCPT TO command
    sprintf(buf, "RCPT TO: <%s>", to);
    write_line(sockfd, buf);
    line = read_line(sockfd);
    if (strncmp(line, "250", 3) != 0) {
        fprintf(stderr, "RCPT TO failed: %s\n", line);
        return -1;
    }

    // write the DATA command
    write_line(sockfd, "DATA");
    line = read_line(sockfd);
    if (strncmp(line, "354", 3) != 0) {
        fprintf(stderr, "DATA failed: %s\n", line);
        return -1;
    }

    // write the subject line
    sprintf(buf, "Subject: %s", subject);
    write_line(sockfd, buf);

    // write the message body
    write_line(sockfd, message);

    // write the dot to end the message
    write_line(sockfd, ".");

    // write the QUIT command
    write_line(sockfd, "QUIT");
    line = read_line(sockfd);
    if (strncmp(line, "221", 3) != 0) {
        fprintf(stderr, "QUIT failed: %s\n", line);
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <hostname> <from> <to> <subject> <message>\n", argv[0]);
        exit(-1);
    }

    int sockfd = connect_to_server(argv[1]);
    if (sockfd < 0) {
        exit(-1);
    }

    int r = send_email(sockfd, argv[2], argv[3], argv[4], argv[5]);
    if (r < 0) {
        exit(-1);
    }

    close(sockfd);
    return 0;
}