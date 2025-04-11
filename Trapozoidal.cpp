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
    cin>>n;

    float h =abs (b - a) / n;
    float X[n + 1]; // To store X0 to Xn
    float Y[n + 1]; // To store Y0=f(X0) to Yn=f(Xn)

    // Step 1: Calculate X0 to Xn
    X[0] = a;
    for (int i = 1; i <= n; i++) {
        X[i] = X[i - 1] + h;
    }

    // Step 2: Calculate Y0=f(X0) to Yn=f(Xn)
    for (int i = 0; i <= n; i++) {
        Y[i] = f(X[i]);
    }

    // Step 3: Apply Trapezoidal formula
    float sum = Y[0] + Y[n]; // f(X0) + f(Xn)
    for (int i = 1; i < n; i++) {
        sum += 2 * Y[i]; // 2 * (f(X1) + f(X2) + ...)
    }

    float result = (h / 2) * sum;

    // Step 4: Output
    cout << "X values:\n";
    for (int i = 0; i <= n; i++) {
        cout << "X" << i << " = " << X[i] << ", f(X" << i << ") = " << Y[i] << endl;
    }

    cout << "\nApproximate value of the integral = " << result << endl;

    return 0;
}
