//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAXLINE 256
#define MAXBACKLOG 25

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char **argv)
{
    int listenfd, connfd, n;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buf[MAXLINE];

    if (argc != 2)
        error("Usage: ./intrusion_detection_system <port>");

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Socket creation failed");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        error("Bind failed");

    if (listen(listenfd, MAXBACKLOG) < 0)
        error("Listen failed");

    for (;;) {
        len = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len)) < 0)
            error("Accept failed");

        if (fork() == 0) {
            close(listenfd);

            for (;;) {
                if ((n = recv(connfd, buf, MAXLINE, 0)) <= 0)
                    break;

                struct timeval tv;
                gettimeofday(&tv, NULL);

                struct rusage usage;
                getrusage(RUSAGE_SELF, &usage);

                char *log_entry = malloc(512);
                snprintf(log_entry, 512, "%s,%ld,%ld,%d\n", inet_ntoa(cliaddr.sin_addr), tv.tv_sec, tv.tv_usec, usage.ru_nvcsw);

                FILE *fp = fopen("ids.log", "a");
                fprintf(fp, "%s", log_entry);
                fclose(fp);

                send(connfd, buf, n, 0);
            }

            close(connfd);
            exit(0);
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}