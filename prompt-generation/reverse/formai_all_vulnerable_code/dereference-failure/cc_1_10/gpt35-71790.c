//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define WIDTH    80           /* Desired width of ASCII output */
#define HEIGHT   WIDTH / 2    /* Desired height of ASCII output */

#define MAX_INTENSITY 255    /* Maximum intensity value (for scaling) */

/* PROTOTYPES */
int get_line(char *s, int lim);
int get_image_header(char *s, int *nrows, int *ncols);
int get_pixel(FILE *fp, unsigned char *r, unsigned char *g, unsigned char *b);
void print_ascii(unsigned char r, unsigned char g, unsigned char b);

/* MAIN */
int main(int argc, char **argv)
{
    FILE *fp;
    char input_line[100];
    int nrows, ncols, rows, cols;
    unsigned char r, g, b;
    double scale_factor;

    if (argc != 2)
    {
        printf("usage: %s image_file\n", argv[0]);
        return 1;
    }

    /* Open image file */
    if ((fp = fopen(argv[1], "rb")) == NULL)
    {
        printf("error: failed to open input file %s\n", argv[1]);
        return 1;
    }

    /* Read image header */
    if (!get_image_header(input_line, &nrows, &ncols))
    {
        printf("error: no image header found\n");
        return 1;
    }

    /* Scale factor based on maximum intensity value */
    scale_factor = MAX_INTENSITY / (double)(WIDTH - 1);

    /* Determine number of rows and columns to print */
    if (nrows > HEIGHT)
        rows = HEIGHT;
    else
        rows = nrows;

    if (ncols > WIDTH)
        cols = WIDTH;
    else
        cols = ncols;

    /* Print ASCII art */
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (!get_pixel(fp, &r, &g, &b))
            {
                printf("error: failed to read pixel at (%d,%d)\n", i, j);
                return 1;
            }

            print_ascii(r, g, b);
        }

        printf("\n");
    }

    /* Close image file */
    fclose(fp);

    return 0;
}

/* FUNCTION DEFINITIONS */

/* Get next input line from stdin */
int get_line(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *(s+i) = c;

    if (c == '\n')
        *(s+i++) = c;

    *(s+i) = '\0';

    return i;
}

/* Read image header */
int get_image_header(char *s, int *nrows, int *ncols)
{
    int i;

    while (get_line(s, 100) != 0)
    {
        if (isdigit(s[0]))
        {
            sscanf(s, "%d %d", nrows, ncols);

            for (i = 0; i < 3; ++i)
                get_line(s, 100);

            return 1;
        }
    }

    return 0;
}

/* Read next pixel in image */
int get_pixel(FILE *fp, unsigned char *r, unsigned char *g, unsigned char *b)
{
    int c;

    if ((c = fgetc(fp)) == EOF)
        return 0;
    *r = (unsigned char)c;

    if ((c = fgetc(fp)) == EOF)
        return 0;
    *g = (unsigned char)c;

    if ((c = fgetc(fp)) == EOF)
        return 0;
    *b = (unsigned char)c;

    return 1;
}

/* Print ASCII representation of pixel */
void print_ascii(unsigned char r, unsigned char g, unsigned char b)
{
    double intensity = 0.3 * r + 0.59 * g + 0.11 * b;  /* Pixel intensity */

    /* ASCII intensity characters */
    char ascii_intensity[] = "$@B%8&WM#*oahkbdpqwmZO02jyuxzcvn1[](){}?-_/^\\~:,;.<>\"'+` ";

    /* Determine ASCII character based on scaled intensity value */
    int idx = (int)round(intensity / MAX_INTENSITY * (sizeof(ascii_intensity) - 1));

    putchar(ascii_intensity[idx]);
}