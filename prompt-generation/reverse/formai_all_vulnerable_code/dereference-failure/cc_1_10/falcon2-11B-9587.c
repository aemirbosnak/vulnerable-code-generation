//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <crypt.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <password strength>\n", argv[0]);
        return 1;
    }

    char *strength = argv[1];

    int sockfd;
    struct sockaddr_in serv_addr;
    int n;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    srand(time(0));

    int level = atoi(strength);

    switch (level) {
        case 1:
            printf("Generating a weak password...\n");
            break;
        case 2:
            printf("Generating a medium password...\n");
            break;
        case 3:
            printf("Generating a strong password...\n");
            break;
        default:
            printf("Invalid password strength level\n");
            exit(1);
    }

    char password[16];
    int i;
    int j;
    int k;

    for (i = 0; i < 8; i++) {
        password[i] = (char) ((rand() % 26) + 97);
    }

    password[i++] = (char) ((rand() % 10) + 48);
    password[i++] = (char) ((rand() % 10) + 48);
    password[i++] = (char) ((rand() % 10) + 48);

    if (level == 3) {
        for (j = i; j < 16; j++) {
            password[j] = (char) ((rand() % 26) + 97);
        }
    }

    printf("Your password is: %s\n", password);

    close(sockfd);
    return 0;
}