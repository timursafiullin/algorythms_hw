#include <iostream>
#include <vector>

// Задача 1
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    return .0;
}

// Задача 2
unsigned int crazyFrog(std::vector<int>& axis)
{
    return 0;
}

// Задача 3
int findDuplicate(std::vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        int next = a[i] < 0 ? -a[i] : a[i];
        if (a[next] < 0)
            return next;
        a[next] *= -1;
    }
    return -1;
}

// Задача 4
std::vector<int> findIndexes(std::vector<int>& a, std::vector<int>& b)
{
    return std::vector<int>();
}

int main()
{
    std::vector<int> nums = {2, 0, 4, 5, 6, 1, 0, 3};
    std::cout << findDuplicate(nums) << std::endl;
    return 0;
}