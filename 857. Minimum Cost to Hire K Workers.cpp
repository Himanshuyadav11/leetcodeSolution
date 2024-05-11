class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double , int>> worker;
        for(int i=0;i<quality.size();i++)
            worker.push_back({(wage[i]*1.0)/quality[i] , quality[i]});
        sort(worker.begin() , worker.end());
        double ans = DBL_MAX , qulatysum = 0;
        priority_queue<int> pq;
        for(auto wr : worker){
            double ratio = wr.first;
            qulatysum += wr.second , pq.push(wr.second);
            if(pq.size() > k) qulatysum -=pq.top() , pq.pop();
            if(pq.size() == k) ans = min(ans , qulatysum*ratio);
        }
        return ans;
    }
};