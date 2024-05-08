class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> rankname = {"Gold Medal","Silver Medal","Bronze Medal"};
        int maxscore = *max_element(score.begin(),score.end());

        vector<int> scoretoindex(maxscore+1 , -1);
        for (int i = 0; i < score.size(); ++i) scoretoindex[score[i]] = i;
        unordered_map<int , int> rank;
        int rankct = 1;
        for(int sc = maxscore; sc >=0 ; sc--){
            if(scoretoindex[sc] == -1) continue;
            rank[sc] = rankct++;
        }

        vector<string> ans(score.size());
        for (int i = 0; i < score.size(); ++i)
        {
            int actualrank = rank[score[i]];
            ans[i] = (actualrank<=3) ? rankname[actualrank-1] : to_string(actualrank);
        }
        return ans;
    }
};