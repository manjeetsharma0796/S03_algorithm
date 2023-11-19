//Recursive approach to knapsack 0 1 problem

#include<iostream>
using namespace std;
// I assume that number of elements will be within 10
int val[10];   // profits
int wt[10];    // weight of the profits

int knapsack(int n , int w) {
    if(w <= 0)
        return 0;

    if(n <= 0)
        return 0;

    if(wt[n - 1] > w) 
        return knapsack(n - 1, w );

    return max(knapsack(n -1, w), knapsack(n-1, w - wt[n-1]) + val[n-1]);
}

int main () {
    int n, sackSize;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter weight: ";
    
    for(int i = 0; i < n; i++) {
        cin>>wt[i];
    }
    
    cout<<"Enter value or profits: ";
    
    for(int i = 0; i < n; i++) {
        cin>>val[i];
    }
    
    cout<<"Enter sack max limit: ";
    cin>>sackSize;

    cout<<knapsack(n, sackSize);
    return 0;
}