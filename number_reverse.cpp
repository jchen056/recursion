
// write a recursive function that takes an integer n and prints the base 10 digits of
// n in reverse order.  E.g. if n = 2345, should print 5432

#include <iostream>
using namespace std;

void func(int n){
	if(n<10) {
  	cout<<n<<endl;
    return;
  }
  cout<<n%10;//print last digit
  func(n/10); 
}
int main()
{
    int a;
    while(cin>>a){
        func(a);
    }
}
