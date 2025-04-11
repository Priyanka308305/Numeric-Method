#include <iostream>
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
    cin>>n;// Must be multiple of 3 for Simpson's 3/8 Rule

    if (n % 3 != 0) {
        cout << "Error: n must be a multiple of 3 for Simpson's 3/8 Rule.\n";
        return 1;
    }

    float h = (b - a) / n;
    float X[n + 1];     // X0 to Xn
    float fx[n + 1];    // f(X0) to f(Xn)

    // Step 1: Calculate X0 to Xn
    X[0] = a;
    for (int i = 1; i <= n; i++) {
        X[i] = X[i - 1] + h;
    }

    // Step 2: Calculate f(Xi)
    for (int i = 0; i <= n; i++) {
        fx[i] = f(X[i]);
    }

    // Step 3: Apply Simpson's 3/8 formula
    float sum = fx[0] + fx[n]; // f(X0) + f(Xn)

    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * fx[i]; // every 3rd index: 2*f(Xi)
        } else {
            sum += 3 * fx[i]; // others: 3*f(Xi)
        }
    }

    float result = (3 * h / 8) * sum;

    // Step 4: Output
    cout << "X values:\n";
    for (int i = 0; i <= n; i++) {
        cout << "X" << i << " = " << X[i] << ", f(X" << i << ") = " << fx[i] << endl;
    }

    cout << "\nApproximate value of the integral = " << result << endl;

    return 0;
}
