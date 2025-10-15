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

        //using lower bound solution
         /*
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n; // default answer if all elements < target

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid;      // possible answer, move left
                high = mid - 1;
            } else {
                low = mid + 1;  // move right
            }
        }

        return ans;
        */
    }
};
