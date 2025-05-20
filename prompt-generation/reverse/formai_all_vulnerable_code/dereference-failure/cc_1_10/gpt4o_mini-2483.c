//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_LINE 1024
#define PORT 8080
#define BUFFER_SIZE 2048

typedef struct {
    int sock;
    struct sockaddr_in client;
} connection_t;

void *connection_handler(void *ptr);
void log_suspicious_activity(const char *message);
int is_suspicious_input(const char *input);
void setup_server();

int main() {
    setup_server();
    return 0;
}

void setup_server() {
    int server_socket, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_size = sizeof(client);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(server_socket, 3);
    printf("Server listening on port %d\n", PORT);

    while ((client_sock = accept(server_socket, (struct sockaddr *)&client, &client_size))) {
        pthread_t sniffer_thread;
        connection_t *con = malloc(sizeof(connection_t));
        con->sock = client_sock;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)con) < 0) {
            perror("Could not create thread");
            free(con);
            exit(EXIT_FAILURE);
        }
        pthread_detach(sniffer_thread);
    }

    if (client_sock < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
}

void *connection_handler(void *ptr) {
    connection_t *con = (connection_t *)ptr;
    int sock = con->sock;
    char client_message[MAX_LINE];

    while (1) {
        memset(client_message, 0, MAX_LINE);
        int read_size = recv(sock, client_message, MAX_LINE, 0);
        if (read_size <= 0) {
            break;
        }

        printf("Received: %s", client_message);
        
        if (is_suspicious_input(client_message)) {
            log_suspicious_activity(client_message);
            const char *response = "Suspicious input detected. Connection terminated.\n";
            send(sock, response, strlen(response), 0);
            break;
        }

        const char *response = "Data received successfully.\n";
        send(sock, response, strlen(response), 0);
    }

    close(sock);
    free(con);
    return 0;
}

void log_suspicious_activity(const char *message) {
    FILE *log_file = fopen("suspicious_log.txt", "a");
    if (log_file != NULL) {
        fprintf(log_file, "Suspicious activity detected: %s", message);
        fclose(log_file);
    } else {
        perror("Could not open log file");
    }
}

int is_suspicious_input(const char *input) {
    // Here we consider inputs containing potentially harmful patterns as suspicious
    const char *suspicious_patterns[] = {
        "DROP TABLE", "SELECT * FROM", "--", ";", "OR", "AND", "1=1", NULL
    };
    for (int i = 0; suspicious_patterns[i] != NULL; i++) {
        if (strstr(input, suspicious_patterns[i]) != NULL) {
            return 1; // suspicious input
        }
    }
    return 0; // not suspicious
}