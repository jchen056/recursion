
/*write a recursive function to compute n! (the factorial function).*/
#include <iostream>
using namespace std;

unsigned int fac(unsigned int n){
    if (n==0) 
        return 1;
    return fac(n-1)*n;
}
int main()
{   cout<<"enter a number and calculate the factorial a!"<<endl;
    int a;
    cin>>a;
    cout<<fac(a);

    return 0;
}
