===FILENAME:Codechef.java===

public class Codechef {
    public static void main(String[] args) {

        // TODO 1: Declare arrays
        String[] name = new String[10];
        int[] roll = new int[10];

        try {

            // TODO 2: Initialize and display students
            for (int i = 0; i < 10; i++) {
                name[i] = "Student" + i;
                roll[i] = i + 1;

                System.out.println(name[i] + " " + roll[i]);
            }

            // TODO 3: Deliberately access invalid index
            System.out.println(name[10]);

        }
        catch (ArrayIndexOutOfBoundsException e) {

            // TODO 4: Handle exception
            System.out.println(
                "Array Index Out Of Bounds Exception Handled"
            );
        }
    }
}
