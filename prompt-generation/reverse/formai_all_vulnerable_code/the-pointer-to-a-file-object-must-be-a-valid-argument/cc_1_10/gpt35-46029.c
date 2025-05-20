//FormAI DATASET v1.0 Category: Image Editor ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

//Functions prototypes
void grayscale(char *filename);
void flip_horizontal(char *filename);
void flip_vertical(char *filename);
void blur(char *filename);
void sharpen(char *filename);

int main(int argc, char *argv[])
{
    //Checking command line arguments
    if(argc<2)
    {
        printf("Please provide a filename as an argument\n");
        return 1;
    }
    
    char *filename = argv[1];
    char option;

    //Menu loop
    while(1)
    {
        printf("\n===============================\n");
        printf(" Welcome to the Image Editor\n");
        printf("===============================\n");
        printf("1. Convert to grayscale\n");
        printf("2. Flip horizontally\n");
        printf("3. Flip vertically\n");
        printf("4. Blur\n");
        printf("5. Sharpen\n");
        printf("0. Quit\n");
        printf("===============================\n");
        printf("Enter an option: ");

        //Getting user input
        option = getchar();
        getchar(); //Discard newline character
        
        switch(option)
        {
            case '1':
                grayscale(filename);
                break;

            case '2':
                flip_horizontal(filename);
                break;

            case '3':
                flip_vertical(filename);
                break;

            case '4':
                blur(filename);
                break;

            case '5':
                sharpen(filename);
                break;

            case '0':
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid option.\n");
        }
    }

    return 0;
}

//Function to convert image to grayscale
void grayscale(char *filename)
{
    FILE *fp_in, *fp_out;
    char line[MAX_SIZE];
    int width, height, max_color;
    int r, g, b, gray;

    //Opening files
    fp_in = fopen(filename, "r");
    fp_out = fopen("grayscale.ppm", "w");

    //Reading PPM header
    fgets(line, MAX_SIZE, fp_in);
    fgets(line, MAX_SIZE, fp_in);
    fscanf(fp_in, "%d %d\n", &width, &height);
    fscanf(fp_in, "%d\n", &max_color);

    //Writing PPM header to output file
    fprintf(fp_out, "P3\n");
    fprintf(fp_out, "# Grayscale Image\n");
    fprintf(fp_out, "%d %d\n", width, height);
    fprintf(fp_out, "%d\n", max_color);

    //Converting image to grayscale and writing to output file
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            fscanf(fp_in, "%d %d %d", &r, &g, &b);

            //Calculating grayscale value
            gray = (r+g+b)/3;

            //Writing grayscale value to output file
            fprintf(fp_out, "%d %d %d ", gray, gray, gray);
        }
        fprintf(fp_out, "\n"); //New line for every row
    }

    printf("\nGrayscale image saved as grayscale.ppm\n");

    //Closing files
    fclose(fp_in);
    fclose(fp_out);
}

//Function to flip image horizontally
void flip_horizontal(char *filename)
{
    FILE *fp_in, *fp_out;
    char line[MAX_SIZE];
    int width, height, max_color;
    int r, g, b;

    //Opening files
    fp_in = fopen(filename, "r");
    fp_out = fopen("flipped_horizontal.ppm", "w");

    //Reading PPM header
    fgets(line, MAX_SIZE, fp_in);
    fgets(line, MAX_SIZE, fp_in);
    fscanf(fp_in, "%d %d\n", &width, &height);
    fscanf(fp_in, "%d\n", &max_color);

    //Writing PPM header to output file
    fprintf(fp_out, "P3\n");
    fprintf(fp_out, "# Flipped Horizontally\n");
    fprintf(fp_out, "%d %d\n", width, height);
    fprintf(fp_out, "%d\n", max_color);

    //Flipping image horizontally and writing to output file
    for(int i=0;i<height;i++)
    {
        for(int j=width-1;j>=0;j--)
        {
            fscanf(fp_in, "%d %d %d", &r, &g, &b);
            fprintf(fp_out, "%d %d %d ", r, g, b);
        }
        fprintf(fp_out, "\n"); //New line for every row 
    }

    printf("\nImage flipped horizontally and saved as flipped_horizontal.ppm\n");

    //Closing files
    fclose(fp_in);
    fclose(fp_out);
}

//Function to flip image vertically
void flip_vertical(char *filename)
{
    FILE *fp_in, *fp_out;
    char line[MAX_SIZE];
    int width, height, max_color;
    int r, g, b;

    //Opening files
    fp_in = fopen(filename, "r");
    fp_out = fopen("flipped_vertical.ppm", "w");

    //Reading PPM header
    fgets(line, MAX_SIZE, fp_in);
    fgets(line, MAX_SIZE, fp_in);
    fscanf(fp_in, "%d %d\n", &width, &height);
    fscanf(fp_in, "%d\n", &max_color);

    //Writing PPM header to output file
    fprintf(fp_out, "P3\n");
    fprintf(fp_out, "# Flipped Vertically\n");
    fprintf(fp_out, "%d %d\n", width, height);
    fprintf(fp_out, "%d\n", max_color);

    //Flipping image vertically and writing to output file
    for(int i=height-1;i>=0;i--)
    {
        for(int j=0;j<width;j++)
        {
            fscanf(fp_in, "%d %d %d", &r, &g, &b);
            fprintf(fp_out, "%d %d %d ", r, g, b);
        }
        fprintf(fp_out, "\n"); //New line for every row 
    }

    printf("\nImage flipped vertically and saved as flipped_vertical.ppm\n");

    //Closing files
    fclose(fp_in);
    fclose(fp_out);
}

