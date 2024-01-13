#include <stdio.h>
#include <math.h>

// Function for nth root
double nthRoot(double num, int n) {
    return pow(num, 1.0 / n);
}

// Function for factorial
int factorial(int num) {
    return (num < 0) ? -1 : (num == 0) ? 1 : num * factorial(num - 1);
}

// Function for statistical mean
double calculate_mean(int n, double numbers[]) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return sum / n;
}

// Function for statistical median
double calculate_median(int n, double numbers[]) {
    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    return (n % 2 != 0) ? numbers[n / 2] : (numbers[(n - 1) / 2] + numbers[n / 2]) / 2.0;
}

// Function for statistical standard deviation
double calculate_std_dev(int n, double numbers[]) {
    double mean = calculate_mean(n, numbers);
    double sum_squared_diff = 0;

    for (int i = 0; i < n; i++) {
        sum_squared_diff += pow(numbers[i] - mean, 2);
    }

    return sqrt(sum_squared_diff / n);
}

// Function for statistical variance
double calculate_variance(int n, double numbers[]) {
    double mean = calculate_mean(n, numbers);
    double sum_squared_diff = 0;

    for (int i = 0; i < n; i++) {
        sum_squared_diff += pow(numbers[i] - mean, 2);
    }

    return sum_squared_diff / n;
}

int main() {
    int mainChoice, subChoice, continueChoice;
    double num1, num2, result;
    int n;
    double numbers[100]; // Assuming maximum 100 elements for simplicity

    while (1) {
        printf("\nEnter the number of your choice: \n");
        printf("1. Basic Operations\n2. Trigonometric Operations\n3. Algebraic Operations\n4. Logarithmic Operations\n5. Statistical Operations\n6. Exit\n");
        scanf("%d", &mainChoice);

        if (mainChoice == 6) {
            break; // Exit the loop, thus exiting the program
        }

        switch (mainChoice) {
            case 1: // Basic Operations
                printf("Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
                scanf("%d", &subChoice);
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                switch(subChoice) {
                    case 1: result = num1 + num2; break;
                    case 2: result = num1 - num2; break;
                    case 3: result = num1 * num2; break;
                    case 4: 
                        if(num2 == 0) {
                            printf("Error: Division by zero\n");
                            continue;
                        }
                        result = num1 / num2; 
                        break;
                    default:
                        printf("Invalid basic operation choice.\n");
                        continue;
                }
                break;
            case 2: // Trigonometric Operations
                printf("Choose an operation:\n1. Sine\n2. Cosine\n3. Tangent\n4. Arcsine\n5. Arccosine\n6. Arctangent\n");
                scanf("%d", &subChoice);
                printf("Enter the angle (in degrees): ");
                scanf("%lf", &num1);
                switch(subChoice) {
                    case 1: result = sin(num1 * M_PI / 180); break;
                    case 2: result = cos(num1 * M_PI / 180); break;
                    case 3: result = tan(num1 * M_PI / 180); break;
                    case 4: result = asin(num1) * 180 / M_PI; break;
                    case 5: result = acos(num1) * 180 / M_PI; break;
                    case 6: result = atan(num1) * 180 / M_PI; break;
                    default:
                        printf("Invalid trigonometric operation choice.\n");
                        continue;
                }
                break;
            case 3: // Algebraic Operations
                printf("Choose an operation:\n1. Exponentiation\n2. Square root\n3. Cube root\n4. nth root\n5. Factorial\n");
                scanf("%d", &subChoice);
                switch(subChoice) {
                    case 1:
                        printf("Enter the base: ");
                        scanf("%lf", &num1);
                        printf("Enter the exponent: ");
                        scanf("%lf", &num2);
                        result = pow(num1, num2);
                        break;
                    case 2:
                        printf("Enter the number: ");
                        scanf("%lf", &num1);
                        result = sqrt(num1);
                        break;
                    case 3:
                        printf("Enter the number: ");
                        scanf("%lf", &num1);
                        result = cbrt(num1);
                        break;
                    case 4:
                        printf("Enter the number: ");
                        scanf("%lf", &num1);
                        printf("Enter the root: ");
                        scanf("%d", &subChoice);
                        result = nthRoot(num1, subChoice);
                        break;
                    case 5:
                        printf("Enter the number: ");
                        scanf("%d", &subChoice);
                        if(subChoice < 0) {
                            printf("Error: Factorial not defined for negative numbers.\n");
                            continue;
                        }
                        result = factorial(subChoice);
                        break;
                    default:
                        printf("Invalid algebraic operation choice.\n");
                        continue;
                }
                break;
            case 4: // Logarithmic Operations
                printf("Choose an operation:\n1. Logarithm (base 10)\n2. Natural logarithm (base e)\n3. Custom base logarithm\n");
                scanf("%d", &subChoice);
                printf("Enter the number: ");
                scanf("%lf", &num1);
                switch(subChoice) {
                    case 1: result = log10(num1); break;
                    case 2: result = log(num1); break;
                    case 3: 
                        printf("Enter the base: ");
                        scanf("%lf", &num2);
                        result = log(num1) / log(num2);
                        break;
                    default:
                        printf("Invalid logarithmic operation choice.\n");
                        continue;
                }
                break;
            case 5: // Statistical Operations
                printf("Choose an operation:\n1. Mean\n2. Median\n3. Mode\n4. Standard Deviation\n5. Variance\n");
                scanf("%d", &subChoice);
                printf("Enter the number of elements in the dataset: ");
                scanf("%d", &n);
                if(n > 100) {
                    printf("Error: Maximum limit of elements exceeded.\n");
                    continue;
                }
                printf("Enter the elements of the dataset:\n");
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%lf", &numbers[i]);
                }
                switch(subChoice) {
                    case 1: result = calculate_mean(n, numbers); break;
                    case 2: result = calculate_median(n, numbers); break;
                    case 3: 
                        printf("Mode calculation not implemented.\n");
                        result = 0; // Placeholder, since mode calculation is not implemented
                        break;
                    case 4: result = calculate_std_dev(n, numbers); break;
                    case 5: result = calculate_variance(n, numbers); break;
                    default:
                        printf("Invalid statistical operation choice.\n");
                        continue;
                }
                break;
            default:
                printf("Invalid main choice.\n");
                continue;
        }

        printf("Result: %.12lf\n", result);

        // Ask user if they want to continue or quit
        printf("\nDo you want to perform another operation?\n1. Yes\n2. No (Exit)\n");
        scanf("%d", &continueChoice);

        if (continueChoice != 1) {
            break; // Exit the loop if the choice is not 1 (Yes)
        }
    }

    return 0;
}
