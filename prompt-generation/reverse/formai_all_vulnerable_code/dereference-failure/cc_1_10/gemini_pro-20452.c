//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH  80  /* Terminal window width  */
#define HEIGHT 25  /* Terminal window height */

typedef struct {
    int x, y;   /* Position on screen   */
    int dx, dy; /* Velocity              */
    int c;      /* Character to display   */
} Star;

Star stars[1000];  /* Array of stars          */
int star_count;     /* Number of stars on screen */

void init_stars() {
    srand(time(NULL));
    for (int i = 0; i < star_count; i++) {
        stars[i].x = rand() % WIDTH;
        stars[i].y = rand() % HEIGHT;
        stars[i].dx = (rand() % 3) - 1;
        stars[i].dy = (rand() % 3) - 1;
        stars[i].c = '.';
    }
}

void move_stars() {
    for (int i = 0; i < star_count; i++) {
        stars[i].x += stars[i].dx;
        stars[i].y += stars[i].dy;
        if (stars[i].x < 0 || stars[i].x >= WIDTH) {
            stars[i].dx = -stars[i].dx;
        }
        if (stars[i].y < 0 || stars[i].y >= HEIGHT) {
            stars[i].dy = -stars[i].dy;
        }
    }
}

void draw_stars() {
    for (int i = 0; i < star_count; i++) {
        printf("%c", stars[i].c);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number of stars>\n", argv[0]);
        return 1;
    }

    star_count = atoi(argv[1]);
    if (star_count < 0 || star_count > 1000) {
        fprintf(stderr, "Invalid number of stars: %d\n", star_count);
        return 1;
    }

    init_stars();

    while (1) {
        move_stars();
        draw_stars();
        usleep(10000);  /* 10 milliseconds delay */
    }

    return 0;
}