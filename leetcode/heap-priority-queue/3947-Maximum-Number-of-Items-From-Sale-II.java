// class Solution {
//     public int maximumSaleItems(int[][] items, int budget) {
//         int n=items.length;
//         int[] c=new int[n];
//         int[] p=new int[n];
//         for(int i=0;i<n;i++){
//             c[i]=items[i][1];
//             int a=1;
//             for(int j=0;j<n;j++){
//                 if(i!=j && items[j][0] % items[i][0]==0){
//                     a++;
//                 }
//             }
//             p[i]=a;
//         }
//         int[][] dp=new int[n+1][budget+1];
//         for(int i=1;i<=n;i++){
//            for( int j=0;j<=budget;j++){
//             dp[i][j]=dp[i-1][j];
//             if(j>=c[i-1]){
//                 dp[i][j]=Math.max(dp[i][j],dp[i-1][j-c[i-1]]+p[i-1]);
//             }
//            }
//         }
//         int ch=Integer.MAX_VALUE;
//         for(int[] item: items){
//             ch=Math.min(ch,item[1]);
//         }
//         int res=0;
//         for(int i=0;i<=budget;i++){
//             int b=dp[n][i];
//             int rem=budget-i;
//             b=b+rem/ch;
//             res=Math.max(res,b);
//         }
//         return res;
//     }
// }

class Solution{
    public int maximumSaleItems(int[][] items, int budget) {
        int n=items.length;
         int[] c=new int[n+1];
         long min=Long.MAX_VALUE;
         for(int i=0;i<n;i++){
           c[items[i][0]]++;
            if(items[i][1]<min){
                min=items[i][1];
            }
         }
         int[] dp=new int[n+1];
         for(int i=1;i<=n;i++){
            if(c[i]>0){
                int m=-1;
                for(int j=i;j<=n;j+=i){
                    m+=c[j];
                }
                dp[i]=m;
            }
         }
         long[] d=new long[n];
         int de=0;
         long limit=min*2;
         for(int i=0;i<n;i++){
            int first=items[i][0];
            int second=items[i][1];
            if(second<limit){
                int m=dp[first];
                if(m>0){
                    d[de++]=((long)second<<32)|(m & 0xFFFFFFFFL);
                }
            }
         }
         Arrays.sort(d,0,de);
         long total=0;
         for(int i=0;i<de;i++){
            long des=d[i];
            int m=(int)(des>>>32);
            int counts=(int)(des & 0xFFFFFFFFL);
            if(budget>=m){
                long time=Math.min((long)counts,budget/m);
                budget -=time*m;
                total +=2*time;
            }
         }
         total +=budget/min;
         return (int)total;

    }

}