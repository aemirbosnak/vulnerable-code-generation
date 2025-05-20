//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
// A journey through pixels, a symphony of coordinates,
// Our virtual GPS, a canvas that captivates.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Our cartographic masterpiece's dimensions
#define WIDTH 1000
#define HEIGHT 1000

// The vessel that traverses our digital realm
typedef struct {
    int x, y; // Its current location
    double heading; // Its compass, charting its course
    int speed; // Its velocity, propelling it forward
} Car;

// The world we traverse, a tapestry of pixels
typedef struct {
    unsigned char *data; // An array of colors, each pixel a hue
} Map;

// Initializes our digital realm
Map init_map() {
    Map map;
    map.data = malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    return map;
}

// Sets the hue of a pixel at a given coordinate
void set_pixel(Map map, int x, int y, unsigned char color) {
    map.data[y * WIDTH + x] = color;
}

// The heart of our GPS, guiding us through the digital landscape
void navigate(Car *car, Map map) {
    // Update the car's position based on its heading and speed
    car->x += car->speed * cos(car->heading);
    car->y += car->speed * sin(car->heading);

    // Handle out-of-bounds scenarios, wrapping around the map's edges
    if (car->x < 0) car->x += WIDTH;
    else if (car->x >= WIDTH) car->x -= WIDTH;
    if (car->y < 0) car->y += HEIGHT;
    else if (car->y >= HEIGHT) car->y -= HEIGHT;

    // Paint the car's trail, leaving a vibrant trace of its journey
    set_pixel(map, car->x, car->y, 0xFF);
}

// The orchestrator of our digital symphony, guiding us through the GPS maze
int main() {
    // Create our canvas and our vessel
    Map map = init_map();
    Car car = {WIDTH / 2, HEIGHT / 2, 0.5 * M_PI, 10};

    // Embark on our pixelated adventure, leaving a trail of color in our wake
    for (int i = 0; i < 1000; i++) {
        navigate(&car, map);
    }

    // Share our digital masterpiece with the world, a testament to our virtual voyage
    FILE *fp = fopen("gps_art.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(map.data, WIDTH * HEIGHT * sizeof(unsigned char), 1, fp);
    fclose(fp);
    return 0;
}