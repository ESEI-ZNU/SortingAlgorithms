package mypackage;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Програма дослідження ефективності алгоритмів сортування масивів.
 *
 * @author Дудова Єлізавета
 */
public class Main {

    /**
     * Головний метод програми.
     *
     * @param args аргументи командного рядка
     */
    public static void main(String[] args) {
        System.out.println("Якого розміру масив Ви хочете створити?");
        Scanner scanner = new Scanner(System.in);
        String answer = scanner.nextLine();
        int arraySize = Integer.parseInt(answer);
        System.out.println("Ви обрали масив з " + arraySize + " елементами цілого типу.");
        MyArray myArray = new MyArray(arraySize);

        System.out.println("Як ви хочете заповнити масив?");
        System.out.println("1 — випадковими числами");
        System.out.println("2 — ввести вручну");
        int option = scanner.nextInt();
        scanner.nextLine(); // очищає буфер

        if (option == 1) {
            myArray.fillRandom(100); // числа від 0 до 99
        } else if (option == 2) {
            myArray.fillManual(scanner);
        } else {
            System.out.println("Невірний вибір. Масив буде заповнений нулями.");
        }

        System.out.println("Ваш масив:");
        System.out.println(Arrays.toString(myArray.getArr()));
        System.out.println("А який алгоритм ви хочете обрати?");

        System.out.println("1 — Bubble Sort");

        System.out.println("2 — Insertion Sort");

        int sortOption = scanner.nextInt();
        SortTester tester = new SortTester(myArray.getArr());
        if (sortOption == 1) {
            tester.runBubbleSort();
        } else if (sortOption == 2) {
            tester.runInsertionSort();
        } else {
            System.out.println("Невірний вибір. Сортування не буде виконано.");
        }
    }
}

class SortTester {
    private int[] array;
    private long comparisons;
    private long swaps;
    public SortTester(int[] array) {
        this.array = array;
    }
    public void runBubbleSort() {
        comparisons = 0;
        swaps = 0;
        long startTime = System.nanoTime();
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - 1 - i; j++) {
                comparisons++;
                if (array[j] > array[j + 1]) {
                    swaps++;
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        long endTime = System.nanoTime();
        System.out.println("Bubble Sort Time: " + (endTime - startTime) + " ns");
        System.out.println("Comparisons: " + comparisons);
        System.out.println("Swaps: " + swaps);
    }
    public void runInsertionSort() {
        comparisons = 0;
        swaps = 0;
        long startTime = System.nanoTime();
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                comparisons++;
                array[j + 1] = array[j];
                swaps++;
                j--;
            }
            array[j + 1] = key;
        }
        long endTime = System.nanoTime();
        System.out.println("Insertion Sort Time: " + (endTime - startTime) + " ns");
        System.out.println("Comparisons: " + comparisons);
        System.out.println("Swaps: " + swaps);

    }

}


