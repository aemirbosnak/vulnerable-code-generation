//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

typedef struct {
    int sockfd;
    struct sockaddr_in servaddr;
} smtp_client_t;

smtp_client_t *smtp_client_create(const char *host) {
    smtp_client_t *client = malloc(sizeof(smtp_client_t));
    if (!client) {
        perror("malloc");
        return NULL;
    }

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        perror("socket");
        free(client);
        return NULL;
    }

    memset(&client->servaddr, 0, sizeof(client->servaddr));
    client->servaddr.sin_family = AF_INET;
    client->servaddr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, host, &client->servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        close(client->sockfd);
        free(client);
        return NULL;
    }

    return client;
}

void smtp_client_destroy(smtp_client_t *client) {
    close(client->sockfd);
    free(client);
}

int smtp_client_connect(smtp_client_t *client) {
    if (connect(client->sockfd, (struct sockaddr *)&client->servaddr, sizeof(client->servaddr)) < 0) {
        perror("connect");
        return -1;
    }

    return 0;
}

int smtp_client_send_command(smtp_client_t *client, const char *command) {
    int n = send(client->sockfd, command, strlen(command), 0);
    if (n < 0) {
        perror("send");
        return -1;
    }

    return n;
}

char *smtp_client_receive_response(smtp_client_t *client) {
    char *response = malloc(1024);
    if (!response) {
        perror("malloc");
        return NULL;
    }

    int n = recv(client->sockfd, response, 1024, 0);
    if (n < 0) {
        perror("recv");
        free(response);
        return NULL;
    }

    response[n] = '\0';
    return response;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s host message\n", argv[0]);
        return EXIT_FAILURE;
    }

    smtp_client_t *client = smtp_client_create(argv[1]);
    if (!client) {
        return EXIT_FAILURE;
    }

    if (smtp_client_connect(client) < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    char *response = smtp_client_receive_response(client);
    if (!response) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", response);
    free(response);

    if (smtp_client_send_command(client, "HELO localhost\r\n") < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    response = smtp_client_receive_response(client);
    if (!response) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", response);
    free(response);

    if (smtp_client_send_command(client, "MAIL FROM: <sender@localhost>\r\n") < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    response = smtp_client_receive_response(client);
    if (!response) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", response);
    free(response);

    if (smtp_client_send_command(client, "RCPT TO: <recipient@localhost>\r\n") < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    response = smtp_client_receive_response(client);
    if (!response) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", response);
    free(response);

    if (smtp_client_send_command(client, "DATA\r\n") < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    response = smtp_client_receive_response(client);
    if (!response) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", response);
    free(response);

    if (smtp_client_send_command(client, argv[2]) < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    if (smtp_client_send_command(client, "\r\n.\r\n") < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    response = smtp_client_receive_response(client);
    if (!response) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", response);
    free(response);

    if (smtp_client_send_command(client, "QUIT\r\n") < 0) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    response = smtp_client_receive_response(client);
    if (!response) {
        smtp_client_destroy(client);
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", response);
    free(response);

    smtp_client_destroy(client);

    return EXIT_SUCCESS;
}