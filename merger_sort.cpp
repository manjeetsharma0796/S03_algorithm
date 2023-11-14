#include<iostream>
using namespace std;

void merge (int arr[], int l, int m, int r) {   //l is leftmost m is mid r is right most
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // create temp arrays
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i=0 ; i < n1 ; i++)
        L[i] = arr[l + i];

    for(j=0 ; j < n2 ; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while(i < n1 && j < n2 ) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy remaining elements of L[], if there are any */
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy remaining elements of R[], if there are any */
    while(j < n2 ){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {               // this part is basically dividing till only single element exist
    if(l < r) {
        int m = l+(r-l)/2;    //l 0 r 6 m = 3
        mergeSort(arr, l, m);  // (0 , 3)  m = 1
        mergeSort(arr, m + 1, r); // (4, 6) m = 5
        merge(arr, l, m, r);
    }
}


// Function to print an array
void printArray(int A[], int size) {
    for (int i=0; i < size; i++ )
    cout << A[i] << " ";
    cout << endl;
}
    // Driver program to test above functions
int main() {
    int arr[] ={9, 78, 0, 13, 5, 45, 0 , 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    cout<<"\nSorted array \n";
    printArray(arr, n);

    return 0;                            
}