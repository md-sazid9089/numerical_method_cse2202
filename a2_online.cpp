#include<bits/stdc++.h>
using namespace std;
vector<double>coeff = {1,-15,85,-225,274,-120};
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

int main(){
int degree=5;
double x0=-1,x1;
double tol=0.000001;
double error;
int n=degree;
int c=0;
int iter=0;
while(n>1){
    error=100;
     c++;
    cout<<"converging to root "<<c<<endl;
    cout<<"iter"<<setw(20)<<"x0"<<setw(20)<<"f1"<<setw(20)<<"f2"<<setw(20)<<"error"<<endl;
    while(error>=tol){
        double f1=f(x0,coeff);
        double f2=df(x0,coeff);
        x1=x0-(f1/f2);
        error=fabs(x1-x0);
        cout<<++iter<<setw(20)<<x0<<setw(20)<<f1<<setw(20)<<f2<<setw(20)<<error<<endl;
        x0=x1;
    }
    cout<<"Root"<<x1<<endl;
     syntheticDivision(coeff, x0);
    n = coeff.size() - 1;
}
    double lastRoot = -coeff[1] / coeff[0];
    cout << "Final root: " << fixed << setprecision(10) << lastRoot << "\n";

}
