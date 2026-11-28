
class Solution {
    static boolean checkPath(ArrayList<ArrayList<Integer>> adj, int u, int v) {
        boolean[] visited = new boolean[adj.size()];
        Queue<Integer> q = new LinkedList<>();

        visited[u] = true;
        q.add(u);

        while (!q.isEmpty()) {
            int curr = q.poll();

            if (curr == v)
                return true;

            for (int neighbor : adj.get(curr)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.add(neighbor);
                }
            }
        }

        return false;
    }
}