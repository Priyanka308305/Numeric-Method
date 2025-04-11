#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Enter number of data points,n: ";
    cin >> n;

    double x[n], y[n], X, sum = 0.0;

    // Taking input for x and y values
    cout << "Enter x values :" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] ;
    }
     cout << "Enter  y values:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    // given value of x;
    cout << "Enter the value of X : ";
    cin >> X;

    // for Formula 
    for (int i = 0; i < n; i++) { 
        double term = y[i]; // Start with y[i]

        for (int j = 0; j < n; j++) { 
            if (j != i) { // Skip when j == i
                term = term * (X - x[j]) / (x[i] - x[j]);
            }
        }

        sum += term; // Add every term to sum
    }

    //  final interpolated value
    cout << "Interpolated value at X = " << X << " is " << sum<< endl;

    return 0;
}