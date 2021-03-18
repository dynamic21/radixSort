#pragma once

static void RadixSort256(unsigned int *arr, int n)
{
    unsigned int *output = new unsigned int[n];
    int *count = new int[256];
    unsigned int *originalArr = arr;

    for (int shift = 0, s = 0; shift < 4; shift++, s += 8)
    {
        for (int i = 0; i < 256; i++)
            count[i] = 0;

        for (int i = 0; i < n; i++)
            count[(arr[i] >> s) & 0xff]++;

        for (int i = 1; i < 256; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
            output[--count[(arr[i] >> s) & 0xff]] = arr[i];

        unsigned int *tmp = arr;
        arr = output;
        output = tmp;
    }
    delete[] output;
    delete[] count;
}