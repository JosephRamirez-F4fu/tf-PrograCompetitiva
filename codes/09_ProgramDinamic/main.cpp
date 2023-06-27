#include<vector>
using namespace std;
class Solution {
public:
bool canJump(vector<int> &nums)
{
    const int len = 1000000;
    bool bucket[len];
    for (int i = 0; i < len; i++)
    {
        bucket[i] = false;
    }
    int n=nums.size();
    bucket[0]=true;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]>0&&bucket[i]){
        for (int j = 0; j <= nums[i]; j++)
        {
            
                bucket[i+j]=true;
                if(i+j==n-1)return true;
            
        }
        }
        
    } 
    return bucket[n-1];
}
};