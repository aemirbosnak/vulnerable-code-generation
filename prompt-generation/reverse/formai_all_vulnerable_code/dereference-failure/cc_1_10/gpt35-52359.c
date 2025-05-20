//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

/** 
 * pop3_read - Reads a full line from the POP3 server
 * sockfd: The socket descriptor
 * buf: The buffer to store the response
 * buf_size: The size of the buffer
 **/
int pop3_read(int sockfd, char *buf, size_t buf_size) {
    ssize_t n_read;
    size_t n_total = 0;
    while (1) {
        n_read = read(sockfd, buf + n_total, buf_size - n_total);
        if (n_read <= 0) {
            return -1;
        }
        n_total += n_read;
        if (buf[n_total - 1] == '\n') {
            break;
        }
    }
    buf[n_total] = '\0';
    return n_total;
}

/**
 * pop3_login - Logs in to the POP3 server
 * sockfd: The socket descriptor
 * username: The username to use for login
 * password: The password to use for login
 **/
int pop3_login(int sockfd, const char *username, const char *password) {
    char buf[1024];
    int status;

    sprintf(buf, "USER %s\r\n", username);
    write(sockfd, buf, strlen(buf));
    pop3_read(sockfd, buf, sizeof(buf));
    sscanf(buf, "+OK %d", &status);
    if (status != 0) {
        return status;
    }

    sprintf(buf, "PASS %s\r\n", password);
    write(sockfd, buf, strlen(buf));
    pop3_read(sockfd, buf, sizeof(buf));
    sscanf(buf, "+OK %d", &status);
    if (status != 0) {
        return status;
    }

    return 0;
}

/**
 * pop3_list - Lists all messages on the POP3 server
 * sockfd: The socket descriptor
 * msg_list: The buffer to store the message list
 **/
int pop3_list(int sockfd, char *msg_list) {
    char buf[1024];
    int status;
    sprintf(buf, "LIST\r\n");
    write(sockfd, buf, strlen(buf));
    pop3_read(sockfd, buf, sizeof(buf));
    sscanf(buf, "+OK %d", &status);
    if (status != 0) {
        return status;
    }

    while (pop3_read(sockfd, buf, sizeof(buf)) > 0) {
        if (buf[0] == '.') {
            break;
        }
        strcat(msg_list, buf);
    }

    return 0;
}

/**
 * pop3_retrieve - Retrieves a message from the POP3 server
 * sockfd: The socket descriptor
 * msg_num: The index of the message to retrieve
 * msg: The buffer to store the message
 **/
int pop3_retrieve(int sockfd, int msg_num, char *msg) {
    char buf[1024];
    int status;
    sprintf(buf, "RETR %d\r\n", msg_num);
    write(sockfd, buf, strlen(buf));
    pop3_read(sockfd, buf, sizeof(buf));
    sscanf(buf, "+OK %d", &status);
    if (status != 0) {
        return status;
    }

    while (pop3_read(sockfd, buf, sizeof(buf)) > 0) {
        if (buf[0] == '.') {
            break;
        }
        strcat(msg, buf);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buf[1024];
    char msg_list[4096];
    char msg[16384];

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    pop3_read(sockfd, buf, sizeof(buf));
    printf("%s", buf);

    pop3_login(sockfd, "username", "password");

    pop3_list(sockfd, msg_list);
    printf("%s", msg_list);

    pop3_retrieve(sockfd, 1, msg);
    printf("%s", msg);

    return 0;
}