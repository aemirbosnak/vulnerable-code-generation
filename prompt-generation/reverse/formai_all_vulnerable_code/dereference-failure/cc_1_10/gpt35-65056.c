//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 4096
#define ENCRYPT_BIT 0x80

/* This function takes a source filename and a target filename as input, compresses the source file and writes the compressed data to the target file. The function returns -1 in case of errors or the number of bytes written to the output file otherwise. */
int compress_file(const char* in_file, const char* out_file)
{
    /* Open the source file in binary read mode */
    FILE* fin = fopen(in_file, "rb");
    if (!fin)
    {
        fprintf(stderr, "Failed to open input file!\n");
        return -1;
    }

    /* Open the target file in binary write mode */
    FILE* fout = fopen(out_file, "wb");
    if (!fout)
    {
        fclose(fin);
        fprintf(stderr, "Failed to open output file!\n");
        return -1;
    }

    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read, bytes_written = 0;

    /* Read the input file in chunks of MAX_BUFFER_SIZE bytes and compress each chunk */
    while ((bytes_read = fread(buffer, sizeof(unsigned char), MAX_BUFFER_SIZE, fin)))
    {
        /* Allocate memory for the compressed data buffer */
        unsigned char* compressed_buffer = malloc(bytes_read * 2 * sizeof(unsigned char));
        if (!compressed_buffer)
        {
            fclose(fin);
            fclose(fout);
            fprintf(stderr, "Failed to allocate memory for compressed data!\n");
            return -1;
        }

        int compressed_data_size = 0;
        unsigned char count = 0;
        unsigned char data = buffer[0];

        /* Compress the input buffer */
        for (size_t i = 1; i < bytes_read; i++)
        {
            if (buffer[i] == data)
            {
                count++;
            }
            else
            {
                /* Compress the current run of data if it is longer than one byte */
                if (count > 0)
                {
                    compressed_buffer[compressed_data_size++] = ENCRYPT_BIT | count;
                    compressed_buffer[compressed_data_size++] = data;
                }
                else
                {
                    compressed_buffer[compressed_data_size++] = data;
                }

                data = buffer[i];
                count = 0;
            }
        }

        /* Compress the last run of data */
        if (count > 0)
        {
            compressed_buffer[compressed_data_size++] = ENCRYPT_BIT | count;
            compressed_buffer[compressed_data_size++] = data;
        }
        else
        {
            compressed_buffer[compressed_data_size++] = data;
        }

        /* Write the compressed data to the output file */
        if (fwrite(compressed_buffer, sizeof(unsigned char), compressed_data_size, fout) != compressed_data_size)
        {
            fclose(fin);
            fclose(fout);
            free(compressed_buffer);
            fprintf(stderr, "Failed to write compressed data to output file!\n");
            return -1;
        }

        /* Update the number of bytes written to the output file */
        bytes_written += compressed_data_size;

        /* Free the memory allocated for the compressed data buffer */
        free(compressed_buffer);
    }

    /* Close the input and output files */
    fclose(fin);
    fclose(fout);

    return bytes_written;
}

/* This function takes a compressed filename and a target filename as input, decompresses the compressed data from the compressed file and writes the decompressed data to the target file. The function returns -1 in case of errors or the number of bytes written to the output file otherwise. */
int decompress_file(const char* in_file, const char* out_file)
{
    /* Open the compressed file in binary read mode */
    FILE* fin = fopen(in_file, "rb");
    if (!fin)
    {
        fprintf(stderr, "Failed to open input file!\n");
        return -1;
    }

    /* Open the target file in binary write mode */
    FILE* fout = fopen(out_file, "wb");
    if (!fout)
    {
        fclose(fin);
        fprintf(stderr, "Failed to open output file!\n");
        return -1;
    }

    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read, bytes_written = 0;

    /* Read the compressed file in chunks of MAX_BUFFER_SIZE bytes and decompress each chunk */
    while ((bytes_read = fread(buffer, sizeof(unsigned char), MAX_BUFFER_SIZE, fin)))
    {
        /* Allocate memory for the decompressed data buffer */
        unsigned char* decompressed_buffer = malloc(bytes_read * sizeof(unsigned char));
        if (!decompressed_buffer)
        {
            fclose(fin);
            fclose(fout);
            fprintf(stderr, "Failed to allocate memory for decompressed data!\n");
            return -1;
        }

        int decompressed_data_size = 0;

        /* Decompress the input buffer */
        for (size_t i = 0; i < bytes_read; i++)
        {
            if (buffer[i] & ENCRYPT_BIT)
            {
                /* Get the count of the run of data */
                unsigned char count = buffer[i] & ~ENCRYPT_BIT;

                /* Get the data */
                unsigned char data = buffer[++i];

                /* Write the run of data to the decompressed data buffer */
                for (size_t j = 0; j <= count; j++)
                {
                    decompressed_buffer[decompressed_data_size++] = data;
                }
            }
            else
            {
                /* Write the single byte to the decompressed data buffer */
                decompressed_buffer[decompressed_data_size++] = buffer[i];
            }
        }

        /* Write the decompressed data to the output file */
        if (fwrite(decompressed_buffer, sizeof(unsigned char), decompressed_data_size, fout) != decompressed_data_size)
        {
            fclose(fin);
            fclose(fout);
            free(decompressed_buffer);
            fprintf(stderr, "Failed to write decompressed data to output file!\n");
            return -1;
        }

        /* Update the number of bytes written to the output file */
        bytes_written += decompressed_data_size;

        /* Free the memory allocated for the decompressed data buffer */
        free(decompressed_buffer);
    }

    /* Close the input and output files */
    fclose(fin);
    fclose(fout);

    return bytes_written;
}

/* This is the main function */
int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <compress/decompress> <input_file> <output_file>\n", argv[0]);
        return -1;
    }

    /* Convert the command-line argument to lowercase */
    char* mode = argv[1];
    for (char* p = mode; *p; ++p) *p = tolower(*p);

    /* Check if the mode is compress */
    if (strcmp(mode, "compress") == 0)
    {
        /* Compress the input file */
        int bytes_written = compress_file(argv[2], argv[3]);
        if (bytes_written < 0)
        {
            fprintf(stderr, "Failed to compress input file!\n");
            return -1;
        }

        printf("Compressed %d bytes to %s\n", bytes_written, argv[3]);
    }

    /* Check if the mode is decompress */
    else if (strcmp(mode, "decompress") == 0)
    {
        /* Decompress the input file */
        int bytes_written = decompress_file(argv[2], argv[3]);
        if (bytes_written < 0)
        {
            fprintf(stderr, "Failed to decompress input file!\n");
            return -1;
        }

        printf("Decompressed %d bytes to %s\n", bytes_written, argv[3]);
    }

    /* Invalid mode */
    else
    {
        fprintf(stderr, "Invalid mode! Use either \"compress\" or \"decompress\".\n");
        return -1;
    }

    return 0;
}