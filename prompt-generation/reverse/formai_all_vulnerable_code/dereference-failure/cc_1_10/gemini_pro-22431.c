//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#define WIDTH 21
#define HEIGHT 21

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point tl;
    Point br;
} Rect;

Rect get_bounding_box(int **matrix) {
    Rect rect = { {WIDTH, HEIGHT}, {0, 0} };
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (matrix[i][j] == 1) {
                rect.tl.x = fmin(rect.tl.x, i);
                rect.tl.y = fmin(rect.tl.y, j);
                rect.br.x = fmax(rect.br.x, i);
                rect.br.y = fmax(rect.br.y, j);
            }
        }
    }
    return rect;
}

int get_orientation(int **matrix) {
    int black_count = 0;
    for (int i = 0; i < HEIGHT; i++) {
        black_count += matrix[i][0];
    }
    return black_count > (WIDTH / 2);
}

int **rotate_matrix(int **matrix) {
    int **rotated = malloc(sizeof(int *) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        rotated[i] = malloc(sizeof(int) * HEIGHT);
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            rotated[j][HEIGHT - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}

int **read_qr_code(const char *filename) {
    char *path = strdup(filename);
    char *ext = basename(path);
    if (strcmp(ext, ".txt") != 0) {
        fprintf(stderr, "Error: Invalid file extension. Expected .txt\n");
        free(path);
        return NULL;
    }
    free(path);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    int matrix[HEIGHT][WIDTH] = {0};
    char line[WIDTH + 1];
    for (int i = 0; i < HEIGHT; i++) {
        if (fgets(line, WIDTH + 1, file) == NULL) {
            fprintf(stderr, "Error: Invalid file format\n");
            fclose(file);
            return NULL;
        }
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = line[j] == '1';
        }
    }
    fclose(file);

    Rect bounding_box = get_bounding_box(matrix);
    int width = bounding_box.br.x - bounding_box.tl.x + 1;
    int height = bounding_box.br.y - bounding_box.tl.y + 1;
    int **cropped = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        cropped[i] = malloc(sizeof(int) * width);
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cropped[i][j] = matrix[bounding_box.tl.x + i][bounding_box.tl.y + j];
        }
    }

    int orientation = get_orientation(cropped);
    if (orientation) {
        cropped = rotate_matrix(cropped);
    }

    return cropped;
}

void print_qr_code(int **matrix) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j] ? '1' : '0');
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <qr_code.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int **matrix = read_qr_code(argv[1]);
    if (matrix == NULL) {
        return EXIT_FAILURE;
    }

    print_qr_code(matrix);

    for (int i = 0; i < HEIGHT; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return EXIT_SUCCESS;
}