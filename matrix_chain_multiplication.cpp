#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void display(vector<vector<int>> arr) {
    for (int i = 1; i < arr.size(); i++) {        // this is a customized which starts from 1
        for (int j = 1; j < arr[i].size(); j++) {        // this is a customized which starts from 1
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrixChainOrder(int p[], int size) {
    //I chose vector so that i can pass to another function to display it's content more easily
    vector<vector<int>> m(size,vector<int>(size));  //To store min scalar multiplication order
    vector<vector<int>> s(size,vector<int>(size));  //To store split position that results into min order

    // Initialization: Setting the cost of multiplying a single matrix as 0
    for (int i = 1; i < size; i++){
        for(int j = 1; j < size; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    // Computing minimum number of scalar multiplications needed
    for (int l = 2; l < size; l++) {
        for (int i = 1; i < size - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }


    cout<<"____________M matrix____________ \n";
    display(m);
    cout<<"____________S matrix____________ \n";
    display(s);
}

int main() {
    int arr[] = {10, 100, 20, 5, 10};
    matrixChainOrder(arr, 5);

    return 0;
}