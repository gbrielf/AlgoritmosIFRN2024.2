import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

class InsertionSort {
    private List<Integer> list_of_numbers;
    private int lengthlist;

    // Construtor da classe InsertionSort
    public InsertionSort(List<Integer> list_of_numbers, int lengthlist) {
        this.list_of_numbers = list_of_numbers;
        this.lengthlist = lengthlist;
    }

    // Método para ordenar a lista usando o algoritmo Insertion Sort
    public List<Integer> ordenaLista() {
        for (int i = 1; i < lengthlist; i++) {
            int key = list_of_numbers.get(i); // Elemento atual
            int j = i - 1;

            // Move os elementos maiores que `key` para frente
            while (j >= 0 && list_of_numbers.get(j) > key) {
                list_of_numbers.set(j + 1, list_of_numbers.get(j));
                j--;
            }
            // Insere o `key` na posição correta
            list_of_numbers.set(j + 1, key);
        }
        return list_of_numbers;
    }
}

public class EntradaDados {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o tamanho da lista:");
        int lengthlist = scanner.nextInt();

        List<Integer> list = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < lengthlist; i++) {
            list.add(random.nextInt(lengthlist)); // Adiciona o número aleatório na lista
        }

        System.out.println();

        long start = System.nanoTime();

        InsertionSort insertionsort = new InsertionSort(list, lengthlist);
        List<Integer> sortedList = insertionsort.ordenaLista();

        System.out.println("Lista de números ordenados:");
        for (int num : sortedList) {
            System.out.print(num + " ");
        }
        System.out.println();

        long end = System.nanoTime();
        long elapsedTime = end - start;

        System.out.println("Tempo de execução (ns): " + elapsedTime);

        // Gravar as informações em um arquivo .txt
        try (FileWriter file = new FileWriter("ArqTeste.txt", true);
             PrintWriter ffile = new PrintWriter(file)) {

            ffile.printf("LISTA DE VALORES ORDENADOS: \n");
            int break_ = 0;

            for (int i = 0; i < lengthlist; i++) {
                ffile.printf("%d ", sortedList.get(i));
                break_++;
                if (break_ == 20) { // Quebra de linha após 20 números
                    break_ = 0;
                    ffile.printf("\n");
                }
            }
            ffile.printf("\nTEMPO: %d ns\n", elapsedTime);

        } catch (IOException e) {
            System.err.println("Erro ao manipular o arquivo: " + e.getMessage());
        }

        scanner.close();
    }
}
