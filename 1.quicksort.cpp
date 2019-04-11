#include <iostream>

using namespace std;

void swap(int &a, int &b){
  int temp = a ;
  a = b;
  b = temp;
}

int partition(int array[],int p, int r){
  int i=p,x = array[r];
  for (int j=p;j<r;j++){
    if (array[j] < x){
      swap(array[i],array[j]);
      i++;
    }
  }
  swap(array[i],array[r]);
  return i;
}

void quicksort(int array[],int p,int r){
  if (p<r){
    int q = partition(array,p,r);
    quicksort(array,p,q-1);
    quicksort(array,q+1,r);
  }
}

int main(){
  int n;
  cout<<"Enter number of elements: ";
  cin>>n;

  int array[n];

  for(int i=0;i<n;i++){
    cout<<"Enter element #"<<i<<" : ";
    cin>>array[i];
  }
  quicksort(array,0,n-1);

  int k;
  cout<<"Enter Kth element to find: ";
  cin>>k;
  cout<<"Kth smallest element is "<<array[k-1];
}
