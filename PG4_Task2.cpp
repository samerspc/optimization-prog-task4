#include <iostream>
#include <cmath>

using namespace std;

// Function to evaluate f(x) = (x - 2)^2 + 3
// This function is unimodal, meaning it has a single minimum in the given interval.
double f(double x) {
    return pow((x - 2), 2) + 3;
}

// Function to implement the Golden Section Method for finding the minimum of a unimodal function
void goldenSectionMethod(double xL, double xR, double eps) {
    // Define the golden ratio part: (sqrt(5) - 1) / 2
    const double weirdGoldenRatioPart = (sqrt(5) - 1) / 2;

    // Repeat until the length of the interval [xL, xR] is smaller than the tolerance eps
    while (xR - xL > eps) {
        // Calculate two internal points x1 and x2 using the golden ratio
        double x1 = xR - (xR - xL) * weirdGoldenRatioPart;
        double x2 = xL + (xR - xL) * weirdGoldenRatioPart;

        // Evaluate the function at x1 and x2
        double fx1 = f(x1);
        double fx2 = f(x2);

        // Update the interval based on the function values at x1 and x2
        if (fx1 < fx2) {
            xR = x2; // The minimum lies in the left subinterval [xL, x2]
        } else if (fx1 > fx2) {
            xL = x1; // The minimum lies in the right subinterval [x1, xR]
        } else {
            // If fx1 == fx2, symmetrically reduce the interval
            xL = x1;
            xR = x2;
        }
    }

    // Calculate the midpoint of the final interval as the approximate minimum x
    double minX = (xL + xR) / 2; 
    // Evaluate the function at minX to find the minimum function value
    double minf = f(minX);

    // Output the results
    cout << "Approximate minimum x: " << minX << endl;
    cout << "Approximate minimum f(x): " << minf << endl;
}

int main() {
    double a, b, eps;

    // Input the initial interval [a, b] and the desired tolerance eps
    cout << "a: ";
    cin >> a; // Left endpoint of the interval
    cout << "b: ";
    cin >> b; // Right endpoint of the interval
    cout << "eps: ";
    cin >> eps; // Desired precision (tolerance)

    // Call the golden section method with the provided inputs
    goldenSectionMethod(a, b, eps);
}
