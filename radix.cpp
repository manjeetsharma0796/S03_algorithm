#include<iostream>
#include<vector>
using namespace std;

// To find max
int getMax(vector<int> arr, int size) {
    int max = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

//Counting sort algorithm in the basis of significant places
vector<int> countingSort(vector<int> arr, int size, int place) { //place is for unit or tens or hundered's place and goes on
    // Create a count array to store the number of elements at each index.
    int range = 10;         
    vector<int> output(size);       // This is sorted array which we will return
    int count[range];          // 0 to 9 there 10 element in each digit

    for(int i = 0; i < range; i++) 
        count[i] = 0;

    //calculating frequency
    for(int i = 0; i < size; i++) 
        count[(arr[i] / place) % 10]++;         // this mod thing is modified here in counting sort
    
    //calculating cumulative frequency
    for(int i =1; i < range; i++)
        count[i] += count[i - 1];

    //Place the elements in sorted order
    for(int i = size - 1; i >= 0; i--) {
        int currValue = (arr[i]/place) % 10;        // this mod thing is modified here in counting sort
        int position = count[currValue];

        output[position - 1] = arr[i];
        count[currValue]--;
    }

    return output;
}

vector<int> radixSort(vector<int> arr, int size) {
    //Get maximum element
    int max = getMax(arr, size);

    //Applying counting sort to sort elements on the basis of their digit place
    for(int place = 1; max / place > 0; place *= 10) {
        arr = countingSort(arr, size, place);
    }

    return arr;
}

void display(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
}

vector<int> input() {
    int size;
    cout<<"Enter number of elements to sort: ";
    cin>>size;
    vector<int> arr(size);

    for(int i = 0; i < size; i++)
        cin>>arr[i];

    return arr;
}

int main() {
    // vector<int> arr = {103, 4, 33, 322, 190, 107};
    vector<int> arr = input();
    int size = arr.size();
    
    cout<<"Sorted elements: ";
    vector<int> sorted = radixSort(arr, size);
    display(sorted);

    return 0;
}