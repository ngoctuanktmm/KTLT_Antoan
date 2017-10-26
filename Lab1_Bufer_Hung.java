/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kythuatlaptrinhat;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author shadyside
 */
public class Bai2Lab1 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Nhap chieu dai mang:");
        int inputLen = input.nextInt();
        int[] inputArray = inputArray(inputLen);

        System.out.println("Mảng nguồn: ");
        printArray(inputArray);
        System.out.println("Nhập điểm bắt đầu sao chép: ");
        int start = input.nextInt();
        System.out.println("Nhập điểm kết thúc: ");
        int end = input.nextInt();
        System.out.println("Nhập chiều dài mảng đích");
        int outputLen = input.nextInt();
        int[] ouputArray = inputArray(outputLen);

        System.out.println("Nhập vị trí bắt đầu thêm dữ liệu");
        int startOfCopy = input.nextInt();

        System.out.println("Mảng đích ban đầu: ");
        printArray(ouputArray);
        System.out.println("-------------------------");
        System.out.println("Ket qua:");
        System.out.println("Mảng nguồn: ");
        printArray(inputArray);
        int[] result = copyArray(inputArray, inputLen, start, end, ouputArray, outputLen, startOfCopy);
        if (result == null) {
            System.out.println("Có lỗi xảy ra");
        } else {
            System.out.println("Mảng đích: ");
            printArray(result);
        }
    }

    public static int[] copyArray(int[] inputArray, int inputLen, int start, int end, int[] outputArray, int outpuLen, int startOfCopy) {
        if (start >= 0 && end <= inputLen && startOfCopy >= 0 && startOfCopy <= outpuLen && start <= end) {
        	/*
        	*Trường hợp số lượng cần copy trong mảng nguồn nhỏ hơn số phần tử còn trống trong mảng đích
        	*/
            if ((end - start + 1) < (outpuLen - startOfCopy - 1)) {
            	/*
            	* Thực hiện dịch các phần tử
         		*/
                for (int i = outpuLen; i > startOfCopy + (end - start + 1) + 1; i--) {
                    outputArray[i - 1] = outputArray[i - 1 - (end - start + 1)];
                }
                /*
            	* Copy các phần tử vào mảng đích
         		*/
                for (int i = start; i <= end; i++) {
                    outputArray[startOfCopy + 1 + (i - start)] = inputArray[i];
                }
                System.out.println("So gia tri duoc sao chep: " + (end - start + 1));
            }
			/*
        	*Trường hợp số lượng cần copy trong mảng nguồn bằng số phần tử còn trống trong mảng đích
        	*/
             else if ((end - start + 1) == (outpuLen - startOfCopy - 1)) {
                for (int i = start; i <= end; i++) {
                    outputArray[startOfCopy + (i - start)] = inputArray[i];
                }
            } 
            /*
        	*Trường hợp số lượng cần copy trong mảng nguồn lớn hơn số phần tử còn trống trong mảng đích
        	*/
            else {
                for (int i = start; i < start + (outpuLen - startOfCopy); i++) {
                    outputArray[startOfCopy + (i - start)] = inputArray[i];
                }
            }
        }
        return outputArray;
    }

    public static int[] inputArray(int len) {
        int[] inputArray = new int[len];
        Random random = new Random();
        for (int i = 0; i < len; i++) {
            inputArray[i] = random.nextInt(100);
        }
        return inputArray;
    }

    public static void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("");
    }

}
