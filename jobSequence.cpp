#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int relArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap(relArr[j], relArr[j + 1]);
            }
        }
    }
}

vector<int> scheduleJobs(int job[], int deadline[], int totalJobs)
{
    bubbleSort(job, deadline, totalJobs);
    vector<int> result; // To store result

    for (int i = 0; i < totalJobs; i++)
    {
        result.push_back(-1); // Initialising slot position with -1 ; where -1 signifies empty place
    }

    for (int i = 0; i < totalJobs; i++)
    {
        int j = deadline[i];

        while (j > 0)
        {
            if (result[j -1] == -1)
            {
                result[j - 1] = job[i];
                break;
            }
            else
            {
                j--;
            }
        }
    }
    return result;
}

void display(vector<int> arr)
{
    cout << "The Result is: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
}

void input(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }
}

int main()
{   int totalJobs;
    cout<<"Enter total number of jobs: ";
    cin >> totalJobs;
    
    int job[totalJobs], deadline[5];

    cout<<"Enter jobs: ";
    input(job, totalJobs);
    
    cout<<"Enter deadlines: ";
    input(deadline, totalJobs);

    vector<int> result = scheduleJobs(job, deadline, totalJobs);
    display(result);

    return 0;
}