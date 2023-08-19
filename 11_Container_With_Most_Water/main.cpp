#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;
        int result = 0;
        int curr_max = 0;
        for (;left < right;)
        {
            curr_max = std::min(height[left], height[right]) * (right - left);
            result = std::max(result, curr_max);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int expected_output = 49;

    int output = solution.maxArea(height1);
    std::cout << (expected_output == output ? "Passed" : "Failed") << "\n";
    return 0;
}