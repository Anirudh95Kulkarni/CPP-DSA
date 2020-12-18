class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long n1 = 2147483648, n2 = 2147483648;
        int count =0, idx2 =0;
        if(nums.size()<3){
            return false;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<n1){
                n1 = nums[i];
            }
            if(nums[i]> n1){
                n2 = nums[i]<n2?nums[i]:n2;
            }
            if(nums[i]> n2){
                return true;
            }
            
        }
        return false;
            
    }
};
