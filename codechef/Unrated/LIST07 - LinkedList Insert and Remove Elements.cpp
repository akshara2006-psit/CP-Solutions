import java.util.*;

class Codechef
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        LinkedList<Integer> list = new LinkedList<>();

        for (int i = 0; i < n; i++)
        {
            list.add(sc.nextInt());
        }

        int q = sc.nextInt();

        for (int i = 0; i < q; i++)
        {
            String operation = sc.next();

            // TODO: Process the LinkedList operations
            switch (operation) {
    case "ADD_FIRST":
        list.addFirst(sc.nextInt());
        break;

    case "ADD_LAST":
        list.addLast(sc.nextInt());
        break;

    case "REMOVE_FIRST":
        if (!list.isEmpty())
            list.removeFirst();
        break;

    case "REMOVE_LAST":
        if (!list.isEmpty())
            list.removeLast();
        break;
}
        }

        if (list.isEmpty())
        {
            System.out.println("Empty");
        }
        else
        {
            for (int i = 0; i < list.size(); i++)
            {
                if (i > 0)
                {
                    System.out.print(" ");
                }

                System.out.print(list.get(i));
            }

            System.out.println();
        }

        sc.close();
    }
}