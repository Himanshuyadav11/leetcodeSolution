class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long int ans = 0 , dec = 0;
        sort(happiness.begin() , happiness.end() , greater<int>());
        for(int i=0;i<k;i++){
            ans +=max(0ll , happiness[i]-dec);
            dec++;
        } 
        return ans;
    }
};