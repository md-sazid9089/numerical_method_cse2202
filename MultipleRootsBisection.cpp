#include<bits/stdc++.h>
using namespace std;
vector<double>coeff= {1,-2,-5,6};
double f(double x)
{
    double result=0;
    for(int i=0; i<coeff.size(); i++)
    {
        result=result*x+coeff[i];
    }
    return result;
}
int main()
{
    double a=-4,b=4,x0,x1,x2,error,t=0.00001,prev_root;
    x1=a;
    x2=x1+0.1;
    while(x2<=b)
    {
        if(f(x1)*f(x2)<0)
        {
            error=100;
            prev_root=x1;
            while(error>=t)
            {
                x0=(x1+x2)/2;

                if(f(x0)==0)
                {
                    break;
                }
                else if(f(x0)*f(x1)<0)
                {
                    x2=x0;
                }
                else
                {
                    x1=x0;
                }
                error=fabs(0-prev_root);
                prev_root=x0;
            }
            cout<<"value of root"<<x0<<endl;
        }
        x1=x2;
        x2=x1+0.1;
    }
    return 0;
}
