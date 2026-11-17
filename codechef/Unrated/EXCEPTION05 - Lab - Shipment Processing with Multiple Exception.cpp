===FILENAME:Codechef.java===
import java.util.Scanner;

public class Codechef {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int totalWeight = 0;

        for (int i = 0; i < n; i++) {

            String shipmentId = scanner.next();
            String weightInput = scanner.next();

            try {
                // 1. Convert String into integer
                int weight = Integer.parseInt(weightInput);

                // 2. Check whether weight is positive
                if (weight <= 0) {
                    throw new IllegalArgumentException();
                }

                // 3. Add valid weight to total
                totalWeight += weight;

                // 4. Print accepted shipment
                System.out.println(shipmentId + " Accepted: " + weight + " kg");

            } catch (NumberFormatException e) {

                System.out.println(shipmentId + " Rejected: Invalid weight format");

            } catch (IllegalArgumentException e) {

                System.out.println(shipmentId + " Rejected: Weight must be positive");

            }
        }

        System.out.println("Total accepted weight: " + totalWeight + " kg");
        scanner.close();
    }
}