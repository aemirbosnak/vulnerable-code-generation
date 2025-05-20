//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define max_chars 1024

char *name;
int   nlines;
int   ncols;
char  *grid;

void welcome(void)
{
    nlines = 24;
    ncols  = 80;
    grid   = malloc(sizeof(char) * nlines * ncols);
    memset(grid, ' ', nlines * ncols);
}

void draw_rectangle(int x, int y, int width, int height)
{
    for (int i = x; i < x + width; ++i) {
        grid[i + (y * ncols)] = '-';
        grid[i + ((y + height - 1) * ncols)] = '-';
    }

    for (int i = y; i < y + height; ++i) {
        grid[x + (i * ncols)] = '|';
        grid[(x + width - 1) + (i * ncols)] = '|';
    }
}

void draw_circle(int x, int y, int radius)
{
    for (int i = -radius; i <= radius; ++i) {
        for (int j = -radius; j <= radius; ++j) {
            if (i * i + j * j <= radius * radius) {
                grid[(x + i) + ((y + j) * ncols)] = 'o';
            }
        }
    }
}

void draw_line(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;

    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        grid[x1 + (y1 * ncols)] = '*';

        if (2 * err > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (2 * err < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void print_grid(void)
{
    for (int i = 0; i < nlines; ++i) {
        for (int j = 0; j < ncols; ++j) {
            putchar(grid[j + (i * ncols)]);
        }

        putchar('\n');
    }
}

int main(int argc, char **argv)
{
    welcome();

    draw_rectangle(10, 10, 20, 10);
    draw_circle(50, 50, 10);
    draw_line(10, 10, 50, 50);

    print_grid();

    return 0;
}