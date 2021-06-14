namespace Polimorfismo
{
    public class BeeKnees : Drink
    {
        public override void adicionarIngrediente()
        {
            ingredientes.limao -=1;
            ingredientes.mel -= 1;
            ingredientes.gin -=1;
        }

        public override void setIngredientes(Ingredientes i)
        {
            ingredientes = i;
        }
    }
}