
class Solution {
    public int[] findSubtreeSizes(int[] parent, String s) {

        int n = parent.length;

        List<Integer>[] tree = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 1; i < n; i++) {
            tree[parent[i]].add(i);
        }

        int[] newParent = new int[n];
        int[] last = new int[26];
        int[] oldLast = new int[n];

        Arrays.fill(last, -1);
        int[] stack = new int[2 * n + 5];
        int[] order = new int[n];

        int top = 0;
        int count = 0;

        stack[top++] = 0;

        while (top > 0) {

            int u = stack[--top];
            if (u < 0) {
                u = ~u;
                int c = s.charAt(u) - 'a';
                last[c] = oldLast[u];
                continue;
            }
            order[count++] = u;

            int c = s.charAt(u) - 'a';

            oldLast[u] = last[c];

            if (u == 0) {
                newParent[u] = -1;
            } else {
                if (last[c] != -1) {
                    newParent[u] = last[c];
                } else {
                    newParent[u] = parent[u];
                }
            }

            last[c] = u;
            stack[top++] = ~u;
            for (int i = tree[u].size() - 1; i >= 0; i--) {
                stack[top++] = tree[u].get(i);
            }
        }
  
        int[] ans = new int[n];
        Arrays.fill(ans, 1);
        for (int i = n - 1; i > 0; i--) {

            int node = order[i];
            int p = newParent[node];

            ans[p] += ans[node];
        }

        return ans;
    }
}
