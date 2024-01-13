#include <stdio.h>
#include <math.h>

// Function declarations
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

float modulus(float a, float b) {
    if (b != 0) {
        return fmod(a, b);
    } else {
        printf("Error: Modulus by zero!\n");
        return 0;
    }
}

float percentage(float a, float b) {
    return (a * b) / 100;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int floorFunc(float num) {
    return (int)num;
}

int ceilingFunc(float num) {
    return (num > (int)num) ? (int)num + 1 : (int)num;
}

// Complex number structure
typedef struct {
    float real;
    float imag;
} Complex;

Complex addComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

Complex subtractComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}

Complex multiplyComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}

Complex divideComplex(Complex num1, Complex num2) {
    Complex result;
    float denominator = (num2.real * num2.real) + (num2.imag * num2.imag);

    if (denominator != 0) {
        result.real = ((num1.real * num2.real) + (num1.imag * num2.imag)) / denominator;
        result.imag = ((num1.imag * num2.real) - (num1.real * num2.imag)) / denominator;
    } else {
        printf("Error: Division by zero!\n");
        result.real = result.imag = 0;
    }

    return result;
}

Complex conjugate(Complex num) {
    Complex result;
    result.real = num.real;
    result.imag = -num.imag;
    return result;
}

// Function pointer type for calculator operations
typedef float (*CalculatorFunction)(float, float);

// Function pointer type for complex number operations
typedef Complex (*ComplexFunction)(Complex, Complex);

