class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // better approach
        
        // int repeating=-1;
        // int missing=-1;
        
        // int n = arr.size();
        
        // int hash [n+1] = {0};
        
        // for (int i=0; i<n; i++) {
        //     hash[arr[i]]++;
        // }
        
        // for(int i = 1; i<=n; i++) {
        //     if(hash[i] == 2) repeating =i;
            
        //     else if (hash[i] == 0) missing =i;
            
        //     if(repeating != -1 && missing != -1) {
        //         break;
        //     }
        // }
        // return {repeating, missing};
        
        
        
        
        //optimal approach using maths
        
        long long n = arr.size();
        
        
        // s - sn
        // s2- s2n
        
        long long sn = (n*(n+1)) /2 ;
        long long s2n = (n*(n+1)*(2*n+1))/6;
        
        long long s=0, s2=0;
        
        for(int i =0; i<n; i++) {
            
            s +=arr[i];
            s2 +=(long long)arr[i] * (long long)arr[i];
        }
        
        long long val1 = s-sn; //x-y
        long long val2 = s2-s2n; //x^2-y^2
        
        val2 = val2/val1; //x+y = value of x^-y^2/x-y
        
       long long x = (val2+val1)/2; //2x = ans of (x+y + x-y) therefore x= (x+y + x-y) /2 
       long long y = val2-x; // x+y = ans (here val2) now y=ans-x, we have value of x 
       
       return {(int)x, (int)y};
    }
};