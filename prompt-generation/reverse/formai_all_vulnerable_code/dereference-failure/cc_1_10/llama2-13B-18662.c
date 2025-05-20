//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: invasive
// Invasive Image Editor

#define INVASION_SIZE 1024
#define INVASION_DEPTH 256

// Structure to hold the image data
typedef struct {
    unsigned char pixels[INVASION_SIZE * INVASION_SIZE];
} Invasion;

// Function to initialize the image editor
Invasion* invasive_init(void) {
    Invasion* invasion = malloc(sizeof(Invasion));
    memset(invasion->pixels, 0, sizeof(invasion->pixels));
    return invasion;
}

// Function to set the image data
void invasive_set_pixel(Invasion* invasion, int x, int y, unsigned char pixel) {
    invasion->pixels[y * INVASION_SIZE + x] = pixel;
}

// Function to get the image data
void* invasive_get_pixel(Invasion* invasion, int x, int y) {
    return &invasion->pixels[y * INVASION_SIZE + x];
}

// Function to draw a line on the image
void invasive_draw_line(Invasion* invasion, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int error = 0;
    int y = y1;

    // Draw the line
    for (int x = x1; x <= x2; x++) {
        invasion->pixels[y * INVASION_SIZE + x] = (dx > 0) ? (y > 0) ? 1 : 0 : (y < 0) ? 0 : 1;
        error += dx;
        if (error > dy) {
            y++;
            error -= dy;
        }
    }
}

// Function to draw a rectangle on the image
void invasive_draw_rectangle(Invasion* invasion, int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            invasion->pixels[y * INVASION_SIZE + x] = 1;
        }
    }
}

// Function to clear the image
void invasive_clear(Invasion* invasion) {
    memset(invasion->pixels, 0, sizeof(invasion->pixels));
}

// Function to display the image
void invasive_display(Invasion* invasion) {
    for (int y = 0; y < INVASION_SIZE; y++) {
        for (int x = 0; x < INVASION_SIZE; x++) {
            printf("%d ", invasion->pixels[y * INVASION_SIZE + x]);
        }
        printf("\n");
    }
}

int main(void) {
    Invasion* invasion = invasive_init();
    invasive_draw_rectangle(invasion, 0, 0, INVASION_SIZE, INVASION_SIZE);
    invasive_draw_line(invasion, 0, 0, INVASION_SIZE, INVASION_SIZE);
    invasive_draw_line(invasion, 0, INVASION_SIZE, INVASION_SIZE, 0);
    invasive_draw_line(invasion, INVASION_SIZE, 0, INVASION_SIZE, INVASION_SIZE);
    invasive_draw_line(invasion, INVASION_SIZE, INVASION_SIZE, 0, 0);
    invasive_clear(invasion);
    invasive_display(invasion);
    free(invasion);
    return 0;
}