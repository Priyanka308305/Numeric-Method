#include <iostream>
#include <cmath>
using namespace std;

// Function whose root we are finding
double f(double x) {
    return x * x - 4;
}

int main() {
    double a, b, c;
    double tol = 0.000001;
    int count = 0;
    

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if (f(a) * f(b) >= 0) {
        cout << "No root exists between " << a << " and " << b << endl;
        return 1;
    }

    // First, count total iterations 
    double temp_a = a, temp_b = b;
    while (fabs(temp_b - temp_a) >= tol) {
        c = (temp_a * f(temp_b) - temp_b * f(temp_a)) / (f(temp_b) - f(temp_a));
        count++;

        if (f(c) * f(temp_a) > 0)
            temp_a = c;
        else
            temp_b = c;
    }

    // Now do the actual process again and print only last n iterations
    int current = 0;
    int n;
    cout<<"how many iteration want to see, n:"<<endl;
    cin>>n;
    cout<<endl;
    cout << "Showing only the last"<<  n <<" "<<"iterations:"<<endl;
    while (fabs(b - a) >= tol) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        current++;

        if (current > count - n) {     // if needs 20 iteration it will print 15 to  20 .
            cout << "Iteration " << current << ": a = " << a
                 << ", b = " << b << ", c = " << c
                 << ", f(c) = " << f(c) << endl;
        }

        if (f(c) * f(a) > 0)
            a = c;
        else
            b = c;
    }

    cout << "\nTotal Iterations = " << count << endl;
    cout << "Root approximately at: " << c << endl;

    return 0;
}
