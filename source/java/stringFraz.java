import java.util.*;
public class stringFraz extends frazione{
    private String mid;
    public stringFraz(int n, int d, String s){
        super(n, d);
        mid=s;
        setName("stringFraz");
    }
    public void setMid(String s){
        mid=s;
    }
    public String getMid(){
        return mid;
    }@Override
    public stringFraz clone(){
        return new stringFraz(getNum(), getDen(), mid);
    }
    @Override
    public String toString(){
        return String.valueOf(getNum())+"/"+mid+"/"+String.valueOf(getDen());
    }
    @Override
    public stringFraz minima(){
        frazione a=super.clone();
        a.reduce();
        return new stringFraz(a.getNum(), a.getDen(), mid);
    }
    @Override
    public stringFraz complementare()throws alert{
        if(super.razionale()>1){
            throw new alert("frazione>1 non puo avere complementare");
        }
        frazione a=super.complementare();
        return new stringFraz(a.getNum(), a.getDen(), mid);
    }
    @Override
    public stringFraz somma(frazione f)throws alert{
        if(f instanceof stringFraz){
            frazione a=super.somma(f);
            if(super.maggiore(f))
                return new stringFraz(a.getNum(), a.getDen(), ((stringFraz)f).mid);
            else
                return new stringFraz(a.getNum(), a.getDen(), mid);
        }
        else 
            throw new alert("entrambi gli oggetti devono esere StringFraz");
    }    
    @Override
    public stringFraz differenza(frazione f)throws alert{
        if(f instanceof stringFraz){
            if(super.maggiore(f)){
                frazione a=super.differenza(f);
                return new stringFraz(a.getNum(), a.getDen(), mid);
            }
            else{
                frazione a= (frazione)f;
                a=a.differenza(this);
                return new stringFraz(a.getNum(), a.getDen(), ((stringFraz)f).mid);
            }
        }
        else 
            throw new alert("entrambi gli oggetti devono esere StringFraz");
    }
    @Override
    public frazione moltiplicazione(frazione f)throws alert{
        if(f instanceof stringFraz){
            frazione a=super.moltiplicazione(f);
            if(super.maggiore(f))
                return new stringFraz(a.getNum(), a.getDen(), mid);
            else
                return new stringFraz(a.getNum(), a.getDen(), ((stringFraz)f).mid);
        }
        else 
            throw new alert("entrambi gli oggetti devono esere StringFraz");
    }
    @Override
    public frazione divisione(frazione f)throws alert{
        if(f instanceof stringFraz){
            if(super.maggiore(f)){
                frazione a=super.divisione(f);
                return new stringFraz(a.getNum(), a.getDen(), ((stringFraz)f).mid);
            }
            else{
                frazione a= (frazione)f;
                a=a.divisione(this);
                return new stringFraz(a.getNum(), a.getDen(), mid);
            }
        }
        else 
            throw new alert("entrambi gli oggetti devono esere StringFraz");
    }
    @Override
    public boolean ugualianza(frazione f)throws alert{
        if(f instanceof stringFraz)
            return razionale()==f.razionale() && mid==((stringFraz)f).mid;
        throw new alert("entrambi gli oggetti devono esere StringFraz");
    }
    @Override
    public boolean diverso(frazione f)throws alert{
        if(f instanceof stringFraz)
            return razionale()!=f.razionale() && mid!=((stringFraz)f).mid;
        throw new alert("entrambi gli oggetti devono esere StringFraz");
    }
    @Override
    public boolean maggiore(frazione f)throws alert{
        if(f instanceof stringFraz)
            return razionale()>f.razionale() /*&& mid==((stringFraz)f).mid*/;
        throw new alert("entrambi gli oggetti devono esere StringFraz");
    }
    @Override
    public boolean minore(frazione f)throws alert{
        if(f instanceof stringFraz)
            return razionale()<f.razionale() /*&& mid==((stringFraz)f).mid*/;
        throw new alert("entrambi gli oggetti devono esere StringFraz");
    }
}