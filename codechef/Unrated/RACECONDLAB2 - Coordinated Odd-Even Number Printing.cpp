===FILENAME:OddEvenThreadLab/src/main/java/NumberCoordinator.java===

public class NumberCoordinator {

    private boolean oddTurn = true;

    public synchronized void printOdd(int number)
            throws InterruptedException {

        // Wait until it is the odd thread's turn
        while (!oddTurn) {
            wait();
        }

        // Print the odd number
        System.out.print(number + " ");

        // Give turn to even thread
        oddTurn = false;

        // Wake waiting threads
        notifyAll();
    }

    public synchronized void printEven(int number)
            throws InterruptedException {

        // Wait until it is the even thread's turn
        while (oddTurn) {
            wait();
        }

        // Print the even number
        System.out.print(number + " ");

        // Give turn to odd thread
        oddTurn = true;

        // Wake waiting threads
        notifyAll();
    }
}
