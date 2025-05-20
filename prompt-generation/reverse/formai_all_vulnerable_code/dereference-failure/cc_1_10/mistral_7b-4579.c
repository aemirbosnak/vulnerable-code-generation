//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR 256

typedef struct {
    char name[10];
    int rgb[3];
} Color;

Color colors[MAX_COLOR];

void read_colors(void) {
    FILE *fp;
    char line[100];
    char *token;
    int i = 0;

    fp = fopen("colors.txt", "r");
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " \t,\n");
        strncpy(colors[i].name, token, sizeof(colors[i].name) - 1);

        token = strtok(NULL, " \t,\n");
        sscanf(token, "%d%d%d", &(colors[i].rgb[0]), &(colors[i].rgb[1]), &(colors[i].rgb[2]));
        i++;
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    char input[10];
    Color target;
    int index;

    if (argc != 2) {
        printf("Usage : %s <color_name>\n", argv[0]);
        exit(1);
    }

    strcpy(input, argv[1]);
    read_colors();

    for (index = 0; index < MAX_COLOR; index++) {
        if (strcasecmp(colors[index].name, input) == 0) {
            target = colors[index];
            break;
        }
    }

    if (index == MAX_COLOR) {
        printf("Color %s not found.\n", input);
        exit(1);
    }

    printf("RGB values for %s : (%d, %d, %d)\n", input, target.rgb[0], target.rgb[1], target.rgb[2]);

    return 0;
}