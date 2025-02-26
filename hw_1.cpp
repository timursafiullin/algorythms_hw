#include <iostream>
#include <vector>

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

int main()
{
    std::vector<int> nums = {2, 0, 4, 5, 6, 1, 0, 3};
    std::cout << findDuplicate(nums) << std::endl;
    return 0;
}