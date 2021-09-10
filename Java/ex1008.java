import java.io.IOException;
 
/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
import java.util.Scanner;
class Main{
	public static void main(String[] args){
		Scanner ler = new Scanner(System.in);
		int num, hrs;
		double salario;
		num = ler.nextInt();
		hrs = ler.nextInt();
		salario = ler.nextDouble();
		salario *= hrs;
		System.out.println("NUMBER = " + num);
		System.out.printf("SALARY = U$ "+ salario);
	}
}