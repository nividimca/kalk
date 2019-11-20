import java.util.*;

public class frazione{
    private int num;
    private int den;
    private String name;
    public frazione(int n, int d){
        if(d<0){
            n=n*(-1);
            d=d*(-1);
        }
        num=n;
        den=d;
        name="frazione";
    }
    public void setNum(int i){
        num=i;
    }
    public int getNum(){
        return num;
    }
    public void setDen(int i){
        den=i;
    }
    public int getDen(){
        return den;
    }
    public void setName(String s){
        name=s;
    }
    public String getName(){
        return name;
    }
    public frazione clone(){
        return new frazione(num, den);
    }
    public String toString(){
        return String.valueOf(getNum())+"/"+String.valueOf(getDen());
    }
    public static int MCD(int x, int y){
        return y==0 ? x: MCD(y, x%y);
    }
    public int getMCD(){
        if (num<0){
            return MCD(-num,den);
        }
        return MCD(num,den);
    }
    public void reduce(){
        int a=getMCD();
        num=num/a;
        den=den/a;
    }
    public frazione minima(){
        frazione a=clone();
        a.reduce();
        return a;
    }
    public Double razionale(){
        double a=num;
        double b=den;
        return a/b;
    }
    public frazione complementare()throws alert{
        if(razionale()>1){
            throw new alert("frazione>1 non puo avere complementare");
        }
        return new frazione(getNum()-getDen(), getDen());
    }
    public frazione somma(frazione f)throws alert{
        Long n=Long.valueOf(num)*Long.valueOf(f.den)+Long.valueOf(f.num)*Long.valueOf(den);
        Long d=Long.valueOf(den)*Long.valueOf(f.den);
        if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE || d>Integer.MAX_VALUE || d<Integer.MIN_VALUE )
            throw new alert("la somma non rispetta i limiti di INT");
        frazione a= new frazione(n.intValue(),d.intValue());
        a.reduce();
        return a;
    }
    public frazione differenza(frazione f)throws alert{
        Long n=Long.valueOf(num)*Long.valueOf(f.den)-Long.valueOf(f.num)*Long.valueOf(den);
        Long d=Long.valueOf(den)*Long.valueOf(f.den);
        if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE || d>Integer.MAX_VALUE || d<Integer.MIN_VALUE )
            throw new alert("la differenza non rispetta i limiti di INT");
        frazione a= new frazione(n.intValue(),d.intValue());
        a.reduce();
        return a;
    }
    public frazione moltiplicazione(frazione f)throws alert{
        Long n=Long.valueOf(num)*Long.valueOf(f.num);
        Long d=Long.valueOf(den)*Long.valueOf(f.den);
        if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE || d>Integer.MAX_VALUE || d<Integer.MIN_VALUE )
            throw new alert("la moltiplicazione non rispetta i limiti di INT");
        frazione a= new frazione(n.intValue(),d.intValue());
        a.reduce();
        return a;
    }
    public frazione divisione(frazione f)throws alert{
        if(num==0){
            return new frazione(0, 1);
        }
        if(f.num==0){
            throw new alert("non si puo dividere per zero");
        }
        Long n=Long.valueOf(num)*Long.valueOf(f.den);
        Long d=Long.valueOf(den)*Long.valueOf(f.num);
        if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE || d>Integer.MAX_VALUE || d<Integer.MIN_VALUE )
            throw new alert("la divisione non rispetta i limiti di INT");
        frazione a= new frazione(n.intValue(),d.intValue());
        a.reduce();
        return a;
    }
    public boolean ugualianza(frazione f)throws alert{
        return razionale()==f.razionale();
    }
    public boolean diverso(frazione f)throws alert{
        return razionale()!=f.razionale();
    }
    public boolean maggiore(frazione f)throws alert{
        return razionale()>f.razionale();
    }
    public boolean minore(frazione f)throws alert{
        return razionale()<f.razionale();
    }
}