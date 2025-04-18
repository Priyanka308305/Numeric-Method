#include <iostream>
#include <iomanip>

using namespace std;

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;  // Example: dy/dx = x + y
}

// Runge-Kutta 4th Order Method implementation
void rungeKutta4(double x0, double y0, double h, int steps) {
    cout << "Step\t\tx\t\ty" << endl;

    for (int i = 0; i <= steps; i++) {
        cout << i << "\t\t" << fixed << setprecision(4) << x0 
             << "\t" << setprecision(6) << y0 << endl;

        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * f(x0 + h, y0 + k3);

        y0 = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 = x0 + h;
    }

    cout << "\nFinal value at x = " << fixed << setprecision(4) << x0 
         << " is y = " << setprecision(6) << y0 << endl;
}

int main() {
    double x0 = 0;     // Initial x
    double y0 = 1;     // Initial y
    double h = 0.2;    // Step size
    int steps = 5;     // Number of steps

    rungeKutta4(x0, y0, h, steps);

    return 0;
}
