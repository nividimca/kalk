import java.util.*;

public class use{
    public static void main(String[] args) {
        frazione fraz1=new frazione(3, 4);
        frazione fraz2=new frazione(20, -4);
        frazione fraz3=new frazione(-45, 15);
        
        frazione stringF1=new stringFraz(3, 4, "F1");
        frazione stringF2=new stringFraz(-32, 10, "F2");
        frazione stringF3=new stringFraz(98645321, -1, "F3");

        frazione tripleF1=new tripleFraz(3, 4, 3);
        frazione tripleF2=new tripleFraz(-45, 7, -15);
        frazione tripleF3=new tripleFraz(350, -100, 50);
        frazione tripleF4=new tripleFraz(1286619151, -1, 50);
                                         
        //frazione        
        System.out.print("\n"+"Parte fraz"+"\n");
        System.out.print(fraz1.toString()+"\n");
        System.out.print(fraz2.toString()+"\n");
        System.out.print(fraz3.toString()+"\n");
        System.out.print("\n"+"operazione"+"\n");
        try{
            System.out.print((fraz1.somma(fraz2)).toString()+"\n");
            System.out.print((fraz2.somma(fraz3)).toString()+"\n");
            System.out.print((fraz1.differenza(fraz3)).toString()+"\n");
            System.out.print((fraz2.moltiplicazione(fraz2)).toString()+"\n");
            System.out.print((fraz1.moltiplicazione(fraz3)).toString()+"\n");
            System.out.print((fraz1.divisione(fraz2)).toString()+"\n");
            System.out.print((fraz1.divisione(fraz3)).toString()+"\n");
        }
        catch(alert a){
            System.out.print(a+"\n");
        }

        //stringFraz        
        System.out.print("\n"+"\n"+"Parte stringFraz"+"\n");
        System.out.print(stringF1.toString()+"\n");
        System.out.print(stringF2.toString()+"\n");
        System.out.print(stringF3.toString()+"\n");
        System.out.print("\n"+"operazione"+"\n");
        try{
            System.out.print((stringF1.somma(stringF2)).toString()+"1\n");
            System.out.print((stringF2.somma(stringF3)).toString()+"\n");
            System.out.print((stringF1.differenza(stringF3)).toString()+"\n");
            System.out.print((stringF1.moltiplicazione(stringF3)).toString()+"\n");
            System.out.print((stringF1.divisione(stringF2)).toString()+"\n");
            System.out.print((stringF1.divisione(stringF3)).toString()+"\n");
            if( stringF1.diverso( stringF2.somma( stringF3))){
                System.out.print("stringF1 !=(stringF2+stringF3) \n");
            }
            if( stringF1.ugualianza(stringF1)){
                System.out.print("stringF1 ==stringF1\n");
            }

            System.out.print((stringF3.moltiplicazione(stringF3)).toString()+"\n");
        }
        catch(alert a){
            System.out.print(a+"\n");
        }

        //tripleFraz        
        System.out.print("\n"+"\n"+"Parte tripleFraz"+"\n");
        System.out.print(tripleF1.toString()+"\n");
        System.out.print(tripleF2.toString()+"\n");
        System.out.print(tripleF3.toString()+"\n");
        System.out.print("\n"+"operazione"+"\n");
        try{
            System.out.print((tripleF1.somma(tripleF2)).toString()+"1\n");
            System.out.print((tripleF2.somma(tripleF3)).toString()+"\n");
            System.out.print((tripleF1.differenza(tripleF3)).toString()+"\n");
            System.out.print((tripleF1.moltiplicazione(tripleF3)).toString()+"\n");
            System.out.print((tripleF1.divisione(tripleF2)).toString()+"\n");
            System.out.print((tripleF1.divisione(tripleF3)).toString()+"\n");
            System.out.print((tripleF4.somma(tripleF4)).toString()+"\n");
        }
        catch(alert a){
            System.out.print(a+"\n");
        }    
        try{
            if( stringF1.diverso( tripleF1)){
                System.out.print("stringF1 != tripleF1 \n");
            }
        }
        catch(alert a){
            System.out.print(a+"\n");
        }    
        try{
            if( tripleF1.diverso( stringF1)){
                System.out.print("tripleF1 != stringF1 \n");
            }
        }
        catch(alert a){
            System.out.print(a+"\n");
        }
    }
}