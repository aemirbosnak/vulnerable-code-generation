//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>

#define WIDTH 50
#define HEIGHT 20

struct ship {
    int x;
    int y;
};

struct alien {
    int x;
    int y;
    int exist;
};

int kbhit(void) {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
}

int getch(void) {
    int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void draw(char buffer[HEIGHT][WIDTH], struct ship s, struct alien a[HEIGHT-2][WIDTH/2]) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(i == s.y && j == s.x)
                printf("A");
            else if(a[i-1][j/2].y == i && a[i-1][j/2].exist)
                printf("V");
            else if(buffer[i][j] == '*')
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    char buffer[HEIGHT][WIDTH] = {{0}};
    int points = 0;
    struct ship s = {WIDTH/2, HEIGHT-2};
    struct alien a[HEIGHT-1][WIDTH/2];
    int i, j;
    for(i = 0; i < HEIGHT-1; i++) {
        for(j = 0; j < WIDTH/2; j++) {
            a[i][j] = (struct alien) { j*2, i, 1 };
        }
    }
    while(1) {
        draw(buffer, s, a);
        int c = -1;
        if(kbhit())
            c = getch();
        switch(c) {
            case 'a':
                if(s.x > 0) s.x--;
                break;
            case 'd':
                if(s.x < WIDTH-1) s.x++;
                break;
            case ' ':
                buffer[s.y-1][s.x] = '*';
                break;
            case 'q':
                printf("Game over. Final score: %d points.\n", points);
                return 0;
        }
        for(i = 0; i < HEIGHT-1; i++) {
            for(j = 0; j < WIDTH/2; j++) {
                if(a[i][j].exist && buffer[a[i][j].y+1][a[i][j].x] == '*') {
                    a[i][j].exist = 0;
                    points++;
                }
            }
        }
        for(i = 0; i < HEIGHT-1; i++) {
            for(j = 0; j < WIDTH/2; j++) {
                if(a[i][j].exist)
                    a[i][j].y++;
            }
        }
        for(i = 0; i < HEIGHT-1; i++) {
            for(j = 0; j < WIDTH/2; j++) {
                if(a[i][j].exist && a[i][j].y == s.y && (s.x / 2) == j) {
                    printf("Game over. Final score: %d points.\n", points);
                    return 0;
                }
            }
        }
        for(i = 0; i < HEIGHT; i++) {
            for(j = 0; j < WIDTH; j++) {
                if(buffer[i][j] == '*')
                    buffer[i-1][j] = '*';
            }
        }
        usleep(100000);
        system("clear");
    }
    return 0;
}