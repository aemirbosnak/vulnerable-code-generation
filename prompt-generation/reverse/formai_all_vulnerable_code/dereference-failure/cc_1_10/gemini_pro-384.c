//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct {
    char *name;
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color_code;

// Define an array of color codes
color_code colors[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 128, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"maroon", 128, 0, 0},
    {"olive", 128, 128, 0},
    {"navy", 0, 0, 128},
    {"teal", 0, 128, 128},
    {"silver", 192, 192, 192},
    {"gold", 255, 215, 0},
    {"lime", 0, 255, 0},
    {"fuchsia", 255, 0, 255},
    {"aqua", 0, 255, 255},
    {"pink", 255, 192, 203},
    {"violet", 127, 0, 255}
};

// Get the number of color codes in the array
int num_colors = sizeof(colors) / sizeof(color_code);

// Get the color code for a given name
color_code *get_color_code(char *name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return &colors[i];
        }
    }

    return NULL;
}

// Print the color code for a given name
void print_color_code(char *name) {
    color_code *color = get_color_code(name);

    if (color != NULL) {
        printf("%s: %d, %d, %d\n", color->name, color->r, color->g, color->b);
    } else {
        printf("Invalid color name: %s\n", name);
    }
}

// Convert a color code to a hex string
char *color_code_to_hex(color_code *color) {
    char *hex = malloc(7);

    sprintf(hex, "#%02X%02X%02X", color->r, color->g, color->b);

    return hex;
}

// Convert a hex string to a color code
color_code *hex_to_color_code(char *hex) {
    color_code *color = malloc(sizeof(color_code));

    sscanf(hex, "#%02X%02X%02X", &color->r, &color->g, &color->b);

    return color;
}

// Print the usage information
void print_usage() {
    printf("Usage: color_code_converter [OPTIONS] [COLOR]\n");
    printf("\nOptions:\n");
    printf("  -h, --help      Print this help message and exit\n");
    printf("  -H, --hex       Convert a color name to a hex string\n");
    printf("  -R, --rgb       Convert a hex string to a color name\n");
}

// Parse the command line arguments
int parse_args(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return -1;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_usage();
        return 0;
    } else if (strcmp(argv[1], "-H") == 0 || strcmp(argv[1], "--hex") == 0) {
        if (argc != 3) {
            printf("Error: Invalid number of arguments\n");
            return -1;
        }

        color_code *color = get_color_code(argv[2]);

        if (color != NULL) {
            char *hex = color_code_to_hex(color);
            printf("%s\n", hex);
            free(hex);
        } else {
            printf("Error: Invalid color name\n");
            return -1;
        }
    } else if (strcmp(argv[1], "-R") == 0 || strcmp(argv[1], "--rgb") == 0) {
        if (argc != 3) {
            printf("Error: Invalid number of arguments\n");
            return -1;
        }

        color_code *color = hex_to_color_code(argv[2]);

        print_color_code(color->name);

        free(color);
    } else {
        print_color_code(argv[1]);
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    return parse_args(argc, argv);
}