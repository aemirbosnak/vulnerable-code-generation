//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 20
#define MAX_COLOR_CODES 100

struct color_name {
    char name[20];
    int code;
};

struct color_code {
    int code;
    char name[20];
};

int main() {
    int num_color_names = 0;
    struct color_name color_names[MAX_COLOR_NAMES];
    int num_color_codes = 0;
    struct color_code color_codes[MAX_COLOR_CODES];

    FILE *fp;
    char line[100];
    char *token;

    fp = fopen("color_names.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(color_names[num_color_names].name, token);
        color_names[num_color_names].code = atoi(token);
        num_color_names++;
    }

    fclose(fp);

    fp = fopen("color_codes.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(color_codes[num_color_codes].name, token);
        color_codes[num_color_codes].code = atoi(token);
        num_color_codes++;
    }

    fclose(fp);

    printf("Enter color name or code: ");
    scanf("%s", token);

    if (isdigit(token[0])) {
        for (int i = 0; i < num_color_codes; i++) {
            if (color_codes[i].code == atoi(token)) {
                printf("%s\n", color_codes[i].name);
                break;
            }
        }
    } else {
        for (int i = 0; i < num_color_names; i++) {
            if (strcmp(color_names[i].name, token) == 0) {
                printf("%d\n", color_names[i].code);
                break;
            }
        }
    }

    return 0;
}