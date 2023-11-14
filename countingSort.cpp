#include<iostream>
#include<vector>
using namespace std;

void input(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
}

int findMax(vector<int> arr) {
    int max = INT8_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}
void display(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

vector<int> countingSort(vector<int>& unsorted, int range) {
    // Create a count array to store the frequency of each element.
    vector<int> countArr;
    vector<int> sorted(unsorted.size());

    for(int i = 0; i <= range; i++) {
        countArr.push_back(0);                        // initialising counts to 0
    }                                                 // to countArr whose size is range

    for(int i = 0; i < unsorted.size(); i++) {
        countArr[unsorted[i]]++;                      // we got a frequency here  
    }

    for(int i = 1; i < countArr.size(); i++) {
        countArr[i] += countArr[i - 1];               // we got cumulative frequency here
    }

    countArr.insert(countArr.begin(), 0);             // shifting one position and poping the last value
    countArr.pop_back();

    for(int i = 0; i < unsorted.size(); i++) {        // iterating to all element of unsorted element array and checking the countArr for index
        int currentElement = unsorted[i];
        int index = countArr[currentElement];

        sorted[index] = currentElement;
        countArr[currentElement]++;
    }

    return sorted;
}

int main() {
    int numOfElements;

    cout<<"Enter total elements' count: ";
    cin>>numOfElements;

    vector<int> arr(numOfElements);                 //initialising array of a certain size
    
    cout<<"Enter elements: ";
    input(arr);
    int range = findMax(arr);                       //getting range

    vector<int> sorted = countingSort(arr, range);  //getting sorted array
    display(sorted);

    return 0;
}