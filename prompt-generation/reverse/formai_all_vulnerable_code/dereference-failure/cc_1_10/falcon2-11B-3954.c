//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // Declare variables
    char elementName[50];
    int atomicNumber, symbol;
    
    // Initialize variables
    srand(time(NULL));
    
    // Create an array of elements
    int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    int elementCount = sizeof(elements) / sizeof(elements[0]);
    
    // Print element names and symbols
    printf("Periodic Table Quiz\n");
    printf("1. Hydrogen (H)\n");
    printf("2. Helium (He)\n");
    printf("3. Lithium (Li)\n");
    printf("4. Beryllium (Be)\n");
    printf("5. Boron (B)\n");
    printf("6. Carbon (C)\n");
    printf("7. Nitrogen (N)\n");
    printf("8. Oxygen (O)\n");
    printf("9. Fluorine (F)\n");
    printf("10. Neon (Ne)\n");
    printf("11. Sodium (Na)\n");
    printf("12. Magnesium (Mg)\n");
    printf("13. Aluminum (Al)\n");
    printf("14. Silicon (Si)\n");
    printf("15. Phosphorus (P)\n");
    printf("16. Sulfur (S)\n");
    printf("17. Chlorine (Cl)\n");
    printf("18. Argon (Ar)\n");
    printf("19. Potassium (K)\n");
    printf("20. Calcium (Ca)\n");
    printf("21. Scandium (Sc)\n");
    printf("22. Titanium (Ti)\n");
    printf("23. Vanadium (V)\n");
    printf("24. Chromium (Cr)\n");
    printf("25. Manganese (Mn)\n");
    printf("26. Iron (Fe)\n");
    printf("27. Cobalt (Co)\n");
    printf("28. Nickel (Ni)\n");
    printf("29. Copper (Cu)\n");
    printf("30. Zinc (Zn)\n");
    printf("31. Gallium (Ga)\n");
    printf("32. Germanium (Ge)\n");
    printf("33. Arsenic (As)\n");
    printf("34. Selenium (Se)\n");
    printf("35. Bromine (Br)\n");
    printf("36. Krypton (Kr)\n");
    printf("37. Rubidium (Rb)\n");
    printf("38. Strontium (Sr)\n");
    printf("39. Yttrium (Y)\n");
    printf("40. Zirconium (Zr)\n");
    printf("41. Niobium (Nb)\n");
    printf("42. Molybdenum (Mo)\n");
    printf("43. Technetium (Tc)\n");
    printf("44. Ruthenium (Ru)\n");
    printf("45. Rhodium (Rh)\n");
    printf("46. Palladium (Pd)\n");
    printf("47. Silver (Ag)\n");
    printf("48. Cadmium (Cd)\n");
    printf("49. Indium (In)\n");
    printf("50. Tin (Sn)\n");
    printf("51. Antimony (Sb)\n");
    printf("52. Tellurium (Te)\n");
    printf("53. Iodine (I)\n");
    printf("54. Xenon (Xe)\n");
    printf("55. Cesium (Cs)\n");
    printf("56. Barium (Ba)\n");
    printf("57. Lanthanum (La)\n");
    printf("58. Cerium (Ce)\n");
    printf("59. Praseodymium (Pr)\n");
    printf("60. Neodymium (Nd)\n");
    printf("61. Promethium (Pm)\n");
    printf("62. Samarium (Sm)\n");
    printf("63. Europium (Eu)\n");
    printf("64. Gadolinium (Gd)\n");
    printf("65. Terbium (Tb)\n");
    printf("66. Dysprosium (Dy)\n");
    printf("67. Holmium (Ho)\n");
    printf("68. Erbium (Er)\n");
    printf("69. Thulium (Tm)\n");
    printf("70. Ytterbium (Yb)\n");
    printf("71. Lutetium (Lu)\n");
    printf("72. Hafnium (Hf)\n");
    printf("73. Tantalum (Ta)\n");
    printf("74. Tungsten (W)\n");
    printf("75. Rhenium (Re)\n");
    printf("76. Osmium (Os)\n");
    printf("77. Iridium (Ir)\n");
    printf("78. Platinum (Pt)\n");
    printf("79. Gold (Au)\n");
    printf("80. Mercury (Hg)\n");
    printf("81. Thallium (Tl)\n");
    printf("82. Lead (Pb)\n");
    printf("83. Bismuth (Bi)\n");
    printf("84. Polonium (Po)\n");
    printf("85. Astatine (At)\n");
    printf("86. Radon (Rn)\n");
    printf("87. Francium (Fr)\n");
    printf("88. Radium (Ra)\n");
    printf("89. Actinium (Ac)\n");
    printf("90. Thorium (Th)\n");
    printf("91. Protactinium (Pa)\n");
    printf("92. Uranium (U)\n");
    printf("93. Neptunium (Np)\n");
    printf("94. Plutonium (Pu)\n");
    printf("95. Americium (Am)\n");
    printf("96. Curium (Cm)\n");
    printf("97. Berkelium (Bk)\n");
    printf("98. Californium (Cf)\n");
    printf("99. Einsteinium (Es)\n");
    printf("100. Fermium (Fm)\n");
    
    // Get user input
    printf("\nEnter your choice:\n");
    scanf("%s", elementName);
    
    // Compare user input with elements array
    int index = -1;
    for (int i = 0; i < elementCount; i++) {
        if (strcmp(elementName, elements[i]) == 0) {
            index = i;
            break;
        }
    }
    
    // Print result
    if (index!= -1) {
        printf("\nYou entered: %s (%d)\n", elementName, elements[index]);
    } else {
        printf("\nInvalid input\n");
    }
    
    return 0;
}