import java.io.IOException;
import java.util.Scanner;

public class ex1007 {
    public static void main(String[] args) throws IOException {
     float A, B, C, D, diferenca;
     Scanner ler = new Scanner(System.in);
     A = ler.nextFloat();
     B = ler.nextFloat();
     C = ler.nextFloat();
     D = ler.nextFloat();
    diferenca = (A * B) - (C * D);
    System.out.println(diferenca);
    }
 
}