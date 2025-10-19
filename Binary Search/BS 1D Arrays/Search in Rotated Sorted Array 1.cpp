class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Brute-Force
        /*
        int ans = -1;
        for (int i = 0; i<nums.size(); i++) {
            if (nums[i]==target) {
                ans = i;
            }
        }

        return ans;
        */

        // optimal
        
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] == target) {
                return mid;
            }

            // left sorted 

            if (nums[low]<=nums[mid]) { 
                if (nums[low] <= target  && target <= nums[mid]){
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }

            // right sorted

            else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low=mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }

        return -1;

    }
};