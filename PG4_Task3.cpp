#include <iostream>
#include <cmath>

using namespace std;

// Function to evaluate f(x) = -x^2 + 4x + 1
// This is the function we aim to maximize.
double f(double x) {
    return -(pow(x, 2)) + 4 * x + 1;
}

// Function to evaluate the derivative of f(x), f'(x) = -2x + 4
// This derivative is used for gradient ascent.
double df(double x) {
    return -2 * x + 4;
}

// Function to implement the Gradient Ascent algorithm
// x0: Initial guess
// a: Learning rate (step size)
// n: Maximum number of iterations
void gradientAscent(double x0, double a, int n) {

    double x = x0;    // Initialize x to the starting point x0
    double fx = f(x); // Calculate the initial function value at x

    // Iterate up to n times or until the stopping condition is met
    for (int i = 0; i < n; i++) {
        // Calculate the gradient step: dx = a * f'(x)
        double dx = a * df(x);
        // Update the value of x
        x += dx;

        // Calculate the new function value after the update
        double newFx = f(x);
        
        // Check if the function value has increased
        if (newFx > fx) {
            fx = newFx; // Update fx to the new function value
        } else {
            // If the function value does not increase, stop the iteration
            break;
        }
    }

    // Output the approximate maximum point and function value
    cout << "Approximate maximum x: " << x << endl;
    cout << "Maximum function value f(x): " << fx << endl;
}

int main() {
    double x0, a; // Variables for initial guess and learning rate
    int N;        // Variable for the number of iterations

    // Input the initial guess, learning rate, and number of iterations
    cout << "initial guess x0: ";
    cin >> x0; // Read the starting point
    cout << "learning rate alpha: ";
    cin >> a;  // Read the step size
    cout << "number of iterations N: ";
    cin >> N;  // Read the maximum number of iterations

    // Call the gradient ascent function with the user-provided inputs
    gradientAscent(x0, a, N);

    return 0;
}
