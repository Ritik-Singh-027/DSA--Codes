class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        // 🔹 Optimal approach: Binary Search (commented out)
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

        // 🔹 C++ STL implementation
        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        return lb;

        // 🔹 Brute-force approach (commented out)
        /*
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= target)
                return i;
        }
        return n;
        */
    }
};
