//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
    char *email;
} user_info_t;

user_info_t *get_user_info(void) {
    user_info_t *user_info = malloc(sizeof(user_info_t));

    printf("Enter your username: ");
    fgets(user_info->username, MAX_USERNAME_LENGTH, stdin);

    printf("Enter your password: ");
    fgets(user_info->password, MAX_PASSWORD_LENGTH, stdin);

    printf("Enter your email: ");
    fgets(user_info->email, MAX_EMAIL_LENGTH, stdin);

    return user_info;
}

int main(void) {
    user_info_t *user_info = get_user_info();

    if (user_info == NULL) {
        printf("Failed to get user information.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 2;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return 3;
    }

    char send_buffer[1024];
    char recv_buffer[1024];

    sprintf(send_buffer, "HELO %s", user_info->username);
    send(sock, send_buffer, strlen(send_buffer), 0);

    recv_buffer[0] = '\0';
    recv(sock, recv_buffer, 1024, 0);

    printf("Server response: %s\n", recv_buffer);

    close(sock);

    free(user_info);

    return 0;
}