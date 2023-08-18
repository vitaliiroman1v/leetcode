#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        std::vector<int> input;
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(input));
        int half_size = input.size() / 2;
        if ( input.size() & 1 )
            return input[half_size];
        return (double(input[half_size - 1] + input[half_size])) / 2;
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    std::vector<int> nums1_1 = {1, 3};
    std::vector<int> nums2_1 = {2};
    double expected_output_1 = 2.0;

    // Test Case 2
    std::vector<int> nums1_2 = {1, 2};
    std::vector<int> nums2_2 = {3, 4};
    double expected_output_2 = 2.5;

    // Test Case 1
    double output_1 = solution.findMedianSortedArrays(nums1_1, nums2_1);
    std::cout << "Test Case 1: " << (output_1 == expected_output_1 ? "Passed" : "Failed") << "\n";

    // Test Case 2
    double output_2 = solution.findMedianSortedArrays(nums1_2, nums2_2);
    std::cout << "Test Case 2: " << (output_2 == expected_output_2 ? "Passed" : "Failed") << "\n";

    return 0;
}