//Function to apply blur to image
void blur(char *filename)
{
    FILE *fp_in, *fp_out;
    char line[MAX_SIZE];
    int width, height, max_color;
    int r, g, b;
    int total_r, total_g, total_b;

    //Opening files
    fp_in = fopen(filename, "r");
    fp_out = fopen("blurred.ppm", "w");

    //Reading PPM header
    fgets(line, MAX_SIZE, fp_in);
    fgets(line, MAX_SIZE, fp_in);
    fscanf(fp_in, "%d %d\n", &width, &height);
    fscanf(fp_in, "%d\n", &max_color);

    //Writing PPM header to output file
    fprintf(fp_out, "P3\n");
    fprintf(fp_out, "# Blurred Image\n");
    fprintf(fp_out, "%d %d\n", width, height);
    fprintf(fp_out, "%d\n", max_color);

    //Applying blur and writing to output file
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            //Resetting total values for each pixel
            total_r = 0;
            total_g = 0;
            total_b = 0;

            //Applying blur to 3x3 neighborhood of each pixel
            for(int k=i-1;k<=i+1;k++)
            {
                for(int l=j-1;l<=j+1;l++)
                {
                    //Checking boundaries
                    if(k>=0 && k<height && l>=0 && l<width)
                    {
                        fscanf(fp_in, "%d %d %d", &r, &g, &b);
                        total_r += r;
                        total_g += g;
                        total_b += b;
                    }
                }
            }

            //Dividing by 9 to get average values
            total_r /= 9;
            total_g /= 9;
            total_b /= 9;

            //Writing blurred pixel to output file
            fprintf(fp_out, "%d %d %d ", total_r, total_g, total_b);
        }
        fprintf(fp_out, "\n"); //New line for every row 
    }

    printf("\nImage blurred and saved as blurred.ppm\n");

    //Closing files
    fclose(fp_in);
    fclose(fp_out);
}

//Function to apply sharpen to image
void sharpen(char *filename)
{
    FILE *fp_in, *fp_out;
    char line[MAX_SIZE];
    int width, height, max_color;
    int r, g, b;
    int total_r, total_g, total_b;

    //Opening files
    fp_in = fopen(filename, "r");
    fp_out = fopen("sharpened.ppm", "w");

    //Reading PPM header
    fgets(line, MAX_SIZE, fp_in);
    fgets(line, MAX_SIZE, fp_in);
    fscanf(fp_in, "%d %d\n", &width, &height);
    fscanf(fp_in, "%d\n", &max_color);

    //Writing PPM header to output file
    fprintf(fp_out, "P3\n");
    fprintf(fp_out, "# Sharpened Image\n");
    fprintf(fp_out, "%d %d\n", width, height);
    fprintf(fp_out, "%d\n", max_color);

    //Applying sharpen and writing to output file
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            //Resetting total values for each pixel
            total_r = 0;
            total_g = 0;
            total_b = 0;

            //Applying sharpen to 3x3 neighborhood of each pixel
            for(int k=i-1;k<=i+1;k++)
            {
                for(int l=j-1;l<=j+1;l++)
                {
                    //Checking boundaries
                    if(k>=0 && k<height && l>=0 && l<width)
                    {
                        fscanf(fp_in, "%d %d %d", &r, &g, &b);

                        //Adding values to total only for inner pixels
                        if(k==i && l==j)
                        {
                            total_r += 9*r;
                            total_g += 9*g;
                            total_b += 9*b;
                        }
                        else
                        {
                            total_r -= r;
                            total_g -= g;
                            total_b -= b;
                        }
                    }
                }
            }

            //Restricting values to 0-255 range
            total_r = total_r > 255 ? 255 : total_r;
            total_g = total_g > 255 ? 255 : total_g;
            total_b = total_b > 255 ? 255 : total_b;
            total_r = total_r < 0 ? 0 : total_r;
            total_g = total_g < 0 ? 0 : total_g;
            total_b = total_b < 0 ? 0 : total_b;

            //Writing sharpened pixel to output file
            fprintf(fp_out, "%d %d %d ", total_r, total_g, total_b);
        }
        fprintf(fp_out, "\n"); //New line for every row 
    }

    printf("\nImage sharpened and saved as sharpened.ppm\n");

    //Closing files
    fclose(fp_in);
    fclose(fp_out);
}