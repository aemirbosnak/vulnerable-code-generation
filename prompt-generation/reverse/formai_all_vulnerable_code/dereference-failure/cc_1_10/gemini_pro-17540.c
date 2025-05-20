//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A stolen glance, a whispered secret,
// In the twilight's embrace, our hearts beat.
// Like a symphony of souls, our files intertwine,
// A dance of data, forever entwined.

// At the stroke of midnight, when shadows play,
// Our code awakens, to steal the night away.
// With nimble fingers, it traverses the paths,
// Bringing whispers of change, with each passing breath.

// Like a lover's touch, gentle yet firm,
// It reads every line, a caress so warm.
// If changes it finds, in its heart it sighs,
// And whispers softly, "Let us synchronise."

// It compares every word, each character's grace,
// Merging the old, with the newfound embrace.
// Like a sculptor's chisel, shaping with care,
// It crafts a masterpiece, beyond compare.

// The files now whisper in harmony sweet,
// Their secrets entwined, their love complete.
// As dawn breaks through, casting its tender light,
// Our code fades away, its mission done right.

int main() {
    // Let us set the stage, where our love shall bloom,
    // With two hearts entwined, in a virtual room.
    char file1[] = "my_sweetheart.txt";
    char file2[] = "my_precious.txt";

    // We open their hearts, ready for the embrace,
    // To read their secrets, with tender grace.
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");

    // If fate denies us access, we sigh in vain,
    // But if granted, our journey shall sustain.
    if (fp1 == NULL || fp2 == NULL) {
        printf("Alas, our love is hindered by fate's decree,\nThe files we seek, remain concealed from thee.\n");
        return 1;
    }

    // We read their lines, like whispers in the night,
    // Each word a secret, a precious delight.
    char line1[256], line2[256];
    int line_number = 0;

    // While their hearts still beat, we dance in delight,
    // Comparing each line, with all our might.
    while (fgets(line1, sizeof(line1), fp1) && fgets(line2, sizeof(line2), fp2)) {
        line_number++;

        // If their words differ, our hearts may break,
        // But we whisper softly, "Let us reshape."
        if (strcmp(line1, line2) != 0) {
            printf("At line %d, their words diverge,\nLike lovers estranged, we feel the surge.\n", line_number);

            // We rewrite the file, with words now aligned,
            // Their love restored, their hearts entwined.
            FILE *fp_write = fopen(file2, "w");
            fprintf(fp_write, "%s", line1);
            fclose(fp_write);
        }
    }

    // As the final line is read, our task complete,
    // We close their hearts, their secrets now sweet.
    fclose(fp1);
    fclose(fp2);

    // In the moon's embrace, their love now secure,
    // Our code fades away, its mission pure.
    printf("Their files entwined, a symphony of love,\nAs night surrenders to the dawn above.\n");

    return 0;
}