//recursion function for Fibonacci sequence (1,1,2,3,5,8,13,21...)
#include <iostream>
using namespace std;
#include<assert.h>
#include<vector>
using std::vector;

//the function has no memory of computing fib(m), and so it computes this value again and again from scratch.
/*int fib(int n){
    if (n<2) 
        return 1;
    return fib(n-1)+fib(n-2);
}*/


/*Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call. */
size_t fmemo(size_t n){
    static vector<size_t> A={1,1};
    if (n<2)
        return 1;
    if(n<A.size()){
        return A[n];
    //if we have a stored answer..use it
    assert(A.size()==n);//this will end the program if boolean is true; make sure we are putting the answer in the right place
    size_t answer=fmemo(n-1)+fmemo(n-2);
    A.push_back(answer);
    return answer;
    }
    
    
}
int main()
{   size_t a;
    while(cin>>a){
        cout<<fmemo(a)<<"\n";}
    return 0;
}
