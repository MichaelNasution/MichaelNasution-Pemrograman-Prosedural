import java.util.Scanner;

public class T00 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();

		// Bagian A: Genap/Ganjil
		System.out.println("Bilangan pertama: " + (a % 2 == 0 ? "Genap" : "Ganjil"));
		System.out.println("Bilangan kedua: " + (b % 2 == 0 ? "Genap" : "Ganjil"));

		// Bagian B: Lebih besar
		if (a > b) {
			System.out.println("Bilangan pertama lebih besar");
		} else if (b > a) {
			System.out.println("Bilangan kedua lebih besar");
		} else {
			System.out.println("Kedua bilangan sama besar");
		}

		// Bagian C: Operasi sesuai jenis
		if (a % 2 == 0 && b % 2 == 0) {
			System.out.println("Hasil penjumlahan: " + (a + b));
		} else if (a % 2 != 0 && b % 2 != 0) {
			System.out.println("Hasil perkalian: " + (a * b));
		} else {
			System.out.println("Berbeda jenis");
		}
	}
}