
import java.util.*;

class Pair {
    int num;
    int freq;

    Pair(int num, int freq) {
        this.num = num;
        this.freq = freq;
    }
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.freq, b.freq)
        );

        for (int key : map.keySet()) {

            Pair curr = new Pair(key, map.get(key));
            if (pq.size() < k) {
                pq.add(curr);
            }
            else if (curr.freq > pq.peek().freq) {
                pq.poll();
                pq.add(curr);
            }
        }
        int[] ans = new int[k];

        for (int i = 0; i < k; i++) {
            ans[i] = pq.poll().num;
        }

        return ans;
    }
}