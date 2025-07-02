#include<bits/stdc++.h>
using namespace std;
float f(float x){
return x*x*x*x-1156*x*x+244036;
}
int main(){
float a=15,b=17;
float root=a-((f(a)*(b-a))/(f(b)-f(a)));
float prev_root=root;

float abs_error=1.00000;
float tolerance=0.00001;
int steps=1;
while(abs_error>tolerance){

    if(f(a)*f(root)<0){
        b=root;
    }
    else a=root;






    cout<<steps<<" "<<a<<" "<<f(a)<<" "<<b<<" "<<f(b)<<" "<<root<<" "<<f(root)<<""<<abs_error<<endl;

    steps++;
    root=a-((f(a)*(b-a))/(f(b)-f(a)));
    abs_error=fabs(root-prev_root);
    prev_root=root;

}

cout<<root<<endl;
}
