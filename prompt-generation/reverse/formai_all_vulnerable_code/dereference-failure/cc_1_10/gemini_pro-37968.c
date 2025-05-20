//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    unsigned int width, height;
    pixel *data;
} image;

image *new_image(unsigned int width, unsigned int height) {
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void set_pixel(image *img, unsigned int x, unsigned int y, pixel color) {
    if (x < img->width && y < img->height) {
        img->data[y * img->width + x] = color;
    }
}

pixel get_pixel(image *img, unsigned int x, unsigned int y) {
    if (x < img->width && y < img->height) {
        return img->data[y * img->width + x];
    }
    return (pixel){0, 0, 0};
}

void save_ppm(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void draw_line(image *img, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, pixel color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    for(;;){
        set_pixel(img, x0,y0,color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void draw_circle(image *img, unsigned int x0, unsigned int y0, unsigned int radius, pixel color) {
    int x = radius, y = 0;
    int xChange = 1 - (radius << 1);
    int yChange = 0;
    int radiusError = 0;

    while (x >= y) {
        set_pixel(img, x + x0, y + y0, color);
        set_pixel(img, y + x0, x + y0, color);
        set_pixel(img, -x + x0, y + y0, color);
        set_pixel(img, -y + x0, x + y0, color);
        set_pixel(img, -x + x0, -y + y0, color);
        set_pixel(img, -y + x0, -x + y0, color);
        set_pixel(img, x + x0, -y + y0, color);
        set_pixel(img, y + x0, -x + y0, color);

        y++;
        radiusError += yChange;
        yChange += 2;
        if (((radiusError << 1) + xChange) > 0) {
            x--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}

void draw_ellipse(image *img, unsigned int x0, unsigned int y0, unsigned int radiusX, unsigned int radiusY, pixel color) {
    int x = 0, y = radiusY;
    int xChange = 1 - (radiusX << 1);
    int yChange = 0 - (radiusY << 1);
    int ellipseError = 0;

    while (x <= y) {
        set_pixel(img, x + x0, y + y0, color);
        set_pixel(img, x + x0, -y + y0, color);
        set_pixel(img, -x + x0, y + y0, color);
        set_pixel(img, -x + x0, -y + y0, color);

        x++;
        ellipseError += xChange;
        xChange += 2;
        if (((ellipseError << 1) + yChange) > 0) {
            y--;
            ellipseError += yChange;
            yChange += 2;
        }
    }
}

void draw_rectangle(image *img, unsigned int x0, unsigned int y0, unsigned int width, unsigned int height, pixel color) {
    for (unsigned int x = x0; x < x0 + width; x++) {
        set_pixel(img, x, y0, color);
        set_pixel(img, x, y0 + height - 1, color);
    }
    for (unsigned int y = y0; y < y0 + height; y++) {
        set_pixel(img, x0, y, color);
        set_pixel(img, x0 + width - 1, y, color);
    }
}

void draw_triangle(image *img, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, pixel color) {
    draw_line(img, x0, y0, x1, y1, color);
    draw_line(img, x1, y1, x2, y2, color);
    draw_line(img, x2, y2, x0, y0, color);
}

int main() {
    image *img = new_image(512, 512);

    pixel white = {255, 255, 255};
    pixel black = {0, 0, 0};

    draw_rectangle(img, 10, 10, 100, 100, white);
    draw_circle(img, 256, 256, 100, black);
    draw_ellipse(img, 256, 256, 100, 50, white);
    draw_line(img, 100, 100, 400, 400, black);
    draw_triangle(img, 100, 400, 400, 100, 256, 256, white);

    save_ppm(img, "out.ppm");
    free_image(img);

    return 0;
}