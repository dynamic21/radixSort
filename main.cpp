#include <iostream>
#include <chrono>
#include <ratio>
#include <algorithm>
#include "RadixSort256.h"

using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::steady_clock;

unsigned int state = 90354;

unsigned int xorshift32()
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

void GenerateRandomData(unsigned int *arr, int count)
{
    for (int i = 0; i < count; i++)
        arr[i] = xorshift32();
}

int main()
{
    int COUNT = 10000000;
    unsigned int *arr = new unsigned int[COUNT];
    for (int r = 0; r < 10; r++)
    {
        steady_clock::time_point t1 = steady_clock::now();
        GenerateRandomData(arr, COUNT);
        RadixSort256(arr, COUNT);
        steady_clock::time_point t2 = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        cout << "Time: " << time_span.count() << endl;
    }
    // cout << endl;
    // cout << "Sorted list: " << endl;
    // for (int i = 0; i < COUNT; i++)
    //     cout << i << ": " << arr[i] << endl;
    for (int i = 1; i < COUNT; i++)
        if (arr[i] < arr[i - 1])
            cout << "error" << endl;
    delete[] arr;
}