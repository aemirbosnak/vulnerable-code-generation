//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define CMD_SIZE 128

char username[BUF_SIZE];
char password[BUF_SIZE];
char folder[BUF_SIZE];
char last_seq[BUF_SIZE];

void imap_send(int sockfd, const char* cmd) {
    char buffer[BUF_SIZE];
    int n = sprintf(buffer, "%s\r\n", cmd);
    send(sockfd, buffer, n, 0);

    printf("\n%s\n", cmd);
}

int imap_recv(int sockfd, char* buffer, int buffer_size) {
    int n = recv(sockfd, buffer, buffer_size, 0);

    if (n > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
    } else {
        buffer[0] = 0;
    }

    return n;
}

int imap_login(int sockfd) {
    char buffer[BUF_SIZE];
    int n = imap_recv(sockfd, buffer, BUF_SIZE);

    sprintf(buffer, "LOGIN %s %s", username, password);
    imap_send(sockfd, buffer);

    n = imap_recv(sockfd, buffer, BUF_SIZE);

    if (strstr(buffer, "OK") != NULL) {
        return 1;
    } else {
        return 0;
    }
}

int imap_select(int sockfd) {
    char buffer[BUF_SIZE];
    int n = imap_recv(sockfd, buffer, BUF_SIZE);

    sprintf(buffer, "SELECT %s", folder);
    imap_send(sockfd, buffer);

    n = imap_recv(sockfd, buffer, BUF_SIZE);

    if (strstr(buffer, "OK") != NULL) {
        sscanf(buffer, "* %[^ ] EXISTS", last_seq);
        return 1;
    } else {
        return 0;
    }
}

int imap_fetch(int sockfd, int seq) {
    char buffer[BUF_SIZE];
    int n = imap_recv(sockfd, buffer, BUF_SIZE);

    sprintf(buffer, "FETCH %d BODY[TEXT]", seq);
    imap_send(sockfd, buffer);

    n = imap_recv(sockfd, buffer, BUF_SIZE);

    return n;
}

void imap_logout(int sockfd) {
    char buffer[BUF_SIZE];
    int n = imap_recv(sockfd, buffer, BUF_SIZE);

    imap_send(sockfd, "LOGOUT");
    close(sockfd);
}

int main(int argc, char** argv) {
    // get username and password from command line arguments
    if (argc != 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    strncpy(username, argv[1], BUF_SIZE - 1);
    strncpy(password, argv[2], BUF_SIZE - 1);

    printf("Username: %s\n", username);
    printf("Password: %s\n", password);

    // connect to IMAP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket()");
        return 1;
    }

    struct hostent* server = gethostbyname("imap.example.com");
    if (server == NULL) {
        perror("gethostbyname()");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(993);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect()");
        return 1;
    }

    // login to IMAP server
    if (!imap_login(sockfd)) {
        printf("Error: Login failed\n");
        imap_logout(sockfd);
        return 1;
    }

    // select folder on IMAP server
    strncpy(folder, "INBOX", BUF_SIZE - 1);
    if (!imap_select(sockfd)) {
        printf("Error: Folder select failed\n");
        imap_logout(sockfd);
        return 1;
    }

    // fetch messages from IMAP server
    int seq;
    for (seq = 1; seq <= atoi(last_seq); seq++) {
        if (imap_fetch(sockfd, seq) < 0) {
            printf("Error: Message fetch failed\n");
            imap_logout(sockfd);
            return 1;
        }
    }

    // logout from IMAP server
    imap_logout(sockfd);

    return 0;
}