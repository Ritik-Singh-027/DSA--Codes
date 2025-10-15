class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 🔹 Brute-force approach 
        /*
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                return i;
            else if (nums[i] > target)
                return i;
        }
        return n;
        */

        // 🔹 Optimal approach — Binary Search
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // When not found, 'low' gives the correct insert position
        return low;
    }
};
