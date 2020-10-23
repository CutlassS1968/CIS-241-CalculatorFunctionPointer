//
//  CIS 241 02, Professor Vijay Bhuse
//  Calculator Using Function Pointers
//
//  Created by Evan Johns on 10/18/2020
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 20

void format(char *);
int getOperation(char *);
void multiply(double, double);
void divide(double, double);
void add(double, double);
void subtract(double, double);
void print(char *, double, double, double);

const char *operationStrPtr[4] = {"multiply", "divide", "add", "subtract"};

int main() {

    void (*functions[4])(double, double) = {multiply, divide, add, subtract};

    char uString[SIZE];    // User's input string
    int uOperation;     // User's selected Operation
    double uN1, uN2;    // User's number input

    do {    // Get user's input
        printf("What calculation would you like to perform?\n"
               "Options: Multiply, Divide, Add, Subtract\n");
        scanf("%s", uString);
        format(uString);
        uOperation = getOperation(uString);
    } while(uOperation == 4);           // Error checking user's input

    printf("What numbers would you like to %s?\n", operationStrPtr[uOperation]);

    do {    // Get user's first number
        printf("Number 1: ");
    } while(scanf("%lf", &uN1) != 1);   // Error checking user's input

    do {    // Get user's second number
        printf("Number 2: ");
    } while(scanf("%lf", &uN2) != 1);   // Error checking user's input

    (*functions[uOperation])(uN1, uN2); // Calculate and print the results

    return 0;
}

// Formats a string input to remove punctuation and spaces
void format(char *sPtr) {
    char *sta = sPtr;   // starting string
    char *res = sPtr;   // resulting string

    while (*sta) {
        if (ispunct((unsigned char)*sta)) {         // removing punctuation
            sta++;
        }
        else if (isupper((unsigned char)*sta)) {    // converting to lowercase
            *res++ = tolower((unsigned char)*sta);
            sta++;
        }
        else if (sta == res) {
            sta++;
            res++;
        }
        else {
            *res++ = *sta++;
        }
    }
    *res = 0;
}

// Return the corresponding operation number
int getOperation(char *sPtr) {
//    convertToLowercase(sPtr);
    for (int i = 0; i < 4; ++i) {
        if (strcmp(sPtr, operationStrPtr[i]) == 0) {
            return i;
            }
        }
    return 4;
}

// Multiplies the two numbers and calls print
void multiply(double n1, double n2) {
    print("*", n1, n2, n1 * n2);
}

// Divides the two numbers and calls print
void divide(double n1, double n2) {
    print("/",n1, n2, n1 / n2);
}

// Adds the two numbers and calls print
void add(double n1, double n2) {
    print("+", n1, n2, n1 + n2);
}

// Subtracts the two numbers and calls print
void subtract(double n1, double n2) {
    print("-", n1, n2, n1 - n2);
}

// Prints the result of a calculation
void print(char calc[], double n1, double n2, double r) {
    printf("%.2f %s %.2f = %.2f", n1, calc, n2, r);
}