//FormAI DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to hexadecimal
char decToHexa(int n)
{
    char hexaDeciNum[17];

    // counter for hexadecimal number array
    int i = 0;
    while(n!=0)
    {
        // temporary variable to store remainder
        int temp  = 0;
        
        // storing remainder in temp variable.
        temp = n % 16;
        
        // check if temp < 10
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        
        n = n/16;
    }

    // printing hexadecimal number array in reverse order
    for(int j=i-1; j>=0; j--)
        printf("%c", hexaDeciNum[j]);
}

int main()
{
    char colorCode[7];
    int r,g,b;

    printf("Enter a Color Code (RGB) (Example: FF1122): ");
    scanf("%s", colorCode);

    // extracting R, G, B values from color code
    r = strtol(colorCode+0, NULL, 16);
    g = strtol(colorCode+2, NULL, 16);
    b = strtol(colorCode+4, NULL, 16);

    printf("\nDecimal representation: \n");
    printf("R: %d\n", r);
    printf("G: %d\n", g);
    printf("B: %d\n", b);

    printf("\nHexadecimal representation: \n");
    printf("R: ");
    decToHexa(r);
    printf("\nG: ");
    decToHexa(g);
    printf("\nB: ");
    decToHexa(b);
    printf("\n");

    return 0;
}