#include <bits/stdc++.h>
using namespace std;

vector<double>coeff = {1 ,-7,15,-9};

double f(double x, const vector<double>& c)
{
    double r = 0;
    for (double a : c)
        r=r * x + a;
    return r;
}

double df(double x, const vector<double>& c)
{
    double r = 0;
    int n = c.size() - 1;
    for (int i = 0; i < n; i++)
        r = r * x + (n - i) * c[i];
    return r;
}

void syntheticDivision(vector<double>& c, double root)
{
    int n = c.size();
    vector<double> b(n);
    b[0] = c[0];
    for (int i = 1; i < n; i++)
        b[i] = c[i] + b[i - 1] * root;
    c.resize(n - 1);
    for (int i = 0; i < n - 1; i++)
        c[i] = b[i];
}

int main()
{
    int dg = 3;
    double x0 = 2.5, tol = 0.000001;

    int n = dg;
    int iter = 0;

    while (n > 1)
    {
        double error = 1e9;

        while (error >= tol)
        {
            double f1 = f(x0, coeff);
            double f2 = df(x0, coeff);

            double x1 = x0 - f1 / f2;
            error = fabs(x1 - x0);
            x0 = x1;
            iter++;
        }


        cout << "iteration: "<<iter<<"   Root found: " << fixed << setprecision(10) << x0 << "\n";

        syntheticDivision(coeff, x0);
        n = coeff.size() - 1;
    }

    double lastRoot = -coeff[1] / coeff[0];
    cout << "Final root: " << fixed << setprecision(10) << lastRoot << "\n";
}


