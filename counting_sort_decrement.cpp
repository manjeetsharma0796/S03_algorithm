#include<iostream>
using namespace std;

// To find max
int getMax(int arr[], int size) {
    int max = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

//Counting sort algorithm in the basis of significant places
void countingSort(int arr[], int size, int place) { // idk why place here is required
    // Create a count array to store the number of elements at each index.
    int range = 10;         //<-- this is made to use for place
    int output[size];       // This is sorted array which we will return
    int count[range];          // 0 to 9 there 10 element in each digit

    for(int i = 0; i < range; i++) 
        count[i] = 0;

    //calculating frequency
    for(int i = 0; i < size; i++) 
        count[arr[i]]++;
    
    //calculating cumulative frequency
    for(int i =1; i < range; i++)
        count[i] += count[i - 1];

    for(int i = 0; i < size; i++) {
        int currentElement = arr[i];
        int position = count[currentElement];
        cout<<currentElement<<"  "<< position<<endl;
        output[position - 1] = currentElement;

        count[currentElement]--;
    }

    cout<<"------Displaying the final sorted array-------"<<endl;
    for(int i = 0; i < size; i++) {
        cout<<output[i]<<" ";
    }
}

int main() {
    int arr[] = {4, 3, 3, 0, 1};
    cout<<"Max element: ";
    countingSort(arr, 5, 4);

    return 0;
}