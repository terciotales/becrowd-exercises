import java.io.IOException;
import java.util.Scanner;

public class ex1006 {
    public static void main(String[] args) throws IOException {
      Scanner ler = new Scanner(System.in);
       double a, b, c, media;
       a = ler.nextDouble();
       b = ler.nextDouble();
       c = ler.nextDouble();
      media = ((a*2)+(b*3)+(c*5))/(2+3+5);
      System.out.println(String.format("MEDIA = %.1f" , media));
    }
 
}