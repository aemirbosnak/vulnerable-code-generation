//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUF 1024

char* send_receive(int sockfd, char* data) {
    char buffer[MAX_BUF];
    memset(buffer, 0, MAX_BUF);
    send(sockfd, data, strlen(data), 0);
    recv(sockfd, buffer, MAX_BUF, 0);
    return strdup(buffer);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Unable to create socket");
        return -1;
    }

    struct hostent* server = gethostbyname("imap.gmail.com");
    if(server == NULL) {
        printf("Unable to resolve host");
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(993);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed");
        return -1;
    }

    char username[MAX_BUF], password[MAX_BUF];
    printf("Username: ");
    fgets(username, MAX_BUF, stdin);
    printf("Password: ");
    fgets(password, MAX_BUF, stdin);

    char auth[MAX_BUF];
    snprintf(auth, MAX_BUF, "a001 LOGIN %s %s\r\n", username, password);
    char* response = send_receive(sockfd, auth);
    printf("%s", response);
    free(response);

    char* inbox = send_receive(sockfd, "a002 SELECT INBOX\r\n");
    printf("%s", inbox);
    free(inbox);

    char* uid = send_receive(sockfd, "a003 UID SEARCH ALL\r\n");
    printf("%s", uid);
    free(uid);

    char* logout = send_receive(sockfd, "a004 LOGOUT\r\n");
    printf("%s", logout);
    free(logout);

    close(sockfd);
    return 0;
}