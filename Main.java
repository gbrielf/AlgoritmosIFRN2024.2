import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;

class InsertionSort {
    private int[] ordenedList;
    private int lengthList;

   
    public InsertionSort(int[] ordenedList, int lengthList) {
        this.ordenedList = ordenedList;
        this.lengthList = lengthList;
    }

    public int[] ordenedList() {
        for (int i = 1; i < lengthList; i++) {
            int j = i;
            while (j > 0 && ordenedList[j] < ordenedList[j - 1]) {
                int aux = ordenedList[j];
                ordenedList[j] = ordenedList[j - 1];
                ordenedList[j - 1] = aux;
                j--;
            }
        }
        return ordenedList;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

     
        System.out.print("Enter quantity of input values: ");
        int lengthList = scanner.nextInt();
        scanner.close();

        int value = 0;

        while (value < 4) {
            int[] ordenedList = new int[lengthList];

       
            for (int i = 0; i < lengthList; i++) {
                ordenedList[i] = random.nextInt(lengthList);
            }

            InsertionSort insertionsort = new InsertionSort(ordenedList, lengthList);

            double start = System.nanoTime() / 1_000_000_000.0; // Convertendo para segundos
            int[] sortedList = insertionsort.ordenedList();
            double end = (System.nanoTime() / 1_000_000_000.0) - start; // Tempo decorrido

         
            String tempoFormatado = String.format("%.6f", end);

           
            System.out.println("Tempo de execução: " + tempoFormatado + " segundos");

     
            try (FileWriter file = new FileWriter("InsertionSort1000000.txt", true);
                 PrintWriter ffile = new PrintWriter(file)) {

                ffile.println("LISTA DE VALORES ORDENADOS:");
                for (int i = 0; i < lengthList; i++) {
                    ffile.printf("%d ", sortedList[i]);
                    if ((i + 1) % 20 == 0) {
                        ffile.println(); 
                    }
                }
