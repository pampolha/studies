namespace Locadora
{
    public  class Jogo
    {
        public  string Genero {get; set;}
        public  string Nome {get; set;}

        public override string ToString()
        {
            return "Nome: " + Nome + " | Gênero: " + Genero + "\n";
        }
    }
}