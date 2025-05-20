//FormAI DATASET v1.0 Category: Image compression ; Style: innovative
// C program to implement image compression
// using the K-means algorithm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Structure to represent an RGB pixel
struct Pixel
{
    int r, g, b;
};

// Function to read the input image
void readImage(char* filename, struct Pixel** image, int* nrows, int* ncols)
{
    // Open the image file
    FILE* f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("Error: Unable to open file %s.\n", filename);
        exit(1);
    }

    // Read the first 54 bytes of the file (header)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, f);

    // Get image dimensions from the header
    *ncols = *(int*)&header[18];
    *nrows = *(int*)&header[22];

    // Allocate memory for the image
    int size = *nrows * *ncols;
    *image = (struct Pixel*)malloc(size * sizeof(struct Pixel));

    // Read the image data
    for (int i = 0; i < size; i++)
    {
        unsigned char data[3];
        fread(data, sizeof(unsigned char), 3, f);
        (*image)[i].b = data[0];
        (*image)[i].g = data[1];
        (*image)[i].r = data[2];
    }

    // Close the file
    fclose(f);
}

// Function to write the output image
void writeImage(char* filename, struct Pixel* image, int nrows, int ncols)
{
    // Open the output file
    FILE* f = fopen(filename, "wb");
    if (f == NULL)
    {
        printf("Error: Unable to open file %s.\n", filename);
        exit(1);
    }

    // Write the header
    unsigned char header[54] = {0};
    header[0] = 'B'; // BMP signature
    header[1] = 'M';
    int filesize = 54 + 3*nrows*ncols; // Image size in bytes
    *(int*)&header[2] = filesize;
    *(int*)&header[10] = 54; // Offset to image data
    *(int*)&header[14] = 40; // Header size
    *(int*)&header[18] = ncols; // Image width
    *(int*)&header[22] = nrows; // Image height
    *(short*)&header[26] = 1; // Number of color planes
    *(short*)&header[28] = 24; // Number of bits per pixel
    fwrite(header, sizeof(unsigned char), 54, f);

    // Write the image data
    int padding = (4 - (ncols*3) % 4) % 4; // Row padding in bytes
    unsigned char* rowdata = (unsigned char*)malloc((3*ncols + padding) * sizeof(unsigned char));
    for (int i = nrows-1; i >= 0; i--)
    {
        for (int j = 0; j < ncols; j++)
        {
            int k = i*ncols + j;
            rowdata[3*j] = image[k].b;
            rowdata[3*j+1] = image[k].g;
            rowdata[3*j+2] = image[k].r;
        }
        fwrite(rowdata, sizeof(unsigned char), 3*ncols+padding, f);
    }
    free(rowdata);

    // Close the file
    fclose(f);
}

// Function to compute the squared Euclidean distance between two pixels
int distance(struct Pixel p1, struct Pixel p2)
{
    int dr = p1.r - p2.r;
    int dg = p1.g - p2.g;
    int db = p1.b - p2.b;
    return dr*dr + dg*dg + db*db;
}

// Function to randomly initialize the centroids
void initializeCentroids(struct Pixel* image, int nrows, int ncols, int K, struct Pixel* centroids)
{
    int* indices = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++)
    {
        int j = rand() % (nrows * ncols);
        for (int k = 0; k < i; k++)
        {
            if (indices[k] == j)
            {
                j = rand() % (nrows * ncols);
                k = -1;
            }
        }
        indices[i] = j;
        centroids[i] = image[j];
    }
    free(indices);
}

// Function to assign pixels to clusters
void assignPixelsToClusters(struct Pixel* image, int nrows, int ncols, struct Pixel* centroids, int K, int* clusters)
{
    for (int i = 0; i < nrows * ncols; i++)
    {
        int min_distance = distance(image[i], centroids[0]);
        int min_index = 0;
        for (int j = 1; j < K; j++)
        {
            int d = distance(image[i], centroids[j]);
            if (d < min_distance)
            {
                min_distance = d;
                min_index = j;
            }
        }
        clusters[i] = min_index;
    }
}

// Function to compute the new centroids
void computeCentroids(struct Pixel* image, int nrows, int ncols, struct Pixel* centroids, int K, int* clusters, int* counts)
{
    for (int i = 0; i < K; i++)
    {
        centroids[i] = (struct Pixel){0, 0, 0};
        counts[i] = 0;
    }
    for (int i = 0; i < nrows * ncols; i++)
    {
        int j = clusters[i];
        centroids[j].r += image[i].r;
        centroids[j].g += image[i].g;
        centroids[j].b += image[i].b;
        counts[j]++;
    }
    for (int i = 0; i < K; i++)
    {
        if (counts[i] > 0)
        {
            centroids[i].r /= counts[i];
            centroids[i].g /= counts[i];
            centroids[i].b /= counts[i];
        }
    }
}

// Function to compress the image
void compressImage(struct Pixel* image, int nrows, int ncols, int K)
{
    struct Pixel* centroids = (struct Pixel*)malloc(K * sizeof(struct Pixel));
    int* clusters = (int*)malloc(nrows * ncols * sizeof(int));
    int* counts = (int*)malloc(K * sizeof(int));
    initializeCentroids(image, nrows, ncols, K, centroids);
    int iterations = 0;
    while (iterations < 10)
    {
        assignPixelsToClusters(image, nrows, ncols, centroids, K, clusters);
        computeCentroids(image, nrows, ncols, centroids, K, clusters, counts);
        iterations++;
    }
    for (int i = 0; i < nrows * ncols; i++)
    {
        image[i] = centroids[clusters[i]];
    }
    free(centroids);
    free(clusters);
    free(counts);
}

// Main function
int main()
{
    // Read the input image
    char* input_filename = "input.bmp";
    struct Pixel* image = NULL;
    int nrows, ncols;
    readImage(input_filename, &image, &nrows, &ncols);
    printf("Image dimensions: %d x %d pixels.\n", nrows, ncols);

    // Compress the image
    int K = 16;
    clock_t start = clock();
    compressImage(image, nrows, ncols, K);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Compression done in %.2f seconds (K = %d).\n", time, K);

    // Write the output image
    char* output_filename = "output.bmp";
    writeImage(output_filename, image, nrows, ncols);
    printf("Output written to %s.\n", output_filename);

    // Free the memory and exit
    free(image);
    return 0;
}