int main() {
    int mainChoice, submenuChoice;
    float num1, num2;
    Complex complexNum1, complexNum2, resultComplex;

    printf("Simple Console-based Scientific Calculator\n");

    do {
        // Display main menu
        printf("\nSelect an operation:\n");
        printf("1. Basic Operations\n");
        printf("2. Additional Operations\n");
        printf("3. Complex Number Operations\n");
        printf("0. Exit\n");

        // User input
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                // Basic Operations submenu
                printf("\nBasic Operations:\n");
                printf("1. Addition\n");
                printf("2. Subtraction\n");
                printf("3. Multiplication\n");
                printf("4. Division\n");
                printf("0. Back\n");

                // User input
                printf("Enter your choice: ");
                scanf("%d", &submenuChoice);

                if (submenuChoice >= 1 && submenuChoice <= 4) {
                    printf("Enter two numbers: ");
                    scanf("%f %f", &num1, &num2);

                    CalculatorFunction basicOperation = NULL;
                    switch (submenuChoice) {
                        case 1:
                            basicOperation = add;
                            break;
                        case 2:
                            basicOperation = subtract;
                            break;
                        case 3:
                            basicOperation = multiply;
                            break;
                        case 4:
                            basicOperation = divide;
                            break;
                    }

                    if (basicOperation != NULL) {
                        printf("Result: %f\n", basicOperation(num1, num2));
                    }
                } else if (submenuChoice == 0) {
                    // Back to main menu
                } else {
                    printf("Invalid choice. Please enter a valid option.\n");
                }
                break;

            case 2:
                // Additional Operations submenu
                printf("\nAdditional Operations:\n");
                printf("1. Modulus (remainder)\n");
                printf("2. Percentage calculation\n");
                printf("3. Greatest Common Divisor (GCD)\n");
                printf("4. Least Common Multiple (LCM)\n");
                printf("5. Floor (round down)\n");
                printf("6. Ceiling (round up)\n");
                printf("0. Back\n");

                // User input
                printf("Enter your choice: ");
                scanf("%d", &submenuChoice);

                switch (submenuChoice) {
                    case 1:
                        printf("Enter two numbers: ");
                        scanf("%f %f", &num1, &num2);
                        printf("Result: %f\n", modulus(num1, num2));
                        break;
                    case 2:
                        printf("Enter two numbers: ");
                        scanf("%f %f", &num1, &num2);
                        printf("Result: %f\n", percentage(num1, num2));
                        break;
                    case 3:
                        printf("Enter two numbers: ");
                        scanf("%d %d", &num1, &num2);
                        printf("Result: %d\n", gcd(num1, num2));
                        break;
                    case 4:
                        printf("Enter two numbers: ");
                        scanf("%d %d", &num1, &num2);
                        printf("Result: %d\n", lcm(num1, num2));
                        break;
                    case 5:
                        printf("Enter a number: ");
                        scanf("%f", &num1);
                        printf("Result: %d\n", floorFunc(num1));
                        break;
                    case 6:
                        printf("Enter a number: ");
                        scanf("%f", &num1);
                        printf("Result: %d\n", ceilingFunc(num1));
                        break;
                    case 0:
                        // Back to main menu
                        break;
                    default:
                        printf("Invalid choice. Please enter a valid option.\n");
                        break;
                }
                break;

            case 3:
                // Complex Number Operations submenu
                printf("\nComplex Number Operations:\n");
                printf("1. Addition of Complex Numbers\n");
                printf("2. Subtraction of Complex Numbers\n");
                printf("3. Multiplication of Complex Numbers\n");
                printf("4. Division of Complex Numbers\n");
                printf("5. Conjugate of Complex Number\n");
                printf("0. Back\n");

                // User input
                printf("Enter your choice: ");
                scanf("%d", &submenuChoice);

                if (submenuChoice >= 1 && submenuChoice <= 5) {
                    switch (submenuChoice) {
                        case 1:
                            printf("Enter real and imaginary parts of the first complex number: ");
                            scanf("%f %f", &complexNum1.real, &complexNum1.imag);
                            printf("Enter real and imaginary parts of the second complex number: ");
                            scanf("%f %f", &complexNum2.real, &complexNum2.imag);
                            resultComplex = addComplex(complexNum1, complexNum2);
                            printf("Result: %.2f + %.2fi\n", resultComplex.real, resultComplex.imag);
                            break;
                        case 2:
                            printf("Enter real and imaginary parts of the first complex number: ");
                            scanf("%f %f", &complexNum1.real, &complexNum1.imag);
                            printf("Enter real and imaginary parts of the second complex number: ");
                            scanf("%f %f", &complexNum2.real, &complexNum2.imag);
                            resultComplex = subtractComplex(complexNum1, complexNum2);
                            printf("Result: %.2f + %.2fi\n", resultComplex.real, resultComplex.imag);
                            break;
                        case 3:
                            printf("Enter real and imaginary parts of the first complex number: ");
                            scanf("%f %f", &complexNum1.real, &complexNum1.imag);
                            printf("Enter real and imaginary parts of the second complex number: ");
                            scanf("%f %f", &complexNum2.real, &complexNum2.imag);
                            resultComplex = multiplyComplex(complexNum1, complexNum2);
                            printf("Result: %.2f + %.2fi\n", resultComplex.real, resultComplex.imag);
                            break;
                        case 4:
                            printf("Enter real and imaginary parts of the first complex number: ");
                            scanf("%f %f", &complexNum1.real, &complexNum1.imag);
                            printf("Enter real and imaginary parts of the second complex number: ");
                            scanf("%f %f", &complexNum2.real, &complexNum2.imag);
                            resultComplex = divideComplex(complexNum1, complexNum2);
                            printf("Result: %.2f + %.2fi\n", resultComplex.real, resultComplex.imag);
                            break;
                        case 5:
                            printf("Enter real and imaginary parts of the complex number: ");
                            scanf("%f %f", &complexNum1.real, &complexNum1.imag);
                            resultComplex = conjugate(complexNum1);
                            printf("Result: %.2f + %.2fi\n", resultComplex.real, resultComplex.imag);
                            break;
                    }
                } else if (submenuChoice == 0) {
                    // Back to main menu
                } else {
                    printf("Invalid choice. Please enter a valid option.\n");
                }
                break;

            case 0:
                printf("Exiting calculator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } while (mainChoice != 0);

    return 0;
}
