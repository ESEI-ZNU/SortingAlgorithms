package mypackage;

import java.util.Scanner; // Переконайся, що цей імпорт є
import java.util.Iterator;//Іпорт для Scanner
/**
 * Клас, що представляє масив цілих чисел.
 * Забезпечує доступ до елементів, копіювання, випадкове заповнення
 * та підтримує ітерацію.
 *
 * @author Довгий Владислав
 */
public class MyArray implements Iterable<Integer> {
    private final int[] arr;

    /**
     * Конструктор класу MyArray.
     *
     * @param size Розмір масиву.
     */
    public MyArray(int size) {
        this.arr = new int[size];
    }

    /**
     * Метод для отримання посилання на масив.
     *
     * @return масив
     */
    public int[] getArr() {
        return arr;
    }

    /**
     * Отримати значення елемента за індексом.
     *
     * @param index індекс елемента
     * @return значення елемента
     */
    public int get(int index) {
        return arr[index];
    }

    /**
     * Встановити значення елемента за індексом.
     *
     * @param index індекс елемента
     * @param value нове значення
     */
    public void set(int index, int value) {
        arr[index] = value;
    }

    /**
     * Повертає розмір масиву.
     *
     * @return кількість елементів у масиві
     */
    public int size() {
        return arr.length;
    }

    /**
     * Створює копію масиву.
     *
     * @return копія масиву
     */
    public int[] copy() {
        return arr.clone();
    }

    /**
     * Заповнює масив випадковими цілими числами.
     *
     * @param bound верхня межа для генерації чисел
     */
    public void fillRandom(int bound) {
        java.util.Random rand = new java.util.Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(bound); // [0, bound)
        }
    }

    /**
     * Заповнює масив елементами, введеними користувачем.
     *
     * @param scanner об'єкт для зчитування вводу користувача
     */
    public void fillManual(Scanner scanner) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print("Введіть елемент [" + i + "]: ");
            arr[i] = scanner.nextInt(); // Зчитуємо елемент від користувача
        }
    }

    /**
     * Повертає ітератор для масиву.
     *
     * @return об'єкт ітератора
     */
    @Override
    public Iterator<Integer> iterator() {
        return new MyArrayIterator();
    }

    /**
     * Внутрішній клас-ітератор.
     */
    private class MyArrayIterator implements Iterator<Integer> {
        private int currentIndex = 0;

        @Override
        public boolean hasNext() {
            return currentIndex < arr.length;
        }

        @Override
        public Integer next() {
            return arr[currentIndex++];
        }
    }
}