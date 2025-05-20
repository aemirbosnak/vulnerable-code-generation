//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct map {
    int width, height;
    char **data;
};

struct point {
    int x, y;
};

struct gps {
    struct point current;
    struct map *map;
};

struct gps *gps_init(const char *filename) {
    FILE *fp;
    struct gps *gps = malloc(sizeof(struct gps));

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }
    fscanf(fp, "%d %d", &gps->map->width, &gps->map->height);
    gps->map->data = malloc(sizeof(char *) * gps->map->height);
    for (int i = 0; i < gps->map->height; i++) {
        gps->map->data[i] = malloc(gps->map->width + 1);
        fscanf(fp, "%s", gps->map->data[i]);
    }
    fclose(fp);
    return gps;
}

void gps_free(struct gps *gps) {
    for (int i = 0; i < gps->map->height; i++) {
        free(gps->map->data[i]);
    }
    free(gps->map->data);
    free(gps->map);
    free(gps);
}

void gps_move_north(struct gps *gps) {
    if (gps->current.y > 0 && gps->map->data[gps->current.y - 1][gps->current.x] != '#') {
        gps->current.y--;
    }
}

void gps_move_east(struct gps *gps) {
    if (gps->current.x < gps->map->width - 1 && gps->map->data[gps->current.y][gps->current.x + 1] != '#') {
        gps->current.x++;
    }
}

void gps_move_south(struct gps *gps) {
    if (gps->current.y < gps->map->height - 1 && gps->map->data[gps->current.y + 1][gps->current.x] != '#') {
        gps->current.y++;
    }
}

void gps_move_west(struct gps *gps) {
    if (gps->current.x > 0 && gps->map->data[gps->current.y][gps->current.x - 1] != '#') {
        gps->current.x--;
    }
}

void gps_print_map(const struct gps *gps) {
    for (int i = 0; i < gps->map->height; i++) {
        for (int j = 0; j < gps->map->width; j++) {
            if (i == gps->current.y && j == gps->current.x) {
                printf("O");
            } else {
                printf("%c", gps->map->data[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    struct gps *gps = gps_init("map.txt");
    if (gps == NULL) {
        printf("Error loading map.\n");
        return -1;
    }
    char input;
    do {
        printf("\n");
        gps_print_map(gps);
        printf("Enter a direction (N, E, S, W, Q to quit): ");
        scanf(" %c", &input);
        switch (input) {
            case 'N':
                gps_move_north(gps);
                break;
            case 'E':
                gps_move_east(gps);
                break;
            case 'S':
                gps_move_south(gps);
                break;
            case 'W':
                gps_move_west(gps);
                break;
        }
    } while (input != 'Q');
    gps_free(gps);
    return 0;
}