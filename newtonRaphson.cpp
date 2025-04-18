#include <iostream>
#include <cmath>  // for abs() and pow()

using namespace std;

// Function f(x) = x^3 - x - 2
double f(double x) {
    return x * x * x - x - 2;
}

// Derivative f'(x) = 3x^2 - 1
double df(double x) {
    return 3 * x * x - 1;
}

int main() {
    double x0 = 1.5;            // Starting value (initial guess)
    double tolerance = 0.000001; // Desired accuracy
    int maxIteration = 100;         // Maximum allowed steps

    double x1; // To store new value of x
    int step = 1;

    cout << "Iteration\t x\t\t f(x)" << endl;

    while (step <= maxIteration) {
        double fx = f(x0);
        double dfx = df(x0);

        // Check if derivative is zero
        if (dfx == 0) {
            cout << "Derivative is zero. Method fails." << endl;
            break;
        }

        x1 = x0 - fx / dfx; // Newton-Raphson formula

        cout << step << "\t " << x0 << "\t " << fx << endl;

        // Check if result is within desired accuracy
        if (abs(x1 - x0) < tolerance) {
            cout << "\nRoot found: " << x1 << " after " << step  << " steps." << endl;
            break;
        }

        x0 = x1; // Update x0 for next step
        step++;
    }

    if (step > maxIteration) {
        cout << "Method did not converge within " << maxIteration << " steps." << endl;
    }

    return 0;
}
