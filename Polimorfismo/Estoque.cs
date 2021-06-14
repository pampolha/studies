namespace Polimorfismo
{
    public class Estoque 
    {
        public Ingredientes ingredientes;

        public void setIngredientes(Ingredientes i)
        {
            ingredientes = i;
        }
        public void Abastecer(int a)
        {
            ingredientes.acucar += a;
            ingredientes.cachaca += a;
            ingredientes.creme += a;
            ingredientes.gelo += a;
            ingredientes.mel += a;
            ingredientes.limao += a;
            ingredientes.licorCereja += a;
            ingredientes.gin += a;
        }
    }
}

