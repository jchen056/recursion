#include <iostream>
using namespace std;
#include<assert.h>
#include<vector>
using std::vector;
/*Imagine you have two stacks of cards, and each one is sorted.
Putting them into one sorted stack is relatively easy:
start a third stack for the result,
and then just examine the top card from each stack to decide which one goes next into the third.*/

#include <iostream>
using namespace std;
#include<assert.h>
#include<vector>
using std::vector;
/*Imagine you have two stacks of cards, and each one is sorted.
Putting them into one sorted stack is relatively easy:
start a third stack for the result,
and then just examine the top card from each stack to decide which one goes next into the third.*/

/* A and B are sorted (ascending) arrays of size nA, nB respectively.
* We will place the result into S, which we assume to have sufficient
* space (at least nA+nB elements). */
void merge(int *A, int *B,size_t nA, size_t nB,int* S){
    //size_t nA=A.size();
    //size_t nB=B.size();
    size_t iA=0;// index for element in A
    size_t iB=0;//index for element in B
    size_t iS=0;//index for element in S
    while (iA < nA && iB < nB) {
        if (A[iA] < B[iB]){
            S[iS] = A[iA];
            iS++;
            iA++;
        }
        else {
            S[iS] = B[iB];
            iS++;
            iB++;
        }}
   while (iA < nA){
        S[iS++] = A[iA++];}
    while (iB < nB){
        S[iS++] = B[iB++];}

}

void mergeSort(int *A,size_t n,int *result){
    if(n<2)
       { return;}
        /*For arrays of size 0 or 1, they are already sorted, so
there's nothing to do!*/
    mergeSort(A,n/2,result);
    mergeSort(A+n/2,n-n/2,result);

    merge(A,A+n/2,n/2,n-n/2,result);
    for (size_t i=0;i<n;i++){
        A[i]=result[i];
    }
}
int main()
{   int A[6]={2,7,6,5,10,5};

    int B[6];
    mergeSort(A,6,B);
    for(int i=0;i<6;i++){
      cout<<A[i]<<" ";}
    cout<<"\n";
    return 0;
}

