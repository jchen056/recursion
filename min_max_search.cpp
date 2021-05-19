#include<iostream>
using namespace std;
#include<string>
#include<vector>
using std::vector;

struct node{
  int data;
  node* next;};



/*Write down recursive versions of the following simple functions. Don't use loops or static/global variables, and don't call any functions other than the one you're writing. In each prototype below, the pointer A is understood to be a pointer to the first element of an array of n elements. Hint: Remember that you can get the sub-array A[k,k+1,...,n-1] of n-k elements via pointer arithmetic: (A+k) is this sub-array!
  */
int max(int*A, size_t n){
  if(n==1){
    return A[0];}
  int m=max(A+1,n-1);
  if(m>A[0]){
    return m;}
  else{
    return A[0];}}

int min(int*A,size_t n){
  if(n==1){
    return A[0];}
  int mini=min(A+1,n-1);
  if(mini<A[0]){
    return mini;}
  else{
    return A[0];}}

bool search(int*A, size_t n,int x){
  if(n==1){
    return A[0]==x;}
  return A[0]==x||search(A+1,n-1,x);}

void smallest2(int*A, size_t n,int& min,int &second){
  if(n==2){
    if(A[0]<A[1]){
      min=A[0];
      second=A[1];
      return;}
    else{
      min=A[1];
      second=A[0];
      return;}}
  int temp1,temp2;
  smallest2(A+1,n-1,temp1,temp2);
  //compare A[0] with temp1 and temp2
  if(A[0]>temp2){
    //no need to change: temp1 is smallest and temp2 is second smallest
    min=temp1;
    second=temp2;
    return;}
  else if(A[0]<temp1){
    //update smallest=A[0];second=temp1
    min=A[0];
    second=temp1;
    return;}
  else if(A[0]>temp1&&A[0]<temp2){
    min=temp1;
    second=A[0];
    return;
    }}

int main(){
  int A[8]={1,2,3,4,9,5,6,7};
  int maxi=max(A,8);
  int minim=min(A,8);
  bool Tf=search(A,8,7);
  int min,second;
  smallest2(A,8,min,second);
  cout<<"maximum:"<<maxi<<"\n";
  cout<<"minimum:"<<minim<<"\n";
  cout<<"7 is in the array?"<<Tf<<"\n";
  cout<<"smallest:"<<min<<"\n";
  cout<<"second smallest:"<<second<<"\n";
  return 0;}