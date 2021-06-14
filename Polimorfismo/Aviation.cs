namespace Polimorfismo
{
    public class Aviation : Drink
    {
        public override void adicionarIngrediente()
        {
            ingredientes.creme -= 1;
            ingredientes.limao -= 1;
            ingredientes.gin -= 1;
            ingredientes.licorCereja -= 1;
        }

        public override void setIngredientes(Ingredientes i)
        {
            ingredientes = i;
        }
    }
}