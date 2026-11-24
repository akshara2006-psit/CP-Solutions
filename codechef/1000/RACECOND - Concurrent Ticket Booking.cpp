===FILENAME:Codechef.java===

import java.util.*;

class TicketInventory {
    private int availableTickets;
    private int successfulBookings;

    TicketInventory(int totalTickets) {
        availableTickets = totalTickets;
        successfulBookings = 0;
    }

    // TODO 2: Thread-safe booking
    public synchronized boolean bookTickets(int quantity) {

        if (quantity <= 0 || quantity > availableTickets) {
            return false;
        }

        availableTickets -= quantity;
        successfulBookings++;

        return true;
    }

    // TODO 3: Return available tickets
    public synchronized int getAvailableTickets() {
        return availableTickets;
    }

    // TODO 4: Return successful bookings
    public synchronized int getSuccessfulBookings() {
        return successfulBookings;
    }
}

// TODO 1: Extend Thread
class BookingWorker extends Thread
{
    private final TicketInventory inventory;
    private final int quantity;
    private final int attempts;

    BookingWorker(TicketInventory inventory, int quantity, int attempts) {
        this.inventory = inventory;
        this.quantity = quantity;
        this.attempts = attempts;
    }

    @Override
    public void run() {
        for (int i = 0; i < attempts; i++) {
            inventory.bookTickets(quantity);
            if (i % 100 == 0) {
                Thread.yield();
            }
        }
    }
}

class Codechef {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);
        int totalTickets = sc.nextInt();
        int n = sc.nextInt();

        TicketInventory inventory = new TicketInventory(totalTickets);
        BookingWorker[] workers = new BookingWorker[n];

        for (int i = 0; i < n; i++) {
            int quantity = sc.nextInt();
            int attempts = sc.nextInt();
            workers[i] = new BookingWorker(inventory, quantity, attempts);
        }

        for (BookingWorker worker : workers) {
            worker.start();
        }
        for (BookingWorker worker : workers) {
            worker.join();
        }

        System.out.println("Tickets Remaining: " + inventory.getAvailableTickets());
        System.out.println("Successful Bookings: " + inventory.getSuccessfulBookings());
        sc.close();
    }
}
