//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h> // Ensure you have libjpeg installed

// Function to embed watermark into the image
void embed_watermark(const char *input_file, const char *output_file, const char *watermark, int x_offset, int y_offset) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    JSAMPARRAY buffer;

    // Open the input file
    if ((infile = fopen(input_file, "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", input_file);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int row_stride = cinfo.output_width * cinfo.output_components;
    uint8_t *image_buffer = (uint8_t *)malloc(row_stride * cinfo.output_height);
    buffer = (*cinfo.mem-> alloc_sarray) ((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

    int index = 0;
    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, buffer, 1);
        memcpy(image_buffer + index, buffer[0], row_stride);
        index += row_stride;
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    // Embed watermark by modifying the pixel values
    int wm_len = strlen(watermark);
    for (int i = 0; i < wm_len && (x_offset + i < cinfo.output_width) && (y_offset < cinfo.output_height); i++) {
        int pixel_index = (y_offset * row_stride) + (x_offset + i) * cinfo.output_components;

        // Simple watermarking technique: Modify the red channel
        image_buffer[pixel_index] = watermark[i];
    }

    // Write the new image with watermark to the output file
    FILE *outfile;
    if ((outfile = fopen(output_file, "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", output_file);
        free(image_buffer);
        return;
    }

    struct jpeg_compress_struct cjpeg;
    cjpeg.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cjpeg);
    jpeg_stdio_dest(&cjpeg, outfile);

    cjpeg.image_width = cinfo.output_width;
    cjpeg.image_height = cinfo.output_height;
    cjpeg.input_components = cinfo.output_components;
    cjpeg.in_color_space = cinfo.out_color_space;

    jpeg_set_defaults(&cjpeg);
    jpeg_start_compress(&cjpeg, TRUE);
    
    while (cjpeg.next_scanline < cjpeg.image_height) {
        buffer[0] = image_buffer + cjpeg.next_scanline * row_stride;
        jpeg_write_scanlines(&cjpeg, buffer, 1);
    }

    jpeg_finish_compress(&cjpeg);
    fclose(outfile);
    free(image_buffer);
}

// Driver function
int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input.jpg> <output.jpg> <watermark_string> <x_offset> <y_offset>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *watermark = argv[3];
    int x_offset = atoi(argv[4]);
    int y_offset = atoi(argv[5]);

    embed_watermark(input_file, output_file, watermark, x_offset, y_offset);
    printf("Watermark has been embedded into %s\n", output_file);
    return 0;
}