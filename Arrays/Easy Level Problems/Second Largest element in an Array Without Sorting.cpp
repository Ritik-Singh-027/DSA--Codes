class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=arr[0];
        
        int s_largest=-1;
        
        int n = arr.size();
        
        for (int i=1; i<n; i++) {
            if (arr[i]>largest) {
                s_largest = largest;
                largest=arr[i];
            }
            else if (arr[i]<largest && arr[i] > s_largest) {
                s_largest=arr[i];
            }
        }
        
        if (s_largest == -1) return -1;
        
        return s_largest;
    }
};