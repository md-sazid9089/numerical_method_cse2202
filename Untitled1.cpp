#include <bits/stdc++.h>
using namespace std;

double horners(int arr[], int degree, double x)
{
    double sum = arr[0];
    for (int i = 1; i <= degree; i++)
    {
        sum = sum * x + arr[i];
    }
    return sum;
}

double equation(double h)
{
    int degree = 3;
    int arr[degree + 1] = {2, -7, 4, -3};
    return horners(arr, degree, h);
}

double differentiation(double h)
{
    return (3 * 2 * h * h) - (7 * 2 * h) + 4;
}

double root(double x)
{
    return x - (equation(x) / differentiation(x));
}

int main()
{
    double x0 = 3.5;
    double x1;
    double relative_error = 1;
    int steps = 0;

    cout << "*************************************************************************************************\n";
    cout << "Iteration||" << "      prev_h||" << setw(17) << "     h||" << setw(17)
         << "       f(h)||" << setw(17) << "     f'(h)||" << setw(20) << "    Relative_error" << endl;

    cout << fixed << setprecision(6);

    while (relative_error > 0.000001)
    {
        steps++;

        double ex = equation(x0);
        double xe = differentiation(x0);

        x1 = root(x0);
        relative_error = fabs((x1 - x0) / x1);

        cout << setw(9) << steps<<"||"
             << setw(12) << x0<<"||"
             << setw(15) << x1<<"||"
             << setw(15) << ex<<"||"
             << setw(15) << xe<<"||";

        if (steps == 1)
            cout << setw(20) << "N/A";
        else
            cout << setw(20) << relative_error;

        cout << endl;

        x0 = x1;
    }

    cout << "*************************************************************************************************\n";
    cout << "Final root (approx): " << x1 << endl;

    return 0;
}
