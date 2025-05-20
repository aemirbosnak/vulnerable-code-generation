//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

typedef struct {
    char name[20];
    int value;
} color_t;

color_t colors[] = {
    {"black", 0},
    {"white", 7},
    {"red", 9},
    {"green", 10},
    {"yellow", 11},
    {"blue", 12},
    {"magenta", 13},
    {"cyan", 14},
    {"gray", 15}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        exit(1);
    }

    char input[MAX_LINE_LEN];
    strcpy(input, argv[1]);
    input[strcspn(input, "\n")] = '\0';

    color_t *color = NULL;
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colors[i].name, input) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        exit(1);
    }

    printf("Color name: %s\n", color->name);
    printf("Color value: %d\n", color->value);

    return 0;
}