//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_CODE_LENGTH];
} color_t;

color_t colors[] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    color_t *color = NULL;

    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("%s", color->code);

    for (int i = 0; i < strlen(color->code); i++) {
        printf("\033[0m%c", color->code[i]);
    }

    printf("\n");

    return 0;
}