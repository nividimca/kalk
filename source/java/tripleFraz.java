import java.util.*;
public class tripleFraz extends frazione{
    private int triple;
    public tripleFraz(int n, int d, int t){
        super(n,d);
        triple=t;
        setName("tripleFraz");
    }
    public void setTriple(int t){
        triple=t;
    }
    public int getMid(){
        return triple;
    }@Override
    public tripleFraz clone(){
        return new tripleFraz(getNum(), getDen(), triple);
    }
    @Override
    public String toString(){
        return String.valueOf(getNum())+"/"+String.valueOf(getDen())+"/"+String.valueOf(triple);
    }
    @Override    
    public int getMCD(){
        if (triple<0){
            return MCD(super.getDen(),-triple);
        }
        return MCD(super.getMCD(), triple);
    }
    @Override
    public void reduce(){
        int a=getMCD();
        setNum(getNum()/a);
        setDen(getDen()/a);
        triple=triple/a;
    } 
    @Override
    public tripleFraz minima(){
        frazione a=super.clone();
        a.reduce();
        return new tripleFraz(a.getNum(), a.getDen(), triple);
    }
    @Override
    public Double razionale(){
        double a=getNum();
        double b=getDen();
        double c=triple;
        return a/b+c/b;
    }
    @Override
    public tripleFraz complementare()throws alert{
        if(super.razionale()>1){
            throw new alert("frazione>1 non puo avere complementare");
        }

        return new tripleFraz(getDen()-getNum(), getDen(), getDen()-triple);
    }
    @Override
    public tripleFraz somma(frazione f)throws alert{
        if(f instanceof tripleFraz){
            frazione a=super.somma(f);
            Long n=Long.valueOf(triple)*Long.valueOf(f.getDen()) + 
            Long.valueOf(((tripleFraz)f).triple)*Long.valueOf(getDen());
            if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE)
               throw new alert("la somma non rispetta i limiti di INT");
            return new tripleFraz(a.getNum(), a.getDen(), n.intValue());
        }
        else 
            throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }    
    @Override
    public tripleFraz differenza(frazione f)throws alert{
        if(f instanceof tripleFraz){
            frazione a=super.differenza(f);
            Long n=Long.valueOf(triple)*Long.valueOf(f.getDen()) - 
            Long.valueOf(((tripleFraz)f).triple)*Long.valueOf(getDen());
            if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE)
               throw new alert("la differenza non rispetta i limiti di INT");
            return new tripleFraz(a.getNum(), a.getDen(), n.intValue());
        }
        else 
            throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }
    @Override
    public frazione moltiplicazione(frazione f)throws alert{
        if(f instanceof tripleFraz){
            frazione a=super.moltiplicazione(f);
            Long n=Long.valueOf(triple)*Long.valueOf(((tripleFraz)f).triple);
            if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE)
               throw new alert("la moltiplicazione non rispetta i limiti di INT");
            return new tripleFraz(a.getNum(), a.getDen(), n.intValue());
        }
        else 
            throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }
    @Override
    public frazione divisione(frazione f)throws alert{
        if(getNum()==0){
            return new frazione(0, 1);
        }
        if(f.getNum()==0){
            throw new alert("non si puo dividere per zero");
        }
        if(f instanceof tripleFraz){
            frazione a=super.somma(f);
            Long n=Long.valueOf(getNum())*Long.valueOf(f.getNum());
            Long d=Long.valueOf(getDen())*Long.valueOf(f.getDen());
            Long t=Long.valueOf(triple)*Long.valueOf(((tripleFraz)f).triple);
            if(n>Integer.MAX_VALUE || n<Integer.MIN_VALUE 
            || d>Integer.MAX_VALUE || d<Integer.MIN_VALUE 
            || t>Integer.MAX_VALUE || t<Integer.MIN_VALUE ){
                throw new alert("la divisione non rispetta i limiti di INT");
            }
            return new tripleFraz(n.intValue(), d.intValue(), t.intValue());
        }
        else 
            throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }
    @Override
    public boolean ugualianza(frazione f)throws alert{
        if(f instanceof tripleFraz)
            return razionale()==f.razionale();
        throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }
    @Override
    public boolean diverso(frazione f)throws alert{
        if(f instanceof tripleFraz)
            return razionale()!=f.razionale();
        throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }
    @Override
    public boolean maggiore(frazione f)throws alert{
        if(f instanceof tripleFraz)
            return razionale()>f.razionale();
        throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }
    @Override
    public boolean minore(frazione f)throws alert{
        if(f instanceof tripleFraz)
            return razionale()<f.razionale();
        throw new alert("entrambi gli oggetti devono esere tripleFraz");
    }
}