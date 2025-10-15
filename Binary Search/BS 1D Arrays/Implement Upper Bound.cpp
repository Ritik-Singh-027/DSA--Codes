class Solution {
public:
    int upperBound(vector<int>& arr, int target) {
        // 🔹 Optimal approach — manual binary search
        /*
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n; // default: if target is >= all elements

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target) {
                ans = mid;       // possible answer, look left
                high = mid - 1;
            } else {
                low = mid + 1;   // move right
            }
        }

        return ans;
        */

        // 🔹 C++ STL built-in implementation (much simpler)
        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        return ub;
    }
};
