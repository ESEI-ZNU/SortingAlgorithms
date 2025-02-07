package mypackage;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Якого розміру масив Ви хочете створити?");
        Scanner scanner = new Scanner(System.in);
        String answer = scanner.nextLine();
        int arraySize = Integer.parseInt(answer);
        System.out.println("Ви обрали масив з " + arraySize + " елементами цілого типу.");
    }
}
