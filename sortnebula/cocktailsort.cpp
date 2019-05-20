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
//Function to implement cocktailsort sort 
 void cocktailsort(vector<item>&arr, int n) 
{ 
    bool swapped = true; 
    int start = 0; 
    int end = n - 1; 
  
    while (swapped) { 
        // reset the swapped flag on entering 
        // the loop, because it might be true from 
        // a previous iteration. 
        swapped = false; 
  
        // loop from left to right same as 
        // the bubble sort 
        for (int i = start; i < end; ++i) { 
           if ((arr[i].key > arr[i+1].key || ( arr[i].key==arr[i+1].key && arr[i].value >= arr[i+1].value ))) 
       { 
                swap(arr[i], arr[i + 1]); 
                swapped = true; 
            } 
        } 
  
        // if nothing moved, then array is sorted. 
        if (!swapped) 
            break; 
  
        // otherwise, reset the swapped flag so that it 
        // can be used in the next stage 
        swapped = false; 
  
        // move the end point back by one, because 
        // item at the end is in its rightful spot 
        --end; 
  
        // from right to left, doing the 
        // same comparison as in the previous stage 
        for (int i = end - 1; i >= start; --i) { 
            if ((arr[i].key >arr[i+1].key || ( arr[i].key==arr[i+1].key && arr[i].value >= arr[i+1].value ))) 
        { 
                swap(arr[i], arr[i + 1]); 
                swapped = true; 
            } 
        } 
  
        // increase the starting point, because 
        // the last stage would have moved the next 
        // smallest number to its rightful spot. 
        ++start; 
    } 
} 
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


    cocktailsort(arr,n);

    cout<<"The sorted pairs are:\n";

    for(int i=0;i<n;i++){
        cout<<arr[i].key<<"\t"<<arr[i].value<<"\n";}
        
   return 0;
}

