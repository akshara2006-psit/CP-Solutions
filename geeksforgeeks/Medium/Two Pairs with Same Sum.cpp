
class Solution {

    public ArrayList<Integer> findPairs(int[] arr) {

        int n = arr.length;

        HashMap<Long, ArrayList<int[]>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                long sum = (long) arr[i] + arr[j];

                if (!map.containsKey(sum)) {
                    map.put(sum, new ArrayList<>());
                }

                map.get(sum).add(new int[]{i, j});
            }
        }
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                long sum = (long) arr[i] + arr[j];

                ArrayList<int[]> pairs = map.get(sum);

                for (int[] p : pairs) {

                    int c = p[0];
                    int d = p[1];
                    if (c < i || (c == i && d <= j)) {
                        continue;
                    }
                    if (i != c && i != d &&
                        j != c && j != d) {

                        return new ArrayList<>(
                            Arrays.asList(i, j, c, d)
                        );
                    }
                }
            }
        }

        return new ArrayList<>(
            Arrays.asList(-1, -1, -1, -1)
        );
    }
}
