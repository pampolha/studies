namespace Polimorfismo
{
    public abstract class Drink 
    {
        public Ingredientes ingredientes;
        public abstract void setIngredientes(Ingredientes i);
        public abstract void adicionarIngrediente();
    }
}