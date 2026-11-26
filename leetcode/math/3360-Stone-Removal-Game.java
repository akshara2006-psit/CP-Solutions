class Solution {
    public boolean canAliceWin(int n) {
        int remove = 10;

        while (n >= remove) {
            n -= remove;
            remove--;
        }
        return remove != 10 && remove % 2 == 9 % 2;
    }
}