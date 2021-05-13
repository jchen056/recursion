// write a function that takes a vector V of (distinct) integers, and an
// integer k and returns a vector of vectors representing all possible
// subsets of k elements from V
// e.g. if V = [1,2,3,4], and k was 2, answer should be [[1,2],[1,3],[2,3],[1,4],[2,4],[3,4]]
// and if k == 1, answer would be [[1],[2],[3],[4]]
// sub([1,2,3],2) would have given  {{1,2}{2,3}{1,3}}
// how to get all the stuff with a 3?
  //
#include <iostream>
using namespace std;
#include<vector>
using std::vector;

vector<vector<int>> sub(vector<int> set,size_t k){
    //base case: take zero elements
    if (k==0){
  return {{}};
  }

  if(k>set.size()){
    return {};}//{}means no sol
  vector<int> set1(set);
  int last=set[set.size()-1];//element removed
  set1.pop_back();//remove one element
  vector<vector<int>> temp=sub(set1,k);//going to add new set into this bigger set
  vector<vector<int>> tempp=sub(set1,k-1);
  for (size_t i=0;i<tempp.size();i++){
    vector<int> a=tempp[i];
    a.push_back(last);//push_back element removed
    temp.push_back(a);}
  return temp;

}

int main()
{
    vector<int> V={1,2,3,4};
    size_t k=2;
    vector<vector<int>> ksub=sub(V,k);
    cout << "{\n";
    for(size_t i=0;i<ksub.size();i++){
      cout << "{";
      for (size_t j=0;j<ksub[i].size();j++){
        cout<<" "<<ksub[i][j];}
      cout<<"}\n";
        }

    cout << "}\n";
    return 0;

}