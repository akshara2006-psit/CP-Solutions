class Solution {
    public int longestSubarrayDivK(int[] arr, int k) {
        // code here
        HashMap<Integer, Integer> map = new HashMap<>();
                map.put(0, -1);
                long prefixSum = 0;
                int maxLen = 0;
                for (int i = 0; i < arr.length; i++) {
                    prefixSum += arr[i];
                    int rem = (int) Math.floorMod(prefixSum, (long) k);
                    if (map.containsKey(rem)) {
                        int len = i - map.get(rem);
                        maxLen = Math.max(maxLen, len);
                    } else {
                        map.put(rem, i);
                    }
                }

                return maxLen;

    }
}
