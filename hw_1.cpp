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
std::vector<int> findIndexes(std::vector<int>& a, std::vector<int>& b) {
    std::vector<int> result;
    for (int i = 0; i < b.size(); ++i)
    {
        int left = 0;
        int right = a.size();
        int mid = left + (right - left) / 2;

        while (left < right)
        {
            if (a[mid] < b[i])
                left = mid + 1;
            else
                right = mid;

            mid = left + (right - left) / 2;
        }

        if (a[left] < b[i])
            result.push_back(a.size());
        else
            result.push_back(left);
    }

    return result;
}

int main()
{
    // Задача 3
    std::vector<int> nums = {2, 4, 4, 5, 6, 1, 0, 3};
    std::cout << "Task 3: " << findDuplicate(nums) << std::endl;

    // Задача 4
    std::cout << "Task 4: ";
    std::vector<int> a = {2, 4, 5, 7};
    std::vector<int> b = {4, 6, 1, 8};
    std::vector<int> indexes = findIndexes(a, b);
    for (auto element : indexes)
        std::cout << element << " ";

    return 0;
}