//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_PORT 8080
#define DEFAULT_HOST "localhost"
#define DEFAULT_BUFFER_SIZE 1024

typedef struct {
    char *host;
    int port;
    int buffer_size;
} configuration;

configuration *parse_config(int argc, char **argv) {
    configuration *config = malloc(sizeof(configuration));
    config->host = DEFAULT_HOST;
    config->port = DEFAULT_PORT;
    config->buffer_size = DEFAULT_BUFFER_SIZE;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            config->host = argv[++i];
        } else if (strcmp(argv[i], "-p") == 0) {
            config->port = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-b") == 0) {
            config->buffer_size = atoi(argv[++i]);
        }
    }

    return config;
}

int main(int argc, char **argv) {
    configuration *config = parse_config(argc, argv);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(config->port);
    serv_addr.sin_addr.s_addr = inet_addr(config->host);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buffer[config->buffer_size];
    while (1) {
        printf("Enter message: ");
        fgets(buffer, config->buffer_size, stdin);
        write(sockfd, buffer, strlen(buffer));

        memset(buffer, 0, config->buffer_size);
        read(sockfd, buffer, config->buffer_size);
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}