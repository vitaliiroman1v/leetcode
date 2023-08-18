#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = (i+1); j < nums.size(); ++j)
            {
                if ((nums.at(i) + nums.at(j)) == target)
                    return {i, j};
            }
        }
        return {};
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    std::vector<int> nums1 = { 2, 7, 11, 15 };
    int target1 = 9;
    std::vector<int> expected_output_1 = { 0, 1 };
    auto output_1 = solution.twoSum(nums1, target1);
    std::cout << "Test Case 1: " << (output_1 == expected_output_1 ? "Passed" : "Failed") << "\n";

    // Test Case 2
    std::vector<int> nums2 = { 3, 2, 4 };
    int target2 = 6;
    std::vector<int> expected_output_2 = { 1, 2 };
    auto output_2 = solution.twoSum(nums2, target2);
    std::cout << "Test Case 2: " << (output_2 == expected_output_2 ? "Passed" : "Failed") << "\n";

    // Test Case 3
    std::vector<int> nums3 = { 3, 3 };
    int target3 = 6;
    std::vector<int> expected_output_3 = { 0, 1 };
    auto output_3 = solution.twoSum(nums3, target3);
    std::cout << "Test Case 3: " << (output_3 == expected_output_3 ? "Passed" : "Failed") << "\n";

    return 0;
}