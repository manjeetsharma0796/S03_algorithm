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

vector<int> scheduleJobs(int job[], int deadline[], int n)
{
    bubbleSort(job, deadline, 5);

    vector<int> result; // To store result

    for (int i = 0; i < n; i++)
    {
        result.push_back(-1); // Initialising slot position with -1
    }

    for (int i = 0; i < n; i++)
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

int main()
{
    int job[5] = {3, 2, 4, 6, 7};
    int deadline[5] = {1, 2, 3, 4, 5};
    int n = 5;
    vector<int> result = scheduleJobs(job, deadline, 5);
    display(result);

    return 0;
}