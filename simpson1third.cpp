#include <iostream>
#include<cmath>
using namespace std;

// Function to integrate
float f(float x) {
    return x * x; // Example: f(x) = x^2
}

int main() {
    float a , b ;
    cout<<"enter lower limit a:"<<endl;
    cin>>a;
    cout<<"enter the upperlimit b:"<<endl;
    cin>>b;
    int n ;
    cout<<"enter interval n"<<endl;
    cin>>n; // Must be even for Simpson's 1/3 Rule

    if (n % 2 != 0) {
        cout << "Error: n must be even for Simpson's 1/3 Rule.\n";
        return 1;
    }

    float h = abs(b - a) / n;
    float X[n + 1];     // X0 to Xn
    float Y[n + 1];    // f(X0) to f(Xn)

    // Step 1: Calculate X0 to Xn
    X[0] = a;
    for (int i = 1; i <= n; i++) {
        X[i] = X[i - 1] + h;
    }

    // Step 2: Calculate f(Xi)
    for (int i = 0; i <= n; i++) {
        Y[i] = f(X[i]);
    }

    // Step 3: Apply Simpson's 1/3 formula
    float sum = Y[0] + Y[n]; // f(X0) + f(Xn)

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * Y[i]; // even index: 2*f(Xi)
        } else {
            sum += 4 * Y[i]; // odd index: 4*f(Xi)
        }
    }

    float result = (h / 3) * sum;

    // Step 4: Output
    cout << "X values:\n";
    for (int i = 0; i <= n; i++) {
        cout << "X" << i << " = " << X[i] << ", f(X" << i << ") = " << Y[i] << endl;
    }

    cout << "\nApproximate value of the integral = " << result << endl;

    return 0;
}
  