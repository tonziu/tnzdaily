// Author: https://github.com/tonziu
// Problem Description:
//   Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
//   For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
//   Bonus: Can you do this in one pass ?

#include <iostream>
#include <array>
#include <unordered_map>

bool has_sum(int* arr, size_t len, int target)
{
    bool ret = false;
    std::unordered_map<int, int> map;
    size_t i = 0;
    while (i < len)
    {
        int complement = target - arr[i];
        auto iter = map.find(complement);
        if (iter != map.end())
        {
            ret = true;
            break;
        }
        else
        {
            map[arr[i++]] = i;
        }
    }
    return ret;
}

int main(void)
{
    std::array<int, 4> test_array = { 10, 3, 3, 7 };
    bool result = has_sum(test_array.data(), 4, 9);
    bool expected = false;
    printf("Got: %d\nExpected: %d\n", result, expected);
    if (result == expected)
    {
        printf("TEST PASSED.\n");
        return 0;
    }
    else
    {
        printf("TEST FAILED.\n");
        return 1;
    }

    return 1;
}
