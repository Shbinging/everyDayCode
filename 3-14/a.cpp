#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, 0, nums.size() - 1, k);
    }
    int find(vector<int>& nums, int l, int r, int k){
        printf("%d %d\n", l, r);
        swap(nums[l], nums[r]);
        int pos = l;
        for(int i = l; i < r; i++){
            if (nums[i] >= nums[r]){
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        swap(nums[r], nums[pos]);
        if (pos - l + 1 == k) return nums[pos];
        else if (pos - l + 1 < k) return find(nums, pos + 1, r, k - (pos - l + 1));
        else return find(nums, l, pos - 1, k);         
    }   
};
int main(){
    int n;
    scanf("%d", &n);
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        nums.push_back(tmp);
    }
    Solution a;
    a.findKthLargest(nums, 3);
    return 0;
}