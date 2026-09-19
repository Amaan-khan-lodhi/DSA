#include <iostream>
using namespace std;

class MedianFinder {
private:
    int arr[50000];
    int size;

public:
    MedianFinder() {
        size = 0;
    }

    void addNum(int num) {

        int i = size - 1;
        while (i >= 0 && arr[i] > num) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = num;
        size++;
    }

    double findMedian() {

        if (size % 2 == 1) {
            return arr[size / 2];
        }
        else {
            return (arr[size / 2 - 1] + arr[size / 2]) / 2;
        }
    }
};