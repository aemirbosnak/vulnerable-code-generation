//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <setjmp.h>
#include <stdint.h>

struct my_error_mgr {
    struct jpeg_error_mgr pub;  /* "public" fields */
    jmp_buf setjmp_buffer;       /* for return to caller */
};

typedef struct my_error_mgr *my_error_ptr;

void my_error_exit (j_common_ptr cinfo) {
    my_error_ptr myerr = (my_error_ptr) cinfo->err;
    (*cinfo->err->output_message) (cinfo);
    longjmp(myerr->setjmp_buffer, 1);
}

void apply_grayscale(unsigned char* pixel_data, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char gray = (unsigned char)(0.299 * pixel_data[i] + 0.587 * pixel_data[i+1] + 0.114 * pixel_data[i+2]);
        pixel_data[i] = gray;     // Red
        pixel_data[i+1] = gray;   // Green
        pixel_data[i+2] = gray;   // Blue
    }
}

void save_jpeg(const char* filename, unsigned char* pixel_data, int width, int height) {
    struct jpeg_compress_struct cinfo;
    struct my_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;

    if (setjmp(jerr.setjmp_buffer)) {
        jpeg_destroy_compress(&cinfo);
        fprintf(stderr, "JPEG compression failed!\n");
        exit(EXIT_FAILURE);
    }

    jpeg_create_compress(&cinfo);
    FILE *outfile = fopen(filename, "wb");
    if (!outfile) {
        fprintf(stderr, "Could not open output file %s\n!", filename);
        exit(EXIT_FAILURE);
    }
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3; // RGB
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    while (cinfo.next_scanline < cinfo.image_height) {
        unsigned char* row_pointer[1];
        row_pointer[0] = &pixel_data[cinfo.next_scanline * width * 3];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
}

unsigned char* load_jpeg(const char* filename, int* width, int* height) {
    struct jpeg_decompress_struct cinfo;
    struct my_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;

    if (setjmp(jerr.setjmp_buffer)) {
        jpeg_destroy_decompress(&cinfo);
        fprintf(stderr, "JPEG decompression failed!\n");
        return NULL;
    }

    jpeg_create_decompress(&cinfo);
    FILE * infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Can't open %s\n!", filename);
        exit(EXIT_FAILURE);
    }

    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    unsigned char* pixel_data = (unsigned char*)malloc(cinfo.output_width * cinfo.output_height * cinfo.output_components);
    
    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char* row_pointer[1];
        row_pointer[0] = &pixel_data[cinfo.output_scanline * cinfo.output_width * cinfo.output_components];
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    return pixel_data;
}

void create_shocked_logo(unsigned char *pixel_data, int width, int height) {
    // Creating a SHOCKED effect
    for (int x = width / 4; x < width * 3 / 4; x++) {
        for (int y = height / 4; y < height * 3 / 4; y++) {
            pixel_data[(y * width + x) * 3 + 0] = 255; // Red-channel
            pixel_data[(y * width + x) * 3 + 1] = 0;   // Green-channel
            pixel_data[(y * width + x) * 3 + 2] = 0;   // Blue-channel
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char* pixel_data = load_jpeg(argv[1], &width, &height);
    if (!pixel_data) {
        fprintf(stderr, "Failed to load image!\n");
        return EXIT_FAILURE;
    }

    printf("Image loaded: %dx%d pixels! Prepare for a shocked transformation!\n", width, height);
    
    apply_grayscale(pixel_data, width, height);
    create_shocked_logo(pixel_data, width, height);
    printf("SHOCKING effect applied, saving output...!\n");

    save_jpeg(argv[2], pixel_data, width, height);
    printf("Output saved: %s\n", argv[2]);

    free(pixel_data);
    return EXIT_SUCCESS;
}