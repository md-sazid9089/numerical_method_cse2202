#include<bits/stdc++.h>
using namespace std;
float f(float x){
return x*x*x*x-1156*x*x+244036;
}
int main(){
float a=15,b=17;
float root=(a+b)/2;
float prev_root=root;

float abs_error=1.00000;
float tolerance=0.00001;
int steps=1;
while(abs_error>tolerance){

    if(f(a)*f(root)<0){
        b=root;
    }
    else a=root;






    cout<<steps<<" "<<abs_error<<" "<<root<<endl;;

    steps++;
    root=(a+b)/2;
    abs_error=fabs(root-prev_root);
    prev_root=root;

}

cout<<root<<endl;
}
