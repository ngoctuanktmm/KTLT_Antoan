/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ktltat;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author DELL
 */
public class Lab1_Buffer {

    /**
     * @param args the command line arguments
     */
    private int src[],dst[],n,m,startSrc,endSrc,startDes;
    public static void main(String[] args) {
        // TODO code application logic here
        Lab1_Buffer lab1=new Lab1_Buffer();
        lab1.inputData();
        int count=lab1.copyArray(lab1.src,lab1.n,lab1.startSrc, lab1.endSrc,lab1.dst,lab1.m,lab1.startDes);
        System.out.println("");
        System.out.println("So gia tri duoc sao chep:"+count);
        for(int i=lab1.startDes;i<lab1.startDes+count;i++){
            System.out.println("dst["+i+"]="+lab1.dst[i]);
        }
    }
    private void inputData(){
        try{
            File file= new File("C:\\Users\\DELL\\Documents\\NetBeansProjects\\KTLTAT\\src\\ktltat\\sample_input.txt");  
            Scanner in = new Scanner(file);
//            Scanner in = new Scanner(System.in);
            while(true){
                System.out.print("Chieu dai Mang Nguon:");
                n= in.nextInt();
                if(n>0){
                    src = new int[n];
                    break;
                }
            }
            for(int i=0; i<n;i++){
                System.out.print("source["+i+"]=");
                src[i]= in.nextInt();
            }
            while(true){
                System.out.print("Chieu dai Mang Dich:");
                m= in.nextInt();
                if(m>0){
                    dst = new int[m+n];
                    break;
                }
            }
            for(int i=0; i<m;i++){
                System.out.print("destination["+i+"]=");
                dst[i]= in.nextInt();
            }
            while(true){
                System.out.print("Vi tri bat dau copy:");
                startSrc= in.nextInt();
                if(startSrc > 0 && startSrc <n){
                    startSrc--;
                    break;
                }
            }
            while(true){
                System.out.print("Vi tri ket thuc copy:");
                endSrc= in.nextInt();
                if(endSrc > startSrc && endSrc <= n){
                    endSrc--;
                    break;
                }
            }
            while(true){
                System.out.print("Vi tri bat dau mang dich:");
                startDes= in.nextInt();
                if(startDes > 0 && startDes < m){
                    startDes--;
                    break;
                }
            }
        }catch(Exception e){
            System.out.println(e);
        }
        
        
    }
    private int copyArray(int src[], int n,int startSrc,int endSrc,int dst[], int m, int startDes){
        int count=endSrc-startSrc+1;
        System.out.println("count="+count);
        for(int i=m+count-1;i>=startDes;i--){
            if(i>=startDes+count)
                dst[i]=dst[i-count];
            else if(i<startDes+count)
                dst[i]=src[endSrc--];
        }
        for(int i=0;i<m+count;i++){
            System.out.print(dst[i]+" ");
        }        
        return count;
    }
}
