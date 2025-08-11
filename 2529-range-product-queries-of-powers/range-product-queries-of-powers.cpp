static constexpr int mod=1e9+7;
int POW2[435];// 435 is enough
class Solution {
public:
    static void preCompute(){
        if (POW2[0]>0) return;// compute just once
        int p=POW2[0]=1;
        for(int i=1; i<435; i++){
            p<<=1;
            if (p>=mod) p-=mod;
            POW2[i]=p;
        }
    }
    static vector<int> productQueries(int n, vector<vector<int>>& queries) {
        preCompute();
        const int m=queries.size();
        bitset<30> B(n);
        vector<int> exp2;
        for(int i=0; i<30; i++)
            if (B[i]) exp2.push_back(i);

        partial_sum(exp2.cbegin(), exp2.cend(), exp2.begin());

        vector<int> ans(m);
        for(int i=0; i<m; i++){
            const int s=queries[i][0], e=queries[i][1];
            const int exp=exp2[e]-((s==0)?0:exp2[s-1]);
            ans[i]=POW2[exp];
        }
        return ans;
    }
};