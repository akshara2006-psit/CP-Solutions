class Solution {
    public ArrayList<Integer> countVowels(String s, int[][] queries) {
        // code here
        int n = s.length();

        int[] prefix = new int[n];
        for (int i = 0; i < n; i++) {
            int vowel = isVowel(s.charAt(i)) ? 1 : 0;

            if (i == 0) {
                prefix[i] = vowel;
            } else {
                prefix[i] = prefix[i - 1] + vowel;
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];

            if (l == 0) {
                ans.add(prefix[r]);
            } else {
                ans.add(prefix[r] - prefix[l - 1]);
            }
        }

        return ans;
    }

    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' ||
               ch == 'i' || ch == 'o' ||
               ch == 'u';
    }
}