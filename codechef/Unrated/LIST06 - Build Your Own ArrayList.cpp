import java.util.*;

class MyArrayList
{
    private int[] arr;
    private int size;
    private int capacity;
    MyArrayList()
    {
        // TODO:
        // Initialize the internal array
        // with a small initial capacity.

        size = 0;
        capacity=2;
        arr=new int[capacity];
        
    }

    void add(int element)
    {
        // TODO:
        // If the internal array is full:
        // 1. Create a larger array.
        // 2. Copy existing elements.
        // 3. Replace the old array.
        //
        // Then add the new element
        // and increase size.
        if(size==capacity){
            resize();
        }
        arr[size]=element;
        size++;
    }
    private void resize(){
        capacity=capacity*2;
        int[] new_Arr =new int[capacity];
        for(int i=0;i<size;i++){
            new_Arr[i]=arr[i];
        }
        arr=new_Arr;
    }
    int get(int index)
    {
        // TODO:
        // Return the element at the given index.

        return arr[index];
    }

    int size()
    {
        // TODO:
        // Return the number of stored elements.

        return size;
    }

    void print()
    {
        // TODO:
        // Print all stored elements
        // space-separated on one line.
       for (int i = 0; i < size; i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(arr[i]);
        }
        System.out.println();
    }
}

class Codechef
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int q = sc.nextInt();

        MyArrayList list = new MyArrayList();

        while (q-- > 0)
        {
            String operation = sc.next();

            if (operation.equals("add"))
            {
                int x = sc.nextInt();
                list.add(x);
            }
            else if (operation.equals("get"))
            {
                int index = sc.nextInt();
                System.out.println(list.get(index));
            }
            else if (operation.equals("size"))
            {
                System.out.println(list.size());
            }
            else if (operation.equals("print"))
            {
                list.print();
            }
        }

        sc.close();
    }
}