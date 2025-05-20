//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

void set_pixel(Image *image, int x, int y, int red, int green, int blue) {
    if (x >= 0 && y >= 0 && x < image->width && y < image->height) {
        int index = x + y * image->width;
        image->data[index].red = red;
        image->data[index].green = green;
        image->data[index].blue = blue;
    }
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, int red, int green, int blue) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        set_pixel(image, x1, y1, red, green, blue);
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    set_pixel(image, x2, y2, red, green, blue);
}

void draw_circle(Image *image, int x0, int y0, int radius, int red, int green, int blue) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        set_pixel(image, x0 + x, y0 + y, red, green, blue);
        set_pixel(image, x0 + y, y0 + x, red, green, blue);
        set_pixel(image, x0 - y, y0 + x, red, green, blue);
        set_pixel(image, x0 - x, y0 + y, red, green, blue);
        set_pixel(image, x0 - x, y0 - y, red, green, blue);
        set_pixel(image, x0 - y, y0 - x, red, green, blue);
        set_pixel(image, x0 + y, y0 - x, red, green, blue);
        set_pixel(image, x0 + x, y0 - y, red, green, blue);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        } else {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void fill_rectangle(Image *image, int x, int y, int width, int height, int red, int green, int blue) {
    for (int i = x; i < x + width; i++) {
        for (int j = y; j < y + height; j++) {
            set_pixel(image, i, j, red, green, blue);
        }
    }
}

void fill_circle(Image *image, int x0, int y0, int radius, int red, int green, int blue) {
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            if (x * x + y * y <= radius * radius) {
                set_pixel(image, x0 + x, y0 + y, red, green, blue);
            }
        }
    }
}

int main() {
    // Create a 200x200 image and fill it dark brown
    Image *image = malloc(sizeof(Image));
    image->width = 200;
    image->height = 200;
    image->data = malloc(sizeof(Pixel) * 200 * 200);

    memset(image->data, 0, sizeof(Pixel) * 200 * 200);

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            set_pixel(image, i, j, 101, 67, 33);
        }
    }

    // Draw a castle in the center of the image
    fill_rectangle(image, 50, 100, 100, 80, 165, 143, 59);    // castle walls
    fill_rectangle(image, 75, 150, 50, 30, 122, 122, 122);    // castle door
    draw_line(image, 70, 135, 70, 170, 165, 143, 59);         // castle left window
    draw_line(image, 130, 135, 130, 170, 165, 143, 59);       // castle right window
    draw_line(image, 70, 135, 130, 135, 165, 143, 59);        // castle roof left
    draw_line(image, 130, 135, 70, 135, 165, 143, 59);        // castle roof right
    draw_line(image, 70, 135, 100, 115, 165, 143, 59);        // castle roof peak
    draw_line(image, 130, 135, 100, 115, 165, 143, 59);       // castle roof peak

    // Draw a knight in front of the castle
    fill_circle(image, 150, 120, 15, 165, 143, 59);           // knight head
    fill_circle(image, 145, 127, 2, 0, 0, 0);                 // knight left eye
    fill_circle(image, 155, 127, 2, 0, 0, 0);                 // knight right eye
    draw_circle(image, 150, 135, 10, 165, 143, 59);           // knight body
    draw_line(image, 145, 130, 155, 130, 165, 143, 59);       // knight belt
    draw_line(image, 150, 135, 150, 160, 165, 143, 59);       // knight leg left
    draw_line(image, 155, 160, 150, 160, 165, 143, 59);       // knight leg left foot
    draw_line(image, 150, 135, 145, 160, 165, 143, 59);       // knight leg right
    draw_line(image, 145, 160, 150, 160, 165, 143, 59);       // knight leg right foot
    fill_circle(image, 150, 144, 5, 0, 0, 0);                 // knight hand holding sword
    draw_line(image, 150, 139, 155, 147, 0, 0, 0);            // knight arm holding sword
    draw_line(image, 150, 139, 145, 143, 0, 0, 0);            // knight sword handle
    draw_line(image, 145, 143, 155, 147, 0, 0, 0);            // knight sword blade

    // Save the image as a PPM file
    FILE *fout = fopen("medieval.ppm", "w");
    fprintf(fout, "P3\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            fprintf(fout, "%d %d %d ", image->data[i + j * image->width].red, image->data[i + j * image->width].green, image->data[i + j * image->width].blue);
        }
    }
    fclose(fout);

    // Cleanup
    free(image->data);
    free(image);

    return 0;
}