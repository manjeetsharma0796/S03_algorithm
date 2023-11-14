#include <iostream>
using namespace std;

void printSubArrays(int arr[], int n) {
    // Pick starting point
    for (int i = 0; i < n; i++) {
        // Pick ending point
        for (int j = i; j < n; j++) {
        int sum = 0;
            // Print subarray between current starting and ending points
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
                sum += arr[k];
            }
            cout <<"==========="<<sum<< endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "All subarrays of the given array are: " << endl;
    printSubArrays(arr, n);
    return 0;
}
