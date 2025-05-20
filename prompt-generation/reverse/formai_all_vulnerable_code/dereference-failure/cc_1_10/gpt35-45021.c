//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

struct mail_data {
    char *username;
    char *password;
    char *server_address;
    int server_port;
};

struct mail {
    char *from;
    char *to;
    char *subject;
    char *body;
};

void *recv_mail(void *arg);
void send_command(int sock, char *command);
char *recv_response(int sock);

int main(int argc, char *argv[]) {
    pthread_t thread_id;
    int sock;
    struct mail_data *data;
    char buffer[BUFFER_SIZE];

    if (argc != 5) {
        printf("Usage: pop3client <username> <password> <server> <port>\n");
        exit(1);
    }

    data = (struct mail_data *) malloc(sizeof(struct mail_data));
    data->username = argv[1];
    data->password = argv[2];
    data->server_address = argv[3];
    data->server_port = atoi(argv[4]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(data->server_address);
    server_address.sin_port = htons(data->server_port);

    if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to POP3 server");
        exit(1);
    }

    printf("Connected to POP3 server\n");

    recv_response(sock);

    sprintf(buffer, "USER %s", data->username);
    send_command(sock, buffer);
    recv_response(sock);

    sprintf(buffer, "PASS %s", data->password);
    send_command(sock, buffer);
    recv_response(sock);

    sprintf(buffer, "STAT");
    send_command(sock, buffer);

    char *response = recv_response(sock);
    char *tokens = strtok(response, " ");
    int num_messages = atoi(tokens + 4);
    printf("There are %d messages in your inbox\n", num_messages);

    pthread_create(&thread_id, NULL, recv_mail, (void *) sock);

    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "QUIT") == 0) {
            break;
        }
        else if (strcmp(buffer, "LIST") == 0) {
            sprintf(buffer, "LIST");
            send_command(sock, buffer);
            recv_response(sock);
        }
        else if (strncmp(buffer, "RETR", 4) == 0) {
            sprintf(buffer, "%s", buffer);
            send_command(sock, buffer);

            response = recv_response(sock);
            while (strcmp(response, ".\r\n") != 0) {
                printf("%s", response);
                response = recv_response(sock);
            }
        }
    }

    pthread_cancel(thread_id);
    close(sock);

    return 0;
}

void *recv_mail(void *arg) {
    int sock = (int) arg;
    char *response = NULL;
    char *tokens = NULL;

    while (1) {
        sleep(5);

        send_command(sock, "STAT");

        response = recv_response(sock);
        tokens = strtok(response, " ");
        printf("You have received %d new messages\n", atoi(tokens + 4));
    }
}

void send_command(int sock, char *command) {
    printf(">> %s\n", command);
    write(sock, command, strlen(command));
    write(sock, "\r\n", 2);
}

char *recv_response(int sock) {
    static char buffer[BUFFER_SIZE + 1];
    int i = 0;
    int n = 0;

    while (1) {
        n = read(sock, &buffer[i], 1);
        if (n == -1) {
            perror("Error reading from POP3 server");
            pthread_exit(NULL);
        }
        if (buffer[i] == '\n') {
            buffer[i + 1] = '\0';
            break;
        }
        i++;
    }

    printf("<< %s", buffer);

    return buffer;
}