#include <iostream>
using namespace std;

// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int value)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if value is present at mid
        if (arr[m] == value)
            return m;
 
        // If value greater, ignore left half
        if (arr[m] < value)
            l = m + 1;
 
        // If value is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}

int main()
{
    int size, value;

    cout<<"Enter number of elements: ";
    cin>>size;

    int arr[size];
    cout<<"Enter elements: ";

    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    cout<<"Enter value to search for: ";
    cin>>value;
    
    cout<<"Element found at index: "<<binarySearch(arr, 0, size - 1, value);

    return 0;
}