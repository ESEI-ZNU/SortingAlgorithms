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
    }
}