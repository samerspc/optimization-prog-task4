#include <iostream>
#include <cmath>
using namespace std;

// Function to evaluate f(x) = x^3 - 6x^2 + 11x - 6
double f(double x) {
    return pow(x, 3) - 6 * pow(x, 2) + 11 * x - 6;
}

// Function to implement the Bisection Method
void bisectionMethod(double a, double b, double e) {

    // Check if the function values at a and b have opposite signs
    // If f(a) and f(b) are both positive or both negative, the method is not applicable
    if ((f(a) > 0 && f(b) > 0) || (f(a) < 0 && f(b) < 0)) {
        cout << "Method is not applicable";
        return; // Exit the function if the method is not applicable
    }

    // Calculate the midpoint c of the interval [a, b]
    double c = a + (b - a) / 2;

    // Iterate until the interval length (b - a) is smaller than the tolerance e
    while ((b - a) > e) {
        // Check if f(c) is zero or satisfies specific conditions for stopping
        if (f(c) == 0 || (f(a) * f(c) < 0 && f(b) * f(c) > 0)) {
            break; // Exit the loop if these conditions are met
        }

        // Update the interval based on the sign of f(c)
        if (f(a) * f(c) < 0) {
            b = c; // The root lies in the left subinterval [a, c]
        } else {
            a = c; // The root lies in the right subinterval [c, b]
        }

        // Recalculate the midpoint c
        c = a + (b - a) / 2;
    }

    // Output the approximate root of the function
    cout << "Approximate root of the function: " << c;
}

int main() {
    double a, b, eps;

    // Input the interval [a, b] and the tolerance e
    cout << "a: ";
    cin >> a; // Read the left endpoint of the interval
    cout << "b: ";
    cin >> b; // Read the right endpoint of the interval
    cout << "eps: ";
    cin >> eps; // Read the desired precision (tolerance)

    // Call the bisection method with the provided inputs
    bisectionMethod(a, b, eps);
}
