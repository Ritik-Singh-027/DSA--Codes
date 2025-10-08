class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> nums3(m+n);

        int left=0; // nums1 
        int right=0; // nums2 

        int index=0; // nums3 

        while (left<m && right<n) {
            if (nums1[left]<=nums2[right]) {
                nums3[index++]=nums1[left++];
            }
            else {
                nums3[index++]=nums2[right++];
            }

        }

        while (left<m) nums3[index++] = nums1[left++];
        while (right<n) nums3[index++] = nums2[right++];

        for (int i=0; i<m+n; i++) {
            nums1[i]=nums3[i];
        }
    }
};

// optimal solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // last valid element in nums1
        int j = n - 1;       // last element in nums2
        int k = m + n - 1;   // last index of nums1

        // Merge from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining nums2 elements (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
    }
};