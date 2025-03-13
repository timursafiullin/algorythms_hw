#include <iostream>
#include <vector>
#include <stack>

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

        // Task 4
        ListNode* deleteDuplicates(ListNode* head)
        {
            ListNode* temp = head;

            if (head == nullptr || head->next == nullptr)
                return head;

            while (temp->next != nullptr)
            {
                if (temp->val == temp->next->val)
                    temp->next = temp->next->next;
                else
                    temp = temp->next;
            }

            return head;
        }

        // Task 3
        int largestRectangleArea(std::vector<int>& heights)
        {
            std::vector<int> stack = {-1};
            int max_area = 0;
            
            for (int i = 0; i < heights.size(); ++i)
            {
                while (heights[i] < heights[stack.back()] && stack.back() != -1)
                {
                    int height = heights[stack.back()];
                    stack.pop_back();
                    int width = stack.back() == -1 ? i : i - stack.back() - 1;
                    max_area = std::max(max_area, height * width);
                }
                stack.push_back(i);
            }
            
            while (stack.back() != -1)
            {
                int height = heights[stack.back()];
                stack.pop_back();
                int width = stack.back() == -1 ? heights.size() : heights.size() - stack.back() - 1;
                max_area = std::max(max_area, height * width);
            }
            
            return max_area;        
        }
};

void test_task2()
{
    std::cout << std::endl;
    std::cout << "[TEST]\tTask 2" << std::endl;

    Solution solution;
    std::string input1 = "///home/./etc/..//auto///get//...";
    std::string input2 = "/.../a/../b/c/../d/./";

    std::cout << "\tInput:\t///home/./etc/..//auto///get//..." << std::endl;
    std::cout << "\tOutput:\t";
    std::cout << solution.simplifyPath(input1) << std::endl << std::endl;

    std::cout << "\tInput:\t/.../a/../b/c/../d/./" << std::endl;
    std::cout << "\tOutput:\t";
    std::cout << solution.simplifyPath(input2) << std::endl;

}

void test_task4()
{
    std::cout << std::endl;
    std::cout << "[TEST]\tTask 4" << std::endl;
    
    Solution solution;

    ListNode* input1 = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3)))));
    std::cout << "\tInput:\t[ 1 1 1 2 3 ]" << std::endl;
    std::cout << "\tOutput:\t[ ";
    ListNode* result1 = solution.deleteDuplicates(input1);
    while (true)
    {
        std::cout << result1->val << " ";
        result1 = result1->next;
        if (result1 == nullptr)
            break;
    }
    std::cout << "]" << std::endl;

    ListNode* input2 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(4)))));
    std::cout << std::endl << "\tInput:\t[ 1 2 2 3 4 ]" << std::endl;
    std::cout << "\tOutput:\t[ ";
    ListNode* result2 = solution.deleteDuplicates(input2);
    while (true)
    {
        std::cout << result2->val << " ";
        result2 = result2->next;
        if (result2 == nullptr)
            break;
    }
    std::cout << "]" << std::endl;

    ListNode* input3 = new ListNode(2, new ListNode(5, new ListNode(5, new ListNode(5, new ListNode(6, new ListNode(6, new ListNode(7, new ListNode(8, new ListNode(10, new ListNode(10))))))))));
    std::cout << std::endl << "\tInput:\t[ 2 5 5 5 6 6 7 8 10 10 ]" << std::endl;
    std::cout << "\tOutput:\t[ ";
    ListNode* result3 = solution.deleteDuplicates(input3);
    while (true)
    {
        std::cout << result3->val << " ";
        result3 = result3->next;
        if (result3 == nullptr)
            break;
    }
    std::cout << "]" << std::endl;
}

void test_task5()
{
    std::cout << std::endl;
    std::cout << "[TEST]\tTask 5" << std::endl;
    std::cout << "\tInput:\t[ 1 1 3 ], [ 1 2 4 ]" << std::endl;
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

void test_task3()
{
    Solution solution;

    std::cout << std::endl;
    std::cout << "[TEST]\tTask 3" << std::endl;
    
    std::cout << "\tInput:\t[ 2 1 5 6 2 3 ]" << std::endl;
    std::cout << "\tOutput:\t";
    std::vector input1 = {2, 1, 5, 6, 2, 3};
    std::cout << solution.largestRectangleArea(input1) << std::endl;

    std::cout << std::endl << "\tInput:\t[ 1 2 4 6 3 1 ]" << std::endl;
    std::cout << "\tOutput:\t";

    std::vector input2 = {1, 2, 4, 6, 3, 1};
    std::cout << solution.largestRectangleArea(input2) << std::endl;
}

int main()
{
    test_task2();
    test_task3();
    test_task4();
    test_task5();
}