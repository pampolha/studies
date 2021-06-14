using System; 

namespace Polimorfismo
{   
    class Program 
    {
        static void Main(string[] args) 
        {
            bool programa;
            programa = true;

            Ingredientes ingredientes = new Ingredientes();
            Estoque estoque = new Estoque();
            estoque.setIngredientes(ingredientes);
            estoque.Abastecer(10);

            int escolha;
            int pos;

            while (programa == true)
            {
                Console.Clear();  
                Console.WriteLine("Bem-vindo ao meu Bar!");
                Console.WriteLine("Selecione um dos drinks a seguir:");
                Console.WriteLine("\n 1. Caipirinha");
                Console.WriteLine(" 2. Bee Knees");
                Console.WriteLine(" 3. Aviation");
                escolha=int.Parse(Console.ReadLine());

                switch (escolha)
                {
                    case 1:
                        Console.Clear();
                        
                        Caipirinha caipirinha = new Caipirinha(); 
                        caipirinha.setIngredientes(ingredientes);
                        caipirinha.adicionarIngrediente();
                        
                        Console.WriteLine("A sua Caipirinha está pronta! Aproveite.");
                        Console.WriteLine("\nInsira qualquer tecla para continuar...");
                        Console.ReadLine();

                    break;
                    case 2:
                        Console.Clear();
                    
                        BeeKnees beeKnees = new BeeKnees(); 
                        beeKnees.setIngredientes(ingredientes);
                        beeKnees.adicionarIngrediente();
                        
                        Console.WriteLine("O seu Bee Knees está pronto! Aproveite.");
                        Console.WriteLine("\nInsira qualquer tecla para continuar...");
                        Console.ReadLine();

                    break;
                    case 3:
                        Console.Clear();
                    
                        Aviation aviation = new Aviation(); 
                        aviation.setIngredientes(ingredientes);
                        aviation.adicionarIngrediente();
                        
                        Console.WriteLine("O seu Aviation está pronto! Aproveite.");
                        Console.WriteLine("\nInsira qualquer tecla para continuar...");
                        Console.ReadLine();

                    break;
                    
                    default:
                        Console.WriteLine("Escolha inválida!");
                        Console.ReadLine();

                    break;
                }
            
                Console.Clear();
                Console.WriteLine("Escolha uma das opções abaixo:");
                Console.WriteLine("\n 1. Pedir outra bebida");
                Console.WriteLine(" 2. Saber mais sobre as bebidas servidas");
                Console.WriteLine(" 3. Verificar o estoque");
                Console.WriteLine(" 4. Sair do bar");
                pos=int.Parse(Console.ReadLine());

                switch (pos)
                {
                    case 1:

                    break;
                
                    case 2:
                        Console.Clear();
                        Console.WriteLine("Caipirinha - Para os brasileiros, este drink dispensa apresentações. Cachaça, limão, açúcar e gelo. Precisamos de mais o que? Uma praia não seria nada mal. Depois dos grandes eventos como copa e olimpíadas, a Caipirinha ficou ainda mais famosa mundialmente. Lembrando que caipirinha é feita de cachaça, OK?");
                        Console.WriteLine("\n--------------------------------------------------------------------------------------------------------------\n");
                        Console.WriteLine("Bee Knees - Criado na época da lei seca, a intenção do Bee Knees era disfarçar o sabor e o cheiro das bebidas caseiras na época. Interessante não? Os ingredientes são bastante simples e realmente fica gostoso: gim, limão e mel.");
                        Console.WriteLine("\n--------------------------------------------------------------------------------------------------------------\n");
                        Console.WriteLine("Aviation - O Aviation é basicamente um Blue Moon com o licor de cereja maraschino. Ou seria o Blue Moon um Aviation sem o licor? Falei do Blue Moon pois é mais fácil de encontrar por aqui. A receita do Aviation vai Gim, Licor de maraschino, Crème de Violette e limão.");
                        Console.WriteLine("\nInsira qualquer tecla para retornar...");
                        Console.ReadLine();
                        
                    break;    
                    case 3:
                        Console.Clear();

                        Console.WriteLine("Quantidade atual de ingredientes no estoque:");
                        Console.WriteLine("Quantidade atual de Gelo: " + ingredientes.gelo + "unidades.");
                        Console.WriteLine("Quantidade atual de Gin: " + ingredientes.gin + "unidades.");
                        Console.WriteLine("Quantidade atual de Açúcar: " + ingredientes.acucar + "unidades.");
                        Console.WriteLine("Quantidade atual de Creme: " + ingredientes.creme + "unidades.");
                        Console.WriteLine("Quantidade atual de Licor de Cereja: " + ingredientes.licorCereja + "unidades.");
                        Console.WriteLine("Quantidade atual de Limão: " + ingredientes.limao + "unidades.");
                        Console.WriteLine("Quantidade atual de Cachaça: " + ingredientes.cachaca + "unidades.");
                        Console.WriteLine("Quantidade atual de Mel: " + ingredientes.mel + "unidades.");
                        Console.WriteLine("\nInsira qualquer tecla para retornar...");
                        Console.ReadLine();
                        
                    break;
                    case 4:
                        Console.WriteLine("Espero que tenha se divertido! Volte em breve!");
                        Console.ReadLine();
                        programa = false;

                    break;
                    default:
                        Console.WriteLine("Escolha inválida!");
                        Console.ReadLine();

                    break;  
                }
            }
        }

    }
        
}

