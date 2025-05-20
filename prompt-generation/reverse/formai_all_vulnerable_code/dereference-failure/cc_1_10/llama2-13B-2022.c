//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int x;
    int y;
    int width;
    int height;
    unsigned char *data;
} Image;

Image *image = NULL;

void init_image(void) {
    image = malloc(sizeof(Image));
    image->x = 0;
    image->y = 0;
    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = malloc(WIDTH * HEIGHT * 3);
}

void draw_point(int x, int y) {
    if (image->data == NULL) {
        return;
    }
    image->data[y * WIDTH * 3 + x * 3] = 255;
    image->data[y * WIDTH * 3 + x * 3 + 1] = 0;
    image->data[y * WIDTH * 3 + x * 3 + 2] = 0;
}

void draw_line(int x1, int y1, int x2, int y2) {
    if (image->data == NULL) {
        return;
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int stepx = 1;
    int stepy = 1;
    int x = x1;
    int y = y1;
    while (x <= x2) {
        draw_point(x, y);
        if (dx == 0) {
            stepx = 0;
        } else {
            stepx = dx > 0 ? 1 : -1;
        }
        if (dy == 0) {
            stepy = 0;
        } else {
            stepy = dy > 0 ? 1 : -1;
        }
        x += stepx;
        y += stepy;
    }
}

void draw_circle(int x, int y, int radius) {
    if (image->data == NULL) {
        return;
    }
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;
    draw_line(x1, y1, x2, y2);
    draw_line(x1, y2, x2, y1);
}

void draw_rectangle(int x, int y, int width, int height) {
    if (image->data == NULL) {
        return;
    }
    int x1 = x;
    int y1 = y;
    int x2 = x + width;
    int y2 = y + height;
    draw_line(x1, y1, x2, y1);
    draw_line(x1, y2, x2, y1);
    draw_line(x1, y1, x1, y2);
    draw_line(x2, y1, x2, y2);
}

void update_image(void) {
    if (image->data == NULL) {
        return;
    }
    char *buf = mmap(NULL, WIDTH * HEIGHT * 3, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (buf == MAP_FAILED) {
        perror("mmap failed");
        return;
    }
    memcpy(buf, image->data, WIDTH * HEIGHT * 3);
    munmap(buf, WIDTH * HEIGHT * 3);
}

int main(void) {
    init_image();
    update_image();
    printf("Image editor\n");
    char command[1024];
    while (1) {
        printf("> ");
        fgets(command, 1024, stdin);
        if (command[0] == '\0') {
            continue;
        }
        if (strcmp(command, "exit") == 0) {
            break;
        }
        if (strcmp(command, "draw point") == 0) {
            int x, y;
            scanf("%d%c%d", &x, &y, &command[0]);
            draw_point(x, y);
        } else if (strcmp(command, "draw line") == 0) {
            int x1, y1, x2, y2;
            scanf("%d%c%d%c%d%c", &x1, &y1, &x2, &y2, &command[0]);
            draw_line(x1, y1, x2, y2);
        } else if (strcmp(command, "draw circle") == 0) {
            int x, y, radius;
            scanf("%d%c%d%c", &x, &y, &radius, &command[0]);
            draw_circle(x, y, radius);
        } else if (strcmp(command, "draw rectangle") == 0) {
            int x, y, width, height;
            scanf("%d%c%d%c%d%c%d%c", &x, &y, &width, &height, &command[0]);
            draw_rectangle(x, y, width, height);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}