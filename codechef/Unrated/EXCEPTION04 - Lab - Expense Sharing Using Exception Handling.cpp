===FILENAME:Codechef.java===
import java.util.Scanner;

public class Codechef {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int totalBill = sc.nextInt();
        int members = sc.nextInt();

        try {
            int share = totalBill / members;
            System.out.println("Each member pays: " + share);
        } 
        catch (ArithmeticException e) {
            System.out.println("Cannot divide expense among zero members");
        }

        sc.close();
    }
}