import java.util.Scanner;

class GradeTask implements Runnable
{
    private final int marks;

    GradeTask(int marks)
    {
        this.marks = marks;
    }

    @Override
    public void run()
    {
        // TODO:
        // Print "Grade A" if marks are between 80 and 100.
        // Otherwise, print "Other Grade".
         if (marks >= 80 && marks <= 100)
        {
            System.out.println("Grade A");
        }
        else
        {
            System.out.println("Other Grade");
        }
    }
}

class MarksheetTask implements Runnable
{
    @Override
    public void run()
    {
        // TODO:
        // Print "Students Marksheet".
        System.out.println("Students Marksheet");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        int marks = scanner.nextInt();

        // TODO:
        // 1. Create a Thread using GradeTask.
        // 2. Create a Thread using MarksheetTask.
        // 3. Start the grade thread.
        // 4. Wait for it to finish using join().
        // 5. Start the marksheet thread.
        // 6. Wait for it to finish using join().
        // 7. Handle InterruptedException properly.
 Thread t1 = new Thread(new GradeTask(marks));

        Thread t2 = new Thread(new MarksheetTask());

        try
        {
            t1.start();

            t1.join();

            t2.start();

            t2.join();
        }
        catch (InterruptedException e)
        {
            Thread.currentThread().interrupt();
        }

        scanner.close();
    }
}