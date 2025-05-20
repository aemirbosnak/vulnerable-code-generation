//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_CODE_SIZE 7

typedef struct {
    char name[MAX_LINE_SIZE];
    char code[MAX_CODE_SIZE];
} Color;

Color colors[] = {
    {"Black", "000000"},
    {"White", "FFFFFF"},
    {"Red", "FF0000"},
    {"Green", "00FF00"},
    {"Blue", "0000FF"},
    {"Yellow", "FFFF00"},
    {"Cyan", "00FFFF"},
    {"Magenta", "FF00FF"},
    {"Gray", "888888"},
    {"LightGray", "CCCCCC"},
    {"DarkRed", "8B0000"},
    {"DarkGreen", "006400"},
    {"DarkBlue", "00008B"},
    {"DarkYellow", "8B8B00"},
    {"DarkCyan", "008B8B"},
    {"DarkMagenta", "8B008B"},
    {"DarkGray", "444444"}
};

int num_colors = sizeof(colors) / sizeof(Color);

char* get_color_code(char* color_name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            return colors[i].code;
        }
    }
    return "000000";
}

int main() {
    char input_line[MAX_LINE_SIZE];
    char* token;
    char* color_name;
    char* color_code;

    printf("Enter color name: ");
    fgets(input_line, MAX_LINE_SIZE, stdin);

    token = strtok(input_line, " ");
    color_name = token;

    color_code = get_color_code(color_name);

    printf("Color code for %s is %s\n", color_name, color_code);

    return 0;
}