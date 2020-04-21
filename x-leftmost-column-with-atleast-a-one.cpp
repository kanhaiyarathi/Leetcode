/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    
    int leftCol(BinaryMatrix &binaryMatrix, int row, int n){
        int start = 0, end = n-1;
        int mid, ans = INT_MAX;
        
        while(start<=end){
            mid = start + (end-start)/2;
            if(binaryMatrix.get(row, mid)==1){
                ans = mid;
                end = mid-1;
            }else
                start=mid+1;
        }
        return ans;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int ans = INT_MAX;
        vector<int> dir = binaryMatrix.dimensions();
        int m = dir[0];
        int n = dir[1];
//        cout << m << "    " << n <<endl;
        int counter = 0;
        for(int i=0;i<m;i++){
            ans = min(ans, leftCol(binaryMatrix, i, n));          
        }
//        cout <<" counter:"<<counter <<endl;
        return ans==INT_MAX?-1:ans;
    }
}; 
