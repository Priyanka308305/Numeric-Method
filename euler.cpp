#include <iostream>
using namespace std;

// Define the differential equation dy/dx = f(x, y)
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    float x0 = 0;       // Initial x
    float y0 = 1;       // Initial y (i.e., y(x0) = y0)
    float h = 0.2;      // Step size
    int n = 5;          // Number of steps

    float x[n + 1];     // Store x0 to xn
    float y[n + 1];     // Store y0 to yn

    // Step 1: Initial values
    x[0] = x0;
    y[0] = y0;

    // Step 2: Apply Euler’s formula
    for (int i = 0; i < n; i++) {
        x[i + 1] = x[i] + h;
        y[i + 1] = y[i] + h * f(x[i], y[i]);
    }

    // Step 3: Output the results
    cout << "Euler Method Results:\n";
    for (int i = 0; i <= n; i++) {
        cout << "x" << i << " = " << x[i] << ", y" << i << " = " << y[i] << endl;
    }
cout<<endl;
    cout << "Approximate value of y at x = " << x[n] << " is " << y[n] << endl;

    return 0;
}
