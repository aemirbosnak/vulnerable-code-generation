//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *user = argv[2];

    struct hostent *he = gethostbyname(server);
    if (he == NULL) {
        printf("Unable to resolve server name '%s'\n", server);
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char recv_buf[1024];
    int num_bytes = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (num_bytes < 3 || recv_buf[0] != '+' || recv_buf[1] != 'O' || recv_buf[2] != 'K') {
        printf("Unexpected response: %s\n", recv_buf);
        return 1;
    }

    char send_buf[1024];
    snprintf(send_buf, sizeof(send_buf), "USER %s\r\n", user);
    if (send(sock, send_buf, strlen(send_buf), 0) < 0) {
        printf("Error sending data\n");
        return 1;
    }

    num_bytes = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (num_bytes < 3 || recv_buf[0] != '+' || recv_buf[1] != 'O' || recv_buf[2] != 'K') {
        printf("Unexpected response: %s\n", recv_buf);
        return 1;
    }

    snprintf(send_buf, sizeof(send_buf), "PASS ");
    size_t len = strlen(send_buf);
    fgets(send_buf + len, sizeof(send_buf) - len, stdin);
    len += strlen(send_buf + len);
    send_buf[len - 1] = '\r';
    send_buf[len] = '\n';
    send_buf[len + 1] = '\0';

    if (send(sock, send_buf, strlen(send_buf), 0) < 0) {
        printf("Error sending data\n");
        return 1;
    }

    num_bytes = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (num_bytes < 3 || recv_buf[0] != '+' || recv_buf[1] != 'O' || recv_buf[2] != 'K') {
        printf("Unexpected response: %s\n", recv_buf);
        return 1;
    }

    snprintf(send_buf, sizeof(send_buf), "STAT\r\n");
    if (send(sock, send_buf, strlen(send_buf), 0) < 0) {
        printf("Error sending data\n");
        return 1;
    }

    num_bytes = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (num_bytes < 3 || recv_buf[0] != '+' || recv_buf[1] != 'O' || recv_buf[2] != 'K') {
        printf("Unexpected response: %s\n", recv_buf);
        return 1;
    }

    int num_messages = 0;
    int total_size = 0;
    sscanf(recv_buf, "+OK %d %d", &num_messages, &total_size);
    printf("You have %d messages (%d bytes)\n", num_messages, total_size);

    for (int i = 1; i <= num_messages; i++) {
        snprintf(send_buf, sizeof(send_buf), "LIST %d\r\n", i);
        if (send(sock, send_buf, strlen(send_buf), 0) < 0) {
            printf("Error sending data\n");
            return 1;
        }

        num_bytes = recv(sock, recv_buf, sizeof(recv_buf), 0);
        if (num_bytes < 3 || recv_buf[0] != '+' || recv_buf[1] != 'O' || recv_buf[2] != 'K') {
            printf("Unexpected response: %s\n", recv_buf);
            return 1;
        }

        int message_size = 0;
        sscanf(recv_buf, "+OK %*d %d", &message_size);
        printf("Message %d is %d bytes:\n", i, message_size);

        snprintf(send_buf, sizeof(send_buf), "RETR %d\r\n", i);
        if (send(sock, send_buf, strlen(send_buf), 0) < 0) {
            printf("Error sending data\n");
            return 1;
        }

        while ((num_bytes = recv(sock, recv_buf, sizeof(recv_buf), 0)) > 0) {
            fwrite(recv_buf, 1, num_bytes, stdout);
            if (num_bytes < sizeof(recv_buf)) break;
        }

        if (num_bytes < 0) {
            printf("Error receiving data\n");
            return 1;
        }

        printf("\n\n");
    }

    snprintf(send_buf, sizeof(send_buf), "QUIT\r\n");
    if (send(sock, send_buf, strlen(send_buf), 0) < 0) {
        printf("Error sending data\n");
        return 1;
    }

    num_bytes = recv(sock, recv_buf, sizeof(recv_buf), 0);
    if (num_bytes < 3 || recv_buf[0] != '+' || recv_buf[1] != 'O' || recv_buf[2] != 'K') {
        printf("Unexpected response: %s\n", recv_buf);
        return 1;
    }

    return 0;
}