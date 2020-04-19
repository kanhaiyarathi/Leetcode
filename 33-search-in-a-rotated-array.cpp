
class Solution {
public:
    
    int indexShort(vector<int> &nums, int start, int end){        
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(mid>=1 && nums[mid-1] > nums[mid])
                return mid-1;
            else if(mid<end && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]>nums[start]){
                start=mid+1;
            }else{
                end =mid-1;
            }
        }
        return -1;
    }
    
    int bs(vector<int> &nums, int target, int start, int end){

        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                start=mid+1;    
            }else{
                end = mid-1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
    
        int i= indexShort(nums, 0, nums.size()-1);
      //  cout << "index: " << i << endl;
        
        int f =bs(nums, target,0,i);
        if(f!=-1)
            return f;
        else 
            return bs(nums, target,i+1, nums.size()-1);
    
    }
};
