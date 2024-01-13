Console-Based Scientific Calculator in C
This is a console-based scientific calculator written in C. It provides a variety of mathematical and scientific operations for basic arithmetic, trigonometry, algebra, logarithms, and statistics. The program also supports complex number operations.

Usage
To use the calculator, follow these steps:

Clone the repository or download the source code to your local machine.

Compile the program using a C compiler (e.g., GCC):

shell
Copy code
gcc -o calculator calculator.c -lm
-o calculator: Specifies the output executable name as "calculator."
-lm: Links the math library for functions like sqrt, sin, cos, etc.
Run the compiled program:

shell
Copy code
./calculator
You will see a menu with different operation categories:

mathematica
Copy code
Simple Console-based Scientific Calculator

Select an operation:
1. Basic Operations
2. Additional Operations
3. Complex Number Operations
0. Exit

Enter your choice:
Enter your choice by typing the corresponding number and pressing Enter.

Follow the on-screen prompts to enter numbers and perform calculations.

The program will display the result of your chosen operation.

You can continue performing operations or exit the calculator by choosing the appropriate option.

Examples
Basic Operations
Choose "Basic Operations" (Option 1) and select an operation (e.g., Addition - Option 1).
Enter two numbers when prompted (e.g., 5 and 3).
The program will display the result (e.g., 8).
Additional Operations
Choose "Additional Operations" (Option 2) and select an operation (e.g., Modulus - Option 1).
Enter two numbers when prompted (e.g., 10 and 3).
The program will display the result (e.g., 1).
Complex Number Operations
Choose "Complex Number Operations" (Option 3) and select an operation (e.g., Addition of Complex Numbers - Option 1).
Enter the real and imaginary parts of two complex numbers when prompted (e.g., 2 3 and 1 4).
The program will display the result (e.g., 3.00 + 7.00i).
Notes
Ensure that you have GCC (GNU Compiler Collection) or another C compiler installed on your system.
The program supports complex number operations, including addition, subtraction, multiplication, division, and finding the conjugate of complex numbers.
It provides additional operations such as modulus, percentage, GCD (Greatest Common Divisor), LCM (Least Common Multiple), floor, and ceiling functions.
The program handles errors like division by zero or modulus by zero gracefully.
