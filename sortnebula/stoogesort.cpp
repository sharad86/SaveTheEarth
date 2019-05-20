#include<bits/stdc++.h>

using namespace std;
struct item{
    int key;
    int value;
};

void swap(item *a, item *b){
    item * temp = a;
    a = b;
    b = temp;
}
//Function to implement stooge sort 
void stoogesort(vector<item>&arr, int l, int h) 
{ 
      if (l >= h) 
        return; 
  
    // If first element is smaller than last, 
    // swap them 
    if ((arr[h].key < arr[l].key || ( arr[h].key==arr[l].key && arr[h].value <= arr[l].value ))) 
        swap(arr[h], arr[l]); 
  
    // If there are more than 2 elements in 
    // the array 
    if (h - l + 1 > 2) { 
        int t = (h - l + 1) / 3; 
  
        // Recursively sort first 2/3 elements 
        stoogesort(arr, l, h - t); 
  
        // Recursively sort last 2/3 elements 
        stoogesort(arr, l + t, h); 
  
        // Recursively sort first 2/3 elements 
        // again to confirm 
        stoogesort(arr, l, h - t); 
    } }
int main()
{
    
    int n;

    cout<<"Enter the number of elements:\n";
    cin>>n;

    vector< item >arr(n);

    cout<<"Enter the key value pairs:\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].key>>arr[i].value;
    
}


    stoogesort(arr,0,n-1);

    cout<<"The sorted pairs are:\n";

    for(int i=0;i<n;i++){
        cout<<arr[i].key<<"\t"<<arr[i].value<<"\n";}
        
   return 0;
}


