#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

unsigned int state = 123;
unsigned int xorshift32()
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

void GenerateRandomData(unsigned int *arr, int count, int seed, int max)
{
    state = seed;
    for (int i = 0; i < count; i++)
        arr[i] = xorshift32() % max;
}

void GenerateRandomData(unsigned int *arr, int count, int seed)
{
    state = seed;
    for (int i = 0; i < count; i++)
        arr[i] = xorshift32();
}

int main()
{
    int COUNT = 10;

    unsigned int *arr = new unsigned int[COUNT];

    for (int r = 0; r < 10; r++)
    {
        long startTime = clock();
        for (int i = 0; i < 1; i++)
        {
            GenerateRandomData(arr, COUNT, 123);
            //RadixSort256(arr, COUNT);
        }
        long finishedTime = clock();

        cout << "Time: " << (finishedTime - startTime) << endl;
    }

    cout << endl;
}