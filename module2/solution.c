#include <stdio.h>

// Recursive function to convert decimal to target base using the custom alphabet
void to_base_n(unsigned long n, int base) {
    if (base < 2 || base > 16) {
        printf("Error: Target base must be between 2 and 16.\n");
        return;
    }

    // Custom alphabet mapping remainders 10 through 15 to specific symbols
    // Indices 0-9: '0'-'9'
    // Index 10: '!', Index 11: '@', Index 12: '#', Index 13: '$', Index 14: '%', Index 15: '^'
    char custom_alphabet[] = "0123456789!@#$%^";

    int remainder = n % base;
    if (n >= (unsigned long)base) {
        to_base_n(n / base, base);
    }
    putchar(custom_alphabet[remainder]);
}

int main(void) {
    unsigned long number;
    int base;

    printf("--- Base-N Converter with a Twist ---\n");
    printf("Enter a decimal integer (or non-integer to exit): ");
    
    while (scanf("%lu", &number) == 1) {
        printf("Enter target base (2-16): ");
        if (scanf("%d", &base) != 1) {
            break;
        }

        if (base < 2 || base > 16) {
            printf("Error: Base value %d is outside the allowed range of 2-16.\n\n", base);
            printf("Enter a decimal integer (or non-integer to exit): ");
            continue;
        }

        // Apply formatting requirements based on target base
        if (base == 8) {
            printf("Equivalent Octal output: 0");
        } else if (base == 16) {
            printf("Equivalent Hexadecimal output: 0x");
        } else {
            printf("Equivalent Base %d output: ", base);
        }

        to_base_n(number, base);
        printf("\n\n");

        printf("Enter a decimal integer (or non-integer to exit): ");
    }

    printf("\nExiting program.\n");
    return 0;
}
