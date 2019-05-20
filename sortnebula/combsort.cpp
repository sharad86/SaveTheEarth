#include<bits/stdc++.h>

using namespace std;

struct item
{
int key;
int value;
};

void swap(item *a,item *b)                             // Function for swapping two elements
{
item * temp=a;
a=b;
b=temp;
}

int getNextGap(int gap)                             // Finding gap between elements initialize gap
{ 
    gap = (gap*10)/13;                             // Shrinking gap by shrink factor
  
    if (gap < 1) 
        return 1; 
    return gap; 
} 
 
void combsort(vector<item>&arr,int n)               // Sorting function
{
int gap=n;                                       // Initialize gap
bool swapped=true;                               // Initialize swapped as true to make sure that loop runs 
    while (gap != 1 || swapped == true)         // Looping till gap becomes 1 last iteration causes a swap
    { 
        gap = getNextGap(gap);                  //finding next gap
        swapped = false;                       // Initialize swapped as false so that we can check if swap happened or not 
  
        for (int i=0; i<n-gap; i++) 
        { 
            if ((arr[i].key > arr[i+gap].value)||(arr[i].key==arr[i+gap].key&&arr[i].value>arr[i+gap].value)   )        // Comparing pairs
            { 
                swap(arr[i], arr[i+gap]); 
                swapped = true; 
            } 
        }
    } 
} 

int main()                                    // Main function
{ 
   int n;
   cout<<"Enter the number of key-value pairs:";
   cin>>n;
    vector<item>arr(n);
    cout<<"Enter the key value pairs:"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].key>>arr[i].value;
    
     }
  
    combsort(arr,n); 
  
  for(int i=0;i<n;i++)
  cout<<arr[i].key<<","<<arr[i].value<<"\n";  
  
    return 0; 
} 