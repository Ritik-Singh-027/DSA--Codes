class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // -------------------------------
        // Better brute-force solution (O(n^2))
        // -------------------------------
        /*
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                maxi = max(maxi, prod);
            }
        }

        return maxi;
        */

        // -------------------------------
        // Optimal solution (O(n)) using prefix and suffix products
        // -------------------------------
        int n = nums.size();
        int maxi = INT_MIN;
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < n; i++) {
            // Reset prefix or suffix if zero encountered
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];               // Product from start
            suffix *= nums[n - i - 1];       // Product from end

            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
    }
};
