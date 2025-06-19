// Author: https://github.com/tonziu
// Problem Description:
//   Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
//   For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], the expected output would be[2, 3, 6].
//   Follow - up: what if you can't use division?

#include <array>
#include <iostream>
#include <unordered_map>

void prod_array(int* src, int* dest, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        int prod = 1;
        for (size_t j = 0; j < len; ++j)
        {
            prod *= src[j];
        }

        int n = 0;
        int diff = prod - src[i] * n;
        while (diff != 0)
        {
            n += 1;
            diff = prod - src[i] * n;
        }

        dest[i] = n;
    }
}

int main(void)
{
    std::array<int, 5> test_array = { 1, 2, 3, 4, 5 };
    std::array<int, 5> result = { 0 };
    
    prod_array(test_array.data(), result.data(), 5);

    for (int i = 0; i < 5; ++i)
    {
        printf(" %d ", result[i]);
    }

    return 0;
}
