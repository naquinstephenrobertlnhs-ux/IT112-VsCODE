#include <stdio.h>

int main() {
    char name[50];
    char section[20];
    int num1, num2;
    
    // Input student details
    printf("Enter Complete Name: ");
    fgets(name, sizeof(name), stdin); // gets full name including spaces
    
    printf("Enter Section: ");
    fgets(section, sizeof(section), stdin); // gets section input
    
    // Input two numbers
    printf("\nEnter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Display student details
    printf("\nStudent Calculator\n");
    printf("Student name: %s", name);
    printf("Section: %s", section);
    printf("Results:\n");
    
    // Calculations
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
    printf("%d / %d = %.2f\n", num1, num2, (float)num1 / num2);
    
    return 0;
}