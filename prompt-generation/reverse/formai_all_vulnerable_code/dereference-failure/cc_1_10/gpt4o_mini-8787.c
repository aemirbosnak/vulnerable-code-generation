//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <string.h>

void convert_to_grayscale(const char *input_filename, const char *output_filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *input_file;
    
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    
    if ((input_file = fopen(input_filename, "rb")) == NULL) {
        fprintf(stderr, "Error opening file %s\n", input_filename);
        return;
    }
    
    jpeg_stdio_src(&cinfo, input_file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    unsigned char *image_buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.output_height * cinfo.output_components);
    unsigned char *rowptr[1];

    while (cinfo.output_scanline < cinfo.output_height) {
        rowptr[0] = image_buffer + cinfo.output_width * cinfo.output_components * cinfo.output_scanline;
        jpeg_read_scanlines(&cinfo, rowptr, 1);
    }
    
    jpeg_finish_decompress(&cinfo);
    fclose(input_file);

    // Convert to grayscale
    for (int i = 0; i < cinfo.output_width * cinfo.output_height; i++) {
        unsigned char r = image_buffer[i * cinfo.output_components];
        unsigned char g = image_buffer[i * cinfo.output_components + 1];
        unsigned char b = image_buffer[i * cinfo.output_components + 2];
        unsigned char gray = (r + g + b) / 3; // Simple average for grayscale
        image_buffer[i * cinfo.output_components] = gray;
        image_buffer[i * cinfo.output_components + 1] = gray;
        image_buffer[i * cinfo.output_components + 2] = gray;
    }

    // Write the grayscale image to a new file
    struct jpeg_compress_struct cinfo_out;
    FILE *output_file;
    cinfo_out.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo_out);
    
    if ((output_file = fopen(output_filename, "wb")) == NULL) {
        fprintf(stderr, "Error opening output file %s\n", output_filename);
        return;
    }

    jpeg_stdio_dest(&cinfo_out, output_file);
    cinfo_out.image_width = cinfo.output_width;
    cinfo_out.image_height = cinfo.output_height;
    cinfo_out.input_components = 3; // Grayscale is 1 channel; but for JPEG it should be 3
    cinfo_out.in_color_space = JCS_GRAYSCALE;

    jpeg_set_defaults(&cinfo_out);
    jpeg_start_compress(&cinfo_out, TRUE);

    while (cinfo_out.next_scanline < cinfo_out.image_height) {
        rowptr[0] = image_buffer + cinfo_out.next_scanline * cinfo_out.image_width * 3; // tripling the gray values
        jpeg_write_scanlines(&cinfo_out, rowptr, 1);
    }

    jpeg_finish_compress(&cinfo_out);
    fclose(output_file);
    
    free(image_buffer);
    jpeg_destroy_decompress(&cinfo);
    jpeg_destroy_compress(&cinfo_out);
    
    printf("Successfully converted %s to grayscale saved as %s\n", input_filename, output_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image.jpg> <output_image.jpg>\n", argv[0]);
        return 1;
    }
    
    const char *input_image = argv[1];
    const char *output_image = argv[2];
    
    convert_to_grayscale(input_image, output_image);

    return 0;
}