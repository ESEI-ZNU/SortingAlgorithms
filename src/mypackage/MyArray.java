package mypackage;

/**
 * Клас, що представляє масив цілих чисел.
 *
 * @author Довгий Владислав
 */
public class MyArray {
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
}
