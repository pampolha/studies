using System;

namespace Locadora
{
    class Program
    {
        static void Main(string[] args)
        {
            string nomeDoJogo;

            Prateleira prateleira = new Prateleira();
            
            bool programa;
            programa = true;

            while (programa)
            {
                int escolha;
                Console.WriteLine("bem vindo a locadora!");
                Console.WriteLine("por favor escolha uma das opções abaixo:");
                Console.WriteLine(" 0. Sair do programa");
                Console.WriteLine(" 1. Proucurar Jogo");
                Console.WriteLine(" 2. Alugar Jogo");
                Console.WriteLine(" 3. Adicionar Jogo");
                Console.WriteLine(" 4. Mostrar os jogos na prateleira");
                Console.WriteLine("digite o numero da sua escolha:");
                escolha=int.Parse(Console.ReadLine());

                    switch (escolha)
                    {
                        case 0:
                            programa = false;
                            break;
                        case 1:
                            Console.WriteLine("digite o nome do jogo que deseja procurar:");
                            nomeDoJogo = Console.ReadLine();
                            Console.WriteLine(prateleira.ProcurarNome(nomeDoJogo));
                            break;
                        case 2:
                            break;
                        case 3:
                            Jogo jogo3 = new Jogo();
                            Console.WriteLine("digite o genero do jogo:");
                            jogo3.Genero =  Console.ReadLine();
                            Console.WriteLine("agora digite o nome do jogo:");
                            jogo3.Nome = Console.ReadLine();
                            prateleira.AdicionarJogo(jogo3);
                            break;
                        case 4:
                            prateleira.MostrarJogos();
                            break;
                        default:
                            break;
                    }
                
            }
        }
    }
}
