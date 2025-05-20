//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

typedef struct {
    int width;
    int height;
    char** image;
} Image;

void create_ascii_art(Image* image) {
    int x = 0;
    int y = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            if (image->image[i][j] == '1') {
                switch (image->image[i][j]) {
                    case '0':
                        printf("   ");
                        break;
                    case '1':
                        printf(" 1");
                        break;
                    case '2':
                        printf(" 2");
                        break;
                    case '3':
                        printf(" 3");
                        break;
                    case '4':
                        printf(" 4");
                        break;
                    case '5':
                        printf(" 5");
                        break;
                    case '6':
                        printf(" 6");
                        break;
                    case '7':
                        printf(" 7");
                        break;
                    case '8':
                        printf(" 8");
                        break;
                    case '9':
                        printf(" 9");
                        break;
                    case 'A':
                        printf(" @");
                        break;
                    case 'B':
                        printf(" BB");
                        break;
                    case 'C':
                        printf(" CC");
                        break;
                    case 'D':
                        printf(" DD");
                        break;
                    case 'E':
                        printf(" EE");
                        break;
                    case 'F':
                        printf(" FF");
                        break;
                    case 'G':
                        printf(" GG");
                        break;
                    case 'H':
                        printf(" HH");
                        break;
                    case 'I':
                        printf(" II");
                        break;
                    case 'J':
                        printf(" JJ");
                        break;
                    case 'K':
                        printf(" KK");
                        break;
                    case 'L':
                        printf(" LL");
                        break;
                    case 'M':
                        printf(" MM");
                        break;
                    case 'N':
                        printf(" NN");
                        break;
                    case 'O':
                        printf(" OO");
                        break;
                    case 'P':
                        printf(" PP");
                        break;
                    case 'Q':
                        printf(" QQ");
                        break;
                    case 'R':
                        printf(" RR");
                        break;
                    case 'S':
                        printf(" SS");
                        break;
                    case 'T':
                        printf(" TT");
                        break;
                    case 'U':
                        printf(" UU");
                        break;
                    case 'V':
                        printf(" VV");
                        break;
                    case 'W':
                        printf(" WW");
                        break;
                    case 'X':
                        printf(" XX");
                        break;
                    case 'Y':
                        printf(" YY");
                        break;
                    case 'Z':
                        printf(" ZZ");
                        break;
                    default:
                        printf("  ");
                        break;
                }
                x++;
                if (x == MAX_WIDTH) {
                    printf("\n");
                    x = 0;
                }
            }
            y++;
            if (y == MAX_HEIGHT) {
                printf("\n");
                y = 0;
            }
        }
    }
}

int main() {
    int width = 0;
    int height = 0;
    Image* image = malloc(sizeof(Image));

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    image->width = width;
    image->height = height;

    image->image = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        image->image[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            image->image[i][j] = '0';
        }
    }

    printf("Enter the ASCII characters for the image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%c", &image->image[i][j]);
        }
    }

    create_ascii_art(image);

    free(image->image);
    free(image);

    return 0;
}