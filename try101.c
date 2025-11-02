/**
 * A menu-driven scientific calculator in C.
 * * This program provides standard arithmetic and scientific functions
 * by prompting the user to select an operation from a menu.
 * * It includes:
 * - Basic Arithmetic: +, -, *, /
 * - Power & Roots: x^y, sqrt(x)
 * - Trigonometry (in degrees): sin, cos, tan
 * - Inverse Trig (results in degrees): asin, acos, atan
 * - Logarithms: log10(x), ln(x)
 * - Exponential: e^x
 * - Constants: PI, e
 * * It includes error handling for invalid inputs like division by zero
 * or the square root of a negative number.
 */

#include <stdio.h>  // For printf, scanf (input/output)
#include <math.h>   // For all scientific math functions (sin, cos, sqrt, pow, etc.)
#include <stdlib.h> // For exit()

// Define constants. M_PI and M_E are often in math.h, 
// but defining them ensures compatibility.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

/**
 * @brief Displays the main menu of calculator options.
 */
void print_menu() {
    printf("\n--- Scientific Calculator ---\n");
    printf("Select operation:\n");
    printf(" 0. Exit\n");
    printf(" 1. Add (+)\t\t 2. Subtract (-)\n");
    printf(" 3. Multiply (*)\t 4. Divide (/)\n");
    printf(" 5. Power (x^y)\t\t 6. Square Root (sqrt)\n");
    printf("\n--- Trigonometry (Input in Degrees) ---\n");
    printf(" 7. sin(x)\t\t 8. cos(x)\n");
    printf(" 9. tan(x)\n");
    printf("10. asin(x)\t\t11. acos(x)\n");
    printf("12. atan(x)\n");
    printf("\n--- Logarithms & Exponentials ---\n");
    printf("13. Log base 10 (log10)\t14. Natural Log (ln)\n");
    printf("15. Exponential (e^x)\n");
    printf("\n--- Constants ---\n");
    printf("16. Print PI\t\t17. Print e\n");
    printf("----------------------------------\n");
    printf("Enter your choice: ");
}

/**
 * @brief Converts an angle from degrees to radians.
 * @param deg Angle in degrees.
 * @return Angle in radians.
 */
double deg_to_rad(double deg) {
    return deg * (M_PI / 180.0);
}

/**
 * @brief Converts an angle from radians to degrees.
 * @param rad Angle in radians.
 * @return Angle in degrees.
 */
double rad_to_deg(double rad) {
    return rad * (180.0 / M_PI);
}

/**
 * @brief Main function: runs the calculator loop.
 */
int main() {
    int choice;
    double num1, num2, result;

    do {
        print_menu();
        
        // Read the user's choice, with basic input validation
        if (scanf(" %d", &choice) != 1) {
            // Clear the invalid input from the buffer
            while (getchar() != '\n'); 
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        // Handle operations that require two numbers
        if (choice >= 1 && choice <= 5) {
            printf("Enter first number: ");
            if (scanf(" %lf", &num1) != 1) {
                 while (getchar() != '\n');
                 printf("Invalid input.\n");
                 continue;
            }
            printf("Enter second number: ");
            if (scanf(" %lf", &num2) != 1) {
                 while (getchar() != '\n');
                 printf("Invalid input.\n");
                 continue;
            }
        } 
        // Handle operations that require one number
        else if ((choice >= 6 && choice <= 15) && choice != 13 && choice != 14) { // log, ln handled in switch
             printf("Enter the number: ");
             if (scanf(" %lf", &num1) != 1) {
                 while (getchar() != '\n');
                 printf("Invalid input.\n");
                 continue;
            }
        }

        // Use a switch to perform the selected operation
        switch (choice) {
            case 0:
                printf("Exiting calculator. Goodbye!\n");
                break;
            case 1: // Add
                result = num1 + num2;
                printf("Result: %.10g + %.10g = %.10g\n", num1, num2, result);
                break;
            case 2: // Subtract
                result = num1 - num2;
                printf("Result: %.10g - %.10g = %.10g\n", num1, num2, result);
                break;
            case 3: // Multiply
                result = num1 * num2;
                printf("Result: %.10g * %.10g = %.10g\n", num1, num2, result);
                break;
            case 4: // Divide
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.10g / %.10g = %.10g\n", num1, num2, result);
                }
                break;
            case 5: // Power
                result = pow(num1, num2);
                printf("Result: %.10g ^ %.10g = %.10g\n", num1, num2, result);
                break;
            case 6: // Square Root
                if (num1 < 0) {
                    printf("Error: Cannot calculate square root of a negative number.\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: sqrt(%.10g) = %.10g\n", num1, result);
                }
                break;
            
            // --- Trig Functions (Input in Degrees) ---
            case 7: // sin
                result = sin(deg_to_rad(num1));
                printf("Result: sin(%.10g deg) = %.10g\n", num1, result);
                break;
            case 8: // cos
                result = cos(deg_to_rad(num1));
                printf("Result: cos(%.10g deg) = %.10g\n", num1, result);
                break;
            case 9: // tan
                // Handle tan(90), tan(270), etc.
                if (fmod(num1, 180.0) == 90.0) {
                     printf("Error: tan(%.10g) is undefined (infinity).\n", num1);
                } else {
                    result = tan(deg_to_rad(num1));
                    printf("Result: tan(%.10g deg) = %.10g\n", num1, result);
                }
                break;
            
            // --- Inverse Trig (Output in Degrees) ---
            case 10: // asin
                if (num1 < -1.0 || num1 > 1.0) {
                    printf("Error: Domain of asin is [-1, 1].\n");
                } else {
                    result = rad_to_deg(asin(num1));
                    printf("Result: asin(%.10g) = %.10g deg\n", num1, result);
                }
                break;
            case 11: // acos
                 if (num1 < -1.0 || num1 > 1.0) {
                    printf("Error: Domain of acos is [-1, 1].\n");
                } else {
                    result = rad_to_deg(acos(num1));
                    printf("Result: acos(%.10g) = %.10g deg\n", num1, result);
                }
                break;
            case 12: // atan
                result = rad_to_deg(atan(num1));
                printf("Result: atan(%.10g) = %.10g deg\n", num1, result);
                break;
            
            // --- Logs & Exponentials ---
            case 13: // log10
                printf("Enter the number (must be > 0): ");
                if (scanf(" %lf", &num1) != 1 || num1 <= 0) {
                     while (getchar() != '\n');
                     printf("Invalid input. Number must be positive.\n");
                     continue;
                }
                result = log10(num1);
                printf("Result: log10(%.10g) = %.10g\n", num1, result);
                break;
            case 14: // ln
                printf("Enter the number (must be > 0): ");
                if (scanf(" %lf", &num1) != 1 || num1 <= 0) {
                     while (getchar() != '\n');
                     printf("Invalid input. Number must be positive.\n");
                     continue;
                }
                result = log(num1); // log() in C is natural log
                printf("Result: ln(%.10g) = %.10g\n", num1, result);
                break;
            case 15: // e^x
                result = exp(num1);
                printf("Result: e^(%.10g) = %.10g\n", num1, result);
                break;
                
            // --- Constants ---
            case 16: // PI
                printf("Result: PI = %.20f\n", M_PI);
                break;
            case 17: // e
                printf("Result: e = %.20f\n", M_E);
                break;
                
            default:
                if (choice != 0) {
                    printf("Invalid choice. Please select from 0 to 17.\n");
                }
                break;
        }

    } while (choice != 0); // Loop until the user selects 0 to exit

    return 0; // Indicate successful execution
}
