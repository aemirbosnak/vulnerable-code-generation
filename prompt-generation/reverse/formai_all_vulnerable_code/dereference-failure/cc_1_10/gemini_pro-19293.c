//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} connection_t;

typedef struct {
    char *name;
    int value;
} sensor_t;

sensor_t sensors[] = {
    {"temperature", 25},
    {"humidity", 50},
    {"light", 100},
};

void *handle_connection(void *arg) {
    connection_t *conn = (connection_t *)arg;

    char buffer[1024];
    int n;

    while ((n = read(conn->sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';

        char *cmd = strtok(buffer, " ");
        char *args = strtok(NULL, " ");

        if (strcmp(cmd, "get") == 0) {
            if (args == NULL) {
                write(conn->sockfd, "ERR: Invalid arguments\n", strlen("ERR: Invalid arguments\n"));
                continue;
            }

            int i;
            for (i = 0; i < sizeof(sensors) / sizeof(sensor_t); i++) {
                if (strcmp(sensors[i].name, args) == 0) {
                    char response[1024];
                    sprintf(response, "%s: %d\n", sensors[i].name, sensors[i].value);
                    write(conn->sockfd, response, strlen(response));
                    break;
                }
            }

            if (i == sizeof(sensors) / sizeof(sensor_t)) {
                write(conn->sockfd, "ERR: Unknown sensor\n", strlen("ERR: Unknown sensor\n"));
            }
        } else if (strcmp(cmd, "set") == 0) {
            if (args == NULL || strtok(NULL, " ") == NULL) {
                write(conn->sockfd, "ERR: Invalid arguments\n", strlen("ERR: Invalid arguments\n"));
                continue;
            }

            int i;
            for (i = 0; i < sizeof(sensors) / sizeof(sensor_t); i++) {
                if (strcmp(sensors[i].name, args) == 0) {
                    sensors[i].value = atoi(strtok(NULL, " "));
                    write(conn->sockfd, "OK\n", strlen("OK\n"));
                    break;
                }
            }

            if (i == sizeof(sensors) / sizeof(sensor_t)) {
                write(conn->sockfd, "ERR: Unknown sensor\n", strlen("ERR: Unknown sensor\n"));
            }
        } else {
            write(conn->sockfd, "ERR: Unknown command\n", strlen("ERR: Unknown command\n"));
        }
    }

    close(conn->sockfd);
    free(conn);

    return NULL;
}

int main() {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, MAX_CONNECTIONS);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        connection_t *conn = malloc(sizeof(connection_t));
        conn->sockfd = newsockfd;
        conn->addr = cli_addr;

        pthread_t thread;
        pthread_create(&thread, NULL, handle_connection, (void *)conn);
    }

    close(sockfd);

    return 0;
}