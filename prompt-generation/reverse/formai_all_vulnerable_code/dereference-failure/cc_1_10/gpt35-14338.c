//FormAI DATASET v1.0 Category: Socket programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Yo, dude! You forgot something. Use like this: ./chatbot <ip_address> <port_number>\n");
        return -1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Looks like you broke my socket, dude. Try again later.\n");
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("Hey, man! You entered an invalid IP address. Are you even trying?\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Oops! Looks like someone already took over the port. Better luck next time, champ.\n");
        return -1;
    }

    printf("You are now connected to the chatbot. Let's have some fun!\n");
    char line[128];

    while (1) {
        printf("You: ");
        memset(line, 0, sizeof(line));
        fgets(line, sizeof(line), stdin);

        if (strlen(line) == 1) {
            printf("Chatbot: Come on, type something!\n");
            continue;
        } else if (strcmp(line, "quit\n") == 0) {
            printf("Chatbot: Sad to see you go, dude. Come back soon!\n");
            close(sock);
            return 0;
        }

        char buffer[256] = {0};
        sprintf(buffer, "Chatbot: LOL, you said \"%s\". That's funny! Do you want to hear a joke?\n", line);
        printf("%s", buffer);
        send(sock, buffer, strlen(buffer), 0);

        memset(buffer, 0, sizeof(buffer));
        int valread = read(sock, buffer, 256);
        printf("%s\n", buffer);
    }

    return 0;
}