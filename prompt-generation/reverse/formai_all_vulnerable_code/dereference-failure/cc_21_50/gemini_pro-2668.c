//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];
    time_t start, end;
    double elapsed;
    int speed;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return 1;
    }

    for (i = 0; i < BUF_SIZE; i++) {
        buf[i] = 'a';
    }

    start = time(NULL);

    for (j = 0; j < 100; j++) {
        for (k = 0; k < 100; k++) {
            for (l = 0; l < 100; l++) {
                for (m = 0; m < 100; m++) {
                    for (n = 0; n < 100; n++) {
                        for (o = 0; o < 100; o++) {
                            for (p = 0; p < 100; p++) {
                                for (q = 0; q < 100; q++) {
                                    for (r = 0; r < 100; r++) {
                                        for (s = 0; s < 100; s++) {
                                            for (t = 0; t < 100; t++) {
                                                for (u = 0; u < 100; u++) {
                                                    for (v = 0; v < 100; v++) {
                                                        for (w = 0; w < 100; w++) {
                                                            for (x = 0; x < 100; x++) {
                                                                for (y = 0; y < 100; y++) {
                                                                    for (z = 0; z < 100; z++) {

                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    end = time(NULL);

    elapsed = difftime(end, start);

    speed = (BUF_SIZE * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100 * 100) / elapsed;

    printf("Speed: %d bytes/sec\n", speed);

    close(sockfd);

    return 0;
}