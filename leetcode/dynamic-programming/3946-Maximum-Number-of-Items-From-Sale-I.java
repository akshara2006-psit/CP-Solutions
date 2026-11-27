class Solution {
    Integer[][][] dp;
    int[] facCount;
    public int s(int[][] items,int k,int i,int isPrev){
        if(k<0)
        return Integer.MIN_VALUE;
        if(i>=items.length)
        return 0;
        if(dp[i][k][isPrev]!=null)
        return dp[i][k][isPrev];
        int free=0;
        if(isPrev==0){
            free=facCount[i];
        }
        int take=1+free+s(items,k-items[i][1],i,1);
        int skip=s(items,k,i+1,0);
        int res=Math.max(take,skip);
        return dp[i][k][isPrev]=res;

    }
    public int maximumSaleItems(int[][] items, int budget) {
        facCount=new int[items.length];
        for(int i=0;i<items.length;i++){
            for(int j=0;j<items.length;j++){
                if(i!=j && items[j][0] % items[i][0]==0){
                    facCount[i]++;
                }
            }
        }
        dp=new Integer[items.length][budget+1][2];
        return s(items,budget,0,0);
    }
}