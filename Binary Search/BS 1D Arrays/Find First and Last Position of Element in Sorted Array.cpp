class Solution {
public:
    int first(vector<int>& nums, int target, int n) {
        //int n = nums.size();
        int low = 0, high = n-1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] == target) {
                ans=mid;
                high=mid-1;
            }
            else if (nums[mid] > target) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }

    int last(vector<int>& nums, int target, int n) {
        //int n = nums.size();
        int low = 0, high = n-1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] == target) {
                ans=mid;
                low=mid+1;
            }
            else if (nums[mid] > target) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
    /*
    int lowerbound(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high=n-1;
        int ans = n;

        while (low <= high) {
            int mid = low+(high-low)/2;

            if(nums[mid] >= target) {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;

    }
    int upperbound(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high=n-1;
        int ans = n;

        while (low <= high) {
            int mid = low+(high-low)/2;

            if(nums[mid]>target) {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
    */
    vector<int> searchRange(vector<int>& nums, int target) {

        //optimal: 2 using binary search

        if (nums.empty()) return {-1, -1};

        int n = nums.size();

        int first_pos = first(nums,target,n);
        int last_pos = last(nums,target,n);

        return {first_pos, last_pos};

        //optimal: 1 using lower and upper bound

        /*
        if (nums.empty()) return {-1, -1};

        int n = nums.size();

        int first_pos = lowerbound(nums, target);

        if(first_pos == n || nums[first_pos] != target ) return {-1,-1};

        int last_pos = upperbound(nums, target) - 1;
        return {first_pos, last_pos};
        */

        // brute-force
        /*
        int n = nums.size();

        int first = -1, last = -1;

        for (int i = 0; i<n; i++) {
            if (nums[i] == target) {
                if (first == -1) first = i;
                last = i;
            }
        }

        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
        */
        
    }
};