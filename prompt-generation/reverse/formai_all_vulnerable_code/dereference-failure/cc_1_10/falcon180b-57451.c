//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Function to read audio file
void read_audio_file(int *data, int size, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fread(data, sizeof(int), size, fp);
    fclose(fp);
}

//Function to write audio file
void write_audio_file(int *data, int size, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fwrite(data, sizeof(int), size, fp);
    fclose(fp);
}

//Function to apply reverb effect
void reverb(int *data, int size)
{
    int i, j, k, n;
    float a, b, c, d;
    float *reverb_buffer = (float *)malloc(size * sizeof(float));
    for (i = 0; i < size; i++)
    {
        reverb_buffer[i] = 0;
        for (j = 0; j < 4; j++)
        {
            n = i - j * 50;
            if (n >= 0 && n < size)
            {
                a = (float)data[n] / 32768.0;
                b = (float)data[i] / 32768.0;
                c = (float)data[i + j * 50] / 32768.0;
                d = (float)data[i - j * 50] / 32768.0;
                reverb_buffer[i] += (a * 0.5) + (b * 0.3) + (c * 0.2) + (d * 0.1);
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        data[i] = (int)(reverb_buffer[i] * 32768.0);
    }
    free(reverb_buffer);
}

//Main function
int main()
{
    int *data, size;
    char filename[100];
    printf("Enter audio file name: ");
    scanf("%s", filename);
    read_audio_file(&data, &size, filename);
    reverb(data, size);
    write_audio_file(data, size, "reverb_output.wav");
    return 0;
}