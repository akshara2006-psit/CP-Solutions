import java.util.ArrayList;
import java.util.Scanner;

class Codechef {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> numbers = new ArrayList<>();

        // Write your code here
        for (int i = 0; i < n; i++) {
            numbers.add(sc.nextInt());
        }
        for (int i = 0; i < numbers.size(); i++) {
            int num = numbers.get(i);

            if (num % 2 == 0) {
                numbers.set(i, num + 1);
            }
        }
        System.out.println("Updated Array:");
        for (int i = 0; i < n; i++) {
            System.out.println(numbers.get(i));
        }
        sc.close();
    }
}
