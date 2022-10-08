//recusive approach........

class Solution {
public:
    int maxMoneyLooted(vector<int>&nums){
        
        //base condition
        
        if(currentIndex >= nums.size()){
            return 0;
        }
        //choices
     
        
      
        int ans=0;
        int lootenge = maxMoneyLooted(nums,currentIndex+2,mp) + nums[currentIndex];
        int nhiLootenge = maxMoneyLooted(nums,currentIndex+1,mp);
        
       ans = max(lootenge,nhiLootenge);
        
        return  ans;
        
    }
    
    int rob(vector<int>& nums) {
        
        return maxMoneyLooted(nums,0);
    }
};

//memoization approach.............


class Solution {
public:
    int maxMoneyLooted(vector<int>&nums, int currentIndex,unordered_map<int,int>&mp){
        
        //base condition
        
        if(currentIndex >= nums.size()){
            return 0;
        }
        //choices
        int currentKey = currentIndex;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int lootenge = maxMoneyLooted(nums,currentIndex+2,mp) + nums[currentIndex];
        int nhiLootenge = maxMoneyLooted(nums,currentIndex+1,mp);
        
        mp[currentKey] = max(lootenge,nhiLootenge);
        
        return   mp[currentKey];
        
    }
    
    int rob(vector<int>& nums) {
        unordered_map<int,int>mp;
        return maxMoneyLooted(nums,0,mp);
    }
};


problem link:https://leetcode.com/problems/house-robber/

