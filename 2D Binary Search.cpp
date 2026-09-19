#include <iostream>
using namespace std;

bool binarySearch(int arr[][4], int target, int m, int n) {

    int low = 0;
    int high = m * n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int row = mid / n;
        int column = mid % n;

        if (arr[row][column] == target) {
            return true;
        }
        else if (arr[row][column] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {

    int arr[3][4] = {{1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 60}};

    int target = 3;

    bool found = binarySearch(arr, target, 3, 4);

    if (found)
        cout << "true";
    else
        cout << "false";

    return 0;
}