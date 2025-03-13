#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
    public:
        // Task 2
        std::string simplifyPath(std::string path) {
            std::string result = "";
            std::string temp;
            std::vector<std::string> stack;

            int i = 0;
            while(path[i] != NULL)
            {
                if (path[i] == '/')
                {
                    while (path[i] == '/')
                        ++i;

                    if (path[i] == NULL)
                        break;

                    if (temp == "..")
                        stack.pop_back();
                    else if (temp == ".") {}
                    else
                        stack.push_back(temp);
                    temp = "";
                }
                temp += path[i];
                ++i;
                if (path[i] == NULL)
                    stack.push_back(temp);
            }


            for (auto& elem : stack)
            {
                if (elem == "")
                    continue;
                result += "/" + elem;
            }
            
            return result;
        }

        // Task 5
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
        {
            if (list1 == nullptr)
                return list2;
            if (list2 == nullptr)
                return list1;

            if (list1->val < list2->val)
            {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else
            {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }

};

void test_task2()
{
    std::cout << std::endl;
    std::cout << "[TEST]\tTask 2" << std::endl;

    Solution solution;
    std::string input1 = "///home/./etc/..//auto///get//...";
    std::string input2 = "/.../a/../b/c/../d/./";

    std::cout << "\tInput:\t///home/./etc/..//auto///get" << std::endl;
    std::cout << "\tOutput:\t";
    std::cout << solution.simplifyPath(input1) << std::endl << std::endl;

    std::cout << "\tInput:\t/.../a/../b/c/../d/./" << std::endl;
    std::cout << "\tOutput:\t";
    std::cout << solution.simplifyPath(input2) << std::endl;

}

void test_task5()
{
    std::cout << std::endl;
    std::cout << "[TEST]\tTask 5" << std::endl;
    std::cout << "\tInput:\t[1 1 3], [1 2 4]" << std::endl;
    std::cout << "\tOutput:\t[ ";
    
    Solution solution;
    ListNode* list1 = new ListNode(1, new ListNode(1, new ListNode(3)));
    ListNode* list2 = new ListNode(1, new ListNode(2, new ListNode(4)));

    ListNode* result = solution.mergeTwoLists(list1, list2);
    while(result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << "]" << std::endl;
}

int main()
{
    test_task2();
    test_task5();
}