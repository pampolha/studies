namespace Polimorfismo
{
    public class Caipirinha : Drink
    {
        public override void adicionarIngrediente()
        {
            ingredientes.gelo -= 1;
            ingredientes.cachaca -= 1;
            ingredientes.limao -= 1;
            ingredientes.acucar -= 1;  
        }

        public override void setIngredientes(Ingredientes i)
        {
            ingredientes = i;
        }
    }
}