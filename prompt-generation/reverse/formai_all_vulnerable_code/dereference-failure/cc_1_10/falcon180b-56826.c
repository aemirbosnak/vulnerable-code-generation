//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CODE_LENGTH 7

struct {
    char* code;
    int value;
} color_code[] = {
    {"Black", 0},
    {"Maroon", 1},
    {"Green", 2},
    {"Olive", 3},
    {"Navy", 4},
    {"Purple", 5},
    {"Teal", 6},
    {"Silver", 7},
    {"Gray", 8},
    {"Red", 9},
    {"Lime", 10},
    {"Yellow", 11},
    {"Blue", 12},
    {"Fuchsia", 13},
    {"Aqua", 14},
    {"White", 15}
};

int get_color_value(char* color_name) {
    int i;
    for(i = 0; i < sizeof(color_code)/sizeof(color_code[0]); i++) {
        if(strcmp(color_code[i].code, color_name) == 0) {
            return color_code[i].value;
        }
    }
    printf("Invalid color name: %s\n", color_name);
    return -1;
}

char* get_color_name(int color_value) {
    int i;
    for(i = 0; i < sizeof(color_code)/sizeof(color_code[0]); i++) {
        if(color_code[i].value == color_value) {
            return color_code[i].code;
        }
    }
    printf("Invalid color value: %d\n", color_value);
    return NULL;
}

char* color_code_converter(char* color_name) {
    int color_value = get_color_value(color_name);
    if(color_value == -1) {
        return NULL;
    }
    char* color_code = malloc(MAX_CODE_LENGTH + 1);
    if(color_code == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    sprintf(color_code, "#%06X", color_value);
    return color_code;
}

int main() {
    char* color_name = "Red";
    char* color_code = color_code_converter(color_name);
    if(color_code!= NULL) {
        printf("Color code for %s: %s\n", color_name, color_code);
    }
    return 0;
}